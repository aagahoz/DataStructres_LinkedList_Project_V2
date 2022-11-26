/**
 * @file  SatirDugumListesi.hpp
 * @description Baglı liste kullanarak satır satır okuma ve yazma işlemleri
 * @course  1.Öğretim A Grubu 
 * @assignment  1.Ödev
 * @date   20.11.2022
 * @author  Merva Banu Duman - Merva.duman@ogr.sakarya.edu.tr
 */

#ifndef SatirDugum_hpp
#define SatirDugum_hpp

class SatirDugum
{
public:
    SatirDugum();
    SatirDugum(int veri);
    ~SatirDugum();

    int getVeri();
    void setVeri(int veri);

    SatirDugum *getSonraki();
    void setSonraki(SatirDugum *sonraki);

    SatirDugum *getOnceki();
    void setOnceki(SatirDugum *onceki);

private:
    int veri;
    SatirDugum *sonraki;
    SatirDugum *onceki;
};

#endif