
class Mesaj
{
	public:
		
		void hata(string m,string b)
		{
			MessageBox(0,m.c_str(),b.c_str(),MB_ICONERROR);
		}
		void basarili(string m,string b)
		{
			MessageBox(0,m.c_str(),b.c_str(),MB_ICONINFORMATION);
		}
		
		int soru(string m,string b)
		{
			return MessageBox(0,m.c_str(),b.c_str(),MB_YESNO);
		}
		
		
};
