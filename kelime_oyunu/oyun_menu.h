class Oyun_menu:public virtual Tanim, public Word_register, public Word_finder
{
	private:

	public:
		
		int menu()
		{
			int selection;
			
			text_print("== Oyun Men�s�ne Ho� Geldiniz ==\n\n");
			text_print("1.Kelime Ekle\n2.Kelime Oyunu Oyna\n\n");
			selection = veriGiris("Se�im: ",i);
		
			return selection;
		}
		
		
		void game_menu()
		{
			dilAyar();
			int selection;
			
			selection = menu();
			
			switch(selection)
			{
				case 1:
					save_word();
					break;
					
				case 2:
					system("cls");
					text_print("===== ADAM ASMACA OYUNUNA HO�GELD�N�Z =====\n\n");
					word_find();
					break;
					
				default:
					text_print("Ge�ersiz Se�im");
			}
		}

};
