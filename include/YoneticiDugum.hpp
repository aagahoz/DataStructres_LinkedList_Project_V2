/**
 * @file  YoneticiDugum.hpp
 * @description Baglı liste kullanarak satır satır okuma ve yazma işlemleri
 * @course  1.Öğretim A Grubu 
 * @assignment  1.Ödev
 * @date   20.11.2022
 * @author  Merva Banu Duman - Merva.duman@ogr.sakarya.edu.tr
 */

#ifndef YoneticiDugum_hpp
#define YoneticiDugum_hpp

#include "SatirDugumListesi.hpp"

class YoneticiDugum
{
public:
    YoneticiDugum();
    YoneticiDugum(SatirDugumListesi *satirListesi);
    ~YoneticiDugum();

    YoneticiDugum *getSonraki();
    void setSonraki(YoneticiDugum *sonraki);

    YoneticiDugum *getOnceki();
    void setOnceki(YoneticiDugum *onceki);

    SatirDugumListesi *getSatirListesi();
    void setSatirListesi(SatirDugumListesi *satirListesi);

private:
    YoneticiDugum *sonraki;
    YoneticiDugum *onceki;
    SatirDugumListesi *satirListesi;
};

#endif