#ifndef  _BURO_H_
#define  _BURO_H_
#include "/ozgan/programs/h/genel.h"
/*-------------------------------------------------------------------------
							 Fonksiyon Prototipleri
  -------------------------------------------------------------------------*/
void islemler(void);
void raporlar(void);
void odemeler(void);
void ana_menu(void);
void musavir(void);
void sifre(void);
/*-------------------------------------------------------------------------
						  Referans Kod Tançmlarç
  -------------------------------------------------------------------------*/
#define REF_MUSAVIR			010000
#define REF_M_ACILIS		010100
#define REF_M_A_YETKILI		010101
#define REF_M_ISTAKIBI    	010200
#define REF_M_AR_ARAMA		010201
#define REF_M_MUKELLEFLST 	010300
#define REF_ODEMELER		020000
#define REF_O_PARAKUTUSU	020100
#define REF_O_P_DETAY		020101
#define REF_O_ODEMELST		020200
#define REF_RAPORLAR		030000
#define REF_R_KESINTILST	030100
#define REF_R_BORCUOLAN		030200
#define REF_R_ODEMEKARTI	030300
/* Genel Referans Kodlarç */
#define REF_YARDIM			590000
#define REF_CIKIS			600000
#define REF_ARACLAR			610000
#define REF_A_HESAPMAK		610100
#define REF_A_NOTLAR		610200
#define REF_A_DATAISLM		610300
#define REF_A_MESAJ			610400
#define REF_DATAMENU		620000
#define REF_D_KAYDET		620100
#define REF_D_SIL			620200
#define REF_D_YENI			620300
#define REF_D_ARAMA			620400
#define REF_D_KOPYALA		620500
#define REF_D_YAPISTIR		620600
#define REF_D_CIKTI			620700
#define	REF_ISLEMLER		630000
#define REF_I_KULLANICI		630100
#define REF_I_FIRMAYAR		630200
#define REF_I_F_FIRMAAC		630201
#define REF_I_F_FIRMASIL	630202
#define REF_I_YAZICI		630300
#define REF_I_DATAISLM		630400
#define REF_MASAUSTU		640000
#endif
