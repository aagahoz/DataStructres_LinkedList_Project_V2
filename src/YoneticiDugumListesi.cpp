/**
 * @file  YoneticiDugumListesi.cpp
 * @description Baglı liste kullanarak satır satır okuma ve yazma işlemleri
 * @course  1.Öğretim A Grubu 
 * @assignment  1.Ödev
 * @date   20.11.2022
 * @author  Merva Banu Duman - Merva.duman@ogr.sakarya.edu.tr
 */

#include "YoneticiDugumListesi.hpp"
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
{
}

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
    int index = 0;
    while (gecici != NULL)
    {
        cout << "Ortalama  " << index << " : " << gecici->getSatirListesi()->getOrtalama() << "  ";
        gecici->getSatirListesi()->yazdir();
        cout << endl;
        gecici = gecici->getSonraki();
        index++;
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
    dosyaOku.open("..\\veriler.txt");
    if (dosyaOku.is_open())
    {
        string okunanSatir;
        while (getline(dosyaOku, okunanSatir))
        {
            stringstream ss(okunanSatir);
            string okunanDeger;
            SatirDugumListesi *satirDugumListesi = new SatirDugumListesi();
            while (ss >> okunanDeger)
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

ostream &operator<<(ostream &out, const YoneticiDugumListesi &yoneticiDugumListesi)
{
    YoneticiDugum *gecici = yoneticiDugumListesi.ilk;
    while (gecici != NULL)
    {
        out << setw(15) << "Ortalama : " << setw(3) << gecici->getSatirListesi()->getOrtalama() << setw(10) << "   ";
        gecici->getSatirListesi()->yazdir();
        out << endl;
        gecici = gecici->getSonraki();
    }
    return out;
}

YoneticiDugum *YoneticiDugumListesi::dugumGetir(int index)
{
    YoneticiDugum *gecici = this->ilk;
    int sayac = 0;
    while (gecici != NULL)
    {
        if (sayac == index)
        {
            return gecici;
        }
        sayac++;
        gecici = gecici->getSonraki();
    }
    return NULL;
}

void YoneticiDugumListesi::menu()
{
    int consolSayfaIndexi = 0;
    int maxconsolSayfaIndexi = (this->yoneticiDugumSayisi - 1) / 8;
    int sonSayfaDugumSayisi = (this->yoneticiDugumSayisi) % 8;

    int sayfaSatirIndexi = 0;

    char secim;

    while (true)
    {
        cout << ": ";
        cin >> secim;

        system("cls");

        if (secim == 'd')
        {
            if (consolSayfaIndexi < maxconsolSayfaIndexi)
            {
                consolSayfaIndexi++;
                sayfaSatirIndexi = 0;
            }
        }
        else if (secim == 'a')
        {
            if (consolSayfaIndexi > 0)
            {
                consolSayfaIndexi--;
                sayfaSatirIndexi = 0;
            }
        }
        else if (secim == 'z')
        {
            if (sayfaSatirIndexi > 0)
            {
                sayfaSatirIndexi--;
            }
        }
        else if (secim == 'c')
        {
            if (consolSayfaIndexi == maxconsolSayfaIndexi)
            {
                if (sayfaSatirIndexi < sonSayfaDugumSayisi - 1)
                {
                    sayfaSatirIndexi++;
                }
            }
            else
            {
                if (sayfaSatirIndexi < 7)
                {
                    sayfaSatirIndexi++;
                }
            }
        }
        else if (secim == 'p')
        {
        }
        else if (secim == 'k')
        {
        }
        else
        {
            cout << "Hatali Secim" << endl;
        }

        yazdirConsoleYonetici(consolSayfaIndexi, maxconsolSayfaIndexi, sayfaSatirIndexi);
        // cout << "Sayfa : " << consolSayfaIndexi + 1 << "/" << maxconsolSayfaIndexi + 1 << endl;
        // cout << "Son Sayfa Dugum Sayisi : " << sonSayfaDugumSayisi << endl;
        cout << endl;
    }
}

void YoneticiDugumListesi::yazdirConsoleYonetici(int consolSayfaIndexi, int maxconsolSayfaIndexi, int sayfaSatirIndexi)
{
    YoneticiDugum *gecici = dugumGetir(consolSayfaIndexi * 8);
    SatirDugum *satirDugumListesi = gecici->getSatirListesi()->getIlk();

    cout << endl;

    if (consolSayfaIndexi == 0 && maxconsolSayfaIndexi == 0)
    {
        cout << "   ilk";
        cout << "                                                                                                                          ";
        cout << "   son";
        cout << endl;
    }
    else if (consolSayfaIndexi == 0)
    {
        cout << "   ilk";
        cout << "                                                                                                                          ";
        cout << "-->";
        cout << endl;
    }
    else if (consolSayfaIndexi == maxconsolSayfaIndexi)
    {
        cout << "   <--";
        cout << "                                                                                                                          ";
        cout << "son";
        cout << endl;
    }
    else
    {
        cout << "   <--";
        cout << "                                                                                                                          ";
        cout << "-->";
        cout << endl;
    }
    cout << endl;


    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {

            cout << setw(14) << gecici << setw(3) << "    ";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici << setw(3) << "    ";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "----------" << setw(3) << "   ";
        }
        cout << endl;
    }

    gecici = dugumGetir(consolSayfaIndexi * 8);
    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {

            cout << setw(6) << "|" << setw(8) << gecici->getOnceki() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(6) << "|" << setw(8) << gecici->getOnceki() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "----------" << setw(3) << "   ";
        }
        cout << endl;
    }

    gecici = dugumGetir(consolSayfaIndexi * 8);
    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(6) << "|" << setw(8) << gecici->getSatirListesi()->getOrtalama() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(6) << "|" << setw(8) << gecici->getSatirListesi()->getOrtalama() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    gecici = dugumGetir(consolSayfaIndexi * 8);
    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(6) << "|" << setw(8) << gecici->getSonraki() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(6) << "|" << setw(8) << gecici->getSonraki() << "|" << setw(3) << "";
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    cout << endl;

    gecici = dugumGetir(consolSayfaIndexi * 8 + sayfaSatirIndexi);

    SatirDugumListesi *geciciSatirListesi = gecici->getSatirListesi();
    yazdirConsoleSatir(geciciSatirListesi, sayfaSatirIndexi);
}

void YoneticiDugumListesi::yazdirConsoleSatir(SatirDugumListesi *satirListesi, int satirIndexi)
{
    SatirDugum *gecici = satirListesi->getIlk();
    // cout << "Satir : " << satirIndexi << endl;

    cout << "     " << setw(satirIndexi * 18) << ""<< "^^^^^^^^^^" << endl;
    while (gecici != NULL)
    {
        cout << endl;
        cout << "      " << setw(satirIndexi * 18) << ""<< gecici << endl;
        cout << "     " << setw(satirIndexi * 18) << ""<< "----------" << endl;
        cout << "     " << setw(satirIndexi * 18) << ""<< "|" << "" << setw(5) << gecici->getVeri() << setw(4) << "|" << endl;
        cout << "     " << setw(satirIndexi * 18) << ""<< "----------" << endl;
        cout << "     " << setw(satirIndexi * 18) << ""<< "|" << "" << setw(5) << gecici->getSonraki() << setw(1) << "|" << endl;
        cout << "     " << setw(satirIndexi * 18) << ""<< "----------" << endl;
        cout << endl;

        gecici = gecici->getSonraki();
    }
}