class BattleShipMenu: public BattleShip
{
	public:
	int selection;
	bool exit_game;
	
	void battle_ship_menu(Bilgi u)
	{
		user = u;

		dilAyar();
		do
		{	
			baslik(" AM�RAL BATTI ");
			selection = veriGiris("1.Oyun Oyna\n2.Skorboard G�ster\n0) ��k��\n\nSe�iminiz: ",i);
	   
			switch(selection)
			{
				case 1:
					play_game();
					break;
					
				case 2:
					skor_tablosu("amiral_batti/amiral_batti_skor.txt");
					break;
					
				case 0:
					exit_game = false;
					break;
				
			}
			
				
		}while(exit_game);		
	}		
};
