#ifndef DOSYA_H
#define DOSYA_H

#include"stdio.h"
#include "stdlib.h"
#include "string.h"
struct DOSYA{
	char* dosyaYolu;	
	int satirSayisi;
	
	char** (*dosyaOku)(struct DOSYA*);
	void (*dosyaKapat)(struct DOSYA*);
};
typedef struct DOSYA* Dosya;

Dosya DosyaOlustur(char*);
char** DosyaOku(const Dosya);
void DosyaKapat(Dosya);
#endif