#include "SatirDugum.hpp"
#include <iostream>
using namespace std;

SatirDugum::SatirDugum()
{
    this->veri = 0;
    this->sonraki = NULL;
    this->onceki = NULL;
}

SatirDugum::SatirDugum(int veri)
{
    this->veri = veri;
    this->sonraki = NULL;
    this->onceki = NULL;
}

SatirDugum::~SatirDugum()
{
    //dtor
}

int SatirDugum::getVeri()
{
    return this->veri;
}
void SatirDugum::setVeri(int veri)
{
    this->veri = veri;
}

SatirDugum *SatirDugum::getSonraki()
{
    return this->sonraki;
}
void SatirDugum::setSonraki(SatirDugum *sonraki)
{
    this->sonraki = sonraki;
}

SatirDugum *SatirDugum::getOnceki()
{
    return this->onceki;
}
void SatirDugum::setOnceki(SatirDugum *onceki)
{
    this->onceki = onceki;
}