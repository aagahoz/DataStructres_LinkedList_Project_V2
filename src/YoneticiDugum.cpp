#include "YoneticiDugum.hpp"
#include <iostream>
using namespace std;

YoneticiDugum::YoneticiDugum()
{
    this->satirListesi = NULL;
    this->sonraki = NULL;
    this->onceki = NULL;
}

YoneticiDugum::YoneticiDugum(SatirDugumListesi *satirListesi)
{
    this->satirListesi = satirListesi;
    this->onceki = NULL;
    this->sonraki = NULL;
}

YoneticiDugum::~YoneticiDugum()
{}

SatirDugumListesi *YoneticiDugum::getSatirListesi()
{
    return this->satirListesi;
}
void YoneticiDugum::setSatirListesi(SatirDugumListesi *satirListesi)
{
    this->satirListesi = satirListesi;
}

YoneticiDugum *YoneticiDugum::getOnceki()
{
    return this->onceki;
}
void YoneticiDugum::setOnceki(YoneticiDugum *onceki)
{
    this->onceki = onceki;
}

YoneticiDugum *YoneticiDugum::getSonraki()
{
    return this->sonraki;
}
void YoneticiDugum::setSonraki(YoneticiDugum *sonraki)
{
    this->sonraki = sonraki;
}
