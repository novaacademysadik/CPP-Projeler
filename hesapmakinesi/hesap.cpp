#include "..\inc.h"

class HesapMakinesi:public virtual Tanim
{
	public:
	double sayi1,sayi2,cevap;
	
	void baslangic()
	{
		dilAyar();
		baslik("+-*/Hesap Makinesi/*-+");
	}
	
	void menu()
	{
		bool cikis = false;
		bool h = false;
		
		do
		{
			h = false;
			int secim = veriGiris ("1)TOPLAMA\n2)ÇIKARMA\n3)BÖLME\n4)ÇARPMA\n0)ÇIKIS\nLütfen Secim Yapýnýz:",i);
			switch (secim)
			{
				case 1:
					topla();
					break;
				case 2:
					cikar();
					break;
				case 3:
					bolme();
					break;
				case 4:
					carpma();
					break;
				case 0:
					cikis = true;
					break;
				default:
					h = true;
					hata("Hatali Seçim Yapýldý !!!","Hatali Seçim");
			}
		}while(!cikis || h);
	}
	void topla()
	{
		temizle();
		//do{
			cout<<"islem Sonucunu Görmek Için ( 0 ) 'e basýn\n";
			for (int i = 1;i >0; i++)
			{
				cout<<i;
				sayi1 = veriGiris(".Sayi :",d);
				
				
				cevap += sayi1;
				
				
				if(sayi1 == 0)
				{
					cout<<"sonuç :"<<cevap<<endl;
					break;
				}
				
				//if(sayi1.size() > 60 && sayi1.size() < 71)
			}
			
			
			
		//}while();
	
		
	}
	void cikar()
	{
		temizle();
		//do{
			cevap = 0;
			cout<<"islem Sonucunu Görmek Için ( 0 ) 'e basýn\n";
			for (int i = 1;i >0; i++)
			{
				cout<<i;
				sayi1 = veriGiris(".Sayi :",d);
				
				
				cevap = sayi1 - cevap;
				
				
				if(sayi1 == 0)
				{
					cout<<"sonuç :"<<cevap<<endl;
					break;
				}
				
				//if(sayi1.size() > 60 && sayi1.size() < 71)
			}
			
			
			
		//}while();
	
		
	}
	void bolme()
	{
		temizle();
		//do{
			cout<<"islem Sonucunu Görmek Için ( 0 ) 'e basýn\n";
			for (int i = 1;i >0; i++)
			{
				cout<<i;
				sayi1 = veriGiris(".Sayi :",d);
				
				
				cevap = sayi1 / cevap;
				
				
				if(sayi1 == 0)
				{
					cout<<"sonuç :"<<cevap<<endl;
					break;
				}
				
				//if(sayi1.size() > 60 && sayi1.size() < 71)
			}
			
			
			
		//}while();
	
		
	}
	void carpma()
	{
		temizle();
		//do{
			cout<<"islem Sonucunu Görmek Için ( 0 ) 'e basýn\n";
			for (int i = 1;i >0; i++)
			{
				cout<<i;
				sayi1 = veriGiris(".Sayi :",d);
				
				
				cevap *= sayi1;
				
				
				if(sayi1 == 0)
				{
					cout<<"sonuç :"<<cevap<<endl;
					break;
				}
				
				//if(sayi1.size() > 60 && sayi1.size() < 71)
			}
			
			
			
		//}while();
	
		
	}
};



int main()
{
	HesapMakinesi h1;
	
	h1.baslangic();
	h1.menu();
	
	return 0;
}
