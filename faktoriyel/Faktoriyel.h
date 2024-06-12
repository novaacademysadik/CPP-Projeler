class Faktoriyel:public virtual Tanim
{
	public:
	int sayi;
	int cevap;
	
	void baslangic()
	{
		dilAyar();
		baslik("******Faktoriyel Hesaplama******");
	}
	
	
	void sayiAlma()
	{
			sayi = 0;
				do
				{	
				
					sayi = veriGiris("Sayýyý giriniz : ",sayi);
									
					if(sayi <= 0)
					{
						cevap = MessageBox(0,"Sayý 0'dan küçük olamaz!!","HATA",MB_OK);
					}else
					{
						f_hesap();
						break;
					}
					
					
					
				}while(cevap == IDOK);
					
		
	}
	
	void f_hesap()
	{
		int toplam=1;
		int sayac=1;
	
			while(sayac <= sayi)
		{
			toplam = sayac*toplam;
			sayac++;	
		}
		s = stringYap(sayi);
		s += "! = ";
		s += stringYap(toplam);
		s += "\nTekrar denemek ister misiniz?";
		cevap =soru(s,"Sonuç");	
				
		
		
		 
		
		if(cevap == IDYES)
		sayiAlma();
		else
		cout<<"Yine bekleriz....";	
	
	}
		
};
int faktoryelHesap()
{
	
	Faktoriyel f1;
	
	f1.baslangic();
	f1.sayiAlma();
	return 0;
}


