# Gosterge
7 Segment çoklu displaylerin kolay kontrol edilebilmesi için hazırlanmış bir kütüphanedir.
Arduino ve arduino tabanlı sistemlerde çalışmaktadır.

* Gosterge(int* segmentler, int* suruculer, int displaySayisi, boolean ortakAnotMu):
	Bu metod yapıcı metoddur ve gösterge nesnemizi oluşturur.
	segmentler bir int dizisidir {DP,G,F,E,D,C,B,A}
	suruculer bir int dizisidir {ANOT0, ANOT1......} 
	displaySayisi : kaç tane display kontrol edilecek
	ortakAnotMu : Bağlana göstergeler ortak anot mu ortak katot mu?

* gostergeGuncelle(int data, int ondalik); göstergeleri gunceller
