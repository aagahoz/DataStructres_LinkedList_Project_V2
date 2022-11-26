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