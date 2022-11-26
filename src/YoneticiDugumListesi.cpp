/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
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
            cout << "d secildi" << endl;
            if (consolSayfaIndexi < maxconsolSayfaIndexi)
            {
                consolSayfaIndexi++;
                sayfaSatirIndexi = 0;
            }
        }
        else if (secim == 'a')
        {
            cout << "a secildi" << endl;
            if (consolSayfaIndexi > 0)
            {
                consolSayfaIndexi--;
                sayfaSatirIndexi = 0;
            }
        }
        else if (secim == 'z')
        {
            cout << "z secildi" << endl;
            if (sayfaSatirIndexi > 0)
            {
                sayfaSatirIndexi--;
            }
        }
        else if (secim == 'c')
        {
            cout << "c secildi" << endl;
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
            cout << "c secildi" << endl;
        }
        else if (secim == 'k')
        {
            cout << "c secildi" << endl;
        }
        else
        {
            cout << "Hatali Secim" << endl;
        }

        yazdirConsole(consolSayfaIndexi, maxconsolSayfaIndexi, sayfaSatirIndexi);
        cout << "Sayfa : " << consolSayfaIndexi + 1 << "/" << maxconsolSayfaIndexi + 1 << endl;
        cout << "Son Sayfa Dugum Sayisi : " << sonSayfaDugumSayisi << endl;
        cout << endl;
    }
}

void YoneticiDugumListesi::yazdirConsole(int consolSayfaIndexi, int maxconsolSayfaIndexi, int sayfaSatirIndexi)
{
    cout << "-------------------------------" << endl;
    cout << "Sayfa satir indexi : " << sayfaSatirIndexi << endl;
    YoneticiDugum *gecici = dugumGetir(consolSayfaIndexi * 8);
    SatirDugum *satirDugumListesi = gecici->getSatirListesi()->getIlk();

    // cout << gecici->getSatirListesi()->getOrtalama() << endl;

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {

            cout << setw(14) << gecici << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

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
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {

            cout << setw(14) << gecici->getOnceki() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici->getOnceki() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

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
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici->getSatirListesi()->getOrtalama() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici->getSatirListesi()->getOrtalama() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

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
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici->getSonraki() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(14) << gecici->getSonraki() << setw(3) << "    ";
            // gecici->getSatirListesi()->yazdir();
            gecici = gecici->getSonraki();
        }
        cout << endl;
    }

    if (maxconsolSayfaIndexi == consolSayfaIndexi)
    {
        int bastirilacakAdet = (this->yoneticiDugumSayisi) % 8;
        // cout << "Son sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "-----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    else
    {
        int bastirilacakAdet = 8;
        // cout << "Orta sayfa : " << bastirilacakAdet << endl;

        for (int i = 0; i < bastirilacakAdet; i++)
        {
            cout << setw(15) << "----------" << setw(3) << "   ";
        }
        cout << endl;
    }
    cout << endl;
}
