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
		   b1.ad = metinGiris("Ad�n�z:");
          do
			{
				
			  b1.kul_ad = metinGiris("Kulland�c� Ad�n�z:");
		
			}while(kulAdKontrol(b1.kul_ad,"uyeler.txt") == false);
			
			do
			{
			  b1.sifre = veriGiris("�ifre:",s);	
			}while(sifreKontrol(b1.sifre) == false);

		   	kayit("uyeler.txt",b1);
	
		}
		

		 
		 bool giris()
		 {
		 		
		 	do
		 	{
		 		b1.kul_ad = veriGiris("Kullan�c� Ad�[��k��:0]:",s);
		 	    b1.sifre = veriGiris("�ifre: ",s);
		 	    if(!kullaniciKontrol(b1.kul_ad,b1.sifre,"uyeler.txt") && b1.kul_ad != "0")
		 	        hata("Hatali Giri�","Hata");
		 		
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
	      		b1.kul_ad = veriGiris("Kullanici Ad�:",s);
	      		
			 }while(!veriKontrol(b1.kul_ad,0,"uyeler.txt"));
	      	
	      	cout<<"eski sifre: "<<sonSifre<<endl;
	      	do
			{
			  b1.sifre = veriGiris("Yeni �ifreyi Giriniz:",s);	
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
				basarili(user.ad + " Sisteme Ho�Geldin...\n","Giri�");
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
			    int secim = veriGiris(	menuInfo("�ye Men�s�",secimler,sizeof(secimler) / sizeof(secimler[0])),i);
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
			 string menuInfo = "1)Kaydol\n2)Giri�\n3)�ifre Yenile\n4)Admin Paneli\nSe�im:";
			 
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
					   hata("Hatali Se�im Yap�ld� !!!","Hatali Se�im");  
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

