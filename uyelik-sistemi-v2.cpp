#include "inc.h"

class Uyelik:public AdminMenu
{	
    Bilgi b1;
	public:

		Uyelik()
		{
	    	srand(time(0));
		}	
		void kaydol()
		{
		   b1.id = idYap("uyeler.txt");
		   cin.ignore();
		   b1.ad = metinGiris("Adýnýz:");
          do
			{
				
			  b1.kul_ad = metinGiris("Kullandýcý Adýnýz:");
		
			}while(kulAdKontrol(b1.kul_ad,"uyeler.txt") == false);
			
			do
			{
			  b1.sifre = veriGiris("Þifre:",s);	
			}while(sifreKontrol(b1.sifre) == false);

		   	kayit("uyeler.txt",b1);
	
		}
		

		 
		 bool giris()
		 {
		 		
		 	do
		 	{
		 		b1.kul_ad = veriGiris("Kullanýcý Adý[Çýkýþ:0]:",s);
		 	    b1.sifre = veriGiris("Þifre: ",s);
		 	    if(!kullaniciKontrol(b1.kul_ad,b1.sifre,"uyeler.txt") && b1.kul_ad != "0")
		 	        hata("Hatali Giriþ","Hata");
		 		
			}while(!kullaniciKontrol(b1.kul_ad,b1.sifre,"uyeler.txt") && b1.kul_ad != "0");
		 	temizle();
		 
		 	if(b1.kul_ad == "0")
		 	    return false;
		 	    
		 	
		 	
		 	return true;
		 }		
	      void sifreYenile()
	      {
	      	do
	      	{
	      		b1.kul_ad = veriGiris("Kullanici Adý:",s);
	      		
			 }while(!veriKontrol(b1.kul_ad,0,"uyeler.txt"));
	      	
	      	cout<<"eski sifre: "<<sonSifre<<endl;
	      	do
			{
			  b1.sifre = veriGiris("Yeni Þifreyi Giriniz:",s);	
			}while(sifreKontrol(b1.sifre) == false);
		  
            
	      	  
	      	  sifreGuncelle(b1.kul_ad,b1.sifre,"uyeler.txt");
	      	
		  }
};

class UyeMenu:public Uyelik,public Adres,public Oyun
{
	public:
		void uyePanel()
		{
			
			if(giris())
			{
				basarili(user.ad + " Sisteme HoþGeldin...\n","Giriþ");
				uyeMenu();
			}
			
		}
		void uyeMenu()
		{
			dilAyar();
			string secimler[] = {"Adres Sistemi","Uygulamalar","Oyunlar","Geri"};

            
			 bool h = false, cikis = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(	menuInfo("Üye Menüsü",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
			     temizle();
			 	switch(secim)
			 	{
			 		case 1:
			 		     adresMenu();
			 			break;
			 		case 3:
			 			 oyunMenu();
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


class UyelikSistemi:public UyeMenu
{
	public:
		void menu()
		{
			dilAyar();
			 string menuInfo = "1)Kaydol\n2)Giriþ\n3)Þifre Yenile\n4)Admin Paneli\nSeçim:";
			 
			 bool h = false;
			 do
			 {
			 	h = false;
			    int secim = veriGiris(menuInfo,i);
			     temizle();
				 switch(secim)
				 {
				 	case 1:
				 		kaydol();
				 		temizle();
				 		break;
				 	case 2:
					    uyePanel();
					    break;
					case 3:
					    sifreYenile();
					    break;
					case 4:
					    panel();
					    break;
					default:
					   hata("Hatali Seçim Yapýldý !!!","Hatali Seçim");  
					   h = true;	
				 }
			 }while(1);
		}
	
};



int main()
{
   UyelikSistemi uye;
   uye.menu();
   
	return 0;
}

