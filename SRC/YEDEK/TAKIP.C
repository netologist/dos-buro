#include "/ozgan/programs/h/genel.h"

void kayit_gir(DOSYA *handle)
{
	char *bellek, data_tut[7];
	long i;
	DOSYA mukellef;

	bellek = ekran_giris();
	strcpy(mukellef.ana_dosya, "mukellef.dat");
	strcpy(mukellef.indeks_dosya, "mukellef.ind");
	strcpy(mukellef.yol, handle->yol);
	dosya_ac(&mukellef);

	takip_data = (TAKIP *) dataci;
	dosya_ac(handle);
	memcpy(data_tut, &handle->ana_baslik->dosya_tanimi[20], 6);
	strcpy(&handle->ana_baslik->dosya_tanimi[20], "ISLEM");
	dosya_kapa(handle);
	for (i = 0; i < mukellef.indeks_baslik->toplam_kayit; i++) {
		detay_oku(&mukellef, indeks_gezgini(&mukellef,  i), DATA_AL);
		memcpy(&dataci[29], mukellef.indeks_detay->data, 44);
		strcpy(&dataci[74], "HAYIR   ");
		takip_kayit_cercevesi(12, 37, takip_data->Muk_Kod);
		dosya_kayit(handle);
	}
	dosya_ac(handle);
	memcpy(&handle->ana_baslik->dosya_tanimi[20], data_tut, 6);
	dosya_kapa(handle);
	ekran_cikis(bellek);
	dosya_kapa(&mukellef);
}

char *takip_dosya_yap(char *string)
{
	strcpy(string, "MT000000.DAT");

	string[3] = takip_data->Takip[0];

	if (strlen(takip_data->Aylar) == 2) {
		string[4] = takip_data->Aylar[0];
		string[5] = takip_data->Aylar[1];
	}
	else
		string[5] = takip_data->Aylar[0];

	if (strlen(takip_data->Yillar) == 2) {
		string[6] = takip_data->Yillar[0];
		string[7] = takip_data->Yillar[1];
	}
	else
		string[7] = takip_data->Yillar[0];
	return string;
}

int dosya_sil(DOSYA *handle)
{
	char birlesen[100];
	int ana, indeks;

	yol_yapici(handle->yol, handle->ana_dosya, birlesen);
	ana = unlink(birlesen);
	if (ana != 0)
		return 0;
	yol_yapici(handle->yol, handle->indeks_dosya, birlesen);
	indeks = unlink(birlesen);
	return indeks;
}

void takip_kayit_cercevesi(int satir, int kolon, char *string)
{
	formyukle(satir, kolon, "bin/talinan.frm");

	harfler(satir+3, kolon+4, string, BEYAZ_ | SIYAH);
}

void dosya_yapisi_doldur(DOSYA *handle, char *yol)
{
	char string[25];

	memset(string, 0, 25);
	takip_data = (TAKIP *)dataci;
	takip_dosya_yap(string);
	strcpy(handle->ana_dosya, string);
	strcpy(&string[9], "IND");
	strcpy(handle->indeks_dosya, string);
	strcpy(handle->yol, yol);
}

int takip_dosya_kontrol(void)
{
	DOSYA handle;
	FILE *fp;
	char birlesen[100];

	dosya_yapisi_doldur(&handle, "DATA/");
	yol_yapici(handle.yol, handle.ana_dosya, birlesen);

	if ((fp = _fsopen(birlesen, "rb", SH_DENYNO)) == NULL)
		return 0; // DOSYA BULUNAMADI...
	dosya_ac(&handle);
	if (strcmp(&handle.ana_baslik->dosya_tanimi[20], "ISLEM") == 0) {
		dosya_kapa(&handle);
		fclose(fp);
		return 2;
	}
	dosya_kapa(&handle);
	fclose(fp);
	return 1; // DOSYA MEVCUT
}

/*
void main(void)
{
	clrscr();

	takip_dosya_kontrol(NULL);
}*/