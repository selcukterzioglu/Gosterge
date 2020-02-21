/*
    Kütüphane Adı   : Gosterge
    Yazar  		    : Selçuk TERZİOĞLU
    Yazım Tarihi    : 21.02.2020 (Güncelleme)
	Llink			: https://github.com/selcukterzioglu/Gosterge
    Açıklama        : Bu Kütüphane Sıcaklık Ölçüm uygulamalarında kullanılmak üzere ORTAK ANOT veya KATOT grup
					  7 segment göstergeleri kullanmak amacıyla yazılmıştır. Bu kütüphanedeki temel amaç 
					  öğrencilerin deney yapmasıdır.     
*/


#include "Gosterge.h"

/*
	Sınıfın constructor(yapıcı) fonksiyonudur. Gosterge nesnesi oluşturulduğunda otomatik olarak çalışır.	
*/
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

/*
	Göstergeyi güncellemek için kullanılan fonksiyondur. +2 overload fonksiyonu vardır.
	gostergeGuncelle(int data) : Ekrana data ile gönderilen sayı yazılır.
	gostergeGuncelle(int data, int ondalikSayisi) : Ekrana data ile gönderilen sayı yazılır ve ondalıkSayisi ile 
	belirtilen 7 segmentin ondalık işaretini aktif eder.
	gostergeGuncelle(int data, int ondalikSayisi, int ozelKarakter, boolean pozisyon) : Ekrana data ile gönderilen 
	sayı yazılır, ondalıkSayisi ile belirtilen 7 segmentin ondalık işaretini aktif eder istenilen DERECE, EKSI, C veya T
	işaretlerinden istenileni göstergenin başına veya sonuna ekler.
*/
void Gosterge::gostergeGuncelle(int data)
{
	static int display = 0;
	if (display > _displaySayisi-1)
		display = 0;
	for (int i = 0; i < _displaySayisi; i++) {
		digitalWrite(_suruculer[i], LOW ^_ortakAnotMu);
	}
	int rakam[8];
	rakamAyir(data, rakam, ONDALIK_YOK);
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
	rakamAyir(data, rakam, ondalikSayisi);
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
	rakamAyir(data, rakam, ondalikSayisi);
	if (pozisyon == BASA_EKLE)
		rakam[0] = ozelKarakter;
	else{
		for(int i=0;i<_displaySayisi-1;i++){
			rakam[i]=rakam[i+1];
		}
		rakam[_displaySayisi - 1] = ozelKarakter;
	}
	gostergeGonder(rakam[display]);
	if ((_displaySayisi - ondalikSayisi - 1) == display)
		digitalWrite(_segmentler[0], HIGH ^ _ortakAnotMu);
	else
		digitalWrite(_segmentler[0], LOW ^ _ortakAnotMu);
	digitalWrite(_suruculer[display], HIGH ^ _ortakAnotMu);
	display++;
}

/*
	Göstegeye aktif segment bilgilerini yazar.
*/
void Gosterge::gostergeGonder(uint8_t dispData)
{
	for (int i = 0; i < 8; i++) {
		digitalWrite(_segmentler[i], GOSTERGE_BILGISI[dispData][i] ^ _ortakAnotMu);
	}
}

/*
	Göstergede gösterilecek veriyi rakamlarına ayırır.
*/
void Gosterge::rakamAyir(int data,int * rakamlar, int ondalik)
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
	//Göstergede başta 0 görülmesinin istemiyoruz. Bu sebeple sıfırları kaldırıyoruz.
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
	if(ondalik != ONDALIK_YOK){
		if(rakamlar[ondalik+1] == D_NULL){
			rakamlar[ondalik+1] = 0;
		}
	}
}