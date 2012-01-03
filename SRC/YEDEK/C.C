/*-------------------------------------------------------------------------*/
#include "/ozgan/programs/buro_v_1/src/h/buro.h"

/* Global De§iŸkenler */
int sifreci = 0; /* Bu global de§iŸken sifre mens i‡indir.          */
int seckin = 0;  /* Ana_Menu fonksiyonundaki, se‡ili eleman g”sterir */
/*-------------------------------------------------------------------------*/

void arac(void)
{
	char *gecici;
	MENU menu = { BEYAZ_ | SIYAH,
				  CYAN_ | SARI,
				  KAHVE_ | A_BEYAZ,
				  KAHVE_ | SARI,
				  BEYAZ_ | GRI,
				  SIYAH_ | GRI,
				  PASIF,
				  DIKEY,
				  4,
				  1000,
				  11,
				  37,
				  15,
				  55,
				  "+Hesap Makinesi+Notlar+Data ˜Ÿlemleri+MesajlaŸma+",
				  "0000",
				  "KFRA"
				  };

	gecici = malloc(16 * 29 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	gettext(33, 8, 62, 22, gecici);
	form_turu = ORTA_SINIF;
	git_xy(25, 80);
	formgolge(9, 33, "bin/arac.frm");
	formyukle(9, 33, "bin/arac.frm");
	menu_cagir(&menu);
	form_turu = YATAY_MENU_SINIFI;
	puttext(33, 8, 62, 22, gecici);
	free(gecici);
}

void kart_islem_turu(void)
{
	char *gecici;
	MENU menu = { BEYAZ_ | SIYAH,
				  BEYAZ_ | SIYAH,
				  BEYAZ_ | A_BEYAZ,
				  KAHVE_ | SARI,
				  BEYAZ_ | GRI,
				  SIYAH_ | GRI,
				  PASIF,
				  KAPALI,
				  3,
				  1000,
				  11,
				  37,
				  13,
				  47,
				  "+Mukellef+Personel+Cari+",
				  "000",
				  ""
				  };
	menu_cagir(&menu);
}

void datamenu(void)
{
	char *gecici;
	MENU menu = { BEYAZ_ | SIYAH,
				  CYAN_ | SARI,
				  KAHVE_ | A_BEYAZ,
				  KAHVE_ | SARI,
				  BEYAZ_ | GRI,
				  SIYAH_ | GRI,
				  PASIF,
				  DIKEY,
				  8,
				  1000,
				  9,
				  37,
				  17,
				  55,
				  "+\x18\F2 Kaydet+\x18\F3 Sil+\x18\F4 Yeni+\x18\F5 Liste+"
				  "\x18\F6 Arama+\x18\F7 Kopyala+\x18\F8 YapŸtr+\x18\F9 €kt Raporu+",
				  "00000000",
				  ""
				  };

	gecici = malloc(16 * 29 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}

	gettext(33, 8, 62, 22, gecici);
	form_turu = ORTA_SINIF;
	git_xy(25, 80);
	formgolge(7, 33, "bin/datamenu.frm");
	formyukle(7, 33, "bin/datamenu.frm");
	menu_cagir(&menu);
	form_turu = YATAY_MENU_SINIFI;
	puttext(33, 8, 62, 22, gecici);
	free(gecici);
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
			if (data_menu == ACIK_DATA)
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

	form_turu = 10000;
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
	int islemler;
	char *gecici, data[800];
	MENU menu;
	TABLO_FORM tablo[] = {
							{YAZI, 4, 20, 22, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
//							{KAPALI_MENU, 4, 43, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA},
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
							{SAYI, 13, 45, 13, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, 123, SONRA}
						 };

	gecici = (char *) malloc(24 * 68 * 2);
	if (gecici == NULL) {
		msj_kutu(NULL, HATA_BELLEK_YETERSIZ, HATA);
		exit(1);
	}
	memset(data, 0, 800);
	mib_al(&menu);
	cift(1, 14, "  A‡lŸ  ˜Ÿ_Takip  Mkellef_Listesi                              ", CYAN_ | SIYAH);
	menuyukle("bin/MENULIST.MNU", 1, &menu);
	islemler = menu_cagir(&menu);
	mib_ver(&menu);
	switch (islemler) {
		case 0: gettext(15, 2, 79, 24, gecici);
				formyukle(2, 15, "bin/acilis.frm");
				tablo_oynatici(2, 15, data, tablo);
				git_xy(0, 0);
				form_turu = UST_SINIF;
				puttext(15, 2, 79, 24, gecici);
	}
	free(gecici);
}

void odemeler(void)
{
	MENU menu;

	mib_al(&menu);
	cift(1, 14, "  Para_Kutusu  ™deme_Listesi                                      ", CYAN_ | SIYAH);
	menuyukle("bin/MENULIST.MNU", 2, &menu);
	menu_cagir(&menu);
	mib_ver(&menu);
}

void raporlar(void)
{
	MENU menu;

	mib_al(&menu);
	cift(1, 14, "  Kesinti_Listesi  Borcu_Olanlar  ™deme_Kart                     ", CYAN_ | SIYAH);
	menuyukle("bin/MENULIST.MNU", 3, &menu);
	menu_cagir(&menu);
	mib_ver(&menu);
}

void islemler(void)
defs.h

    Common definitions for pointer size and calling conventions.

    Copyright (c) 1991, 1992 by Borland International
    All Rights Reserved.
*/

#if !defined(___DEFS_H)
#define ___DEFS_H

#if __STDC__
#  define _Cdecl
#else
#  define _Cdecl  cdecl
#endif

#ifndef __PAS__
#  define _CType _Cdecl
#else
#  define _CType pascal
#endif

#ifdef __MSC
#  define _emit db
#  define __far _far
#  define __near _near
#  define __cdecl _cdecl
#  define __pascal _pascal
#  define __export _export
#  ifdef __SMALL__
#    define _M_I86SM
#  endif
#  ifdef __COMPACT__
#    define _M_I86CM
#  endif
#  ifdef __MEDIUM__
#    define _M_I86MM
#  endif
#  ifdef __LARGE__
#    define _M_I86LM
#  endif
#  ifndef _Windows
#    define _DOS
#  else
#    defin