/*
bilisim ve bilgisar fakültesi 
blisim sistemleri mühendisligi

bassar saraf b201200571 

pdp 2. odev 
luhn algoritmasi ve make file kullaniimi

*/
#include "Kontrol.h"

Kontrol KontrolOlustur(){
	Kontrol new;
	new = (Kontrol)malloc(sizeof(struct KONTROL));
	new->gecerliSayisi = 0;
	new->gecersizSayisi = 0;
	new->satirSirasi = 0;
	Dosya dosya = DosyaOlustur("sayilar.txt");
	new->satirlar = dosya->dosyaOku(dosya);
	new->satirSayisi = dosya->satirSayisi;
	dosya->dosyaKapat(dosya);

	new->kontrolBasla = &KontrolBasla;
	new->yikiciMetot = &YikiciMetot;

	return new;

}
int* RakamDizisiOlustur(const Kontrol this){

	char* satir = this->satirlar[this->satirSirasi];
	int* rakamlar = (int*)malloc(sizeof(int)*16);
	int index = 0;
	int index2 = 0;
	for(int i =0 ; i < 19 ; i++){
		if(satir[i] == ' '){

			continue;

		}
		rakamlar[index2] = satir[i] - '0' ;
		index2++;
	}
	this->satirSirasi++;
	return rakamlar;
}
int KontrolBasla(const Kontrol this){
	this->rakamlarDizisi = RakamDizisiOlustur(this);
	for(int i = 0 ; i < 16 ; i++){
		if( i % 4 == 0 && i != 0){
			printf(" %d",this->rakamlarDizisi[i]);
			continue;
		}
		printf("%d",this->rakamlarDizisi[i]);
	}
	int toplam = 0;

	for(int i = 15 ;i>=0 ; i-- ){
		if(i % 2 == 0){
			this->rakamlarDizisi[i]*= 2;
		}

	}
		for(int i = 15 ;i>=0 ; i-- ){
		if(this->rakamlarDizisi[i]>9){
			this->rakamlarDizisi[i]-=9;

		}

		toplam += this->rakamlarDizisi[i];
	}


	if(toplam % 10 == 0){
		this->gecerliSayisi++;

		printf("----Gecerli\n");
		return 1;
	}
	this->gecersizSayisi++;
	printf("----Gecersiz\n");
	return 0;
}
void YikiciMetot(Kontrol this){
	for(int i = 0 ; i < this->satirSayisi ; i++){
		free(this->satirlar[i]);
	}
	free(this->satirlar);
	free(this->rakamlarDizisi);
	free(this);
}
