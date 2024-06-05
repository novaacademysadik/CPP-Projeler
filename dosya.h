
class Dosya:public Mesaj,public Veri,public Ayar{
	public:
	string veriler[5];
	string sonSifre;
	Bilgi detay;
	Bilgi user;
	void kayit(string dosyaAd,Bilgi b)
	{
		ofstream dosya(dosyaAd.c_str(),ios::app);
		
		dosya<<"-"<<b.id;
		dosya<<"-"<<b.ad;
		dosya<<"-"<<b.kul_ad;
		dosya<<"-"<<b.sifre<<"-"<<endl;
		
		basarili("Kayýt Baþarýlý..","Kayýt");
	
		dosya.close();
		
		ac(dosyaAd);

	}


	bool veriKontrol(string kulAd,int id,string dosyaAd) 
	{
		
		ifstream dosya;
		dosya.open(dosyaAd.c_str());
		string veriler[5];
		while(getline(dosya,veriler[0],'-') && getline(dosya,veriler[1],'-'))
		{
			getline(dosya,veriler[2],'-'); // ad
			getline(dosya,veriler[3],'-'); // kul_ad
			getline(dosya,veriler[4],'-'); // sifre
			
		   if(id == 0)
			{
				if(veriler[3] == kulAd )
			    {
			    	sonSifre = veriler[4];
					return true;
				}
				  
			}
			else
			{
				if(veriler[1] == stringYap(id) )
				{
					detay.id = intYap(veriler[1] );
					detay.kul_ad = veriler[3];
					detay.ad = veriler[2];
					detay.sifre = veriler[4];
					
					return true;
				}
				  
			}	
			
		}
		
	//	hata("Kiþi bulunamadý ...","HATA");
	
		return false;
	}
	
	int idYap(string dosyaAd)
	{
		int id;
		do
		{
			id = rand() % 900 + 100; // 100 - 999
	
		}while(veriKontrol(" ",id,dosyaAd));
		
		return id;
	}
	
	bool kullaniciKontrol(string kulAd,string sifre,string dosyaAd)
	{
		ifstream dosya(dosyaAd.c_str());
		
		while(getline(dosya,veriler[0],'-') && getline(dosya,veriler[1],'-'))
		{
			getline(dosya,veriler[2],'-'); // ad
			getline(dosya,veriler[3],'-'); // kul_ad
			getline(dosya,veriler[4],'-'); // sifre
			
			if(veriler[3] == kulAd && veriler[4] == sifre)
			{
                user.id = intYap(veriler[1]);
                user.ad = veriler[2];
                user.kul_ad = veriler[3];
                user.sifre = veriler[4];
				
				return true;	
			}
			    
			
		}
		
		dosya.close();
		
		return false;
	}
	int kullaniciSayisi(string dosyaAd)
	{
		ifstream dosya;
		dosya.open(dosyaAd.c_str());
		
		int count = 0;
		
		string a[5];
		
		string a1,a2,a3,a4,a5;
		
		while(getline(dosya,a1,'-') && getline(dosya,a2,'-') && getline(dosya,a3,'-') && getline(dosya,a4,'-'))
		{
			getline(dosya,a5,'-'); // sifre
			count++;
		}
		dosya.close();
		
		
		dosya.open(dosyaAd.c_str());

		return count;
	}
	
	void sifreGuncelle(string kulAd,string sifre,string dosyaAd)
	{
        int count = kullaniciSayisi(dosyaAd);
		
		Bilgi bilgiler[count];
	    ifstream dosya;
	    dosya.open(dosyaAd.c_str());

		for(int i = 0; i < count; i++)
		{
			getline(dosya,veriler[0],'-');
			getline(dosya,veriler[1],'-');
			
		    bilgiler[i].id = intYap(veriler[1]);
		     
	    	getline(dosya,bilgiler[i].ad,'-'); // ad
			getline(dosya,bilgiler[i].kul_ad,'-'); // kul_ad
			if(bilgiler[i].kul_ad == kulAd)
		    	bilgiler[i].sifre = sifre;
		    else
		       getline(dosya,bilgiler[i].sifre,'-'); // sifre
		}
		dosya.close();
		
		veriYenile(bilgiler,count,dosyaAd);
		
	}
	
	void veriYenile(Bilgi bilgiler[],int count,string dosyaAd)
	{
		ofstream dosya(dosyaAd.c_str());
		
		for(int i = 0; i < count; i++)
		{
		
			dosya<<"-"<<bilgiler[i].id;
			dosya<<"-"<<bilgiler[i].ad;
			dosya<<"-"<<bilgiler[i].kul_ad;
			dosya<<"-"<<bilgiler[i].sifre<<"-"<<endl;
				
     	}
		
		basarili(" Baþarýlý..","Baþarýlý");
		
		dosya.close();
		ac(dosyaAd);
	}
	
	void kayitSil(int id,string dosyaAd)
	{
        int count = kullaniciSayisi(dosyaAd);
		
		Bilgi bilgiler[count];
	    ifstream dosya;
	    dosya.open(dosyaAd.c_str());
	    int kulId;
	
		for(int i = 0; i < count; i++)
		{
			getline(dosya,veriler[0],'-');
			getline(dosya,veriler[1],'-');
		    getline(dosya,veriler[2],'-'); // ad
		    getline(dosya,veriler[3],'-'); // kul_ad
		    getline(dosya,veriler[4],'-'); // sifre 
		    kulId = intYap(veriler[1]);
	
			if(kulId != id)
			{
				bilgiler[i].id = kulId; 
		    	bilgiler[i].ad = veriler[2]; 
				bilgiler[i].kul_ad = veriler[3]; 
				bilgiler[i].sifre = veriler[4]; 			
			}
			else
			{
				 i--;	
			}
			
		}
		
		dosya.close();
     
		veriYenile(bilgiler,count-1,dosyaAd);
		
	}
	
	void veriOku(Bilgi bilgiler[],int count,string dosyaAd)
	{
		ifstream dosya(dosyaAd.c_str());
		
		for(int i = 0; i < count; i++)
		{
			getline(dosya,veriler[0],'-');
			getline(dosya,veriler[1],'-');
		    getline(dosya,veriler[2],'-'); // ad
		    getline(dosya,veriler[3],'-'); // kul_ad
		    getline(dosya,veriler[4],'-'); // sifre 
		    
			bilgiler[i].id = intYap(veriler[1]); 
		    bilgiler[i].ad = veriler[2]; 
			bilgiler[i].kul_ad = veriler[3]; 
			bilgiler[i].sifre = veriler[4]; 			
				
		}
		
		
	}
	
	void veriGuncelle(Bilgi b1,string dosyaAd)
	{
        int count = kullaniciSayisi(dosyaAd);
		
		Bilgi bilgiler[count];
	    ifstream dosya;
	    dosya.open(dosyaAd.c_str());
		for(int i = 0; i < count; i++)
		{
			getline(dosya,veriler[0],'-');
			getline(dosya,veriler[1],'-');
			
		    bilgiler[i].id = intYap(veriler[1]);  
	    	getline(dosya,bilgiler[i].ad,'-'); // ad
			getline(dosya,bilgiler[i].kul_ad,'-'); // kul_ad
			getline(dosya,bilgiler[i].sifre,'-');
			
			if(bilgiler[i].id == b1.id)
			{
				bilgiler[i].ad = b1.ad;
				bilgiler[i].kul_ad = b1.kul_ad;
				bilgiler[i].sifre = b1.sifre;
			}
		       
		}
	
		dosya.close();
				
		
		veriYenile(bilgiler,count,dosyaAd);
		
	}
	
	
	
	
	
	
	
	
};
