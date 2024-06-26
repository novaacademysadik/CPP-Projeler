
class Dosya:public Mesaj,public Veri,public Ayar{
	public:
	string veriler[5];
	string sonSifre;
	Bilgi detay;
	Bilgi user;
	AdresBilgi adres;

	void kayit(string dosyaAd,Bilgi b)
	{
		ofstream dosya(dosyaAd.c_str(),ios::app);
		
		dosya<<"-"<<b.id;
		dosya<<"-"<<b.ad;
		dosya<<"-"<<b.kul_ad;
		dosya<<"-"<<b.sifre<<"-"<<endl;
		
		basarili("Kay�t Ba�ar�l�..","Kay�t");
	
		dosya.close();
		
		ac(dosyaAd);

	}
	void adresKayit(string dosyaAd,AdresBilgi a)
	{
		ofstream dosya(dosyaAd.c_str(),ios::app);
		
		dosya<<"-"<<a.id;
		dosya<<"-"<<a.kul_ad;
		dosya<<"-"<<a.baslik;
		dosya<<"-"<<a.il;
		dosya<<"-"<<a.ilce;
		dosya<<"-"<<a.mahalle;
		dosya<<"-"<<a.detay<<"-"<<endl;
		
		basarili("Kay�t Ba�ar�l�..","Kay�t");
	
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
		
		basarili(" Ba�ar�l�..","Ba�ar�l�");
		
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
	
	int adresSayisi(string dosyaAd)
	{
		ifstream dosya;
		dosya.open(dosyaAd.c_str());
		
		int count = 0;
		
		string a[8];
		
		while(getline(dosya,a[0],'-') && getline(dosya,a[1],'-')  )
		{
			getline(dosya,a[2],'-'); // kul_ad
			getline(dosya,a[3],'-'); // basl�k
			getline(dosya,a[4],'-'); // il
			getline(dosya,a[5],'-'); // ilce
			getline(dosya,a[6],'-'); //mahalle
			getline(dosya,a[7],'-'); //detay
			count++;
		}
		dosya.close();
		
		
		dosya.open(dosyaAd.c_str());

		return count;
	}
	
	
	void adresOku(AdresBilgi adresler[],int count,string dosyaAd)
	{
		ifstream dosya(dosyaAd.c_str());
			string a[8];
		for(int i = 0; i < count; i++)
		{
			getline(dosya,a[0],'-'); // bosluk
			getline(dosya,a[1],'-'); // id
			getline(dosya,a[2],'-'); // kul_ad
			getline(dosya,a[3],'-'); // basl�k
			getline(dosya,a[4],'-'); // il
			getline(dosya,a[5],'-'); // ilce
			getline(dosya,a[6],'-'); //mahalle
			getline(dosya,a[7],'-'); //detay
			
			adresler[i].id = intYap(a[1]);
			adresler[i].kul_ad = a[2]; 
		    adresler[i].baslik = a[3]; 
			adresler[i].il = a[4]; 
			adresler[i].ilce = a[5]; 
			adresler[i].mahalle = a[6]; 
			adresler[i].detay = a[7]; 			
				
		}
		
		dosya.close();
		
		
	}
	
		void skor_kayit(string dosyaAd,int yeniSkor)
		{
			skor_ekle(dosyaAd);
			int adet = skor_sayisi(dosyaAd);
			
			Skor skorlar[adet];
			tum_skorlar(skorlar,dosyaAd,adet);
			skor_ayarla(skorlar,yeniSkor,adet);
			skor_sirala(skorlar,adet);
			   
			skor_yenile(skorlar,dosyaAd,adet);
			
			cout<<"Skor kayit edildi....\n";
			Sleep(3000);
			
		}
		
		int skor_sayisi(string dosyaAd)
		{
		    ifstream dosya;
			dosya.open(dosyaAd.c_str());
			int adet = 0;
		   	for(;getline(dosya,veriler[0],'-') && getline(dosya,veriler[1],'-');)
			{
				
			    getline(dosya,veriler[2],'-'); // kul_ad
			    getline(dosya,veriler[3],'-'); // skor
			    
			    adet++;
					
			}
			dosya.close();
			
			return adet;
  		  }
        
        void tum_skorlar(Skor skorlar[],string dosyaAd,int adet)
        {
        	ifstream dosya;	
			dosya.open(dosyaAd.c_str());
			for(int i = 0; i < adet;i++)
			{
				getline(dosya,veriler[0],'-'); 
				getline(dosya,veriler[1],'-');//id 
			    getline(dosya,veriler[2],'-'); // kul_ad
			    getline(dosya,veriler[3],'-'); // skor
			    
			    skorlar[i].id = intYap(veriler[1]);
			    skorlar[i].kul_ad = veriler[2];
			    skorlar[i].skor = intYap(veriler[3]);
			   
					
			}
			
			dosya.close();
			
		}
	
	 void skor_ayarla(Skor skorlar[],int yeniSkor,int adet)
	 {
	   
	 	for(int i = 0; i < adet;i++ )
	 	{
	 		if(skorlar[i].kul_ad == user.kul_ad)
	 		{
	 			if(skorlar[i].skor < yeniSkor)
	 			  skorlar[i].skor = yeniSkor;
			 }
		 }
		 
	 	
	 }
    	bool skor_yenile(Skor skorlar[],string dosyaAd,int adet){
		
		   ofstream dosya(dosyaAd.c_str());
	 	   
		   for(int i = 0; i < adet ; i++)
		  {
		  	
		    	dosya<<"-"<<skorlar[i].id<<"-"<<skorlar[i].kul_ad<<"-"<<skorlar[i].skor<<"-"<<endl;
		  	
		   } 
		   
	      dosya.close();
	      
	      return true;
		   
		}
		
		
		
		void skor_sirala(Skor skorlar[],int adet)
		{
			int rezId, rezSkor;
			string rezKulAd;
			for(int i = 0; i < adet;i++ )
		 	{
		 		for(int j = i + 1; j < adet; j++)
		 		{
		 			if(skorlar[i].skor < skorlar[j].skor)
		 			{
		 				rezSkor = skorlar[i].skor;
		 				rezId = skorlar[i].id;
		 				rezKulAd = skorlar[i].kul_ad;
		 				
		 				skorlar[i].id = skorlar[j].id;
		 				skorlar[i].kul_ad = skorlar[j].kul_ad;
		 				skorlar[i].skor = skorlar[j].skor;
		 				
		 				skorlar[j].id = rezId;
		 				skorlar[j].kul_ad = rezKulAd;
		 				skorlar[j].skor = rezSkor;
		 				
					 }
					 
			
				 }
			 }
			 
			
			   
		
		 
		}
		
		void skor_ekle(string dosyaAd)
		{
			ofstream dosya(dosyaAd.c_str(),ios::app);
			
			
			if(!skor_kontrol(dosyaAd))
			   	dosya<<"-"<<user.id<<"-"<<user.kul_ad<<"-0-"<<endl;
			
			
		}
		
		bool skor_kontrol(string dosyaAd)
		{
			ifstream dosya(dosyaAd.c_str());
			
			for(;getline(dosya,veriler[0],'-') && getline(dosya,veriler[1],'-');)
			{		
			    getline(dosya,veriler[2],'-'); // kul_ad
			    getline(dosya,veriler[3],'-'); // skor
			    
			    
			    if(veriler[2] == user.kul_ad)
			       return true;
					
			}
			
			
			return false;
		}
		
		void son_skor_goster(string dosyaAd)
		{
			ifstream dosya;	
			dosya.open(dosyaAd.c_str());
			int adet = skor_sayisi(dosyaAd);
			bool sonuc;
			
			for(int i = 0; i < adet;i++)
			{
				sonuc = false;
				getline(dosya,veriler[0],'-'); 
				getline(dosya,veriler[1],'-'); //id 
			    getline(dosya,veriler[2],'-'); // kul_ad
			    getline(dosya,veriler[3],'-'); // skor	
			    
			    if(veriler[2] == user.kul_ad)
			    {
			    	text_print("Son skorunuz: " + veriler[3]);
			    	Sleep(1000);
					break;	
				}
				
				else
					sonuc = true;
			}
			
			if(sonuc)
			{
				text_print("Kay�tl� skor bulunamad�...");
				Sleep(1000);
			}

			dosya.close();
		}
		
		void skor_tablosu(string dosyaAd)
		{
			ifstream dosya;
			dosya.open(dosyaAd.c_str());
			
			int adet = skor_sayisi(dosyaAd);
			string rez[3];
			string bos;
			Skor skorlar[adet];
			
			for(int i = 0; i<adet; i++)
			{
				getline(dosya,bos,'-'); 
				getline(dosya,rez[0],'-'); //id
			    getline(dosya,rez[1],'-'); // kul_ad
			    getline(dosya,rez[2],'-'); // skor
			    
			    skorlar[i].id = intYap(rez[0]);  //id 
			    skorlar[i].kul_ad = rez[1];          // kul_ad
			    skorlar[i].skor = intYap(rez[2]);  // skor 
			}
			
			dosya.close();
			
			temizle();
			cout<<" ----- SKOR TABLOSU -----\n\n";
			
			for(int i = 0; i<adet; i++)
			{
			    cout<<"Kullan�c� ad�: "<<skorlar[i].kul_ad<<endl; // kul_ad
			    cout<<"Skor: "<<skorlar[i].skor<<endl; // skor
			    cout<<"----------\n";
			}
			
			system("pause");
			text_print("Oyun men�s�ne tekrar d�n�l�yor...");
			Sleep(500);
			temizle();
		}
	
};

