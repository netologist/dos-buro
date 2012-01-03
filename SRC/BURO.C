/*-------------------------------------------------------------------------*/
#include "/ozgan/programs/h/genel.h"
/*-------------------------------------------------------------------------*/
/* Global Deßiükenler */
int sifreci = 0; /* Bu global deßiüken sifre menÅsÅ iáindir.          */
int seckin = 0;  /* Ana_Menu fonksiyonundaki, seáili elemanç gîsterir */
PENCERE pencere; /* Pencere Kontrollerini dÅzenler */
char *tasiyici_pano = 0;
char *menu_ayarla = "00000000";
char *dataci; // datalar burada ayarlanir
TABLO_BILGI baslik; // tablolar ve
TABLO_FORM *tablo; //              basliklar burada tutulur
ACILIS_DATA *acilis_data; // ACILIS dosya gîstergesidir
ACILIS_INDEKS *acilis_indeks; // ACILIS dosya gîstergesidir
long kayit_adresi;
TAKIP *takip_data;
PARA_KUTU *para_data;
PARA_INDEKS *para_indeks;


char *ekran_giris(void)
{
	char *bellek;
	bellek = (char *) malloc(3294 + 4);
	if (bellek == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	*(bellek + 3294) = (int) ekran_x;
	*(bellek + 3296) = (int) ekran_y;
	pencere.turu += DUZEY;
	pencere.derecesi += DUZEY;
	baslik.referans +=DUZEY;
	gettext(15, 2, 79, 24, bellek);
	return bellek;
}

void ekran_cikis(char *bellek)
{
	puttext(15, 2, 79, 24, bellek);
	git_xy(*(bellek + 3294), *(bellek + 3296));
	ekran_x = (int) *(bellek + 3294);
	ekran_y = (int) *(bellek + 3296);
	baslik.referans -=DUZEY;
	pencere.derecesi -= DUZEY;
	pencere.turu -= DUZEY;
	if (pencere.derecesi == UST_DUZEY)
		memcpy(&baslik, 0, sizeof(baslik));
	free(bellek);
}

void form_cagir(int referans)
{
	char *bellek;

	TABLO_BILGI baslik2 = {20, 345, Form_PARA_KUTUSU, 0};
	TABLO_FORM tablo2[] = { {Data_ParaKutusu_Genel, KAPALI_MENU, 3, 17, 9 , BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ISLEM_TURU, SONRA},
							{Data_ParaKutusu_Genel, KAPALI_MENU, 3, 46, 11, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ACILIS, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 5, 20, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, YOK},
							{Data_ParaKutusu_Genel, TARIH, 5, 49, 10, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 6, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, YOK},
							{Data_ParaKutusu_Genel, YAZI, 7, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, KAPALI_MENU, 8, 21, 8, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ODEME_TURU, SONRA},
							{Data_ParaKutusu_Genel, SAYI, 8, 45, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_Genel, YAZI, 9, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 10, 20, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, TARIH, 10, 43, 10, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 11, 20, 39, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 12, 11, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 33, 12, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_Genel, YAZI, 12, 53, 6, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, YOK},
							{Data_ParaKutusu_CekDetayi, KAPALI_MENU, 3, 38, 9, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_AYLAR, SONRA},
							{Data_ParaKutusu_KurBilgisi, SAYI, 3, 38, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_KurBilgisi, SAYI, 3, 38, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_IndeksAdres, SAYI, 3, 38, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA},
							{Data_ParaKutusu_IndeksAdres, SAYI, 3, 38, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA}
						  };
	tabloyarat("bin/parakutu.tbl", &baslik2, tablo2);
	bellek = ekran_giris();

	switch (referans) {
		case Form_ACILIS :
			tablo = (TABLO_FORM *) tabloyukle("bin/acilis.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			formyukle(2, 15, "bin/acilis.Frm");
			tablo_oynatici(2, 15, Data_Acilis_Bilgisi, (char *) dataci, tablo, &baslik);
			kayit_adresi = 0;
			free(dataci);
			break;
		case Form_IS_TAKIBI :
			formyukle(2, 15, "bin/takip.frm");
			tablo = (TABLO_FORM *) tabloyukle("bin/takip.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			strcpy(menu_ayarla, "00011111");
			memset(dataci, 0, baslik.data_uzunlugu);
			tablo_oynatici(2, 15, Data_IsTakip_Genel, (char *) dataci, tablo, &baslik);
			kayit_adresi = 0;
			free(dataci);
			strcpy(menu_ayarla, "00000000");
			break;
		case Form_MUKELLEF_LISTESI :
			pencere.turu += DUZEY;
			formgolge(7, 20, "bin/tekalan.frm");
			formyukle(7, 20, "bin/tekalan.frm");
			tablo = (TABLO_FORM *) tabloyukle("bin/tekalan.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			tablo_oynatici(7, 20, Data_TekAlan, (char *) dataci, tablo, &baslik);
			free(dataci);
			pencere.turu -= DUZEY;
			break;
		case Form_PARAMETRELER :
			formgolge(3, 22, "bin/prmtre.frm");
			formyukle(3, 22, "bin/prmtre.frm");
			tablo = (TABLO_FORM *) tabloyukle("bin/prmtre.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			tablo_oynatici(3, 22, Data_Parametreler, (char *) dataci, tablo, &baslik);
			free(dataci);
			break;
		case Form_PARA_KUTUSU :
			tablo = (TABLO_FORM *) tabloyukle("bin/parakutu.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			formyukle(2, 15, "bin/parakutu.frm");
			kasa_goruntusu();
			kayit_adresi = 0;
			tablo_oynatici(2, 15, Data_ParaKutusu_Genel, (char *) dataci, tablo, &baslik);
			kayit_adresi = 0;
			free(dataci);
			break;
		case Form_ODEME_LISTESI :
			pencere.turu += DUZEY;
			tablo = (TABLO_FORM *) tabloyukle("bin/tumalan.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu+20);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu+20);
			formgolge(6, 20, "bin/tumalan.frm");
			formyukle(6, 20, "bin/tumalan.frm");
			tablo_oynatici(6, 20, Data_TumAlan, (char *) dataci, tablo, &baslik);
			free(dataci);
			pencere.turu -= DUZEY;
			break;
		case Form_KESINTI_LISTESI :
			pencere.turu += DUZEY;
			formgolge(7, 20, "bin/tekalan.frm");
			formyukle(7, 20, "bin/tekalan.frm");
			tablo = (TABLO_FORM *) tabloyukle("bin/tekalan.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			tablo_oynatici(7, 20, Data_TekAlan, (char *) dataci, tablo, &baslik);
			free(dataci);
			pencere.turu -= DUZEY;
			break;
		case Form_BORCU_OLANLAR :
			pencere.turu += DUZEY;
			tablo = (TABLO_FORM *) tabloyukle("bin/tumalan.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu+20);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu+20);
			formgolge(6, 20, "bin/tumalan.frm");
			formyukle(6, 20, "bin/tumalan.frm");
			tablo_oynatici(6, 20, Data_TumAlan, (char *) dataci, tablo, &baslik);
			free(dataci);
			pencere.turu -= DUZEY;
			break;
		case Form_ODEME_KARTI :
			pencere.turu += DUZEY;
			formgolge(7, 20, "bin/tekalan.frm");
			formyukle(7, 20, "bin/tekalan.frm");
			tablo = (TABLO_FORM *) tabloyukle("bin/tekalan.tbl", &baslik);
			dataci = (char *) malloc(baslik.data_uzunlugu);
			if (dataci == NULL) {
				msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
				exit(1);
			}
			memset(dataci, 0, baslik.data_uzunlugu);
			tablo_oynatici(7, 20, Data_TekAlan, (char *) dataci, tablo, &baslik);
			free(dataci);
			pencere.turu -= DUZEY;
			break;
		case Form_KULLANICI :
			formyukle(2, 15, "bin/kullan.frm");
			git_xy(0, 0);
			islem();
			break;
		case Form_FIRMA_AYARI :
			formyukle(2, 14, "bin/firmayar.frm");
			git_xy(0, 0);
			islem();
			break;
		case Form_YAZICI :
			formgolge(5, 20, "bin/yazici.frm");
			formyukle(5, 20, "bin/yazici.frm");
			git_xy(0, 0);
			islem();
			break;
		case Form_DATA_ISLEMLERI :
			formyukle(2, 14, "bin/dataislm.frm");
			git_xy(0, 0);
			islem();  break;
		case Form_HESAP_MAKINESI :
			formgolge(4, 32, "bin/hesapci.frm");
			formyukle(4, 32, "bin/hesapci.frm");
			git_xy(0, 0);
			islem();
			break;
		case Form_NOTLAR :
			formgolge(6, 29, "bin/notlar.frm");
			formyukle(6, 29, "bin/notlar.frm");
			git_xy(0, 0);
			islem();
			break;
		case Form_MESAJLASMA :
			formgolge(6, 29, "bin/mesaj.frm");
			formyukle(6, 29, "bin/mesaj.frm");
			git_xy(0, 0);
			islem();
			break;
	}
	ekran_cikis(bellek);
}

void datamenu(void)
{
	MENU data_menu;
	char *bellek, *data = "      ";
	int ch;

	data[0] = '2';
	bellek = ekran_giris();

	git_xy(25, 80);
	formgolge(7, 33, "bin/datamenu.frm");
	formyukle(7, 33, "bin/datamenu.frm");
	mib_al(&data_menu);
	menuyukle("bin/menulist.mnu", DMenu_DATAMENU, &data_menu);
	strcpy(data_menu.MenuDurumDizisi, menu_ayarla);
	ch = menu_cagir(&data_menu, data);
	mib_ver(&data_menu);
	ekran_cikis(bellek);
	if (ch == ENTER || ch == DOWN)
		switch (data[0]) {
			case '0': shiftf2(baslik.referans); break;
			case '1': shiftf3(baslik.referans); break;
			case '2': shiftf4(baslik.referans); break;
			case '3': shiftf5(baslik.referans); break;
//			case '4': shiftf6(baslik.referans); break;
			case '5': shiftf7(); break;
			case '6': shiftf8(baslik.referans); break;
		}
}

void arac(void)
{
	int islemler, ch;
	char *veri = "      ", *bellek, *menu_kontrol = "0";

	if (menu_kontrol[0] != '0')
		goto SON;

	menu_kontrol[0] = '1';
	bellek = ekran_giris();
	pencere.turu += DUZEY;
	git_xy(25, 80);
	formgolge(9, 33, "bin/arac.frm");
	formyukle(9, 33, "bin/arac.frm");
	ch = menu_sec(veri, 1, 1, 1, DMenu_ARAC, NULL);
	menu_kontrol[0] = '0';
	ekran_cikis(bellek);
	pencere.turu -= DUZEY;
	islemler = ((atoi(veri)+2) + 20000);
	if (ch != ESC)
		form_cagir(islemler);
SON: // ModÅl Sonu
}

void tarih(void)
{
	/* Bu fonksiyon ekranda iüinizi yaptçßçnçz halde saati áalçütçran
	bir fonksiyondur. */
	int j = 0;
	struct tm *p;
	long t_old, t_new = 0, saniye;
	char temp[50];
	char *hafta[7] = { "  Pazar  ", "Pazartesi", "   Salç   ", " Äarüamba ",
		" Perüembe ", "   Cuma  ", "Cumartesi" };
	char *string = " MÅkellef Takip Sistemi - òüimiz, iüinizi kolaylaütçrmak ";

	harf(0, 55, '≥', YESIL_ | A_BEYAZ);
	while (!kbhit()) {
		t_old = time(NULL);
		p = localtime(&t_old);
		if (t_old != t_new) {
			t_old = time(NULL);
			p = localtime(&t_old);
			t_new = t_old;
			++j;
		}
		if (j == 1) {
			saniye = time(NULL);
			p = localtime(&saniye);
			sprintf(temp, "%02d/%02d/%04d - ",
			p->tm_mday, p->tm_mon + 1, p->tm_year + 1900);
			harfler(0, 57, temp, YESIL_ | A_BEYAZ);
			harfler(0, 70, hafta[p->tm_wday], YESIL_ | A_BEYAZ);
			sprintf(temp, "%02d:%02d.%02d", p->tm_hour, p->tm_min, p->tm_sec);
			harfler(0, 46, temp, YESIL_ | A_BEYAZ);
			j = 0;
			if (pencere.turu == DATA_FORM)
				cift_renk(24, 57, "&F&9 DataMenu", KAHVE_ | A_BEYAZ, KAHVE_ | SARI);
			else
				harfler(24, 57, "F9 DataMenu", KAHVE_ | BEYAZ);
			rengarenk(0, 0, string, 24, YESIL_ | A_BEYAZ);
		}
	}
}

void ana_menu(void)
{
	char *p;
	int gecici = 2, ch = 0, sayac;
	char *panel_elemanlari[4] = { "MöKELLEF", "ôDEMELER", "RAPORLAR",
								  "òûLEMLER"};

	git_xy(24, 80);
	for (sayac = 0; sayac < 4; sayac++)
		doldur(4 + sayac, 2, ' ', 10, MAVI_);
	doldur(3, 2, 'ﬂ', 10, MAVI_ | A_MAVI);
	doldur(8, 2, '‹', 10, MAVI_ | A_MAVI);
	for (sayac = 0; sayac < 4; sayac++)
		harfler(sayac + 4, 3, panel_elemanlari[sayac], MAVI_ | A_BEYAZ);

	for (;;) {
		switch(ch) {
			case UP : seckin--; break;
			case DOWN : seckin++; break;
		}
EKRAN:
		switch (seckin) {
			case -1 : seckin = 3; break;
			case 4 : seckin = 0; break;
		}
		harfler(gecici + 4, 3, struprtr(panel_elemanlari[gecici]), MAVI_ | A_BEYAZ);
		harfler(gecici + 4, 3, panel_elemanlari[gecici], MAVI_ | A_BEYAZ);
		harfler(gecici + 4, 0, "€€", A_MAVI);
		harfler(gecici + 4, 12, "€€", A_MAVI);
		harfler(seckin + 4, 3, strlwrtr(panel_elemanlari[seckin]), YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 3, panel_elemanlari[seckin], YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 0, "  ", YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 12, "  ", YESIL_ | A_BEYAZ);
		gecici = seckin;

		switch (seckin) {
			case 0 : musavir();
					 goto EKRAN;
			case 1 : odemeler();
					 goto EKRAN;
			case 2 : raporlar();
					 goto EKRAN;
			case 3 : islemler();
					 goto EKRAN;
		}
	ch = islem();
	}
}

void musavir(void)
{
	char *veri = "      ";
	int islemler, ch, i;

	ch = menu_sec(veri, 1, 1, 1, YMenu_MUSAVIR, NULL);
	islemler = (atoi(veri)+1) * 1000;
	if (ch != ESC)
		form_cagir(islemler);
}

void odemeler(void)
{
	char *veri = "      ";
	int islemler, ch, i;

	ch = menu_sec(veri, 1, 1, 1, YMenu_ODEMELER, NULL);
	islemler = (atoi(veri)+1) * 1000 + 4000;
	if (ch != ESC)
		form_cagir(islemler);
}

void raporlar(void)
{
	char *veri = "      ";
	int islemler, ch, i;

	ch = menu_sec(veri, 1, 1, 1, YMenu_RAPORLAR, NULL);
	islemler = (atoi(veri)+1) * 1000 + 6000;
	if (ch != ESC)
		form_cagir(islemler);
}

void islemler(void)
{
	char *veri = "      ";
	int islemler, ch, i;

	ch = menu_sec(veri, 1, 1, 1, YMenu_ISLEMLER, NULL);
	islemler = (atoi(veri)+1) * 1000 + 9000;
	if (ch != ESC)
		form_cagir(islemler);
}

void sifre(void)
{
	int i;
	char *p, denem[80]; /* gecici denem */
	memset(denem, 0, 79);

	if ((p = malloc(800)) == NULL) {
		printf("Bellek Yetersiz\n");

		exit(1);
	}
	gettext(48, 15, 47+32, 18+7, p);
	golgele(16, 49, 7, 29, SIYAH_ | GRI);
	formyukle(15, 47, "bin/sifre.frm");
	yazi_yaz(denem, 17, 62, 9, BEYAZ_ | SIYAH, BEYAZ_ | GRI);
	yazi_yaz(denem, 18, 62, 9, BEYAZ_ | SIYAH, BEYAZ_ | GRI);
	puttext(48, 15, 47+32, 18+7, p);
	git_xy(24, 80);
	free(p);
}

void kmenu_islem(char *data, TABLO_FORM *tablo, TABLO_BILGI *baslik, int sayac)
{
	DOSYA handle;
	int n;
	char *bellek;

	handle.tablo = tablo;
	handle.baslik = *baslik;
	handle.data = dataci;

	switch (tablo[sayac].referans) {
		case KMenu_TAKIP : break;
		case KMenu_DATA_ISLEM :	break;
		case KMenu_AYLAR :
			 if (baslik->referans == Form_PARA_KUTUSU+1)
					detay_listesi();
			 break;
		case KMenu_YILLAR :
			if (baslik->referans == Form_IS_TAKIBI) {
				kayit_adresi = takip_dosya_kontrol();
				if (kayit_adresi == 2)
					msj_kutu(NULL, "ûu anda data yaratçlçyor", UYARI);
				else if (kayit_adresi != 0) {
					baslik->kontrol = 1;
					dosya_yapisi_doldur(&handle, "DATA/");
					dosya_ac(&handle);
					bellek = ekran_giris();
					kayit_adresi = liste_kutusu(8, 20, 0, 13, 55, BEYAZ_ | SIYAH, SIYAH_ | A_BEYAZ, &handle);
					ekran_cikis(bellek);
					baslik->kontrol = 0;
					dosya_kapa(&handle);
				}
				break;
			}
		case KMenu_ACILIS :	break;
		case KMenu_ISLEM_TURU : break;
		case KMenu_ODEME_TURU :
			if (data[0] != '0' && data[0] != '1' && data[0] != '2') {
				golge(11, 20, 14, BEYAZ_ | SIYAH);
				golge(12, 20, 14, BEYAZ_ | SIYAH);
				golge(12, 50, 7, BEYAZ_ | SIYAH);
				golge(13, 20, 14, BEYAZ_ | SIYAH);
				golge(14, 20, 6, BEYAZ_ | SIYAH);
				golge(14, 39, 8, BEYAZ_ | SIYAH);
				golge(14, 61, 6, BEYAZ_ | SIYAH);
				for (n = sayac+2; n < baslik->eleman_sayisi-5; n++)
					tablo[n].islem_sirasi = SONRA;
			}
			else {
				golgele(11, 20, 4, 50, BEYAZ_ | GRI);
				for (n = sayac+2; n < baslik->eleman_sayisi-5; n++)
					tablo[n].islem_sirasi = YOK;
			}
			break;
	}
}

int menu_sec(char *veri, int satir, int kolon, int uzunluk, int eleman_referansi, char *depo_dizi)
{
	MENU menu;
	int ch;

	mib_al(&menu);

	switch (eleman_referansi) {
		case YMenu_MUSAVIR : menuyukle("bin/MENULIST.MNU", YMenu_MUSAVIR, &menu);
							 cift(1, 14, "  Aáçlçü  òü_Takip  MÅkellef_Listesi  Parametreler                ", CYAN_ | SIYAH);
							 break;
		case YMenu_ODEMELER : menuyukle("bin/MENULIST.MNU", YMenu_ODEMELER, &menu);
							  cift(1, 14, "  Para_Kutusu  ôdeme_Listesi                                      ", CYAN_ | SIYAH);
							  break;
		case YMenu_RAPORLAR : menuyukle("bin/MENULIST.MNU", YMenu_RAPORLAR, &menu);
							  cift(1, 14, "  Kesinti_Listesi  Borcu_Olanlar  ôdeme_Kartç                     ", CYAN_ | SIYAH);
							  break;
		case YMenu_ISLEMLER : cift(1, 14, "  Kullançcç  Firma_Ayarç  Yazçcç  Data_òülemleri                  ", CYAN_ | SIYAH);
							  menuyukle("bin/MENULIST.MNU", YMenu_ISLEMLER, &menu);
							  break;
		case DMenu_ARAC : menuyukle("bin/menulist.mnu", DMenu_ARAC, &menu);
						  strcpy(menu.MenuDurumDizisi, "0010");
						  break;
		case DMenu_DATAMENU : break;
		case KMenu_TAKIP :  menuyukle("bin/menulist.mnu", KMenu_TAKIP, &menu);
							menu.BaslangicSatiri = satir;
							menu.BaslangicKolonu = kolon;
							menu.BitisSatiri = satir + 2;
							menu.BitisKolonu = kolon + uzunluk;
						   break;
		case KMenu_DATA_ISLEM : menuyukle("bin/menulist.mnu", KMenu_DATA_ISLEM, &menu);
								menu.BaslangicSatiri = satir;
								menu.BaslangicKolonu = kolon;
								menu.BitisSatiri = satir + 2;
								menu.BitisKolonu = kolon + uzunluk;
								break;
		case KMenu_AYLAR : menuyukle("bin/menulist.mnu", KMenu_AYLAR, &menu);
						   menu.BaslangicSatiri = satir;
						   menu.BaslangicKolonu = kolon;
						   menu.BitisSatiri = satir + 2;
						   menu.BitisKolonu = kolon + uzunluk;
						   break;
		case KMenu_YILLAR :	menuyukle("bin/menulist.mnu", KMenu_YILLAR, &menu);
							menu.BaslangicSatiri = satir;
							menu.BaslangicKolonu = kolon;
							menu.BitisSatiri = satir + 2;
							menu.BitisKolonu = kolon + uzunluk;
							break;
		case KMenu_ACILIS :	menuyukle("bin/menulist.mnu", KMenu_ACILIS, &menu);
							menu.BaslangicSatiri = satir;
							menu.BaslangicKolonu = kolon;
							menu.BitisSatiri = satir + 2;
							menu.BitisKolonu = kolon + uzunluk;
							break;
		case KMenu_ISLEM_TURU :	menuyukle("bin/menulist.mnu", KMenu_ISLEM_TURU, &menu);
								menu.BaslangicSatiri = satir;
								menu.BaslangicKolonu = kolon;
								menu.BitisSatiri = satir + 2;
								menu.BitisKolonu = kolon + uzunluk;
								break;
		case KMenu_ODEME_TURU : menuyukle("bin/menulist.mnu", KMenu_ODEME_TURU, &menu);
								menu.BaslangicSatiri = satir;
								menu.BaslangicKolonu = kolon;
								menu.BitisSatiri = satir + 2;
								menu.BitisKolonu = kolon + uzunluk;
								break;
	}
	if (depo_dizi == NULL)
		ch = menu_cagir(&menu, veri);
	else {
		if (veri[0] == 0)
			veri[0] = '0';
			dizi_yapici(&menu, veri[0]-'0', depo_dizi);
			harfler(satir, kolon, depo_dizi, menu.AktifSecili);
	}
	mib_ver(&menu);
	return ch;
}

void mesaj_goster_kac(char *string)
{
	char *bellek;
	int alan;

	bellek = malloc(100);
	gettext(1, 24, 22, 25, bellek);
	alan = strlen(string);

	if (alan > 22)
		strcpy(&string[18], "...");

	doldur(24, 0, ' ', 22, KAHVE_);
	harfler(24, 0, string, KAHVE_ | A_BEYAZ);
	delay(350);
	puttext(1, 24, 22, 25, bellek);
	free(bellek);
}

char *liste_elemani(int satir, int kolon, char *string, DOSYA *handle, int baslangic, int uzunluk, int boy, int renk)
{
	int sayac, kontrol = handle->indeks_baslik->indeks_data_uzunlugu,
		boy_sayaci = 0;
	long adres;

	if (uzunluk < kontrol)
		kontrol = uzunluk;

	adres = indeks_gezgini(handle, baslangic);
	for (boy_sayaci = 0; boy_sayaci < boy; boy_sayaci++) {
		detay_oku(handle, adres, DATA_AL);
		adres = handle->indeks_detay->sonraki;

		memcpy(&string[(boy_sayaci * kontrol)+1], handle->indeks_detay->data, kontrol);
		string[(kontrol * boy_sayaci)] = ' ';
		for (sayac = 1; sayac < kontrol; sayac++) {
			if (string[(boy_sayaci * kontrol) + sayac] == '\0')
				string[(kontrol * boy_sayaci) + sayac] = ' ';
		}
		string[(kontrol * boy_sayaci) + sayac-1] = '\0';
		if (string[(kontrol * boy_sayaci) + sayac-2] != ' ')
			strcpy(&string[(kontrol * boy_sayaci) + sayac-5], "... ");
		harfler(satir + boy_sayaci, kolon, &string[kontrol * boy_sayaci], renk);
	}
	return string;
}

long liste_kutusu(int satir, int kolon, int baslangic, int boy, int en, int renk1, int renk2, DOSYA *handle)
{
	char *eleman;

	int sayac = 0, toplam = handle->indeks_baslik->toplam_kayit, isaretli_sayac = 0,
		ch = 0, bayrak = 0, yeni_baslangic = 0;
	long adres = 0;

	eleman = (char *) malloc((en+5) * boy * 2);
	if (eleman == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	memset(eleman, 0, (en+5) * boy * 2);

	if (toplam == 0) {
		free(eleman);
		return -2;
	}
	else if (toplam < boy) {
		boy = toplam;
		bayrak = 1;
	}

	liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
	for (;;) {
		if (yeni_baslangic != baslangic) {
			yeni_baslangic = baslangic;
			liste_elemani(satir, kolon, eleman, handle, baslangic, en, boy, renk1);
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

#if 1
void main(void)
{
	int i;
	/* TÅrkáe Karakter Ayarlarç //
	system("mode con codepage prepare=((857) C:\\WINDOWS\\COMMAND\\ega2.cpi)");
	system("mode con codepage select=857");
	system("keyb tr,,C:\\WINDOWS\\COMMAND\\keybrd2.sys /id:179");
/*--------------------------*/
	git_xy(0, 0);
	formyukle(0, 0, "bin/anaform.Frm");
	pencere.derecesi = UST_DUZEY;
	ana_menu(); //*/
/*	clrscr();
	kalin_cerceve(2, 15, 20, 63, BEYAZ_ | A_BEYAZ);
	for (i = 0; i < 20; i++)
		doldur(3+i, 16, ' ', 62, BEYAZ_);

	doldur(3, 17, ' ', 60, KAHVE_ | A_BEYAZ);
	harfler(3, 41, "Kullançcç Ayarlarç", KAHVE_ | A_BEYAZ);
	ince_cerceve(4, 17, 17, 59, BEYAZ_ | GRI);

	ice_pen(6, 19, 14, 55);
	cift_renk(7, 21, "        òáerik        &≥Genel&≥ òlk &≥Kayçt&≥ Sil &≥Liste", KAHVE_ | A_BEYAZ, KAHVE_ | BEYAZ);
	harfler(8, 21, "Aáçlçü ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(8, 45, "[ ]   [ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(9, 21, "òü_Takibi ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(9, 45, "[ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(10, 21, "MÅkellef_Listesi", BEYAZ_ | SIYAH);
	harfler(10, 45, "[ ]", BEYAZ_ | SIYAH);
	harfler(11, 21, "Parametreler", BEYAZ_ | SIYAH);
	harfler(11, 45, "[ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(12, 21, "Para_Kutusu ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(12, 45, "[ ]   [ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(13, 21, "ôdeme_Listesi", BEYAZ_ | SIYAH);
	harfler(13, 45, "[ ]", BEYAZ_ | SIYAH);
	harfler(14, 21, "Kesinti_Listesi", BEYAZ_ | SIYAH);
	harfler(14, 45, "[ ]", BEYAZ_ | SIYAH);
	harfler(15, 21, "Borcu_Olanlar", BEYAZ_ | SIYAH);
	harfler(15, 45, "[ ]", BEYAZ_ | SIYAH);
	harfler(16, 21, "ôdeme_Kartç", BEYAZ_ | SIYAH);
	harfler(16, 45, "[ ]", BEYAZ_ | SIYAH);
	harfler(17, 21, "Kullançcç ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(17, 45, "[ ]   [ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(18, 21, "Firma_Ayarç ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(18, 45, "[ ]   [ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(19, 21, "Yazçcç ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(19, 45, "[ ]   [ ]   [ ]   [ ]   [ ]", BEYAZ_ | SIYAH);
	harfler(20, 21, "Data_òülemleri ModÅlÅ", BEYAZ_ | SIYAH);
	harfler(20, 45, "[ ]", BEYAZ_ | SIYAH);

	harfler(5, 20, "Kullançcç", BEYAZ_ | SIYAH);
	harfler(5, 42, "Parola", BEYAZ_ | SIYAH);
	harfler(5, 59, "Tekrar", BEYAZ_ | SIYAH);
	formyarat(2, 15, 22, 64, "bin/kullan.frm");
  //	getch();
	formyukle(1, 16, "kullan.frm");//*/
}
#endif