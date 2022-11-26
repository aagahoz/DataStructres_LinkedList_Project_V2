#include "YoneticiDugumListesi.hpp"

using namespace std;

int main()
{
     system("pause");

     YoneticiDugumListesi *yoneticiDugumListesi = new YoneticiDugumListesi();
     yoneticiDugumListesi->dosyadanVerileriOkuVeListeyeEkle();
     yoneticiDugumListesi->menu();

     return 0;
}
