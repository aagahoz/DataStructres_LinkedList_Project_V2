/**
 * @file  main.cpp
 * @description Baglı liste kullanarak satır satır okuma ve yazma işlemleri
 * @course  1.Öğretim A Grubu 
 * @assignment  1.Ödev
 * @date   20.11.2022
 * @author  Merva Banu Duman - Merva.duman@ogr.sakarya.edu.tr
 */

#include "YoneticiDugumListesi.hpp"
using namespace std;

int main()
{
     YoneticiDugumListesi *yoneticiDugumListesi = new YoneticiDugumListesi();
     yoneticiDugumListesi->dosyadanVerileriOkuVeListeyeEkle();
     
     yoneticiDugumListesi->menu();

     return 0;
}
