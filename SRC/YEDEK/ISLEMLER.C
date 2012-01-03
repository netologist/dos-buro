#include "/ozgan/programs/h/genel.h"
/*
	TABLO_FORM tablo2[] = { {Data_ParaKutusu_Genel, KAPALI_MENU, 3, 17, 9 , BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ISLEM_TURU, SONRA},
							{Data_ParaKutusu_Genel, KAPALI_MENU, 3, 46, 11, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ACILIS, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 5, 20, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, TARIH, 5, 49, 10, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 6, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 7, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, KAPALI_MENU, 8, 21, 8, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ODEME_TURU, SONRA},
							{Data_ParaKutusu_Genel, SAYI, 8, 44, 15, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 9, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 10, 20, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, TARIH, 10, 43, 10, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 11, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 12, 11, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 33, 12, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 53, 6, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_CekDetayi, KAPALI_MENU, 3, 38, 9, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_AYLAR, SONRA}
						  };

{{Data_Acilis_Bilgisi, YAZI, 4, 20, 12, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							{Data_Acilis_Bilgisi, KAPALI_MENU, 4, 44, 12, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ACILIS, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 5, 20, 38, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 6, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 7, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 7, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 8, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 8, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 9, 20, 38, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 10, 6, 52, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 11, 15, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 11, 41, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 12, 15, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, YAZI, 12, 41, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, SAYI, 13, 18, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bilgisi, SAYI, 13, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Yetkili, YAZI, 3, 17, 31, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Yetkili, YAZI, 4, 17, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Yetkili, YAZI, 4, 41, 5, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Yetkili, YAZI, 5, 17, 31, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Yetkili, YAZI, 6, 17, 31, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Devir, SAYI, 3, 12, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Devir, SAYI, 4, 12, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bakiye, SAYI, 16, 45, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Bakiye, SAYI, 17, 45, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 22, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 27, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 32, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 37, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 42, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 18, 47, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 22, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 27, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 32, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 37, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 42, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_Acilis_Tablo, KARE_KUTU, 19, 47, 1, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
						 };*/

void f2_tusu(int referans)
{
	DOSYA handle;
	char *bellek;
	long mukellef_kaydi;

	if (pencere.derecesi > UST_DUZEY + 1) // Bîylece pencere bir kez aáçlçr.
		goto SON;

	bellek = (char *)ekran_giris();
	switch (referans) {
		case Form_ACILIS: formgolge(7, 20, "bin/yetkili.frm");
						  formyukle(7, 20, "bin/yetkili.frm");
						  tablo_oynatici(7, 20, Data_Acilis_Yetkili, dataci, tablo, &baslik);
						  ekran_cikis(bellek);
						  acilis_goruntusu();
						  goto SON;
		case Form_PARA_KUTUSU:
			if (kayit_adresi == 0) {
				strcpy(handle.ana_dosya, "mukellef.dat");
				strcpy(handle.indeks_dosya, "mukellef.ind");
				strcpy(handle.yol, "data/");
				formyukle(7, 32, "bin/muklist.frm");
				dosya_ac(&handle);
				mukellef_kaydi = liste_kutusu(10, 36, 0, 10, 37, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
				if (mukellef_kaydi == -2) {
					dosya_kapa(&handle);
					ekran_cikis(bellek);
					msj_kutu(NULL, UYARI_LISTE_BOS, UYARI);
					goto SON;
				}
				else if (mukellef_kaydi >= 0) {
					detay_oku(&handle, indeks_gezgini(&handle, mukellef_kaydi), DATA_AL);
					para_data = (PARA_KUTU *) dataci;
					acilis_data = (ACILIS_DATA *) handle.ana_detay->data;
					strcpy(para_data->Unvan, acilis_data->Unvan_Ad);
					strcpy(para_data->Hareket_Turu, acilis_data->Hareket_Turu);
					para_data->Mukellef_Adresi = indeks_gezgini(&handle, mukellef_kaydi);
				}
				dosya_kapa(&handle);
				ekran_cikis(bellek);
				kasa_goruntusu();
				goto SON;
			}
		else
			msj_kutu(NULL, "Kayçt ettißiniz firmayç deßiütiremezsiniz", UYARI);
	}
	ekran_cikis(bellek);
SON: // PROGRAM SONU
}

void f3_tusu(int referans)
{
	char *bellek;

	if (pencere.derecesi == UST_DUZEY + 2) // Bîylece pencere bir kez aáçlçr.
		goto SON;

	bellek = (char *)ekran_giris();
	switch (referans) {
		case Form_ACILIS : formgolge(8, 33, "bin/devir.frm");
						   formyukle(8, 33, "bin/devir.frm");
						   tablo_oynatici(8, 33, Data_Acilis_Devir, dataci, tablo, &baslik);
						   ekran_cikis(bellek);
						   acilis_goruntusu();
						   goto SON;
	}
	ekran_cikis(bellek);
SON: // PROGRAM SONU
}

void f4_tusu(int referans)
{
	switch (referans) {
		case Data_Acilis_Yetkili :
		case Data_Acilis_Devir :  ;
	}
}

void f5_tusu(int referans)
{
	char *bellek;

	if (pencere.derecesi >= UST_DUZEY + 2) // Bîylece pencere bir kez aáçlçr.
		goto SON;

	bellek = (char *)ekran_giris();
	switch (referans) {
		case Form_PARA_KUTUSU:
			formgolge(6, 20, "bin/cekdetay.frm");
			formyukle(6, 20, "bin/cekdetay.frm");
			tablo_oynatici(6, 20, Data_ParaKutusu_CekDetayi, dataci, tablo, &baslik); break;
	}
	ekran_cikis(bellek);
SON: // PROGRAM SONU
}

void f6_tusu(int referans)
{
	switch (referans) {
		case Data_Acilis_Yetkili :
		case Data_Acilis_Devir : ;

	}
}

int dosya_varmi(DOSYA *handle)
{
	char birlesen[100];
	int dosya_kontrol;

	yol_yapici(handle->yol, handle->indeks_dosya, birlesen);
	dosya_kontrol = access(birlesen, 0);

	if (dosya_kontrol != 0)
		return msj_kutu(handle->ana_dosya, SORU_DOSYA_YARATMAK, SORU);

	return -1;
}

void shiftf2(int referans)
{
	DOSYA handle;
	int i;
	long adres = 0;
	char *bellek;

	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = dataci;

	switch (referans) {
		case Form_ACILIS:
			strcpy(handle.ana_dosya, "mukellef.dat");
			strcpy(handle.indeks_dosya, "mukellef.ind");
			strcpy(handle.yol, "data/");
			i = dosya_varmi(&handle);
			if (i == EVET)
				dosya_yarat(&handle);
			else if (i != HAYIR) {
				if (kayit_adresi == 0) {
					kayit_adresi = dosya_kayit(&handle);
					if (kayit_adresi == 0)
						msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);
					else {
						mesaj_goster_kac(" Kayçt tamamlandç !");
						indeks_bilgisi(tablo, &baslik, INDEKS_KAPA);
					}
				}
				else {
					dosya_ac(&handle);
					detay_oku(&handle, kayit_adresi, DATA_ALMA);
					memcpy(handle.ana_detay->data, dataci, baslik.data_uzunlugu);
					indeks_uzunlugu(&handle, handle.indeks_detay->data);
					eski_kayit(&handle, kayit_adresi);
					dosya_kapa(&handle);
					mesaj_goster_kac(" Kayçt deßiütirildi.");
				}
			}
			break;

		case Form_IS_TAKIBI:
/*		clrscr();
			for (i = 0; i < baslik.eleman_sayisi; i++)
				printf("%d\n", tablo[i].uzunluk + 1);
			exit(1);*/
			bellek = ekran_giris();
			adres = takip_dosya_kontrol();
			if (adres == 0) {
				dosya_yapisi_doldur(&handle, "DATA/");
				dosya_yarat(&handle);
				kayit_gir(&handle);
				mesaj_goster_kac(" Kayçt tamamlandç ...");
				baslik.kontrol = 1;
				adres = liste_kutusu(8, 20, 0, 13, 55, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
				baslik.kontrol = 0;
			}
			else if (adres == 2)
				msj_kutu(NULL, "ûu anda data yaratçlçyor", UYARI);
			else
				msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);//*/
			 ekran_cikis(bellek);
			 break;

		case Form_PARA_KUTUSU:
			bellek = ekran_giris();
			strcpy(handle.ana_dosya, "hareket.dat");
			strcpy(handle.indeks_dosya, "hareket.ind");
			strcpy(handle.yol, "data/");
			i = dosya_varmi(&handle);
			if (i == EVET) {
				dosya_yarat(&handle);
				ekran_cikis(bellek);
			}
			else if (i != HAYIR) {
				para_kaydi_gir();
				ekran_cikis(bellek);
				kasa_goruntusu();
			}
			break;
	}
}

int aidat_kontrol(DOSYA *handle)
{
	int i;
	ACILIS_DATA *mukellef_data;

	mukellef_data = (ACILIS_DATA *) handle->data;

	for (i = 0; i < 12; i++)
		if (mukellef_data->Tablo[i * 2] == 1) {
			msj_kutu(NULL, "ônce hareketleri silmelisiniz !..", UYARI);
			return 1;
		}
	return 0;
}

void shiftf3(int referans)
{
	DOSYA handle;
	long adres = 0;

	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = dataci;

	switch (referans) {
		case Form_ACILIS:
			if (kayit_adresi != 0) {
				strcpy(handle.ana_dosya, "mukellef.dat");
				strcpy(handle.indeks_dosya, "mukellef.ind");
				strcpy(handle.yol, "data/");
				if (aidat_kontrol(&handle) == 0) {
					if (msj_kutu(NULL, SORU_KAYDI_SILMEK, SORU) == EVET) {
						dosya_ac(&handle);
						data_sil(&handle, kayit_adresi);
						dosya_kapa(&handle);
						mesaj_goster_kac(" Kayçt Silindi...");
						shiftf4(referans);
					}
				}
			}
			else
				mesaj_goster_kac(" Kayçt etmediniz ...");
			break;

		case Form_IS_TAKIBI:
			adres = takip_dosya_kontrol();
			if (adres == 1) {
				dosya_yapisi_doldur(&handle, "DATA/");
				if (msj_kutu(NULL, SORU_KAYDI_SILMEK, SORU) == EVET) {
					if (dosya_sil(&handle) == 0) {
						mesaj_goster_kac(" Kayçt Silindi...");
						shiftf4(referans);
					}
					else
						msj_kutu(NULL, "Dosya Silinemiyor !!!", HATA);
				}
			}
			else if (adres == 2)
				msj_kutu(NULL, "ûu anda data yaratçlçyor", UYARI);
			else
				mesaj_goster_kac(" Kayçt etmediniz ...");
	}
}

void shiftf4(int referans)
{
	switch (referans) {
		case Form_ACILIS:
			kayit_adresi = 0;
			memset(dataci, 0, baslik.data_uzunlugu);
			acilis_goruntusu();
			indeks_bilgisi(tablo, &baslik, INDEKS_AC);
			uyari_gonder(0);
			mesaj_goster_kac(" Y e n i   kayçt ..."); break;

		case Form_IS_TAKIBI:
			memset(dataci, 0, baslik.data_uzunlugu);
			takip_goruntusu();
			uyari_gonder(0);
			mesaj_goster_kac(" Y e n i   kayçt ..."); break;
	}
}

void takip_goruntusu(void)
{
	int i;

	for (i = 0; i < 13; i++)
		doldur(8+i, 20, ' ', 54, BEYAZ_);
	tablo_yerlestir(2, 15, Data_IsTakip_Genel, dataci, tablo, &baslik);
}

void acilis_goruntusu(void)
{
	char sonuc[80];
	int konum;

	memset(sonuc, 0, 80);

	acilis_data = (ACILIS_DATA *) dataci;
	toplama(acilis_data->Devir_Borc, acilis_data->Bakiye_Borc, sonuc);
	konum =	strlen(basamakla(sonuc));
	doldur(18, 60, ' ', 14, BEYAZ_);
	harfler(18, 74-konum, basamakla(sonuc), BEYAZ_ | SIYAH);
	memset(sonuc, 0, 80);
	toplama(acilis_data->Devir_Alacak, acilis_data->Bakiye_Alacak, sonuc);
	konum =	strlen(basamakla(sonuc));
	doldur(19, 60, ' ', 14, BEYAZ_);
	harfler(19, 74-konum, basamakla(sonuc), BEYAZ_ | SIYAH);

	tablo_yerlestir(2, 15, Data_Acilis_Bilgisi, dataci, tablo, &baslik);
	tablo_yerlestir(0, 0, Data_Acilis_Tablo, dataci, tablo, &baslik);
}

void shiftf5(int referans)
{
	DOSYA handle;
	long eski_kayit_adresi = kayit_adresi;
	char *bellek;

	bellek = ekran_giris();
	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = dataci;
	git_xy(0, 0);

	switch (referans) {
		case Form_ACILIS:
			strcpy(handle.ana_dosya, "mukellef.dat");
			strcpy(handle.indeks_dosya, "mukellef.ind");
			strcpy(handle.yol, "data/");
			formyukle(7, 32, "bin/muklist.frm");
			dosya_ac(&handle);
			kayit_adresi = liste_kutusu(10, 36, 0, 10, 37, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
			ekran_cikis(bellek);
			if (kayit_adresi == -2) {
				msj_kutu(NULL, UYARI_LISTE_BOS, UYARI);
				kayit_adresi = eski_kayit_adresi;
			}
			else if (kayit_adresi == -1)
				kayit_adresi = eski_kayit_adresi;
			else {
				kayit_adresi = indeks_gezgini(&handle, kayit_adresi);
				detay_oku(&handle, kayit_adresi, DATA_AL);
				memcpy(dataci, handle.ana_detay->data, handle.ana_baslik->bir_datanin_uzunlugu);
				uyari_gonder(2);
				indeks_bilgisi(tablo, &baslik, INDEKS_KAPA);
				acilis_goruntusu();
//				tablo_yerlestir(2, 15, Data_Acilis_Bilgisi, dataci, tablo, &baslik);
			}
			dosya_kapa(&handle);
			goto SON;
	}
	ekran_cikis(bellek);
SON: // fonksiyon sonu
}

void shiftf7(void)
{
	if (tasiyici_pano == NULL) {
		tasiyici_pano = (char *) malloc(baslik.data_uzunlugu);
		if (tasiyici_pano == NULL) {
			msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
			exit(1);
		}
	}
	memcpy(tasiyici_pano, dataci, baslik.data_uzunlugu);
	mesaj_goster_kac(" Panoya Kopyalandç ");
}

void shiftf8(int referans)
{
	if (tasiyici_pano != NULL && kayit_adresi == 0) {
		memcpy(dataci, tasiyici_pano, baslik.data_uzunlugu);
		mesaj_goster_kac(" Panodan alçndç... ");
		free(tasiyici_pano);
		tasiyici_pano = NULL;
	}
	else if (kayit_adresi != 0)
		mesaj_goster_kac(" Buraya kopyalanamaz");
	else
		mesaj_goster_kac(" ônce kopyalayçn!");

	switch (referans) {
		case Form_ACILIS: if (tasiyici_pano == NULL && kayit_adresi == 0) {
							  acilis_goruntusu();
							  uyari_gonder(0);
						  } break;

	}
}

int islem(void)
{
	int ch;

	tarih();
	ch = getkb();
	switch (ch) {
//		case F1 : formyukle(2, 14, "bin/yardim.frm"); break;
		case F2 : f2_tusu(baslik.referans); break;
		case F3 : f3_tusu(baslik.referans); break;
		case F4 : break;
		case F5 : f5_tusu(baslik.referans); break;
		case F6 : break;
		case F7 : if (pencere.derecesi == UST_DUZEY)
					  cikis();
				  else
					  return ch;
				  break;
		case F8 : arac(); break;
		case F9 : if (pencere.turu == DATA_FORM)
					 datamenu();
				  break;
		case SHIFT_F2: shiftf2(baslik.referans); break;
		case SHIFT_F3: shiftf3(baslik.referans); break;
		case SHIFT_F4: shiftf4(baslik.referans); break;
		case SHIFT_F5: shiftf5(baslik.referans); break;
		case SHIFT_F6:
		case SHIFT_F7: shiftf7(); break;
		case SHIFT_F8: shiftf8(baslik.referans); break;
		case SHIFT_F9: break;
		case UP :
		case KP_UP : if (pencere.derecesi == UST_DUZEY) {
						 seckin--; return ESC;
					 }
					 else
						 return ch;
		case DOWN :
		case KP_DOWN : if (pencere.derecesi == UST_DUZEY) {
						   seckin++; return ESC;
					   }
					   else
						   return ch;
		default : return ch;
	}
	return ch;
}
//  */