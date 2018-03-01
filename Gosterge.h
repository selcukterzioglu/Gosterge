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

class Gosterge
{
public:


	Gosterge(int* segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu);
	void gostergeGuncelle(int data);
	void gostergeGuncelle(int data, int ondalikSayisi);

private:
	int* _segmentler;
	int* _suruculer;
	int _displaySayisi;
	boolean _ortakAnotMu;

	void gostergeGonder(uint8_t dispData);
	void rakamAyir(int data, int* rakamlar);

	const uint8_t GOSTERGE_BILGISI[10][8] = {
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
		{0,1,1,0,0,1,1,1}		//9
	};

};

#endif

