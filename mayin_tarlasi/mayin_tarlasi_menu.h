class MayinTarlasiMenu: public MayinTarlasi 
{
	public:
	int ans;
	bool exit_game;
	
	void mayin_tarlasi_menu(Bilgi u)
	{
		user = u;

		dilAyar();
		do
		{
				
			baslik(" MAYIN TARLASI ");
			ans = veriGiris("1) Oyun Oyna\n2) En Y�ksek Skoru G�ster\n3) Son Skorumu G�ster\n0) ��k��\n\nSe�iminiz: ",i);
	   
			switch(ans)
			{
				case 1:
					mayin_tarlasi_oyna();
					break;
					
				case 2:
					
				//	show_highest_score();
					break;
					
				case 3:
					show_user_score();
					break;
					
				case 0:
					exit_game = true;
					break;
					
			}
			
				
		}while(exit_game);
		
	}
};
