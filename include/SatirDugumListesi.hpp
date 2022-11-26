#ifndef SatirDugumListesi_hpp
#define SatirDugumListesi_hpp

#include <iostream>
#include <fstream>
#include "SatirDugum.hpp"
using namespace std;

class SatirDugumListesi // has satırDugums and methods to manipulate them
{
public:
    SatirDugumListesi();
    SatirDugumListesi(SatirDugum *ilk);
    ~SatirDugumListesi();

    void ekle(SatirDugum *yeni);

    void yazdir();

    SatirDugum *getIlk();
    void setIlk(SatirDugum *ilk);

    SatirDugum *getSon();
    void setSon(SatirDugum *son);

    int getDugumSayisi();
    void setDugumSayisi(int dugumSayisi);

    float getOrtalama();
    void setOrtalama(float ortalama);

    void ortalamaHesaplaVeGuncelle();
private:
    SatirDugum *ilk;
    int dugumSayisi;
    float ortalama;
};

#endif