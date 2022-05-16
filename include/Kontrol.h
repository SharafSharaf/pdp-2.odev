#ifndef KONTROL_H
#define KONTROL_H

#include "Dosya.h"

struct KONTROL{
	int gecerliSayisi;
	int gecersizSayisi;
	int *rakamlarDizisi;
	int satirSirasi;
	int satirSayisi;
	char** satirlar;
	
	int (*kontrolBasla)(struct KONTROL* );
	void (*yikiciMetot)(struct KONTROL* );
	
	
};
typedef struct KONTROL* Kontrol;

Kontrol KontrolOlustur();
int* RakamDizisiOlustur(const Kontrol);
int KontrolBasla(const Kontrol);
void YikiciMetot(Kontrol);


#endif