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
	char *bellek;

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
			ekran_cikis(bellek);
			firmalar();
			goto SON;
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
			tablo_oynatici(6, 20, Data_ParaKutusu_CekDetayi, dataci, tablo, &baslik);
			ekran_cikis(bellek);
			kasa_goruntusu();
			goto SON;
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
	char *bellek;

	handle.tablo = tablo;
	handle.baslik = baslik;

	switch (referans) {
		case Form_ACILIS:
			handle.data = dataci;
			strcpy(handle.ana_dosya, "mukellef.dat");
			strcpy(handle.indeks_dosya, "mukellef.ind");
			strcpy(handle.yol, "data/");
			i = dosya_varmi(&handle);
			if (i == EVET)
				dosya_yarat(&handle);
			else if (i != HAYIR)
				acilis_kayit(&handle);
			break;

		case Form_IS_TAKIBI:
			bellek = ekran_giris();
			takip_kayit();
			ekran_cikis(bellek); break;

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
				if (kayit_adresi == 0)
					para_ilk_kayit();
				else
					para_kayit_degistir();
				ekran_cikis(bellek);
				kasa_goruntusu();
			}
			break;
	}
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
				acilis_kayit_sil(&handle);
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
			break;

		case Form_PARA_KUTUSU:
			if (kayit_adresi != 0) {
				if (msj_kutu(NULL, SORU_KAYDI_SILMEK, SORU) == EVET)
					para_kayit_sil();
			}
			else
				mesaj_goster_kac(" Kayçt etmediniz ...");
			break;
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

		case Form_PARA_KUTUSU:
			kayit_adresi = 0;
			memset(dataci, 0, baslik.data_uzunlugu);
			kasa_goruntusu();
			parakutu_form_ayari(YENI);
			mesaj_goster_kac(" Y e n i   kayçt ..."); break;
	}
}

void shiftf5(int referans)
{
	DOSYA handle;

	handle.tablo = tablo;
	handle.baslik = baslik;
	handle.data = dataci;
	git_xy(0, 0);

	switch (referans) {
		case Form_ACILIS:
			strcpy(handle.ana_dosya, "mukellef.dat");
			strcpy(handle.indeks_dosya, "mukellef.ind");
			strcpy(handle.yol, "data/");
			acilis_listesi(&handle); break;
		case Form_PARA_KUTUSU:
			strcpy(handle.ana_dosya, "hareket.dat");
			strcpy(handle.indeks_dosya, "hareket.ind");
			strcpy(handle.yol, "data/");
			hareket_listesi(&handle);
	}
}

void shiftf7(void)
{
	if (pencere.turu != DATA_FORM)
		goto SON;
	if (tasiyici_pano == NULL) {
		tasiyici_pano = (char *) malloc(baslik.data_uzunlugu);
		if (tasiyici_pano == NULL) {
			msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
			exit(1);
		}
	}
	memcpy(tasiyici_pano, dataci, baslik.data_uzunlugu);
	mesaj_goster_kac(" Panoya Kopyalandç ");
SON:
}

void shiftf8(int referans)
{
	if (pencere.turu != DATA_FORM)
		goto SON;
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
		case Form_ACILIS:
			if (tasiyici_pano == NULL && kayit_adresi == 0) {
				acilis_goruntusu();
				 uyari_gonder(0);
			} break;
	}
SON:
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
		case SHIFT_F6: break;
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
