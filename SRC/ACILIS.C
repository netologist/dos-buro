#include "/ozgan/programs/h/genel.h"

void acilis_goruntusu(void)
{
	char sonuc[80];
	int konum;

	memset(sonuc, 0, 80);

	acilis_data = (ACILIS_DATA *) dataci;
	toplama(acilis_data->Devir_Borc, acilis_data->Bakiye_Borc, sonuc);
	sayi_temizle(acilis_data->Devir_Borc, 14);
	if (acilis_data->Devir_Borc[0] == '0')
		memset(acilis_data->Devir_Borc, 0, 14);

	sayi_temizle(acilis_data->Bakiye_Borc, 14);
	if (acilis_data->Bakiye_Borc[0] == '0')
		memset(acilis_data->Bakiye_Borc, 0, 14);

	sayi_temizle(sonuc, 14);
	if (sonuc[0] == 0)
		memset(sonuc, 0, 14);
	konum =	strlen(basamakla(sonuc));
	doldur(18, 60, ' ', 14, BEYAZ_);
	harfler(18, 74-konum, basamakla(sonuc), BEYAZ_ | SIYAH);

	memset(sonuc, 0, 80);
	toplama(acilis_data->Devir_Alacak, acilis_data->Bakiye_Alacak, sonuc);
	sayi_temizle(acilis_data->Devir_Alacak, 14);
	if (acilis_data->Devir_Alacak[0] == '0')
		memset(acilis_data->Devir_Alacak, 0, 14);
	sayi_temizle(acilis_data->Bakiye_Alacak, 14);
	if (acilis_data->Bakiye_Alacak[0] == '0')
		memset(acilis_data->Bakiye_Alacak, 0, 14);
	sayi_temizle(sonuc, 14);
	if (sonuc[0] == 0)
		memset(sonuc, 0, 14);
	konum =	strlen(basamakla(sonuc));
	doldur(19, 60, ' ', 14, BEYAZ_);
	harfler(19, 74-konum, basamakla(sonuc), BEYAZ_ | SIYAH);
	tablo_yerlestir(2, 15, Data_Acilis_Bilgisi, dataci, tablo, &baslik);
	tablo_yerlestir(0, 0, Data_Acilis_Tablo, dataci, tablo, &baslik);
}

int aidat_kontrol(DOSYA *handle)
{
	int i;
	ACILIS_DATA *mukellef_data;

	mukellef_data = (ACILIS_DATA *) handle->data;

	for (i = 0; i < 12; i++)
		if (strlen(mukellef_data->Bakiye_Borc) != 0 || strlen(mukellef_data->Bakiye_Alacak) != 0) {
			msj_kutu(NULL, "™nce hareketleri silmelisiniz !..", UYARI);
			return 1;
		}
	return 0;
}

void acilis_kayit(DOSYA *handle)
{
	// kstl kullanm ayar
	dosya_ac(handle);
	if (handle->ana_baslik->toplam_kayit > 9) {
		msj_kutu(NULL, "DEMO VERS˜YON-10 KAYITTAN FAZLA G˜R˜LEMEZ", HATA);
		dosya_kapa(handle);
		goto SON;
	}
	dosya_kapa(handle);
	if (kayit_adresi == 0) {
		kayit_adresi = dosya_kayit(handle);
		if (kayit_adresi == 0)
			msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);
		else {
			mesaj_goster_kac(" Kayt tamamland !");
			uyari_gonder(2);
			indeks_bilgisi(tablo, &baslik, INDEKS_KAPA);
		}
	}
	else {
		dosya_ac(handle);
		detay_oku(handle, kayit_adresi, DATA_ALMA);
		memcpy(handle->ana_detay->data, dataci, baslik.data_uzunlugu);
		indeks_uzunlugu(handle, handle->indeks_detay->data);
		eski_kayit(handle, kayit_adresi);
		dosya_kapa(handle);
		mesaj_goster_kac(" Kayt de§iŸtirildi.");
	}
SON:
}

void acilis_kayit_sil(DOSYA *handle)
{
	if (aidat_kontrol(handle) == 0) {
		if (msj_kutu(NULL, SORU_KAYDI_SILMEK, SORU) == EVET) {
			dosya_ac(handle);
			data_sil(handle, kayit_adresi);
			dosya_kapa(handle);
			mesaj_goster_kac(" Kayt Silindi...");
			shiftf4(Form_ACILIS);
		}
	}
}

void acilis_listesi(DOSYA *handle)
{
	char *bellek;
	long eski_kayit_adresi = kayit_adresi;

	bellek = ekran_giris();
	git_xy(0, 0);
	formyukle(7, 32, "bin/muklist.frm");
	dosya_ac(handle);
	kayit_adresi = liste_kutusu(10, 36, 0, 10, 37, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, handle);
	ekran_cikis(bellek);
	if (kayit_adresi == -2) {
		msj_kutu(NULL, UYARI_LISTE_BOS, UYARI);
		kayit_adresi = eski_kayit_adresi;
	}
	else if (kayit_adresi == -1)
		kayit_adresi = eski_kayit_adresi;
	else {
		kayit_adresi = indeks_gezgini(handle, kayit_adresi);
		detay_oku(handle, kayit_adresi, DATA_AL);
		memcpy(dataci, handle->ana_detay->data, handle->ana_baslik->bir_datanin_uzunlugu);
		uyari_gonder(2);
		indeks_bilgisi(tablo, &baslik, INDEKS_KAPA);
	}
	acilis_goruntusu();
	dosya_kapa(handle);
}