/**
 * @file  ManagerListNode.hpp
 * @description Programınızın açıklaması ne yaptığına dair.
 * @course  Dersi aldığınız eğitim türü ve grup
 * @assignment  Kaçıncı ödev olduğu
 * @date  Kodu oluşturduğunuz Tarih
 * @author  Gruptakilerin yazar adları ve mail adresleri
 */
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
