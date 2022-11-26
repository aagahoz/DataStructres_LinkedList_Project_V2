#include "SatirDugumListesi.hpp"

SatirDugumListesi::SatirDugumListesi()
{
    this->ilk = NULL;
    this->dugumSayisi = 0;
}

SatirDugumListesi::SatirDugumListesi(SatirDugum *ilk)
{
    this->ilk = ilk;
    this->dugumSayisi = 1;
}

SatirDugumListesi::~SatirDugumListesi()
{
    // dtor
}

void SatirDugumListesi::ekle(SatirDugum *yeni)
{
    if (this->ilk == NULL)
    {
        this->ilk = yeni;
        this->dugumSayisi++;
    }
    else
    {
        SatirDugum *gecici = this->ilk;
        while (gecici->getSonraki() != NULL)
        {
            gecici = gecici->getSonraki();
        }
        gecici->setSonraki(yeni);
        this->dugumSayisi++;
    }
    ortalamaHesaplaVeGuncelle();
}

void SatirDugumListesi::yazdir()
{
    // cout << "Yazdiriliyor..." << endl;
    SatirDugum *gezici = this->ilk;
    if (gezici == NULL)
    {
        cout << "Liste bos!" << endl;
    }
    else
    {
        while (gezici != NULL)
        {
            cout << gezici->getVeri() << " ";
            gezici = gezici->getSonraki();
        }
    }
}

SatirDugum *SatirDugumListesi::getIlk()
{
    return this->ilk;
}
void SatirDugumListesi::setIlk(SatirDugum *ilk)
{
    this->ilk = ilk;
}

int SatirDugumListesi::getDugumSayisi()
{
    return this->dugumSayisi;
}
void SatirDugumListesi::setDugumSayisi(int dugumSayisi)
{
    this->dugumSayisi = dugumSayisi;
}

float SatirDugumListesi::getOrtalama()
{
    return this->ortalama;
}
void SatirDugumListesi::setOrtalama(float ortalama)
{
    this->ortalama = ortalama;
}

void SatirDugumListesi::ortalamaHesaplaVeGuncelle()
{
    float toplam = 0;
    SatirDugum *gezici = this->ilk;
    while (gezici != NULL)
    {
        toplam += gezici->getVeri();
        gezici = gezici->getSonraki();
    }
    this->ortalama = toplam / this->dugumSayisi;
}

