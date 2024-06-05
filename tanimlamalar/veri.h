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
		cout<<info;
		getline(cin,s);
		
		return s;
	}
	
	template <typename X>
	X veriGiris(string info,X deger)
	{
		cout<<info;
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
	
	
	
};
