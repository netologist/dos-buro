#include "/ozgan/programs/h/genel.h"

void firmalar(void)
{
	DOSYA handle;
	char *bellek;
	long mukellef_kaydi;

	strcpy(handle.ana_dosya, "mukellef.dat");
	strcpy(handle.indeks_dosya, "mukellef.ind");
	strcpy(handle.yol, "data/");

	git_xy(0, 0);
	bellek = ekran_giris();
	if (kayit_adresi == 0) {
		formyukle(7, 32, "bin/muklist.frm");
		dosya_ac(&handle);
		mukellef_kaydi = liste_kutusu(10, 36, 0, 10, 37, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
		ekran_cikis(bellek);
		if (mukellef_kaydi == -2) {
			dosya_kapa(&handle);
			msj_kutu(NULL, UYARI_LISTE_BOS, UYARI);
		}
		else if (mukellef_kaydi >= 0) {
			detay_oku(&handle, indeks_gezgini(&handle, mukellef_kaydi), DATA_AL);
			para_data = (PARA_KUTU *) dataci;
			acilis_data = (ACILIS_DATA *) handle.ana_detay->data;
			strcpy(para_data->Unvan, acilis_data->Unvan_Ad);
			strcpy(para_data->Hareket_Turu, acilis_data->Hareket_Turu);
			if (para_data->Odeme_Turu[0] == '0') {
				memset(para_data->Tutar, 0, sizeof(para_data->Tutar));
				strcpy(para_data->Tutar, acilis_data->Resmi_Aylik);
			}
			para_data->Mukellef_Adresi = indeks_gezgini(&handle, mukellef_kaydi);
			dosya_kapa(&handle);
		}
		kasa_goruntusu();
		goto SON;
	 }
	 else
		msj_kutu(NULL, "Kayçt ettißiniz firmayç deßiütiremezsiniz", UYARI);
	ekran_cikis(bellek);
SON:
}

void kasa_goruntusu(void)
{
	DOSYA handle;
	KASA_DURUMU veri;
	FILE *fp;
	char birlesen[100];

	strcpy(handle.ana_dosya, "kasadurm.dat");
	strcpy(handle.indeks_dosya, "kasadurm.ind");
	strcpy(handle.yol, "data/");

	para_data = (PARA_KUTU *) dataci;
	handle.tablo = (TABLO_FORM *) tabloyukle("bin/kasadurm.tbl", &handle.baslik);

	yol_yapici(handle.yol, handle.ana_dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb", SH_DENYNO)) == NULL) {
		msj_kutu(handle.ana_dosya, HATA_DOSYA_BULUNAMADI, HATA);
		exit(1);
	}
	fseek(fp, 0, SEEK_SET);
	fread(&veri, 1, sizeof(KASA_DURUMU), fp);
	fclose(fp);

	sayi_temizle(para_data->Tutar, 14);
	if (para_data->Tutar[0] == '0')
		memset(para_data->Tutar, 0, 14);

	if (kayit_adresi == 0)
		kayit_no_al();

	tablo_yerlestir(2, 15, Data_ParaKutusu_Genel, (char *) para_data, tablo, &baslik);
	tablo_yerlestir(2, 15, Data_ParaKutusu_KasaDurumu, (char *) &veri, handle.tablo, &handle.baslik);
}

void kasa_durumu(void)
{
	DOSYA handle;
	KASA_DURUMU veri;
	char sonuc[25], birlesen[100];
	FILE *fp;
	int ay;

	strcpy(handle.ana_dosya, "kasadurm.dat");
	strcpy(handle.indeks_dosya, "kasadurm.ind");
	strcpy(handle.yol, "data/");

	yol_yapici(handle.yol, handle.ana_dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb+", SH_DENYNO)) == NULL) {
		msj_kutu(handle.ana_dosya, HATA_DOSYA_BULUNAMADI, HATA);
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
					  cikarma(veri.Lira, para_data->Tutar, sonuc);
				  strcpy(veri.Lira, sonuc); break;
		case '1': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Dolar, sonuc);
				  else
					  cikarma(veri.Dolar, para_data->Tutar, sonuc);
				  strcpy(veri.Dolar, sonuc); break;
		case '2': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Mark, sonuc);
				  else
					  cikarma(veri.Mark, para_data->Tutar, sonuc);
				  strcpy(veri.Mark, sonuc); break;
		case '3':
		case '4': if (para_data->Odeme_Turu[0] != '2')
					  toplama(para_data->Tutar, veri.Cek, sonuc);
				  else
					  cikarma(veri.Cek, para_data->Tutar, sonuc);

				  strcpy(veri.Cek, sonuc);
				  veri.Tablo[ay * 2] = 1;
				  break;
	}
	fseek(fp, 0, SEEK_SET);
	fwrite(&veri, 1, sizeof(KASA_DURUMU), fp);
	fclose(fp);
}

void cek_tablosu(int ay, int durum)
{
	FILE *fp;
	DOSYA handle;
	KASA_DURUMU veri;
	char birlesen[100];

	strcpy(handle.ana_dosya, "kasadurm.dat");
	strcpy(handle.indeks_dosya, "kasadurm.ind");
	strcpy(handle.yol, "data/");

	yol_yapici(handle.yol, handle.ana_dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb+", SH_DENYNO)) == NULL) {
		msj_kutu(handle.ana_dosya, HATA_DOSYA_BULUNAMADI, HATA);
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	fread(&veri, 1, sizeof(KASA_DURUMU), fp);

	if (durum == EKLE)
		veri.Tablo[ay * 2] = 1;
	else
		veri.Tablo[ay * 2] = 0;

	fseek(fp, 0, SEEK_SET);
	fwrite(&veri, 1, sizeof(KASA_DURUMU), fp);

	fclose(fp);
}

void odeme_secenegi_kontrol(void)
{
	char *bellek;

	bellek = ekran_giris();

	if (para_data->Odeme_Secenegi[0] == '1' || para_data->Odeme_Secenegi[0] == '2') {
		formgolge(9, 32, "bin/kurlar.frm");
		formyukle(9, 32, "bin/kurlar.frm");
		sayi_yaz(para_data->Kur, 12, 47, 9, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI);
	}
	carpma(para_data->Tutar, para_data->Kur, para_data->Kur_Cevirisi);
	ekran_cikis(bellek);
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
		msj_kutu(NULL, "Aidat sadece mÅkellefte kullançlabilir", UYARI);
		return 1;
	}
	else if (para_data->Mukellef_Adresi == 0) {
		msj_kutu(NULL, "Firma seámek zorundasçnçz !", UYARI);
		return 1;
	}
	else if (strlen(para_data->Kayit_Tarihi) == 0) {
		msj_kutu(NULL, "Kayçt tarihini girmek zorundasçnçz !", UYARI);
		return 1;
	}
	else if (strlen(para_data->Tutar) == 0) {
		msj_kutu(NULL, "Para girmezseniz kayçt edemezsiniz !", UYARI);
		return 1;
	}
	else if (para_data->Odeme_Turu[0] == '0' && (para_data->Odeme_Secenegi[0] == '1' || para_data->Odeme_Secenegi[0] == '2')) {
		msj_kutu(NULL, "Aidatta, Dolar ve Mark giremezsiniz !", UYARI);
		return 1;
	}
	else if (para_data->Odeme_Secenegi[0] >= '3' && strlen(para_data->Vadesi) == 0) {
		msj_kutu(NULL, "Vade tarihini girmek zorundasçnçz !", UYARI);
		return 1;
	}
	else if (aidat_tablosu(EKLE) != 0)
		return 1;

	odeme_secenegi_kontrol();
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

void bakiye_eski_haline(void)
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
		cikarma(mukellef_data->Bakiye_Alacak, tasiyici, sonuc);
		strcpy(mukellef_data->Bakiye_Alacak, sonuc);
	}
	else {
		cikarma(mukellef_data->Bakiye_Borc, tasiyici, sonuc);
		strcpy(mukellef_data->Bakiye_Borc, sonuc);
	}
	eski_kayit(&mukellef, para_data->Mukellef_Adresi);
	dosya_kapa(&mukellef);
}

void parakutu_form_ayari(int durum)
{
	if (durum == DEGISIKLIK) {
		tablo[0].islem_sirasi = YOK;
		tablo[1].islem_sirasi = YOK;
		tablo[3].islem_sirasi = YOK;
		tablo[6].islem_sirasi = YOK;
		kmenu_islem(para_data->Odeme_Secenegi, tablo, &baslik, 6);
		tablo[10].islem_sirasi = YOK;
		uyari_gonder(5);
	}
	else {
		tablo[0].islem_sirasi = SONRA;
		tablo[1].islem_sirasi = SONRA;
		tablo[3].islem_sirasi = SONRA;
		tablo[6].islem_sirasi = SONRA;
		kmenu_islem(para_data->Odeme_Secenegi, tablo, &baslik, 6);
		uyari_gonder(0);
	}
}

void kasa_eski_haline(void)
{
	DOSYA handle;
	KASA_DURUMU veri;
	char sonuc[25], birlesen[100];
	FILE *fp;

	strcpy(handle.ana_dosya, "kasadurm.dat");
	strcpy(handle.indeks_dosya, "kasadurm.ind");
	strcpy(handle.yol, "data/");

	yol_yapici(handle.yol, handle.ana_dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb+", SH_DENYNO)) == NULL) {
		msj_kutu(handle.ana_dosya, HATA_DOSYA_BULUNAMADI, HATA);
		exit(1);
	}

	fseek(fp, 0, SEEK_SET);
	fread(&veri, 1, sizeof(KASA_DURUMU), fp);

	switch (para_data->Odeme_Secenegi[0]) {
		case '0': if (para_data->Odeme_Turu[0] != '2')
					  cikarma(veri.Lira, para_data->Tutar, sonuc);
				  else
					  toplama(para_data->Tutar, veri.Lira, sonuc);
				  strcpy(veri.Lira, sonuc); break;
		case '1': if (para_data->Odeme_Turu[0] != '2')
					  cikarma(veri.Dolar, para_data->Tutar, sonuc);
				  else
					  toplama(para_data->Tutar, veri.Dolar, sonuc);
				  strcpy(veri.Dolar, sonuc); break;
		case '2': if (para_data->Odeme_Turu[0] != '2')
					  cikarma(veri.Mark, para_data->Tutar, sonuc);
				  else
					  toplama(para_data->Tutar, veri.Mark, sonuc);
				  strcpy(veri.Mark, sonuc); break;
		case '3':
		case '4': if (para_data->Odeme_Turu[0] != '2')
					  cikarma(veri.Cek, para_data->Tutar, sonuc);
				  else
					  toplama(para_data->Tutar, veri.Cek, sonuc);
				  strcpy(veri.Cek, sonuc); break;
	}
	fseek(fp, 0, SEEK_SET);
	fwrite(&veri, 1, sizeof(KASA_DURUMU), fp);
	fclose(fp);
}

void para_ilk_kayit(void)
{
	DOSYA handle;
	int cek_hatasi = 1;

	handle.tablo = tablo;
	handle.baslik = baslik;

	strcpy(handle.ana_dosya, "hareket.dat");
	strcpy(handle.indeks_dosya, "hareket.ind");
	strcpy(handle.yol, "data/");
	para_data = (PARA_KUTU *) dataci;

	// kçsçtlç kullançm ayarç
	dosya_ac(&handle);
	if (handle.ana_baslik->toplam_kayit > 9) {
		msj_kutu(NULL, "DEMO VERSòYON-10 KAYITTAN FAZLA GòRòLEMEZ", HATA);
		dosya_kapa(&handle);
		goto SON;
	}
	dosya_kapa(&handle);

	if (genel_kontrol() == 0) {
		handle.data = (char *) dataci;
		kayit_adresi = dosya_kayit(&handle);
		if (kayit_adresi == 0)
			msj_kutu(NULL, UYARI_KAYIT_MEVCUT, UYARI);
		else {
			dosya_ac(&handle);
			if (para_data->Odeme_Secenegi[0] >= '3') {
				detay_oku(&handle, kayit_adresi, DATA_AL);
				para_data = (PARA_KUTU *) handle.ana_detay->data;
				cek_hatasi = cek_ilk_kayit();
				eski_kayit(&handle, kayit_adresi);
			}
			if (cek_hatasi != 0) {
				bakiye_gir();
				kasa_durumu();
			}
			else
				data_sil(&handle, kayit_adresi);

			dosya_kapa(&handle);
			parakutu_form_ayari(DEGISIKLIK);
			mesaj_goster_kac(" Kayçt tamamlandç !");
		}
	}
SON:
}

void para_kayit_degistir(void)
{
	char eski_tutar[15];
	DOSYA handle;

	handle.tablo = tablo;
	handle.baslik = baslik;
	strcpy(handle.ana_dosya, "hareket.dat");
	strcpy(handle.indeks_dosya, "hareket.ind");
	strcpy(handle.yol, "data/");

	if (genel_kontrol() == 0) {
		dosya_ac(&handle);
		detay_oku(&handle, kayit_adresi, DATA_AL);
		para_data = (PARA_KUTU *) handle.ana_detay->data;
		bakiye_eski_haline();
		kasa_eski_haline();
		para_data = (PARA_KUTU *) dataci;
		handle.data = (char *) dataci;
		bakiye_gir();
		kasa_durumu();
		if (para_data->Odeme_Secenegi[0] >= '3')
			cek_kayit_degistir(para_data->Cek_Adresi);
		memcpy(handle.ana_detay->data, dataci, handle.ana_baslik->bir_datanin_uzunlugu);
		eski_kayit(&handle, kayit_adresi);
		dosya_kapa(&handle);
		mesaj_goster_kac(" Kayçt deßiütirildi !");
	}
}

void para_kayit_sil(void)
{
	DOSYA handle;

	handle.tablo = tablo;
	handle.baslik = baslik;
	strcpy(handle.ana_dosya, "hareket.dat");
	strcpy(handle.indeks_dosya, "hareket.ind");
	strcpy(handle.yol, "data/");

	dosya_ac(&handle);
	detay_oku(&handle, kayit_adresi, DATA_AL);
	para_data = (PARA_KUTU *) handle.ana_detay->data;
	bakiye_eski_haline();
	if (para_data->Odeme_Secenegi[0] >= '3')
		cek_kayit_sil(para_data->Cek_Adresi);
	kasa_eski_haline();
	aidat_tablosu(CIKAR);
	data_sil(&handle, kayit_adresi);
	dosya_kapa(&handle);
	mesaj_goster_kac(" Kayçt silindi... ");
	shiftf4(Form_PARA_KUTUSU);
}

int aidat_tablosu(int Durum)
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
			msj_kutu(NULL, "Bu aidat daha once girilmiü ...", UYARI);
			return 1;
		}
		if (Durum == EKLE)
			mukellef_data->Tablo[ay * 2] = 1;
		else
			mukellef_data->Tablo[ay * 2] = 0;
		eski_kayit(&mukellef, para_data->Mukellef_Adresi);
		dosya_kapa(&mukellef);
	}
	return 0;
}

char *para_liste_elemani(int satir, int kolon, char *string, DOSYA *handle, int baslangic, int uzunluk, int boy, int renk)
{
	int sayac, kontrol = handle->indeks_baslik->indeks_data_uzunlugu,
		boy_sayaci = 0, sayac2;
	long adres;
	char birlesen[100];
	PARA_KUTU *para_kutu;

	if (uzunluk < kontrol)
		kontrol = uzunluk;

	adres = indeks_gezgini(handle, baslangic);
	for (boy_sayaci = 0; boy_sayaci < boy; boy_sayaci++) {
		detay_oku(handle, adres, DATA_AL);
		adres = handle->indeks_detay->sonraki;
		para_kutu = (PARA_KUTU *) handle->ana_detay->data;
		memcpy(&string[(boy_sayaci * kontrol)+1], handle->indeks_detay->data, kontrol);
		memset(birlesen, 0, 100);
		formatla(&string[(boy_sayaci * kontrol)+16], birlesen, "##/##/####");
		strcpy(&string[(boy_sayaci * kontrol)+16], birlesen);
		string[(kontrol * boy_sayaci) + 0] = ' ';
		for (sayac = 0; sayac < kontrol; sayac++) {
			if (string[(boy_sayaci * kontrol) + sayac] == '\0')
				string[(kontrol * boy_sayaci) + sayac] = ' ';
		}
		string[(kontrol * boy_sayaci) + sayac-1] = '\0';
		switch (para_kutu->Odeme_Secenegi[0]) {
			case '0': strncpy(&string[(kontrol * boy_sayaci) + 10], "Lira ", 4); break;
			case '1': strncpy(&string[(kontrol * boy_sayaci) + 10], "Dolar", 5); break;
			case '2': strncpy(&string[(kontrol * boy_sayaci) + 10], "Mark ", 4); break;
			case '3': strncpy(&string[(kontrol * boy_sayaci) + 10], "Äek  ", 4); break;
			case '4': strncpy(&string[(kontrol * boy_sayaci) + 10], "Senet", 5); break;
		}
	}
	if (string[(kontrol * boy_sayaci) + sayac-2] != ' ')
		strcpy(&string[(kontrol * boy_sayaci) + sayac-5], "... ");
	harfler(satir + boy_sayaci, kolon, &string[(kontrol * boy_sayaci)], renk);
	return string;
}

long para_liste_kutusu(int satir, int kolon, int baslangic, int boy, int en, int renk1, int renk2, DOSYA *handle)
{
	char *eleman;

	int sayac = 0, toplam = handle->indeks_baslik->toplam_kayit, isaretli_sayac = 0,
		ch = 0, bayrak = 0, yeni_baslangic = 0;
	long adres = 0;

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

	para_liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
	for (;;) {
		if (yeni_baslangic != baslangic) {
			yeni_baslangic = baslangic;
			para_liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
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
							mesaj_goster_kac(" Dosya Baüç ...");
						}
						else if (bayrak == 1) {
							baslangic = 0;
							isaretli_sayac = 0;
							mesaj_goster_kac(" Dosya Baüç ...");
						}
						break;
			case KP_ENTER:
			case ENTER: if (baslik.referans == Form_IS_TAKIBI+1 && baslik.kontrol == 1) {
							adres = indeks_gezgini(handle, isaretli_sayac + baslangic);
							detay_oku(handle, adres, DATA_AL);
							memcpy(dataci, handle->ana_detay->data, baslik.data_uzunlugu);
							if (strcmp(&dataci[74], "HAYIR   ") == 0) {
								strcpy(&dataci[74], "EVET    ");
								strcpy(&eleman[(en * isaretli_sayac) + 46], "EVET    ");
							}
							else {
								strcpy(&dataci[74], "HAYIR   ");
								strcpy(&eleman[(en * isaretli_sayac) + 46], "HAYIR   ");
							}
							memcpy(handle->ana_detay->data, dataci, baslik.data_uzunlugu);
							indeks_uzunlugu(handle, handle->indeks_detay->data);
							eski_kayit(handle, adres);
						}
						else {
							free(eleman);
							return (long) isaretli_sayac + baslangic;
						}
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
			mesaj_goster_kac(" Dosya Baüç ...");
		}
	}
}

int kactane_var(DOSYA *handle, long mukellef_adresi)
{
	int sayac, n = 0;
	FILE *indeks, *ana;
	char birlesen[100];
	PARA_KUTU *para_kutu;

	indeks = indeks_dosya_ac(indeks, handle, birlesen, "rb");
	ana = ana_dosya_ac(ana, handle, birlesen, "rb");

	for (sayac = 0; sayac < handle->ana_baslik->toplam_kayit; sayac++) {
		/******* INDEKS DOSYA DETAY BòLGòSò OKUNUYOR *******/
		fseek(indeks, indeks_gezgini(handle, sayac), SEEK_SET);
		fread(handle->indeks_detay, 1, sizeof(INDEKS_DETAY)-sizeof(char *), indeks);
		fread(handle->indeks_detay->data, 1, handle->indeks_baslik->indeks_data_uzunlugu, indeks);
		/*----------------AÄIKLAMA SONU-------------------*/
		/******* ANA DOSYA DETAY BòLGòSò OKUNUYOR *******/
		fseek(ana, handle->indeks_detay->ana_dosya_adresi, SEEK_SET);
		fread(handle->ana_detay, 1, sizeof(ANA_DETAY)-sizeof(char *), ana);
		fread(handle->ana_detay->data, 1, handle->ana_baslik->bir_datanin_uzunlugu, ana);
		/*---------------AÄIKLAMA SONU------------------*/
		para_kutu = (PARA_KUTU *) handle->ana_detay->data;
		if (para_kutu->Mukellef_Adresi == mukellef_adresi)
			n++;
	}
	data_dosyasini_kapa(ana);
	data_dosyasini_kapa(indeks);
	return n;
}

void hareket_listesi(DOSYA *handle)
{
	char *bellek;
	long eski_kayit_adresi = kayit_adresi;

	bellek = ekran_giris();
	git_xy(0, 0);
	formyukle(6, 20, "bin/hareket.frm");
	dosya_ac(handle);
	kayit_adresi = para_liste_kutusu(9, 24, 0, 10, 49, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, handle);
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
		parakutu_form_ayari(DEGISIKLIK);
	}
	kasa_goruntusu();
	dosya_kapa(handle);
}