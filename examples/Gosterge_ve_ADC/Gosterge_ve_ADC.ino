#include <Gosterge.h>
#include <TimerOne.h>
/*
        A
      ─────   
    F|  G  |B  
      ─────   
    D|     |C  
      ─────   .DP
        C
     Segment bağlantıları (DP display Nokta)
     DP=9, G=8, F=7, E=6, D=5, C=4, B=3, A=2     
     
     ────    ────    ────
    |    |  |    |  |    |
     ────    ────    ────  .........
    |    |  |    |  |    |
     ────    ────    ────
     Anot0   Anot1   Anot2 .........

 */
int segmentler[]={9,8,7,6,5,4,3,2};
int anotlar[]={10,11,12};
int displaySayisi = 3;

Gosterge gosterge(segmentler, anotlar, displaySayisi, ORTAK_ANOT);

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize(5000);
  Timer1.attachInterrupt(timer1Kesmesi,5000);
}

int adcData;

void loop() {
  // put your main code here, to run repeatedly:
  adcData = analogRead(0);
  delay(500);
}

void timer1Kesmesi(){
  gosterge.gostergeGuncelle(adcData);
}

