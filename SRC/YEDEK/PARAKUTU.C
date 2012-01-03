#include "/ozgan/programs/h/genel.h"

void kasa_goruntusu(void)
{
	TABLO_FORM *tablo2;
	TABLO_BILGI baslik2;
	KASA_DURUMU veri;
	FILE *fp;
	para_data = (PARA_KUTU *) dataci;

	tablo2 = (TABLO_FORM *) tabloyukle("bin/kasadurm.tbl", &baslik2);
	if ((fp = fopen("data/kasadurm.dat", "rb")) == NULL) {
		printf("DOSYA HATASI\n");
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	fread(&veri, 1, sizeof(KASA_DURUMU), fp);

	tablo_yerlestir(2, 15, Data_ParaKutusu_Genel, (char *) para_data, tablo, &baslik);
	tablo_yerlestir(2, 15, Data_ParaKutusu_KasaDurumu, (char *) &veri, tablo2, &baslik2);
	fclose(fp);
}

void kasa_durumu(void)
{
	KASA_DURUMU veri;
	char sonuc[25];
	FILE *fp;
	int ay;

	if ((fp = fopen("data/kasadurm.dat", "rb+")) == NULL) {
		printf("DOSYA HATASI\n");
		exit(1);
	}
	strncpy(sonuc, &para_data->Vadesi[2], 2);
	ay = atoi(sonuc) - 1;
	memset(sonuc, 0, 25);

	fseek(fp, 0, SEEK_SET);
	fread(&veri, 1, sizeof(KASA_DURUMU), fp);

	switch (para_data->Odeme_Secenegi[0]) {
		case '0': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Lira, sonuc);
				  else
					  cikarma(para_data->Tutar, veri.Lira, sonuc);
				  strcpy(veri.Lira, sonuc); break;
		case '1': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Dolar, sonuc);
				  else
					  cikarma(para_data->Tutar, veri.Dolar, sonuc);
				  strcpy(veri.Dolar, sonuc); break;
		case '2': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Mark, sonuc);
				  else
					  cikarma(para_data->Tutar, veri.Mark, sonuc);
				  strcpy(veri.Mark, sonuc); break;
		case '3':
		case '4': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Cek, sonuc);
				  else
					  cikarma(para_data->Tutar, veri.Cek, sonuc);

				  strcpy(veri.Cek, sonuc);
				  veri.Tablo[ay * 2] = 1;
				  break;
	}
	fseek(fp, 0, SEEK_SET);
	fwrite(&veri, 1, sizeof(KASA_DURUMU), fp);
	fclose(fp);
}

void odeme_secenegi_kontrol(void)
{
	if (para_data->Odeme_Secenegi[0] == '1' || para_data->Odeme_Secenegi[0] == '2') {
		formgolge(9, 32, "bin/kurlar.frm");
		formyukle(9, 32, "bin/kurlar.frm");
		sayi_yaz(para_data->Kur, 12, 47, 9, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI);
	}
	carpma(para_data->Tutar, para_data->Kur, para_data->Kur_Cevirisi);
}

void kayit_no_al(void)
{
	DOSYA handle;
	PARA_KUTU *eski_data;
	char sonuc[25], artibir[25];

	handle.tablo = tablo;
	handle.baslik = baslik;
	para_data = (PARA_KUTU *) dataci;
	handle.data = (char *) dataci;

	memset(artibir, 0, 25);
	memset(sonuc, 0, 25);
	artibir[0] = '1';

	strcpy(handle.ana_dosya, "hareket.dat");
	strcpy(handle.indeks_dosya, "hareket.ind");
	strcpy(handle.yol, "data/");
	dosya_ac(&handle);
	if (handle.indeks_baslik->toplam_kayit == 0)
		strcpy(para_data->Kayit_No, "000000");
	else {
		detay_oku(&handle, handle.indeks_baslik->son_kayit, DATA_AL);
		eski_data = (PARA_KUTU *) handle.ana_detay->data;
		toplama(eski_data->Kayit_No, artibir, sonuc);
		memset(artibir, 0, 25);
		memset(artibir, '0', 6);
		strcpy(&artibir[6-strlen(sonuc)], sonuc);
		strcpy(para_data->Kayit_No, artibir);
	}
	dosya_kapa(&handle);
}

int genel_kontrol(void)
{
	if (para_data->Odeme_Turu[0] == '0' && para_data->Hareket_Turu[0] != '0') {
		msj_kutu(NULL, "Aidat sadece mkellefte kullanlabilir", UYARI);
		return 1;
	}
	else if (para_data->Mukellef_Adresi == 0) {
		msj_kutu(NULL, "Firma se‡mek zorundasnz !", UYARI);
		return 1;
	}
	else if (strlen(para_data->Kayit_Tarihi) == 0) {
		msj_kutu(NULL, "Kayt tarihini girmek zorundasnz !", UYARI);
		return 1;
	}
	else if (strlen(para_data->Tutar) == 0) {
		msj_kutu(NULL, "Para girmezseniz kayt edemezsiniz !", UYARI);
		return 1;
	}
	else if (para_data->Odeme_Secenegi[0] >= '3') {
		if (strlen(para_data->Vadesi) == 0) {
			msj_kutu(NULL, "Vade tarihini girmek zorundasnz !", UYARI);
			return 1;
		}
	}
	return 0;
}

void bakiye_gir(void)
{
	DOSYA mukellef;
	ACILIS_DATA *mukellef_data;
	char sonuc[25], tasiyici[25], *dataci;

	memset(sonuc, 0, 25);
	memset(tasiyici, 0, 25);

	strcpy(mukellef.ana_dosya, "mukellef.dat");
	strcpy(mukellef.indeks_dosya, "mukellef.ind");
	strcpy(mukellef.yol, "data/");

	dosya_ac(&mukellef);
	detay_oku(&mukellef, para_data->Mukellef_Adresi, DATA_AL);
	mukellef_data = (ACILIS_DATA *) mukellef.ana_detay->data;

	if (para_data->Odeme_Secenegi[0] == '1' || para_data->Odeme_Secenegi[0] == '2')
		strcpy(tasiyici, para_data->Kur_Cevirisi);
	else
		strcpy(tasiyici, para_data->Tutar);

	if (para_data->Odeme_Turu[0] == '2') {
		toplama(tasiyici, mukellef_data->Bakiye_Alacak, sonuc);
		strcpy(mukellef_data->Bakiye_Alacak, sonuc);
	}
	else {
		toplama(tasiyici, mukellef_data->Bakiye_Borc, sonuc);
		strcpy(mukellef_data->Bakiye_Borc, sonuc);
	}
	eski_kayit(&mukellef, para_data->Mukellef_Adresi);
	dosya_kapa(&mukellef);
}

void para_kaydi_gir(void)
{
	DOSYA handle;

	handle.tablo = tablo;
	handle.baslik = baslik;

	strcpy(handle.ana_dosya, "hareket.dat");
	strcpy(handle.indeks_dosya, "hareket.ind");
	strcpy(handle.yol, "data/");

	if (kayit_adresi == 0) {
		if (genel_kontrol() == 0) {
			if (aidat_tablosu() == 0) {
				dosya_ac(&handle);
				para_data = (PARA_KUTU *) dataci;
				handle.data = (char *) dataci;
				odeme_secenegi_kontrol();
				bakiye_gir();
				kasa_durumu();
				dosya_kapa(&handle);
				kayit_adresi = dosya_kayit(&handle);
				if (kayit_adresi == 0)
					msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);
				else
					mesaj_goster_kac(" Kayt tamamland !");
			}
		}
	}
	else {
		if (genel_kontrol() == 0) {
			dosya_ac(&handle);
			detay_oku(&handle, kayit_adresi, DATA_ALMA);
			memcpy(handle.ana_detay->data, dataci, baslik.data_uzunlugu);
			indeks_uzunlugu(&handle, handle.indeks_detay->data);
			eski_kayit(&handle, kayit_adresi);
			dosya_kapa(&handle);
			mesaj_goster_kac(" Kayt de§iŸtirildi.");
		}
	}
}

int aidat_tablosu(void)
{
	DOSYA mukellef;
	char depo[5];
	ACILIS_DATA *mukellef_data;
	int ay;

	if (para_data->Odeme_Turu[0] == '0') {
		strcpy(mukellef.ana_dosya, "mukellef.dat");
		strcpy(mukellef.indeks_dosya, "mukellef.ind");
		strcpy(mukellef.yol, "data/");
		memset(depo, 0, 5);
		strncpy(depo, &para_data->Kayit_Tarihi[2], 2);
		ay = atoi(depo) - 1;
		dosya_ac(&mukellef);
		detay_oku(&mukellef, para_data->Mukellef_Adresi, DATA_AL);
		mukellef_data = (ACILIS_DATA *)mukellef.ana_detay->data;
		if (mukellef_data->Tablo[ay * 2] == 1 && kayit_adresi == 0) {
			msj_kutu(NULL, "Bu aidat daha once girilmiŸ ...", UYARI);
			return 1;
		}
		mukellef_data->Tablo[ay * 2] = 1;
		eski_kayit(&mukellef, para_data->Mukellef_Adresi);
		dosya_kapa(&mukellef);
	}
	return 0;
}