/*
bilisim ve bilgisar fakültesi 
blisim sistemleri mühendisligi

bassar saraf b201200571 

pdp 2. odev 
luhn algoritmasi ve make file kullaniimi

*/
#include "Dosya.h"

//private:

void SatirSayisiBul(Dosya this){ // satir sayisi bulup struct'a atiyor.
	int sayac = 0;
	FILE* dosya = fopen(this->dosyaYolu, "r");
	char satir[256];

	while (fgets(satir, sizeof(satir), dosya)) 
		sayac++;
	
	fclose(dosya);
	this->satirSayisi = sayac;
}

//public:

Dosya DosyaOlustur(char* yol){
	Dosya this;
	this =(Dosya) malloc(sizeof(struct DOSYA));
	this->dosyaYolu = yol;
	SatirSayisiBul(this);
	
	this->dosyaOku = &DosyaOku;
	this->dosyaKapat = &DosyaKapat;
	return this;
	
}

char** DosyaOku(Dosya this){//dosyayi okuyup satirlari dizi halinde donduruyor.

	FILE* dosya = fopen(this->dosyaYolu, "r");
	char satir[256];
	char ** satirlar = (char**)malloc(sizeof(char*)*this->satirSayisi);
	int i = 0;
	while (fgets(satir, sizeof(satir), dosya)) {
			satirlar[i] = strdup(satir);
			i++;
	}

	fclose(dosya);
	return satirlar; // bu fonksiyondan olusan copler programci tarafindan silinmesi lazim.
}

void DosyaKapat(Dosya this){
	free(this);
}
