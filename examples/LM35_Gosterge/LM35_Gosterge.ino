#include <Gosterge.h>
#include <TimerOne.h>

int segmentler[] = { 8, 10, 4, 6, 7, 9, 3, 5 };
int anotlar[] = { 13, 12, 11, 14 }; //01
int displaySayisi = 4;

Gosterge gosterge(segmentler, anotlar, displaySayisi, ORTAK_ANOT);

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(5000);
  Timer1.attachInterrupt(timer1Kesmesi, 5000);
  analogReference(INTERNAL);            //internal 1.1V analog referans
}

int _sicaklik = 0, sicaklik = 0;
void loop() {
  // put your main code here, to run repeatedly:
  //int data = analogRead(1);
  //float mv = data * 0.48828125;
  //sicaklik = mv * 10;
  //sicaklik += _sicaklik;
  //sicaklik /= 2;
  //_sicaklik = sicaklik;
  //delay(2000);
}

int yuvarla(int data) {
  int birler = data % 10;
  if (birler<3)
    data -= birler;
  else if (birler>2 && birler<7) {
    data -= birler;
    data += 5;
  }
  else {
    data -= birler;
    data += 10;
  }

  return data;
}

void timer1Kesmesi() {
  static int timerSay = 0;
  static int temp = 0;
  sicaklik = analogRead(1);
  _sicaklik = (sicaklik + _sicaklik) / 2;
  if (timerSay == 0) {
    float tmv = 0.107421875 * _sicaklik;
    temp = tmv * 10;
    temp = yuvarla(temp);
    temp *= 10;
  }
  timerSay++;
  if (timerSay > 1000)
    timerSay = 0;
  gosterge.gostergeGuncelle(temp, 2,DERECE,SONA_EKLE);
}
