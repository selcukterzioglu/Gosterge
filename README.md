# Gosterge
7 Segment çoklu displaylerin kolay kontrol edilebilmesi için hazırlanmış bir kütüphanedir.
Arduino ve arduino tabanlı sistemlerde çalışmaktadır.

* Gosterge(int* segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu):
	* Bu metod yapıcı metoddur ve gösterge nesnemizi oluşturur.
	* segmentler bir int dizisidir {DP,G,F,E,D,C,B,A}
	* suruculer bir int dizisidir {ANOT0, ANOT1......} 
	* displaySayisi : kaç tane display kontrol edilecek
	* ortakAnotMu : Bağlana göstergeler ortak anot mu ortak katot mu?

* gostergeGuncelle(int data, int ondalik); 
	* göstergeleri gunceller
	* Bu metod bir zamanlayıcı(timer) kesmesi ile 5msn aralıklarla çağrılmalıdır.

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
