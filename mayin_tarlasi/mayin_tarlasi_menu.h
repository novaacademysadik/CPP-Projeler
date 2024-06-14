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
					skor_tablosu("mayin_tarlasi/skorlar.txt");
					mayin_tarlasi_menu(u);
					break;
					
				case 3:
					son_skor_goster("mayin_tarlasi/skorlar.txt");
					temizle();
					mayin_tarlasi_menu(u);
					break;
					
				case 0:
					exit_game = true;
					break;
			}
			
				
		}while(exit_game);
		
	}
};
