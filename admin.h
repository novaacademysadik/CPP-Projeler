class Admin:public virtual Tanim
{
   
	public:
	int deneme = 0;
	Bilgi b1;
		void adminGiris()
		{
			//baslik("Admin Paneli Giriþ");
			do
			{	
				b1.kul_ad = veriGiris("Admin Kullanici Adi: (Çýkmak için: [0])",s);
		     	b1.sifre = veriGiris("Admin Þifre: ",s);
		     	
		     	if(!kullaniciKontrol(b1.kul_ad,b1.sifre,"admin.txt") && b1.kul_ad != "0")
		     	    hata("Yetkisiz Giriþ","Admin Giriþ");
		     	    
				deneme++;
			}while(!kullaniciKontrol(b1.kul_ad,b1.sifre,"admin.txt") && deneme != 3 && b1.kul_ad != "0");
		
		}
		
		void uyeEkle()
		{
		   b1.id = idYap("uyeler.txt");
		   cin.ignore();
		   b1.ad = metinGiris("Adý:");
          do
			{
				
			  b1.kul_ad = metinGiris("Kullandýcý Adý:");
		
			}while(kulAdKontrol(b1.kul_ad,"uyeler.txt") == false);
			
		   b1.sifre = veriGiris("Þifre:",s);
		   
		   kayit("uyeler.txt",b1);
		   	  
		
		}
		
		void adminEkle()
		{
		   b1.id = idYap("admin.txt");
		   cin.ignore();
		   b1.ad = metinGiris("Adýnýz:");
            do
			{
				
			  b1.kul_ad = metinGiris("Kullandýcý Adýnýz:");
		
			}while(kulAdKontrol(b1.kul_ad,"admin.txt") == false);
		
			
		   b1.sifre = veriGiris("Þifre:",s);
		   
		   kayit("admin.txt",b1);
					
		}
		bool kulAdKontrol(string kulAd,string dosyaAd)
		{
			if(veriKontrol(kulAd,0,dosyaAd))
			{
				   hata("Kullanýcý adý daha önce alýnmýþ !!!","Kullanýcý adý hatalý");  
				   return "þ";
			}
			
			
			bool tk = false;
			bool b = false;
			string m;
			if(kulAd.size()>10)
		    {
		       hata("Kullanýcý adý 10 karakterden büyük olamaz !!!","Kullanýcý adý hatalý");  
			   	return false;	
			}
			for(int i=0; i < kulAd.size();i++)
			{
				switch(kulAd[i])
				{
					case 'ý':case 'þ':case'ð':case 'ü':
					case 'ö':case 'ç':
						tk = true;
						break;
				}
				
				if(isblank(kulAd[i]))
		 	         b = true;	
			}
			
			if(tk)
		    	m += "Kullanýcý Adýnda Türkçe Karakter Olamaz";
			if(b)
			    m += "\nKullanýcý Adýnda Boþluk Olamaz";
			    
			if(tk || b)
			{
			   	hata(m,"Kullanýcý adý hatalý");  
			   	return false;
			}  
					
			return true;
		}
		
		
		void listele(string dosyaAd)
		{
			int count = kullaniciSayisi(dosyaAd);
		    Bilgi bilgiler[count];
		     
			veriOku(bilgiler,count,dosyaAd);
			 
			cout<<count<<" tane kullanýcý listeleniyor\n"; 
			 
			for(int i = 0; i < count; i++)
			{
				cout<<"ID: "<<bilgiler[i].id<<endl;
				cout<<"Ad: "<<bilgiler[i].ad<<endl;
				cout<<"Kullanýcý Adý: "<<bilgiler[i].kul_ad<<endl;
				cout<<"Kullanýcý Þifre: "<<bilgiler[i].sifre<<endl;
				cout<<"----------------------\n";
			}
		
		   
			
		}
		
		
		bool sifreKontrol(string sifre)
		{
			if(sifre == sonSifre)
			{
				hata("Son þifreden farklý olmalýdýr!! ","HATA");
				
				return false;
			}
			if(sifre.size() < 5 )
			{
				hata("Þifre çok kýsa !!","Hatali Þifre");
				return false;
			}
			
			return true;
		}
		
		
		void uyeDuzenle(string dosyaAd)
		{
			ac(dosyaAd);
			do
			{
				b1.id = veriGiris("Düzenlenecek Kullanýcý ID'si[çýkýþ:0]:",i);
				
			}while(!veriKontrol("asd",b1.id,dosyaAd) && b1.id != 0);
		   
		   if(b1.id != 0)
		   {
		   		cout<<"ID: "<<detay.id<<endl;
				cout<<"Ad: "<<detay.ad<<endl;
				cout<<"Kullanýcý Adý: "<<detay.kul_ad<<endl;
				cout<<"Kullanýcý Þifre: "<<detay.sifre<<endl;
				cout<<"----------------------\n";	
					
			    cin.ignore();
			    
				b1.ad = metinGiris("Ad:");	
				do
				{
					b1.kul_ad = metinGiris("Kullanýcý Adý:");
				}while(kulAdKontrol(b1.kul_ad,dosyaAd) == false);
					
				do
				{
					b1.sifre = veriGiris("Þifre:",s);
				}while(!sifreKontrol(b1.sifre));	
			
				
				veriGuncelle(b1,dosyaAd);
		   	
		   }
			
		
		}
		
		
};


class AdminMenu:public Admin
{
	public:
		void panel()
		{
			deneme = 0;
			adminGiris();
			
			if(deneme == 3 || b1.kul_ad == "0")
			  {
			     if(deneme == 3)
			     	hata("Çok sayýda baþarýsýz deneme...","HATA");
			   }
			else   
			  adminMenu();
			
		}
		void adminMenu()
		{  
		    bool cikis = true;
			baslik("Admin Paneli | Menu");
			
			 string menuInfo = "1)Admin Ekle\n2)Üye Sil\n3)Üye Ekle\n4)Üye Listele\n5)Admin Listele\n6)Üye Düzenle\n7)Admin Düzenle\n0)Çýkýþ Yap\nSeçim:";
			 
			 bool h = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(menuInfo,i);
			 
				 switch(secim)
				 {
				 	case 1:
				 		adminEkle();
				 		break;
			 		case 2:	
				        uyeSil();
				    break;
				    case 3:
				    	uyeEkle();
				    	break;
				    case 4:
					     listele("uyeler.txt");
						 break;	
					case 5:
					     listele("admin.txt");
						 break;	
					case 6:
						uyeDuzenle("uyeler.txt");
						break;
					case 7:
						uyeDuzenle("admin.txt");
						break;
				 	case 0:	
				 	    temizle();
 					    cout<<"çýkýþ yapýlýr...\n";
 					    cikis = false;
					    break;
					default:
					   hata("Hatali Seçim Yapýldý !!!","Hatali Seçim");  
					   h = true;			
				 		 
				 }
			 	
			 }while(cikis);
		}
		
		
		void uyeSil()
		{
			ac("uyeler.txt");
			
			b1.id = veriGiris("Silinecek Üye ID'si:",i);
			kayitSil(b1.id,"uyeler.txt");	
			
		}
		
		
	
};
