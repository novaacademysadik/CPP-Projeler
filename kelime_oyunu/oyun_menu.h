class Oyun_menu:public virtual Tanim, public Word_register, public Word_finder
{
	private:

	public:
		
		int menu()
		{
			int selection;
			
			text_print("== Oyun Menüsüne Hoþ Geldiniz ==\n\n");
			text_print("1.Kelime Ekle\n2.Kelime Oyunu Oyna\n\n");
			selection = veriGiris("Seçim: ",i);
		
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
					text_print("===== ADAM ASMACA OYUNUNA HOÞGELDÝNÝZ =====\n\n");
					word_find();
					break;
					
				default:
					text_print("Geçersiz Seçim");
			}
		}

};
