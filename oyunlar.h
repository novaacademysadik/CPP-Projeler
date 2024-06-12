#include "kelime_oyunu/kelime_oyunu.h"
#include "islem_oyunu/islem_oyunu.h"
#include "mayin_tarlasi/mayin_tarlasi_oyunu.h"

class Oyun:public virtual Tanim
{
	public:
		void oyunMenu()
		{
			string secimler[] = {"Kelime Oyunu","Ýþlem Oyunu","Savaþ Oyunu","Mayýn Tarlasý"};
         bool h = false, cikis = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(	menuInfo("Oyunlar Menüsü",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
			     temizle();
			 	switch(secim)
			 	{
			 		case 1:
			 		    kelimeOyunuOyna(user);
			 			break;
			 		case 2:
			 		    islem_oyunu_oyna(user);
			 			break;	
			 		case 3:
			 			savas_oyunu_oyna();
			 			break;
			 		case 4:
			 			MayinTarlasi(user);
			 			break;
			 		case 0:
					    cikis = true;
						break;
							
			 		default:
			 				h = true;
				 }
			 	
			 }while(!cikis || h);
		}
};
