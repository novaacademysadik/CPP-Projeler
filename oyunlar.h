#include "kelime_oyunu/kelime_oyunu.h"
#include "islem_oyunu/islem_oyunu.h"
#include "mayin_tarlasi/mayin_tarlasi_oyunu.h"
#include "taskagitmakas/taskagitmakas.h"
#include "savas_oyunu/battle.h"
#include "tahmin_oyunu/tahmin_oyunu.h"

class Oyun:public virtual Tanim
{
	public:
		void oyunMenu()
		{
			string secimler[] = {"Kelime Oyunu","Ýþlem Oyunu","Savaþ Oyunu","Mayýn Tarlasý","Taþ Kaðýt Makas","Tahmin Oyunu"};
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
			 		    islem_oyna(user);
			 			break;	
			 		case 3:
			 			savas_oyna(user);
			 			break;
			 		case 4:
			 			MayinTarlasi(user);
			 			break;
			 		case 5:
			 			TasKagitMakasOyna();
			 			break;
					case 6:
					     tahminOyunuOyna();	 	
			 		case 0:
					    cikis = true;
						break;
							
			 		default:
			 				h = true;
				 }
			 	
			 }while(!cikis || h);
		}
};
