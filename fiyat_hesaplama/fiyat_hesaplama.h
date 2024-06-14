class Fiyat: public Tanim
{
	public:
	double fiyat, oran;
	
	int tercih, cevap;
	
	void fiyat_hesapla_menu(Bilgi u)
	{
		bool exit = true;
		do
		{
			user = u;
			dilAyar();
			baslik(" ÜRÜN FÝYATI HESAPLAMA PROGRAMI ");
			cout<<endl;
			
			text_print("Hoþ geldin "+ user.ad + " !");
			cout<<endl<<endl;
			tercih = veriGiris("1) KDV oranýna göre\n2) Ýndirim oranýna göre\n0) Çýkýþ\n\nFiyat hesaplamasý yapmak istediðiniz iþlem tipini seçiniz: ", i);
			
			switch(tercih)
			{
				case 1:
					loading(15);
					kdv_hesapla();
					break;
					
				case 2:
					loading(15);
					indirim_hesapla();
					break;
					
				case 0:
					exit = false;
					break;
					
				default:
					hata("Hatalý bir seçim gerçekleþti!", "HATA!");	
			}
			
			if(cevap == IDNO || tercih == 0)
				text_print("Uygulamalar Menüsü'ne dönülüyor...");

				
		}while(exit && cevap == IDYES);
	}

	void kdv_hesapla()
	{
		fiyat = fiyat_kayit();
		oran = oran_kayit("KDV oraný (%): ");
		
		fiyat = fiyat*((oran/100) + 1);
		
		text_print("KDV dahil fiyat: " + stringYap(fiyat));
		cevap = soru("Yeni bir iþlem yapmak ister misiniz?", "ÜRÜN FÝYATI HESAPLAMA PROGRAMI");
	}
	
	void indirim_hesapla()
	{
		fiyat = fiyat_kayit();
		oran = oran_kayit("Ýndirim oraný (%): ");
		
		fiyat = fiyat*(1 - (oran/100));
		
		text_print("Ýndirimli fiyat: " + stringYap(fiyat));
		cevap = soru("Yeni bir iþlem yapmak ister misiniz?", "ÜRÜN FÝYATI HESAPLAMA PROGRAMI");
	}
	
	double fiyat_kayit()
	{
		baslik(" ÜRÜN FÝYATI HESAPLAMA PROGRAMI ");
		
		do
		{
			fiyat = veriGiris("Fiyat: ",d);
			
		}while(!veri_kontrol(fiyat));
		
		return fiyat;
	}
	
	double oran_kayit(string mesaj)
	{
		baslik(" ÜRÜN FÝYATI HESAPLAMA PROGRAMI ");
		
		do
		{
			oran = veriGiris(mesaj,d);
			
		}while(!veri_kontrol(oran));
		
		return oran;
	}
	
	bool veri_kontrol(double veri)
	{
		if(veri<=0)
		{
			hata("0'dan küçük deðerler girilemez!", "HATA!");
			return false;
		}
		
		return true;	
	}
};

void fiyatHesapla(Bilgi b)
{
	Fiyat f;
	f.fiyat_hesapla_menu(b);
}
