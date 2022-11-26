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
private:
    YoneticiDugum *ilk;
    int yoneticiDugumSayisi;
};

#endif