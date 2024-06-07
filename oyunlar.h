#include "kelime_oyunu/kelime_oyunu.h"
#include "islem_oyunu/system.h"

class Oyun:public virtual Tanim
{
	public:
		void oyunMenu()
		{
			string secimler[] = {"Kelime Oyunu","Ýþlem Oyunu"};
         bool h = false, cikis = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(	menuInfo("Oyunlar Menüsü",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
			     temizle();
			 	switch(secim)
			 	{
			 		case 1:
			 		     kelimeOyunuOyna();
			 			break;
			 		case 2:
			 		     start();
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
