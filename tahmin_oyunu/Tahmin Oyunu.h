class Oyun :public Tanim
		{
	public:
		Ayar a;
		int z;
		string zorluk = "Normal";
		int tur = 3;
		
		
		void Zorluk()
		{
			a.baslik("Tahmin Oyunu");
			cout<<"Güncel Zorluk : "<<zorluk<<endl;
			z = veriGiris("Zorluk Ayarlayın \n[1] Kolay\n[2] Normal\n[3] Zor ",z);
			
			switch (z)
			{
				case 1:
					zorluk = "Kolay";
					break;
				case 2:
					zorluk = "Normal";
					break;
				case 3:
					zorluk = "Zor";
					break;
			}
			Ayarlar();
		}
		void TurAyar()
		{
			a.baslik("Tahmin Oyunu");
			cout<<"Güncel Tur Sayısı : "<<tur<<endl;
			tur = veriGiris("Tur Sayısını Ayarlayın",tur);
			Ayarlar();	
		}
		void Ayarlar()
		{
			
			int secim;
			
			a.baslik("Tahmin Oyunu");
			secim = veriGiris("[1] Zorluk Ayarları\n[2] Tur Ayarları\n[3]Ana Menü",secim);
			
			switch (secim)
			{
				case 1:
					Zorluk();
					break;
				case 2:
					TurAyar();
					break;
				case 3:
					menu();
					break;
					
					
			}
		}
		void menu()
		{
			int secim;
			
			a.baslik("Tahmin Oyunu");
			secim = veriGiris("[1] Oyuna Başla\n[2] Skor Görüntüle\n[3] Ayarlar",secim);
			
			switch (secim)
			{
				case 1:
					Basla();
					break;
				case 2:
					//Skor();
					break;
				case 3:
					Ayarlar();
					break;
			}
		}
		void Basla()
		{
			srand(time(0));
			int id , as , npc = 0, plyr = 0, soru;

			for(int i = 0;i<tur;i++)
			{
				a.baslik("Tahmin Oyunu");
				cout<<"=== "<<i+1<<".Tur ==="<<endl;
				
				
				
				switch (z)
				{
					case 1:
						id = rand()&10;
						as = veriGiris("1 ile 10 Arasında Bir Sayı Tuttum Bakalım Bilebilecekmisin ? ",as);	
						break;
					case 2:
						id = rand()&100;
						as = veriGiris("1 ile 100 Arasında Bir Sayı Tuttum Bakalım Bilebilecekmisin ? ",as);
						break;
					case 3:
						id = rand()&1000;
						as = veriGiris("1 ile 1000 Arasında Bir Sayı Tuttum Bakalım Bilebilecekmisin ? ",as);
				}
				cout<<"sasasa"<<endl;
				if(as == id)
				{
					plyr++;
					cout<<"Kazandın Skor : "<<plyr<<" - "<<npc;
					Sleep(1000);
				}
				else
				{
					npc++;
					cout<<"Kaybettin Sayı "<<id<<" Olmalıydı Skor : "<<plyr<<" - "<<npc;	
					Sleep(1000);
				}
							
			}
			a.baslik("Tahmin Oyunu");
			if(npc > plyr)
				cout<<"Malesef Kaybettin :( ";
			else
				cout<<"Waoow Kazandın :))) ";
			
			soru = 	MessageBox(0,"Tekrar Denemek İstermisiniz ??","Tahmin Oyunu", MB_ICONINFORMATION | MB_YESNO);
			if(soru == IDYES)
				menu();
		}
};
