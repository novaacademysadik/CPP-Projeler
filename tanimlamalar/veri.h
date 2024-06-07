class Veri
{
	public:
	string s;
	int i;
	char c;
	bool b;
	double d;
	
	string metinGiris(string info)
	{
		text_print(info);
		getline(cin,s);
		
		return s;
	}
	
	template <typename X>
	X veriGiris(string info,X deger)
	{
		text_print(info);
		cin>>deger;
		
		return deger;
	}
	
	string stringYap(int veri)
	{
		stringstream s1;
		s1<<veri;
		
		return s1.str();
	}
	
	int intYap(string veri)
	{
		int deger;
		
		stringstream i(veri);
		i>>deger;
		
		return deger;
		
		
	}
	
	void text_print(string baslik) // kayan yazı efekti fonksiyonu
	{
		for(int i = 0; i < baslik.size(); i++)
		{
			cout<<baslik[i];
			Sleep(1);
		}
	}
	
	
	
};
