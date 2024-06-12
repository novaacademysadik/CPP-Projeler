#include<iostream>
#include<windows.h>
#include<ctime>
#include<ctype.h>
#include<fstream>
#include<sstream>

using namespace std;

struct Bilgi
{
	int id;
	string ad;
	string kul_ad;
	string sifre;
};

struct AdresBilgi
{
	int id;
	string kul_ad;
	string il;
	string ilce;
	string mahalle;
	string detay;
	string baslik;
	
};

struct Skor
{
	int id;
	string kul_ad;
	int skor;
};

#include "tanimlamalar/ayar.h"
#include "tanimlamalar/veri.h"
#include "tanimlamalar/mesaj.h"
#include "tanimlamalar/dosya.h"

class Tanim:public Dosya
{
	public:
		
	string menuInfo(string b,string secimler[],int boyut)
	{
		temizle();
		baslik(b);
		string info;
	    for(int i = 0; i < boyut; i++)
	        info += stringYap(i+1) +")"+ secimler[i] + "\n";
	
			info += "0)Çýkýþ\nSeçim:";
		return info;
			 
	}
   
};

#include "admin.h"

#include "adres-sistemi.h"
#include "oyunlar.h"
#include "uygulamalar.h"





