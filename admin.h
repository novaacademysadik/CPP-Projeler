class Admin:public virtual Tanim
{
   
	public:
	int deneme = 0;
	Bilgi b1;
		void adminGiris()
		{
			//baslik("Admin Paneli Giri�");
			do
			{	
				b1.kul_ad = veriGiris("Admin Kullanici Adi: (��kmak i�in: [0])",s);
		     	b1.sifre = veriGiris("Admin �ifre: ",s);
		     	
		     	if(!kullaniciKontrol(b1.kul_ad,b1.sifre,"admin.txt") && b1.kul_ad != "0")
		     	    hata("Yetkisiz Giri�","Admin Giri�");
		     	    
				deneme++;
			}while(!kullaniciKontrol(b1.kul_ad,b1.sifre,"admin.txt") && deneme != 3 && b1.kul_ad != "0");
		
		}
		
		void uyeEkle()
		{
		   b1.id = idYap("uyeler.txt");
		   cin.ignore();
		   b1.ad = metinGiris("Ad�:");
          do
			{
				
			  b1.kul_ad = metinGiris("Kulland�c� Ad�:");
		
			}while(kulAdKontrol(b1.kul_ad,"uyeler.txt") == false);
			
		   b1.sifre = veriGiris("�ifre:",s);
		   
		   kayit("uyeler.txt",b1);
		   	  
		
		}
		
		void adminEkle()
		{
		   b1.id = idYap("admin.txt");
		   cin.ignore();
		   b1.ad = metinGiris("Ad�n�z:");
            do
			{
				
			  b1.kul_ad = metinGiris("Kulland�c� Ad�n�z:");
		
			}while(kulAdKontrol(b1.kul_ad,"admin.txt") == false);
		
			
		   b1.sifre = veriGiris("�ifre:",s);
		   
		   kayit("admin.txt",b1);
					
		}
		bool kulAdKontrol(string kulAd,string dosyaAd)
		{
			if(veriKontrol(kulAd,0,dosyaAd))
			{
				   hata("Kullan�c� ad� daha �nce al�nm�� !!!","Kullan�c� ad� hatal�");  
				   return "�";
			}
			
			
			bool tk = false;
			bool b = false;
			string m;
			if(kulAd.size()>10)
		    {
		       hata("Kullan�c� ad� 10 karakterden b�y�k olamaz !!!","Kullan�c� ad� hatal�");  
			   	return false;	
			}
			for(int i=0; i < kulAd.size();i++)
			{
				switch(kulAd[i])
				{
					case '�':case '�':case'�':case '�':
					case '�':case '�':
						tk = true;
						break;
				}
				
				if(isblank(kulAd[i]))
		 	         b = true;	
			}
			
			if(tk)
		    	m += "Kullan�c� Ad�nda T�rk�e Karakter Olamaz";
			if(b)
			    m += "\nKullan�c� Ad�nda Bo�luk Olamaz";
			    
			if(tk || b)
			{
			   	hata(m,"Kullan�c� ad� hatal�");  
			   	return false;
			}  
					
			return true;
		}
		
		
		void listele(string dosyaAd)
		{
			int count = kullaniciSayisi(dosyaAd);
		    Bilgi bilgiler[count];
		     
			veriOku(bilgiler,count,dosyaAd);
			 
			cout<<count<<" tane kullan�c� listeleniyor\n"; 
			 
			for(int i = 0; i < count; i++)
			{
				cout<<"ID: "<<bilgiler[i].id<<endl;
				cout<<"Ad: "<<bilgiler[i].ad<<endl;
				cout<<"Kullan�c� Ad�: "<<bilgiler[i].kul_ad<<endl;
				cout<<"Kullan�c� �ifre: "<<bilgiler[i].sifre<<endl;
				cout<<"----------------------\n";
			}
		
		   
			
		}
		
		
		bool sifreKontrol(string sifre)
		{
			if(sifre == sonSifre)
			{
				hata("Son �ifreden farkl� olmal�d�r!! ","HATA");
				
				return false;
			}
			if(sifre.size() < 5 )
			{
				hata("�ifre �ok k�sa !!","Hatali �ifre");
				return false;
			}
			
			return true;
		}
		
		
		void uyeDuzenle(string dosyaAd)
		{
			ac(dosyaAd);
			do
			{
				b1.id = veriGiris("D�zenlenecek Kullan�c� ID'si[��k��:0]:",i);
				
			}while(!veriKontrol("asd",b1.id,dosyaAd) && b1.id != 0);
		   
		   if(b1.id != 0)
		   {
		   		cout<<"ID: "<<detay.id<<endl;
				cout<<"Ad: "<<detay.ad<<endl;
				cout<<"Kullan�c� Ad�: "<<detay.kul_ad<<endl;
				cout<<"Kullan�c� �ifre: "<<detay.sifre<<endl;
				cout<<"----------------------\n";	
					
			    cin.ignore();
			    
				b1.ad = metinGiris("Ad:");	
				do
				{
					b1.kul_ad = metinGiris("Kullan�c� Ad�:");
				}while(kulAdKontrol(b1.kul_ad,dosyaAd) == false);
					
				do
				{
					b1.sifre = veriGiris("�ifre:",s);
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
			     	hata("�ok say�da ba�ar�s�z deneme...","HATA");
			   }
			else   
			  adminMenu();
			
		}
		void adminMenu()
		{  
		    bool cikis = true;
			baslik("Admin Paneli | Menu");
			
			 string menuInfo = "1)Admin Ekle\n2)�ye Sil\n3)�ye Ekle\n4)�ye Listele\n5)Admin Listele\n6)�ye D�zenle\n7)Admin D�zenle\n0)��k�� Yap\nSe�im:";
			 
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
 					    cout<<"��k�� yap�l�r...\n";
 					    cikis = false;
					    break;
					default:
					   hata("Hatali Se�im Yap�ld� !!!","Hatali Se�im");  
					   h = true;			
				 		 
				 }
			 	
			 }while(cikis);
		}
		
		
		void uyeSil()
		{
			ac("uyeler.txt");
			
			b1.id = veriGiris("Silinecek �ye ID'si:",i);
			kayitSil(b1.id,"uyeler.txt");	
			
		}
		
		
	
};
