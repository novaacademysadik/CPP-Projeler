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
			loading(10);
			temizle();
			baslik(" MAYIN TARLASI ");
			ans = veriGiris("1) Oyun Oyna\n2) T�m Skorlar� G�ster\n3) Son Skorumu G�ster\n0) ��k��\n\nSe�iminiz: ",i);
	   
			switch(ans)
			{
				case 1:
					mayin_tarlasi_oyna();
					break;
					
				case 2:
					ac("mayin_tarlasi/skorlar.txt");
					exit_game = true;
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
