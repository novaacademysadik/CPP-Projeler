

class Adres:public virtual Tanim
{
	public:

		void adresMenu()
		{
			string info;
			string secimler[] = {"Adres Ekleme","Adres Listeleme","Adres Silme"};
			
			 info =menuInfo("Adres Sistemi",secimler,sizeof(secimler)/sizeof(secimler[0]));
			 
			 bool h = false;
			 bool cikis = false; 
			 do
			 {
			 	h = false;
			    int secim = veriGiris(info,i);
			     temizle();
				 switch(secim)
				 {
				 	case 1:
				 		adresEkle();
				 		break;
				 	case 2:
					    adresListele("Adresler.txt");
					    break;
				 	case 0:	
				       	temizle();
 					    cikis = true;
					    break;
					default:
					   hata("Hatali Se�im Yap�ld� !!!","Hatali Se�im");  
					   h = true;	
				 }
			 }while(!cikis || h);
		}
		
		void adresEkle()
		{
			baslik("Adres Ekleme");
			adres.id = 1;
			adres.kul_ad = user.kul_ad;
			adres.il = veriGiris("�l:",s);
			adres.ilce = veriGiris("�l�e:",s);
			adres.mahalle = veriGiris("Mahalle:",s);
			cin.ignore();
			adres.detay = metinGiris("Detay:");
			adres.baslik = metinGiris("Adres Ba�l�k");
			adresKayit("Adresler.txt",adres);
			
		}
		
		void adresListele(string dosyaAd)
		{
			baslik(user.ad + " Adres Listesi");
			int count = adresSayisi(dosyaAd);
		    AdresBilgi adresler[count];
		  int adet = 0;
		     
			adresOku(adresler,count,dosyaAd);
			 
			for(int i = 0; i < count; i++)
			{
				if(adresler[i].kul_ad == user.kul_ad)
				{
					adet++;
					cout<<"ID: "<<adresler[i].id<<endl;
					cout<<"Ba�l�k: "<<adresler[i].baslik<<endl;
					cout<<"�l: "<<adresler[i].il<<endl;
					cout<<"�l�e: "<<adresler[i].ilce<<endl;
					cout<<"Mahalle: "<<adresler[i].mahalle<<endl;
					cout<<"Detay: "<<adresler[i].detay<<endl;
					cout<<"----------------------\n";
					
				}
				
			}
		  cout<<adet<<" tane adres listeleniyor...\n";
		   
			
		}
		
		
		
		
		
};
