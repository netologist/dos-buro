void cek_detay_olustur(void)
{
	char veri[150];
	TABLO_BILGI baslikci = {5, 50, Form_PARA_KUTUSU, 0};
	TABLO_FORM tablocu[] = { {Data_ParaKutusu_CekDetayi, YAZI, 6, 4, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 8, 5, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, YAZI, 6, 14, 19, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_CekDetayi, SAYI, 6, 35, 14, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Indeks_Bilgisi, SONRA},
							 {Data_ParaKutusu_Genel, SAYI, 3, 38, 3, BEYAZ_ | A_BEYAZ, BEYAZ_ | GRI, Data_Bos_Referans, SONRA}
						   };
}

void cek_detay_kontrol(void)
{
	FILE *fp;
	char depo[5], birlesen[100];
	char *dosya = "pk_cd_00.dat";
	char *yol = "data/";

	memset(depo, 0, 5);

	strncpy(depo, &para_data->Vadesi[2], 2);
	strncpy(&dosya[6], depo, 2);

	yol_yapici(yol, dosya, birlesen);
	if ((fp = _fsopen(birlesen, "rb", SH_DENYNO)) == NULL) {
		msj_kutu(dosya, HATA_DOSYA_BULUNAMADI, HATA);
		exit(1);
	}

	fclose(fp);
}

void cek_kayit_gir(void)
{
	DOSYA handle;
	CEK_DETAYI veri;

	handle.tablo = tabloyukle("bin/cekdetay.tbl", &handle.baslik);



	cek_yapisi_olustur(&handle);
	if (kayit_adresi == 0)
		dosya_kayit(&handle);
}
