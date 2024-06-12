class Kelime_Oyunu:public virtual Tanim, public Word_register, public Word_finder
{
	private:

	public:
	int selection;
		
	void game_menu()
		{	
			text_print("== Kelime Oyununa Hoþ Geldiniz ==\n");
			cout<<("---------------------------------\n\n");
			text_print("1.Kelime Ekle\n2.Kelime Oyunu Oyna\n3.Oyunlar Menüsüne Dön\n\n");
			selection = veriGiris("Seçim: ",i);

		}
		
	void Kelime_Oyunu_Menu(Bilgi u)
	{
		user = u;
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
					word_find(u);
					break;
				case 3:
					t = false;
					break;	
				default:
					text_print("Geçersiz Seçim");
			}
		}while(t);
	}
};
