#include "/ozgan/programs/h/genel.h"
/************** SADECE L˜STELEME, YEN˜ FORM G™RšNTšSš kald ***************/

void detay_dosyasi_yarat(void)
{
	DOSYA handle;
	TABLO_BILGI baslikci = {6, 59, Form_PARA_KUTUSU, 0};
	TABLO_FORM tablocu[] = { {Data_ParaKutusu_Genel, YAZI, 6, 21, 9, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 4, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 8, 5, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 14, 19, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 35, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 21, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA}
						   };
	handle.baslik = baslikci;
	handle.tablo = tablocu;
	strcpy(handle.ana_dosya, "pk_cd_01.dat");
	strcpy(handle.indeks_dosya, "pk_cd_01.ind");
	strcpy(handle.yol, "data/");

	dosya_yarat(&handle);
//	tabloyarat("bin/cekdetay.tbl", &baslikci, tablocu);
}

void detay_yapisi_doldur(DOSYA *handle)
{
	char depo[5];

	para_data = (PARA_KUTU *) dataci;
	memset(depo, 0, 5);
	strcpy(handle->ana_dosya, "pk_cd_00.dat");
	strcpy(handle->indeks_dosya, "pk_cd_00.ind");

	strncpy(depo, &para_data->Vadesi[2], 2);
	strncpy(&handle->ana_dosya[6], depo, 2);
	strncpy(&handle->indeks_dosya[6], depo, 2);
}

void detay_liste_yapisi(DOSYA *handle)
{
	char depo[5];
	int ch;

	para_data = (PARA_KUTU *) dataci;

	memset(depo, 0, 5);
	strcpy(handle->ana_dosya, "pk_cd_00.dat");
	strcpy(handle->indeks_dosya, "pk_cd_00.ind");

	ch = atoi(para_data->Vade_Ayi);
	ch++;
	itoa(ch, depo, 10);

	if (strlen(depo) != 1) {
		strncpy(&handle->ana_dosya[6], depo, 2);
		strncpy(&handle->indeks_dosya[6], depo, 2);
	}
	else {
		strncpy(&handle->ana_dosya[7], depo, 1);
		strncpy(&handle->indeks_dosya[7], depo, 1);
	}
}

void cek_detay_kontrol(void)
{
	FILE *fp;
	char birlesen[100];
	DOSYA handle;

	detay_yapisi_doldur(&handle);
	strcpy(handle.yol, "data/");
	yol_yapici(handle.yol, handle.ana_dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb", SH_DENYNO)) == NULL) {
		msj_kutu(handle.ana_dosya, HATA_DOSYA_BULUNAMADI, HATA);
		exit(1);
	}
	fclose(fp);
}

int cek_ilk_kayit(void)
{
	DOSYA handle;
	CEK_DETAYI veri;

	memset(&veri, 0, sizeof(veri));
	strcpy(veri.Kayit_No, para_data->Kayit_No);

	veri.Gun[0] = ' ';
	strncpy(&veri.Gun[1], para_data->Vadesi, 2);

	if (para_data->Odeme_Turu[0] == '2')
		strcpy(veri.Durum, "€kan");
	else
		strcpy(veri.Durum, "Giren");

	strncpy(veri.Aciklama, para_data->Unvan, 19);
	strcpy(veri.Tutar, para_data->Tutar);
	veri.Para_Kutusu_Adresi = kayit_adresi;
	handle.tablo = tabloyukle("bin/cekdetay.tbl", &handle.baslik);
	detay_yapisi_doldur(&handle);
	strcpy(handle.yol, "data/");
	handle.data = (char *) &veri;
	para_data->Cek_Adresi = dosya_kayit(&handle);
	if (para_data->Cek_Adresi == 0) {
		msj_kutu(NULL, "Bilinmeyen dosya hatas", UYARI);
		return 0;
	}
	return 1;
}

void cek_kayit_sil(long Cek_Yeri)
{
	DOSYA handle;
	int ay;
	char depo[5];

	para_data = (PARA_KUTU *) dataci;

	handle.tablo = tabloyukle("bin/cekdetay.tbl", &handle.baslik);
	detay_yapisi_doldur(&handle);
	strcpy(handle.yol, "data/");

	dosya_ac(&handle);
	memset(depo, 0, 5);
	strncpy(depo, &para_data->Vadesi[2], 2);
	ay = atoi(depo) - 1;
	data_sil(&handle, Cek_Yeri);
	if (handle.indeks_baslik->toplam_kayit <= 0)
		cek_tablosu(ay, CIKAR);
	dosya_kapa(&handle);
}

void cek_kayit_degistir(long Cek_Yeri)
{
	DOSYA handle;
	CEK_DETAYI *ana, *indeks;

	handle.tablo = tabloyukle("bin/cekdetay.tbl", &handle.baslik);
	detay_yapisi_doldur(&handle);
	strcpy(handle.yol, "data/");

	dosya_ac(&handle);
	detay_oku(&handle, Cek_Yeri, DATA_AL);
	para_data = (PARA_KUTU *) dataci;
	ana = (CEK_DETAYI *)handle.ana_detay->data;
	memset(ana->Tutar, 0, sizeof(ana->Tutar));
	strcpy(ana->Tutar, para_data->Tutar);
	indeks = (CEK_DETAYI *)handle.indeks_detay->data;
	memset(indeks->Tutar, 0, sizeof(indeks->Tutar));
	strcpy(indeks->Tutar, para_data->Tutar);
	eski_kayit(&handle, Cek_Yeri);
	dosya_kapa(&handle);
}

char *detay_liste_elemani(int satir, int kolon, char *string, DOSYA *handle, int baslangic, int uzunluk, int boy, int renk)
{
	int sayac, kontrol = handle->indeks_baslik->indeks_data_uzunlugu,
		boy_sayaci = 0, konum;
	FILE *indeks, *ana;
	char birlesen[100];

	indeks = indeks_dosya_ac(indeks, handle, birlesen, "rb");
	ana = ana_dosya_ac(ana, handle, birlesen, "rb");

	if (uzunluk < kontrol)
		kontrol = uzunluk;

	for (boy_sayaci = 0; boy_sayaci < boy; boy_sayaci++) {
		/******* INDEKS DOSYA DETAY B˜LG˜S˜ OKUNUYOR *******/
		fseek(indeks, indeks_gezgini(handle, baslangic+boy_sayaci), SEEK_SET);
		fread(handle->indeks_detay, 1, sizeof(INDEKS_DETAY)-sizeof(char *), indeks);
		fread(handle->indeks_detay->data, 1, handle->indeks_baslik->indeks_data_uzunlugu, indeks);
		/*----------------A€IKLAMA SONU-------------------*/
		/******* ANA DOSYA DETAY B˜LG˜S˜ OKUNUYOR *******/
		fseek(ana, handle->indeks_detay->ana_dosya_adresi, SEEK_SET);
		fread(handle->ana_detay, 1, sizeof(ANA_DETAY)-sizeof(char *), ana);
		fread(handle->ana_detay->data, 1, handle->ana_baslik->bir_datanin_uzunlugu, ana);
		/*---------------A€IKLAMA SONU------------------*/
		memcpy(&string[(boy_sayaci * kontrol)+1], &handle->indeks_detay->data[11], kontrol);
		memset(birlesen, 0, 100);
		memcpy(birlesen, &string[(boy_sayaci * kontrol)+30], 14);
		konum = strlen(basamakla(birlesen));
		memset(&string[(boy_sayaci * kontrol)+30], 0, 14);
		strcpy(&string[(boy_sayaci * kontrol)+45 - konum], basamakla(birlesen));
		string[(kontrol * boy_sayaci)] = ' ';
		for (sayac = 1; sayac < kontrol; sayac++) {
			if (string[(boy_sayaci * kontrol) + sayac] == '\0')
				string[(kontrol * boy_sayaci) + sayac] = ' ';
		}
		string[(kontrol * boy_sayaci) + sayac-1] = '\0';
		harfler(satir + boy_sayaci, kolon, &string[kontrol * boy_sayaci], renk);
	}
	data_dosyasini_kapa(ana);
	data_dosyasini_kapa(indeks);
	return string;
}

long detay_liste_kutusu(int satir, int kolon, int baslangic, int boy, int en, int renk1, int renk2, DOSYA *handle)
{
	char *eleman;

	int sayac = 0, toplam = handle->indeks_baslik->toplam_kayit, isaretli_sayac = 0,
		ch = 0, bayrak = 0, yeni_baslangic = 0;

	eleman = (char *) malloc((en+1) * boy * 2);
	if (eleman == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	memset(eleman, 0, (en+1) * boy * 2);

	if (toplam == 0) {
		free(eleman);
		return -2;
	}
	else if (toplam < boy) {
		boy = toplam;
		bayrak = 1;
	}

	detay_liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
	for (;;) {
		if (yeni_baslangic != baslangic) {
			yeni_baslangic = baslangic;
			detay_liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
		}
		for (sayac = 0; sayac < boy; sayac++)
			harfler(satir + sayac, kolon, &eleman[en * sayac], renk1);

		harfler(satir + isaretli_sayac, kolon, &eleman[en * isaretli_sayac], renk2);

		ch = islem();

		switch (ch) {
			case ESC: free(eleman);
					  return -1;
			case DOWN: isaretli_sayac++;
					   if (isaretli_sayac == boy)
						   baslangic++;
					   break;
			case UP: isaretli_sayac--;
					 if (isaretli_sayac == -1)
						 baslangic--;
					 break;
			case PGDN : baslangic += boy - 1;
						if ((baslangic + isaretli_sayac) > (toplam - boy) && bayrak == 0) {
							baslangic = toplam - boy;
							isaretli_sayac = boy;
							mesaj_goster_kac(" Dosya Sonu ...");
						}
						else if ((baslangic + isaretli_sayac) > (toplam - boy) && bayrak == 1) {
							baslangic = 0;
							isaretli_sayac = boy;
							mesaj_goster_kac(" Dosya Sonu ...");
						}
						break;
			case PGUP :	baslangic -= (boy - 1);
						if ((baslangic + isaretli_sayac) <= (toplam % boy)+1 && bayrak == 0) {
							baslangic = 0;
							isaretli_sayac = 0;
							mesaj_goster_kac(" Dosya BaŸ ...");
						}
						else if (bayrak == 1) {
							baslangic = 0;
							isaretli_sayac = 0;
							mesaj_goster_kac(" Dosya BaŸ ...");
						}
						break;
			case KP_ENTER:
			case ENTER: free(eleman);
						return (long) isaretli_sayac + baslangic;
		}
		if (isaretli_sayac == boy)
			isaretli_sayac = boy - 1;

		if (isaretli_sayac == -1)
			isaretli_sayac = 0;

		if (baslangic == toplam - boy + 1&& bayrak == 0) {
			baslangic = toplam - boy;
			mesaj_goster_kac(" Dosya Sonu ...");
		}
		else if (baslangic == toplam - boy + 1 && bayrak == 1) {
			baslangic = 0;
			mesaj_goster_kac(" Dosya Sonu ...");
		}

		if (baslangic == -1) {
			baslangic = 0;
			mesaj_goster_kac(" Dosya BaŸ ...");
		}
	}
}

void detay_listesi(void)
{
	char *bellek;
	DOSYA handle, para_kutu;
	long yer = 0;
	CEK_DETAYI *cek_detayi;

	handle.tablo = tabloyukle("bin/cekdetay.tbl", &handle.baslik);
	detay_liste_yapisi(&handle);
	strcpy(handle.yol, "data/");

	para_kutu.tablo = tablo;
	para_kutu.baslik = baslik;
	para_kutu.data = dataci;
	strcpy(para_kutu.ana_dosya, "hareket.dat");
	strcpy(para_kutu.indeks_dosya, "hareket.ind");
	strcpy(para_kutu.yol, "data/");

	bellek = ekran_giris();
	dosya_ac(&handle);
	yer = detay_liste_kutusu(12, 24, 0, 4, 46, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
	ekran_cikis(bellek);
	if (yer == -2)
		msj_kutu(NULL, UYARI_LISTE_BOS, UYARI);
	else if (yer >= 0) {
		yer = indeks_gezgini(&handle, yer);
		detay_oku(&handle, yer, DATA_AL);
		cek_detayi = (CEK_DETAYI *) handle.indeks_detay->data;
		kayit_adresi = cek_detayi->Para_Kutusu_Adresi;
		dosya_ac(&para_kutu);
		detay_oku(&para_kutu, kayit_adresi, DATA_AL);
		memcpy(dataci, para_kutu.ana_detay->data,
			para_kutu.ana_baslik->bir_datanin_uzunlugu);
		dosya_kapa(&para_kutu);
	}

	dosya_kapa(&handle);
}