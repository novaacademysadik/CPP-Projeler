class Ayar
{
	public:
		string menuBaslik[50];	
		void dilAyar()
		{
			SetConsoleCP(1254);
			SetConsoleOutputCP(1254);
		}
		void temizle()
		{
			system("cls");
		}
		void ac(string dosyaAd)
		{
			string ad = "start "+dosyaAd;
			system(ad.c_str());
		}
		void baslik(string baslik)
		{
			temizle();
			cout<<"******"<<baslik<<"******"<<endl;
			
		}
		
};
