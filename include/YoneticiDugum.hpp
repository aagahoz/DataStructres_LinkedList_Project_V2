/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
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