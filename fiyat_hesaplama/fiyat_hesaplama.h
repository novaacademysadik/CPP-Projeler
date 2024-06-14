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
			baslik(" �R�N F�YATI HESAPLAMA PROGRAMI ");
			cout<<endl;
			
			text_print("Ho� geldin "+ user.ad + " !");
			cout<<endl<<endl;
			tercih = veriGiris("1) KDV oran�na g�re\n2) �ndirim oran�na g�re\n0) ��k��\n\nFiyat hesaplamas� yapmak istedi�iniz i�lem tipini se�iniz: ", i);
			
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
					hata("Hatal� bir se�im ger�ekle�ti!", "HATA!");	
			}
			
			if(cevap == IDNO || tercih == 0)
				text_print("Uygulamalar Men�s�'ne d�n�l�yor...");

				
		}while(exit && cevap == IDYES);
	}

	void kdv_hesapla()
	{
		fiyat = fiyat_kayit();
		oran = oran_kayit("KDV oran� (%): ");
		
		fiyat = fiyat*((oran/100) + 1);
		
		text_print("KDV dahil fiyat: " + stringYap(fiyat));
		cevap = soru("Yeni bir i�lem yapmak ister misiniz?", "�R�N F�YATI HESAPLAMA PROGRAMI");
	}
	
	void indirim_hesapla()
	{
		fiyat = fiyat_kayit();
		oran = oran_kayit("�ndirim oran� (%): ");
		
		fiyat = fiyat*(1 - (oran/100));
		
		text_print("�ndirimli fiyat: " + stringYap(fiyat));
		cevap = soru("Yeni bir i�lem yapmak ister misiniz?", "�R�N F�YATI HESAPLAMA PROGRAMI");
	}
	
	double fiyat_kayit()
	{
		baslik(" �R�N F�YATI HESAPLAMA PROGRAMI ");
		
		do
		{
			fiyat = veriGiris("Fiyat: ",d);
			
		}while(!veri_kontrol(fiyat));
		
		return fiyat;
	}
	
	double oran_kayit(string mesaj)
	{
		baslik(" �R�N F�YATI HESAPLAMA PROGRAMI ");
		
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
			hata("0'dan k���k de�erler girilemez!", "HATA!");
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
