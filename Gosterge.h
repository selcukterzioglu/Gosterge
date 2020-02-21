/*
    Kütüphane Adı   : Gosterge
    Yazar  		    : Selçuk TERZİOĞLU
    Yazım Tarihi    : 21.02.2020 (Güncelleme)
	Llink			: https://github.com/selcukterzioglu/Gosterge
    Açıklama        : Bu Kütüphane Sıcaklık Ölçüm uygulamalarında kullanılmak üzere ORTAK ANOT veya KATOT grup
					  7 segment göstergeleri kullanmak amacıyla yazılmıştır. Bu kütüphanedeki temel amaç 
					  öğrencilerin deney yapmasıdır.     
*/


#ifndef _GOSTERGE_h
#define _GOSTERGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define ORTAK_ANOT			1
#define ORTAK_KATOT 		0
#define ONDALIK_YOK			-1
#define OZEL_KARAKTER_YOK 	-1

#define DERECE				10
#define EKSI				11
#define D_NULL				12
#define C					13
#define T					14
#define SONA_EKLE			true
#define BASA_EKLE			false

class Gosterge
{
public:
/*
	Sınıfın constructor(yapıcı) fonksiyonudur. Gosterge nesnesi oluşturulduğunda otomatik olarak çalışır.	
*/
	Gosterge(int* segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu);

/*
	Göstergeyi güncellemek için kullanılan fonksiyondur. +2 overload fonksiyonu vardır.
	gostergeGuncelle(int data) : Ekrana data ile gönderilen sayı yazılır.
	gostergeGuncelle(int data, int ondalikSayisi) : Ekrana data ile gönderilen sayı yazılır ve ondalıkSayisi ile 
	belirtilen 7 segmentin ondalık işaretini aktif eder.
	gostergeGuncelle(int data, int ondalikSayisi, int ozelKarakter, boolean pozisyon) : Ekrana data ile gönderilen 
	sayı yazılır, ondalıkSayisi ile belirtilen 7 segmentin ondalık işaretini aktif eder istenilen DERECE, EKSI, C veya T
	işaretlerinden istenileni göstergenin başına veya sonuna ekler.
*/
	void gostergeGuncelle(int data);
	void gostergeGuncelle(int data, int ondalikSayisi);
	void gostergeGuncelle(int data, int ondalikSayisi, int ozelKarakter, boolean pozisyon);
private:
	int* _segmentler;
	int* _suruculer;
	int _displaySayisi;	
	boolean _ortakAnotMu;

	void gostergeGonder(uint8_t dispData);
	void rakamAyir(int data, int* rakamlar, int ondalik);

	//7 segment dönüşüm tablosu
	const uint8_t GOSTERGE_BILGISI[15][8] = {
	   //P,G,F,E,D,C,B,A
		{0,0,1,1,1,1,1,1},		//0
		{0,0,0,0,0,1,1,0},		//1
		{0,1,0,1,1,0,1,1},		//2
		{0,1,0,0,1,1,1,1},		//3
		{0,1,1,0,0,1,1,0},		//4
		{0,1,1,0,1,1,0,1},		//5
		{0,1,1,1,1,1,0,0},		//6
		{0,0,0,0,0,1,1,1},		//7
		{0,1,1,1,1,1,1,1},		//8
		{0,1,1,0,0,1,1,1},		//9
		{0,1,1,0,0,0,1,1},		//DERECE
		{0,1,0,0,0,0,0,0},		//EKSİ
		{0,0,0,0,0,0,0,0},		//KAPALI
		{0,0,1,1,1,0,0,1},		//C
		{0,1,1,1,1,0,0,0}		//T
	};
};
#endif
