// Gosterge.h
// 01.03.2018
// Ortak anot/katod çoklu gösterge sürücü kütüphanesi
// Selçuk TERZİOĞLU @strz35
// Elektronik Öğretmeni
// <strz35@hotmail.com.tr>

#ifndef _GOSTERGE_h
#define _GOSTERGE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#define ORTAK_ANOT	1
#define ORTAK_KATOT 0
#define ONDALIK_YOK	-1
#define OZEL_KARAKTER_YOK -1

#define DERECE		10
#define EKSI		11
#define D_NULL		12
#define S		13
#define H		14
#define SONA_EKLE	true
#define BASA_EKLE	false

class Gosterge
{
public:
	Gosterge(int* segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu);
	void gostergeGuncelle(int data);
	void gostergeGuncelle(int data, int ondalikSayisi);
	void gostergeGuncelle(int data, int ondalikSayisi, int ozelKarakter, boolean pozisyon);
private:
	int* _segmentler;
	int* _suruculer;
	int _displaySayisi;
	boolean _ortakAnotMu;

	void gostergeGonder(uint8_t dispData);
	void rakamAyir(int data, int* rakamlar);
	void sifiriKaldir(int* rakamlar, int ondalikSayisi);

	const uint8_t GOSTERGE_BILGISI[13][8] = {
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
		{1,1,1,0,1,1,0,1},		//S
		{1,1,1,1,0,1,1,0}		//H
	};
};
#endif
