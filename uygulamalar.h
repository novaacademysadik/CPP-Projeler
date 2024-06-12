#include "faktoriyel/Faktoriyel.h"


class Uygulama:public virtual Tanim
{
	public:
		void uygulamaMenu()
		{
			string secimler[] = {"Faktöriyel Hesap"};
         bool h = false, cikis = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(	menuInfo("Uygulamalar Menüsü",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
			     temizle();
			 	switch(secim)
			 	{
			 		case 1:
			 		    faktoryelHesap();
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
