/*-------------------------------------------------------------------------*/
#include "/ozgan/programs/buro_v_1/src/h/buro.h"
int menu_sec(char *veri, int satir, int kolon, int uzunluk, int eleman_referansi);

/* Global De§iŸkenler */
int sifreci = 0; /* Bu global de§iŸken sifre mens i‡indir.          */
int seckin = 0;  /* Ana_Menu fonksiyonundaki, se‡ili eleman g”sterir */
PENCERE pencere;
/*-------------------------------------------------------------------------*/

void datamenu(void)
{
	char *gecici, *menu_kontrol = "0";
	MENU menu;

	if (menu_kontrol[0] == '1')
		goto SON;

	menu_kontrol[0] = '1';
	pencere.derecesi += DUZEY;
	gecici = malloc(16 * 29 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}

	gettext(33, 8, 62, 22, gecici);
	git_xy(25, 80);
	formgolge(7, 33, "bin/datamenu.frm");
	formyukle(7, 33, "bin/datamenu.frm");
	mib_al(&menu);
	menuyukle("bin/menulist.mnu", DMenu_DATAMENU, &menu);
	menu_cagir(&menu, "0");
	mib_ver(&menu);
	puttext(33, 8, 62, 22, gecici);
	free(gecici);
	menu_kontrol[0] = '0';
	pencere.derecesi -= DUZEY;
SON:
}


void arac(void)
{
	char *gecici, *menu_kontrol = "0"; // Bir kez a‡lmas i‡in
	MENU menu;

	if (menu_kontrol[0] == '1')
		goto SON;

	menu_kontrol[0] = '1';
	gecici = malloc(16 * 29 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	gettext(33, 8, 62, 22, gecici);
	git_xy(25, 80);
	pencere.derecesi += DUZEY; //
	formgolge(9, 33, "bin/arac.frm");
	formyukle(9, 33, "bin/arac.frm");
	menu_sec("0", 1, 1, 1, DMenu_ARAC);
	puttext(33, 8, 62, 22, gecici);
	free(gecici);
	menu_kontrol[0] = '0';
	pencere.derecesi -= DUZEY;
SON: // Program sonu
}

void tarih(void)
{
	/* Bu fonksiyon ekranda iŸinizi yapt§nz halde saati ‡alŸtran
	bir fonksiyondur. */
	int j = 0;
	struct tm *p;
	long t_old, t_new = 0, saniye;
	char temp[50];
	char *hafta[7] = { "  Pazar  ", "Pazartesi", "   Sal   ", " €arŸamba ",
		" PerŸembe ", "   Cuma  ", "Cumartesi" };
	char *string = " Mkellef Takip Sistemi - ˜Ÿimiz, iŸinizi kolaylaŸtrmak ";

	harf(0, 55, '³', YESIL_ | A_BEYAZ);
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
	char *panel_elemanlari[4] = { "MšKELLEF", "™DEMELER", "RAPORLAR",
								  "˜žLEMLER"};

	git_xy(24, 80);
	for (sayac = 0; sayac < 4; sayac++)
		doldur(4 + sayac, 2, ' ', 10, MAVI_);
	doldur(3, 2, 'ß', 10, MAVI_ | A_MAVI);
	doldur(8, 2, 'Ü', 10, MAVI_ | A_MAVI);
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
		harfler(gecici + 4, 0, "ÛÛ", A_MAVI);
		harfler(gecici + 4, 12, "ÛÛ", A_MAVI);
		harfler(seckin + 4, 3, strlwrtr(panel_elemanlari[seckin]), YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 3, panel_elemanlari[seckin], YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 0, "  ", YESIL_ | A_BEYAZ);
		harfler(seckin + 4, 12, "  ", YESIL_ | A_BEYAZ);
		gecici = seckin;

		switch (seckin) {
			case 0 : musavir();
					 goto EKRAN;
			case 1 : menu_sec("0", 1, 1, 1, YMenu_ODEMELER);
					 goto EKRAN;
			case 2 : menu_sec("0", 1, 1, 1, YMenu_RAPORLAR);
					 goto EKRAN;
			case 3 : menu_sec("0", 1, 1, 1, YMenu_ISLEMLER);
					 goto EKRAN;
		}
	ch = islem();
	}
}

void musavir(void)
{
	int islemler, ch, i;
	char *gecici, *data, veri[1] = {'0'};
	TABLO_BILGI baslik = {18, 0, YMenu_MUSAVIR};
	TABLO_FORM tablo[] = {	{YAZI, 4, 20, 22, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{KAPALI_MENU, 4, 44, 12, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, KMenu_ACILIS, SONRA},
							{YAZI, 5, 20, 38, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 6, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 7, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 7, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 8, 20, 17, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 8, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 9, 20, 38, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 10, 6, 52, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 11, 15, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 11, 41, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 12, 15, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{YAZI, 12, 41, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{SAYI, 13, 18, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{SAYI, 13, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{SAYI, 16, 45, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
							{SAYI, 17, 45, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA}
						 };
	for (i = 0; i < baslik.eleman_sayisi; i++)
		baslik.data_uzunlugu += tablo[i].uzunluk + 1;


	gecici = (char *) malloc(24 * 68 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	data = (char *) malloc(baslik.data_uzunlugu);
	if (data == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	memset(data, 0, baslik.data_uzunlugu);

	ch = menu_sec(veri, 1, 1, 1, YMenu_MUSAVIR);
	islemler = atoi(veri);
	if (ch != ESC)
		switch (islemler) {
			case 0: pencere.derecesi += DUZEY;
					pencere.turu = DATA_FORM;
					gettext(15, 2, 79, 24, gecici);
					formyukle(2, 15, "bin/acilis.frm");
					tablo_oynatici(2, 15, data, tablo, &baslik);
					git_xy(0, 0);
					puttext(15, 2, 79, 24, gecici);
					pencere.turu = UST_DUZEY;
					pencere.derecesi -= DUZEY;
		}
	free(data);
	free(gecici);
}
/*
void odemeler(void)
{
	int islemler, ch;
	char *gecici, data[800], veri[1]  = {'0'};
	MENU menu;
	gecici = (char *) malloc(24 * 68 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}

	memset(data, 0, 800);
	mib_al(&menu);
	menuyukle("bin/MENULIST.MNU", YMenu_ODEMELER, &menu);
	cift(1, 14, "  Para_Kutusu  ™deme_Listesi                                      ", CYAN_ | SIYAH);
	ch = menu_cagir(&menu, veri);
	islemler = atoi(veri);
	if (ch != ESC)
		switch (islemler) {
			case 0: gettext(15, 2, 79, 24, gecici);
					formyukle(2, 15, "bin/parakutu.frm");
					git_xy(0, 0);
					form_turu = UST_SINIF;
					getkb();
					puttext(15, 2, 79, 24, gecici);
		}
	free(gecici);
	mib_ver(&menu);
}

void raporlar(void)
{
	char veri[2];
	MENU menu;

	mib_al(&menu);
	menuyukle("bin/MENULIST.MNU", 3, &menu);
	cift(1, 14, "  Kesinti_Listesi  Borcu_Olanlar  ™deme_Kart                     ", CYAN_ | SIYAH);
	menu_cagir(&menu, veri);
	mib_ver(&menu);
}

void islemler(void)
{
	int ch, islemler;
	char veri[1] = {'0'}, *gecici;
	MENU menu;

	gecici = (char *) malloc(24 * 68 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	mib_al(&menu);
	cift(1, 14, "  Kullanc  Firma_Ayar  Yazc  Data_˜Ÿlemleri                  ", CYAN_ | SIYAH);
	menuyukle("bin/MENULIST.MNU", YMenu_ISLEMLER, &menu);
	ch = menu_cagir(&menu, veri);

	islemler = atoi(veri);
	if (ch != ESC)
		switch (islemler) {
			case 3: gettext(15, 2, 79, 24, gecici);
					formyukle(2, 14, "bin/dataislm.frm");
					git_xy(0, 0);
					form_turu = UST_SINIF;
					getkb();
					puttext(15, 2, 79, 24, gecici);
		}
	free(gecici);
	mib_ver(&menu);
} */

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

int islem(void)
{
	int ch;

	tarih();
	ch = getkb();
	switch (ch) {
//		case F1 : formyukle(2, 14, "bin/yardim.frm"); break;
		case F2 :
		case F3 :
		case F4 :
		case F5 :
		case F6 : break;
		case F7 : cikis(); break;
		case F8 : arac(); break;
		case F9 : if (pencere.turu == DATA_FORM)
					 datamenu();
				  break;
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
	return 0;
}

int menu_sec(char *veri, int satir, int kolon, int uzunluk, int eleman_referansi)
{
	MENU menu;
	int ch;

	mib_al(&menu);
	switch (eleman_referansi) {
		case YMenu_MUSAVIR : menuyukle("bin/MENULIST.MNU", YMenu_MUSAVIR, &menu);
							 cift(1, 14, "  A‡lŸ  ˜Ÿ_Takip  Mkellef_Listesi  Parametreler                ", CYAN_ | SIYAH);
							 break;
		case YMenu_ODEMELER : menuyukle("bin/MENULIST.MNU", YMenu_ODEMELER, &menu);
							  cift(1, 14, "  Para_Kutusu  ™deme_Listesi                                      ", CYAN_ | SIYAH);
							  break;
		case YMenu_RAPORLAR : menuyukle("bin/MENULIST.MNU", YMenu_RAPORLAR, &menu);
							  cift(1, 14, "  Kesinti_Listesi  Borcu_Olanlar  ™deme_Kart                     ", CYAN_ | SIYAH);
							  break;
		case YMenu_ISLEMLER : cift(1, 14, "  Kullanc  Firma_Ayar  Yazc  Data_˜Ÿlemleri                  ", CYAN_ | SIYAH);
							  menuyukle("bin/MENULIST.MNU", YMenu_ISLEMLER, &menu);
							  break;
		case DMenu_ARAC : menuyukle("bin/menulist.mnu", DMenu_ARAC, &menu);  break;
		case DMenu_DATAMENU : break;
		case KMenu_TAKIP : menuyukle("bin/menulist.mnu", KMenu_TAKIP, &menu);
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
		case KMenu_ACILIS : menuyukle("bin/menulist.mnu", KMenu_ACILIS, &menu);
							menu.BaslangicSatiri = satir;
							menu.BaslangicKolonu = kolon;
							menu.BitisSatiri = satir + 2;
							menu.BitisKolonu = kolon + uzunluk;
							break;
	}
	ch = menu_cagir(&menu, veri);
	mib_ver(&menu);
	return ch;
}

#if 1
void main(void)
{
	/* Trk‡e Karakter Ayarlar //
	system("mode con codepage prepare=((857) C:\\WINDOWS\\COMMAND\\ega2.cpi)");
	system("mode con codepage select=857");
	system("keyb tr,,C:\\WINDOWS\\COMMAND\\keybrd2.sys /id:179");
	/*--------------------------*/
	int x, y;
	formyukle(0, 0, "bin/anaform.Frm");
	pencere.derecesi = UST_DUZEY;
	ana_menu();
}
#endif