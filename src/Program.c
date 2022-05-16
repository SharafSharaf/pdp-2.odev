/*
bilisim ve bilgisar fakültesi 
blisim sistemleri mühendisligi

bassar saraf b201200571 

pdp 2. odev 
luhn algoritmasi ve make file kullaniimi

*/
#include "Kontrol.h"


int main(){
	Kontrol k = KontrolOlustur();
	
	for(int i = 0 ; i <k->satirSayisi ; i++){
		k->kontrolBasla(k);
		printf("\n");
	}
	/*k->yikiciMetot(k);*/
	return 0;
}
