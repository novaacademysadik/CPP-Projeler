#include "../inc.h"

class Menu: public Tanim
{
	public:
		
	int level_option()
	{
		dilAyar();
		baslik(" MAYIN TARLASI ");
		
		
		int level = veriGiris("1) Kolay\n2) Orta\n3) Zor\n\nBir seviye seçiniz: ",i);
		
		switch(level)
		{
			case 1:
				return 5;
			case 2:
				return 3;
			case 3:
				return 2;
			
			default:
				hata("Hatalý bir seçim gerçekleþtirildi!", "HATA");
		}
	}
};



int main()
{
	
	Menu m;
	m.level_option();
	
	return 0;
}
