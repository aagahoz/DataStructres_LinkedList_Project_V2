/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
 */

#include "YoneticiDugumListesi.hpp"
#include <iostream>
using namespace std;

YoneticiDugumListesi::YoneticiDugumListesi()
{
    this->ilk = NULL;
    this->yoneticiDugumSayisi = 0;
}

YoneticiDugumListesi::YoneticiDugumListesi(YoneticiDugum *ilk)
{
    this->ilk = ilk;
    this->yoneticiDugumSayisi = 1;
}

YoneticiDugumListesi::~YoneticiDugumListesi()
{}

void YoneticiDugumListesi::ekle(YoneticiDugum *yoneticiDugum)
{
    if (this->ilk == NULL)
    {
        this->ilk = yoneticiDugum;
        this->yoneticiDugumSayisi++;
    }
    else
    {
        YoneticiDugum *gecici = this->ilk;
        while (gecici->getSonraki() != NULL)
        {
            gecici = gecici->getSonraki();
        }
        gecici->setSonraki(yoneticiDugum);
        yoneticiDugum->setOnceki(gecici);
        this->yoneticiDugumSayisi++;
    }
}

void YoneticiDugumListesi::yazdir()
{
    cout << "YoneticiDugumListesi::yazdir()" << endl;
    YoneticiDugum *gecici = this->ilk;
    while (gecici != NULL)
    {
        cout << "Ortalama : " << gecici->getSatirListesi()->getOrtalama() << "  ";
        gecici->getSatirListesi()->yazdir();
        cout << endl;
        gecici = gecici->getSonraki();
    }
}

YoneticiDugum *YoneticiDugumListesi::getIlk()
{
    return this->ilk;
}
void YoneticiDugumListesi::setIlk(YoneticiDugum *ilk)
{
    this->ilk = ilk;
}

int YoneticiDugumListesi::getDugumSayisi()
{
    return this->yoneticiDugumSayisi;
}
void YoneticiDugumListesi::setDugumSayisi(int dugumSayisi)
{
    this->yoneticiDugumSayisi = dugumSayisi;
}

void YoneticiDugumListesi::siralaKucuktenBuyugeOrtalamayaGore()
{
    YoneticiDugum *gecici = this->ilk;

    while (gecici != NULL)
    {
        YoneticiDugum *gecici2 = gecici->getSonraki();
        while (gecici2 != NULL)
        {
            if (gecici->getSatirListesi()->getOrtalama() > gecici2->getSatirListesi()->getOrtalama())
            {
                // swap
                YoneticiDugum *gecici3 = new YoneticiDugum();
                gecici3->setSatirListesi(gecici->getSatirListesi());
                gecici->setSatirListesi(gecici2->getSatirListesi());
                gecici2->setSatirListesi(gecici3->getSatirListesi());
            }
            gecici2 = gecici2->getSonraki();
        }
        gecici = gecici->getSonraki();
    }
}

void YoneticiDugumListesi::dosyadanVerileriOkuVeListeyeEkle()
{
    ifstream dosyaOku;
    dosyaOku.open("veriler.txt");
    if (dosyaOku.is_open())
    {
        string okunanSatir;
        while(getline(dosyaOku, okunanSatir))
        {
            stringstream ss(okunanSatir);
            string okunanDeger;
            SatirDugumListesi *satirDugumListesi = new SatirDugumListesi();
            while(ss >> okunanDeger)
            {
                int sayi = atoi(okunanDeger.c_str());
                SatirDugum *satirDugum = new SatirDugum(sayi);
                satirDugumListesi->ekle(satirDugum);
            }           
            YoneticiDugum *yoneticiDugum = new YoneticiDugum(satirDugumListesi);
            this->ekle(yoneticiDugum);
        }
    }
    else
    {
        cout << "Dosya okunamadi." << endl;
    }
    siralaKucuktenBuyugeOrtalamayaGore();
}