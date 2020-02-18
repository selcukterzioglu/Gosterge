// 01.03.2018
// Ortak anot/katod çoklu gösterge sürücü kütüphanesi
// Selçuk TERZİOĞLU @strz35
// Elektronik Öğretmeni
// <strz35@hotmail.com.tr>

#include "Gosterge.h"

Gosterge::Gosterge(int * segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu)
{
	_segmentler = segmentler;
	_suruculer = suruculer;
	_displaySayisi = displaySayisi;
	_ortakAnotMu = ortakAnotMu;
	for (int i = 0; i < 8; i++)
		pinMode(_segmentler[i], OUTPUT);
	for (int i = 0; i < _displaySayisi; i++)
		pinMode(_suruculer[i], OUTPUT);
}

void Gosterge::gostergeGuncelle(int data)
{
	static int display = 0;
	if (display > _displaySayisi-1)
		display = 0;
	for (int i = 0; i < _displaySayisi; i++) {
		digitalWrite(_suruculer[i], LOW ^_ortakAnotMu);
	}
	int rakam[8];
	rakamAyir(data, rakam);
	gostergeGonder(rakam[display]);
	digitalWrite(_suruculer[display], HIGH ^ _ortakAnotMu);
	display++;
}

void Gosterge::gostergeGuncelle(int data, int ondalikSayisi)
{
	static int display = 0;
	if (display > _displaySayisi-1)
		display = 0;
	for (int i = 0; i < _displaySayisi; i++) {
		digitalWrite(_suruculer[i], LOW ^_ortakAnotMu);
	}
	int rakam[8];
	rakamAyir(data, rakam);
	if(rakam[ondalikSayisi] == D_NULL)
		rakam[ondalikSayisi] == 0;
	gostergeGonder(rakam[display]);
	if ((_displaySayisi - ondalikSayisi - 1) == display)
		digitalWrite(_segmentler[0], HIGH ^ _ortakAnotMu);
	else
		digitalWrite(_segmentler[0], LOW ^ _ortakAnotMu);
	digitalWrite(_suruculer[display], HIGH ^ _ortakAnotMu);
	display++;
}

void Gosterge::gostergeGuncelle(int data, int ondalikSayisi, int ozelKarakter, boolean pozisyon)
{
	static int display = 0;
	if (display > _displaySayisi - 1)
		display = 0;
	for (int i = 0; i < _displaySayisi; i++) {
		digitalWrite(_suruculer[i], LOW ^_ortakAnotMu);
	}
	int rakam[8];
	rakamAyir(data, rakam);
	if(rakam[ondalikSayisi] == D_NULL)
		rakam[ondalikSayisi] == 0;
	if (pozisyon == BASA_EKLE)
		rakam[0] = ozelKarakter;
	else
		rakam[_displaySayisi - 1] = ozelKarakter;
	gostergeGonder(rakam[display]);
	if ((_displaySayisi - ondalikSayisi - 1) == display)
		digitalWrite(_segmentler[0], HIGH ^ _ortakAnotMu);
	else
		digitalWrite(_segmentler[0], LOW ^ _ortakAnotMu);
	digitalWrite(_suruculer[display], HIGH ^ _ortakAnotMu);
	display++;
}

void Gosterge::gostergeGonder(uint8_t dispData)
{
	for (int i = 0; i < 8; i++) {
		digitalWrite(_segmentler[i], GOSTERGE_BILGISI[dispData][i] ^ _ortakAnotMu);
	}
}

void Gosterge::rakamAyir(int data,int * rakamlar)
{
	int temp = data;
	int dispSay = _displaySayisi - 1;
	for (int i = 0; i < _displaySayisi; i++) {
		if (temp < 1) {
			rakamlar[_displaySayisi - i - 1] = 0;
		}
		else {
			rakamlar[_displaySayisi - i-1] = temp % 10;
			temp -= rakamlar[_displaySayisi - i-1];
			temp /= 10;
		}		
	}
	if(data >= 0){
		if(data < 10){
			rakamlar[0] = D_NULL;
			rakamlar[1] = D_NULL;
			rakamlar[2] = D_NULL;
		} else if(data <100 ) {
			rakamlar[0] = D_NULL;
			rakamlar[1] = D_NULL;
		} else if(data < 1000) {
			rakamlar[0] = D_NULL;
		}
	} else {
		if(data > -10){
			rakamlar[0] = D_NULL;
			rakamlar[1] = D_NULL;
			rakamlar[2] = D_NULL;
		} else if(data > -100 ) {
			rakamlar[0] = D_NULL;
			rakamlar[1] = D_NULL;
		} else if(data >- 1000) {
			rakamlar[0] = D_NULL;
		}
	}
}
