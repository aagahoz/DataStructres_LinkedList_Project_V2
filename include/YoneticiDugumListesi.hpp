/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
 */

#ifndef YoneticiDugumListesi_hpp
#define YoneticiDugumListesi_hpp

#include "YoneticiDugum.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

class YoneticiDugumListesi
{
public:
    YoneticiDugumListesi();
    YoneticiDugumListesi(YoneticiDugum *ilk);
    ~YoneticiDugumListesi();

    void ekle(YoneticiDugum *yoneticiDugum);
    void yazdir();

    YoneticiDugum *getIlk();
    void setIlk(YoneticiDugum *ilk);

    int getDugumSayisi();
    void setDugumSayisi(int dugumSayisi);

    void siralaKucuktenBuyugeOrtalamayaGore();

    void dosyadanVerileriOkuVeListeyeEkle();

    friend ostream &operator<<(ostream &out, const YoneticiDugumListesi &ydl);

    void menu();

    void yazdirConsoleYonetici(int consolSayfaIndexi, int maxconsolSayfaIndexi, int sayfaSatirIndexi);
    void yazdirConsoleSatir(SatirDugumListesi *satirListesi, int satirIndexi);
    
    YoneticiDugum *dugumGetir(int index);
private:
    YoneticiDugum *ilk;
    int yoneticiDugumSayisi;
};

#endif