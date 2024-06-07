#include "kelime_oyunu/kelime_oyunu.h"


class Oyun:public virtual Tanim,public Kelime_Oyunu
{
	public:
		void oyunMenu()
		{
			string secimler[] = {"Kelime Oyunu"};
         bool h = false, cikis = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(	menuInfo("Oyunlar Menüsü",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
			     temizle();
			 	switch(secim)
			 	{
			 		case 1:
			 		     Kelime_Oyunu_Menu();
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
