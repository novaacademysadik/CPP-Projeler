class kontrol
{
	public:
		Mesaj m;
		bool uzunluk(string metin , int uzunluk, char kb)
		{
			stringstream s1;
			s1<<uzunluk;
			string mesaj1  = "Girdi�iniz kelime "+s1.str()+" harften uzun olmal�d�r";
			string mesaj2  = "Girdi�iniz kelime "+s1.str()+" harften K�sa olmal�d�r";

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
			string mesaj1  = "Girdi�iniz Say� "+s1.str()+" 'dan b�y�k olmal�d�r";
			string mesaj2  = "Girdi�iniz Say� "+s1.str()+" 'dan K���k olmal�d�r";

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
