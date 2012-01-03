#ifndef  _BURO_H_
#define  _BURO_H_
/*------------ typedef tançmlamalarç ------------*/
typedef struct ekTAKIP {
	char Takip[12];
	char Aylar[10];
	char Yillar[7];
	char Muk_Kod[14];
	char Muk_Ad[32];
	char Onay[13];
} TAKIP;

typedef struct ek_CEK_DETAYI {
	char Kayit_No[10];
	char Gun[4];
	char Durum[6];
	char Aciklama[20];
	char Tutar[15];
	long Para_Kutusu_Adresi;
} CEK_DETAYI;

typedef struct ek_KASA_DURUMU {
	char Lira[15];
	char Dolar[15];
	char Mark[15];
	char Cek[15];
	char Tablo[24];
} KASA_DURUMU;

typedef struct ek_ACILIS_DATA {
	char Mukellef_Kodu[13];
	char Hareket_Turu[13];
	char Unvan_Ad[39];
	char V_D[18];
	char V_N[18];
	char Oda_No[14];
	char Bag_Ol_Kurum[18];
	char Sicil_No[14];
	char Adres_1[39];
	char Adres_2[53];
	char Tel_1[15];
	char Tel_2[15];
	char Fax[15];
	char Cep_Tel[15];
	char Resmi_Aylik[14];
	char Gercek_Aylik[14];
	char Yetkili_Ad[32];
	char Yetkili_Gorevi[14];
	char Yetkili_Dahili[6];
	char Yetkili_Cep_Tel[32];
	char Yetkili_Email[32];
	char Devir_Borc[15];
	char Devir_Alacak[15];
	char Bakiye_Borc[15];
	char Bakiye_Alacak[15];
	char Tablo[12];
} ACILIS_DATA;

typedef struct ek_ACILIS_INDEKS {
	char Mukellef_Kodu[14];
	char Unvan_Ad[39];
} ACILIS_INDEKS;

typedef struct ek_PARA_KUTUSU {
	char Odeme_Turu[10];
	char Hareket_Turu[12];
	char Kayit_No[15];
	char Kayit_Tarihi[11];
	char Unvan[40];
	char Aciklama[40];
	char Odeme_Secenegi[9];
	char Tutar[15];
	char Cek_Sahibi[40];
	char Keside_Yeri[15];
	char Vadesi[11];
	char Banka_Sube[40];
	char Cek_No[12];
	char Hesap_No[13];
	char Defter_No[7];
	char Vade_Ayi[10];
	char Kur[15];
	char Kur_Cevirisi[15];
	long Mukellef_Adresi;
	long Cek_Adresi;
} PARA_KUTU;

typedef struct ek_PARA_INDEKS {
	char Kayit_No[15];
	char Kayit_Tarihi[11];
	char Unvan[40];
} PARA_INDEKS;
/*----------------------------------------------*/
/*--------------- Fonksiyonlar -------------------*/
void para_kayit_degistir(void);
void firmalar(void);
void parakutu_form_ayari(int durum);
void para_kayit_sil(void);
void acilis_goruntusu(void);
void hareket_listesi(DOSYA *handle);
void takip_kayit(void);
int aidat_kontrol(DOSYA *handle);
void acilis_kayit(DOSYA *handle);
void acilis_kayit_sil(DOSYA *handle);
void acilis_listesi(DOSYA *handle);
void islemler(void);
void raporlar(void);
void odemeler(void);
void ana_menu(void);
int aidat_tablosu(int Durum);
void odeme_secenegi_kontrol(void);
void para_ilk_kayit(void);
void detay_dosyasi_yarat(void);
void cek_kayit_degistir(long Cek_Yeri);
void cek_kayit_sil(long Cek_Yeri);
int cek_ilk_kayit(void);
void cek_detay_kontrol(void);
void detay_yapisi_doldur(DOSYA *handle);
int genel_kontrol(void);
void bakiye_gir(void);
void kayit_no_al(void);
void kasa_goruntusu(void);
void kasa_durumu(void);
void detay_listesi(void);
void musavir(void);
void uyari_gonder(int uyari);
void sifre(void);
char *ekran_giris(void);
void cek_tablosu(int ay, int durum);
void ekran_cikis(char *bellek);
void mesaj_goster_kac(char *string);
int menu_sec(char *veri, int satir, int kolon, int uzunluk, int eleman_referansi, char *depo_dizi);
void datamenu(void);
void arac(void);
void shiftf2(int referans);
void shiftf3(int referans);
void shiftf4(int referans);
void shiftf5(int referans);
void shiftf6(int referans);
void shiftf7(void);
void shiftf8(int referans);
void shiftf9(int referans);
void acilis_goruntusu(void);
void takip_goruntusu(void);
long liste_kutusu(int satir, int kolon, int baslangic, int boy, int en, int renk1, int renk2, DOSYA *handle);
void takip_kayit_cercevesi(int satir, int kolon, char *string);
void kayit_gir(DOSYA *handle);
char *takip_dosya_yap(char *string);
int dosya_sil(DOSYA *handle);
void takip_kayit_cercevesi(int satir, int kolon, char *string);
void dosya_yapisi_doldur(DOSYA *handle, char *yol);
int takip_dosya_kontrol(void);
void cek_detay_kontrol(void);

extern char *dataci;
extern seckin;
extern ACILIS_DATA *acilis_data; // ACILIS dosya gîstergesidir
extern ACILIS_INDEKS *acilis_indeks;
extern PARA_KUTU *para_data;
extern PARA_INDEKS *para_indeks;
extern char *tasiyici_pano;
extern long kayit_adresi;
extern int uyarici;
extern PENCERE pencere; /* Pencere Kontrollerini dÅzenler */
extern TABLO_BILGI baslik;
extern TABLO_FORM *tablo;
extern TAKIP *takip_data;

#define EKLE 	0
#define CIKAR	1
#define DEGISIKLIK 0
#define YENI	   1

/* -------------------------------------------------------------------------
						  BURO_V_1 Programçna Ait
					  örÅn Referans Kodlarç (c) 2000
 ------------------------------------------------------------------------- */

		/* MENULIST.MNU DOSYASINA (yani menulere ait) TANIMLAMA */
#define YMenu_MUSAVIR		1
#define	YMenu_ODEMELER		2
#define YMenu_RAPORLAR		3
#define YMenu_ISLEMLER		4
#define DMenu_ARAC			5
#define DMenu_DATAMENU		6
#define KMenu_TAKIP			7
#define KMenu_DATA_ISLEM	8
#define KMenu_AYLAR			9
#define KMenu_YILLAR	   10
#define KMenu_ACILIS	   11
#define KMenu_ISLEM_TURU   14
#define KMenu_ODEME_TURU   16

		/*---------- MENULIST.MNU ADLI TANIMLAMANIN SONU ---------*/

		   /* PENCERE DERECELERI ve TURLERINE AIT REFERANSLAR */
#define UST_DUZEY	0
#define DATA_FORM   1
#define ORTA_DUZEY  2
#define ALT_DUZEY   3
#define DUZEY		1 // Buradaki deßer Pencere_ozellißini attçrçp, eksiltir

		   /*-------------------------------------------------*/
						/*    DATA_MENU òûARETLERò     */
#define YENI_KAYIT 		"11000111"
#define KOPYALA_MODU    "00000010"
#define HEPSI_ACIK		"00000000"
						/*-----------------------------*/
							/*  Form Referanslarç */
#define Form_BOS					0000
#define Form_ACILIS					1000
#define Data_Acilis_Bilgisi			1100
#define Data_Acilis_Yetkili			1200
#define Data_Acilis_Devir			1300
#define Data_Acilis_Bakiye			1400
#define Data_Acilis_Tablo			1500
#define Form_IS_TAKIBI				2000
#define Data_IsTakip_Genel			2100
#define Data_IsTakip_Tablo			2200
#define Form_MUKELLEF_LISTESI		3000
#define Data_TekAlan				3100
#define Data_TumAlan				3200
#define Form_PARAMETRELER			4000
#define Data_Parametreler			4100
#define Form_PARA_KUTUSU			5000
#define Data_ParaKutusu_Genel		5100
#define Data_ParaKutusu_CekDetayi   5200
#define Data_ParaKutusu_CekTablosu	5300
#define Data_ParaKutusu_KasaDurumu	5400
#define Data_ParaKutusu_IndeksAdres	5500
#define Data_ParaKutusu_KurBilgisi	5600
#define Form_ODEME_LISTESI			6000
#define Data_OdemeListesi			6100
#define Form_KESINTI_LISTESI		7000
#define Data_KesintiListesi			7100
#define Form_BORCU_OLANLAR			8000
#define Data_BorcuOlanlar			8100
#define Form_ODEME_KARTI			9000
#define Data_OdemeKarti         	9100
#define Form_KULLANICI			   10000
#define Data_Kullanici			   10100
#define Form_FIRMA_AYARI	   	   11000
#define Data_FirmaAyari			   11100
#define Form_YAZICI			       12000
#define Data_Yazici				   12100
#define Form_DATA_ISLEMLERI	       13000
#define Data_DataIslm_Yedekleme	   13100
#define Data_DataIslm_Duzenleme	   13200
#define Data_DataIslm_Onarma	   13300
#define Data_DataIslm_Aktarma	   13400
#define Data_DataIslm_Devir		   13500
#define Form_DIGERLERI			   20000
#define Form_ARACLAR_MENU		   20001
#define Form_HESAP_MAKINESI		   20002
#define Form_NOTLAR				   20003
#define Form_MESAJLASMA			   20005
#define Data_DIGERLERI			   21000
#define Data_Indeks_Bilgisi    	   21001
#define Data_Bos_Referans          21002
							/*--------------------*/
#endif