#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iostream>

#include "SatirDugum.hpp"
#include "SatirDugumListesi.hpp"
#include "YoneticiDugum.hpp"
#include "YoneticiDugumListesi.hpp"

using namespace std;

int main()
{
     SatirDugumListesi *liste1 = new SatirDugumListesi();

     SatirDugum *ilk = new SatirDugum(11);
     SatirDugum *ikinci = new SatirDugum(21);
     SatirDugum *ucuncu = new SatirDugum(3);
     SatirDugum *dorduncu = new SatirDugum(4);


     liste1->ekle(ilk);
     liste1->ekle(ikinci);
     liste1->ekle(ucuncu);
     liste1->ekle(dorduncu);
     cout << "Ortalama: " << liste1->getOrtalama() << endl;

     SatirDugumListesi *liste2 = new SatirDugumListesi();
     liste2->ekle(new SatirDugum(3));
     liste2->ekle(new SatirDugum(4));



     YoneticiDugumListesi *yoneticiListesi = new YoneticiDugumListesi();
     YoneticiDugum *yoneticiDugum1 = new YoneticiDugum(liste1);
     YoneticiDugum *yoneticiDugum2 = new YoneticiDugum(liste2);

     yoneticiListesi->ekle(yoneticiDugum1);
     yoneticiListesi->ekle(yoneticiDugum2);
     cout << "Ortalama: " << liste1->getOrtalama() << endl;

     yoneticiListesi->yazdir();

     yoneticiListesi->siralaKucuktenBuyugeOrtalamayaGore();

     yoneticiListesi->yazdir();

     return 0;
}
