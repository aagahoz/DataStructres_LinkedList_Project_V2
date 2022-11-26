/**
 * @file  YoneticiDugumListesi.hpp
 * @description Baglı liste kullanarak satır satır okuma ve yazma işlemleri
 * @course  1.Öğretim A Grubu 
 * @assignment  1.Ödev
 * @date   20.11.2022
 * @author  Merva Banu Duman - Merva.duman@ogr.sakarya.edu.tr
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