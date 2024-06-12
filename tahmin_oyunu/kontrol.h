class kontrol
{
	public:
		Mesaj m;
		bool uzunluk(string metin , int uzunluk, char kb)
		{
			stringstream s1;
			s1<<uzunluk;
			string mesaj1  = "Girdiğiniz kelime "+s1.str()+" harften uzun olmalıdır";
			string mesaj2  = "Girdiğiniz kelime "+s1.str()+" harften Kısa olmalıdır";

			bool d = true;
			
			if(kb == 'k' || kb == 'K')
				if(metin.size() <= uzunluk)
					m.hata(mesaj1,"Tahmin Oyunu");
					return false;
			if(kb == 'b' || kb == 'B')
				if(metin.size() >= uzunluk)
					m.hata(mesaj1,"Tahmin Oyunu");
					return false;	
			
			return true;	
		}
		bool Sayi(int sayi , int uzunluk, char kb)
		{
			stringstream s1;
			s1<<uzunluk;
			string mesaj1  = "Girdiğiniz Sayı "+s1.str()+" 'dan büyük olmalıdır";
			string mesaj2  = "Girdiğiniz Sayı "+s1.str()+" 'dan Küçük olmalıdır";

			bool d = true;
			
			if(kb == 'k' || kb == 'K')
				if(sayi < uzunluk)
					m.hata(mesaj1,"Tahmin Oyunu");
					return false;
			if(kb == 'b' || kb == 'B')
				if(sayi > uzunluk)
					m.hata(mesaj1,"Tahmin Oyunu");
					return false;	
			
			return true;
		}
};
