class Kelime_Oyunu:public virtual Tanim, public Word_register, public Word_finder
{
	private:

	public:
	int selection;
		
	void game_menu()
		{	
			text_print("== Oyun Men�s�ne Ho� Geldiniz ==\n\n");
			text_print("1.Kelime Ekle\n2.Kelime Oyunu Oyna\n3.Geri\n\n");
			selection = veriGiris("Se�im: ",i);

		}
	
	void Kelime_Oyunu_Menu()
	{
	    dilAyar();
		bool t;
		
		do
		{
			game_menu();
		
			t = true;
			switch(selection)
			{
				case 1:
					save_word();
					break;
					
				case 2:
					system("cls");
					text_print("===== KEL�ME OYUNUNA HO�GELD�N�Z =====\n\n");
					word_find();
					break;
				case 3:
					t = false;
					break;	
				default:
					text_print("Ge�ersiz Se�im");
			}
		}while(t);
	}
};
