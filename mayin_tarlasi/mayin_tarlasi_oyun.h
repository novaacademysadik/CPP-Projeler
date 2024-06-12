class MayinTarlasi: public Tanim
{
	public:
	int size = 0;
	int score = 0;
	int line, column;
	
	char game_map[5][5];
	int figure[5][5];
	
	int level_option()
	{
		
		baslik(" MAYIN TARLASI ");

		int level = veriGiris("1) Kolay\n2) Orta\n3) Zor\n\nBir seviye seçiniz: ",i);
		
		switch(level)
		{
			case 1:
				temizle();
				return 5;
			case 2:
				temizle();
				return 3;
			case 3:
				temizle();
				return 2;
			
			default:
				temizle();
				hata("Hatalý bir seçim gerçekleþtirildi!", "HATA");
		}
	
	}
	
	void create_map()
	{
		game_map[size][size];
		figure[size][size];
		int target = 0; // oyun haritasýnda oyuncunun atýþ yapacaðý noktayý seçebilmesi için
		
		for(int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				figure[i][j] = target + 1;
				target++;
			}
		}
		
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
			{
				game_map[i][j] = '0';
			}
		}
	}
	
	void fill_map()
	{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				cout<<figure[i][j]<< " ";
				
			cout<<endl;
		}
	}
	
	void add_mine()
	{
		srand(time(0));
	
		for(int i=0; i<size; i++)
		{
			do
			{
				line = generate_mine();
				column = generate_mine();
				
			}while(game_map[line][column] == 'X');
			
			game_map[line][column] = 'X';
		}
	}
	
	void show_mine()
	{
		for(int i=0; i<size; i++)
		{
			for(int j=0; j<size; j++)
				cout<<game_map[i][j]<<" ";

			cout<<endl;
		}
	}
	
	int generate_mine()
	{
		return rand() % size;
	}
	
	void game_start()
	{
		bool life = false;
		bool cell = false;
		int choice;
		
		while(!life && score != 300)
		{
			cell = false;
			
			choice = veriGiris("Bir hedef seçiniz: ", i);
			cout<<endl;
			
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<size; j++)
				{
					if(figure[i][j] == choice)
					{
						cell = true;
						
						if(game_map[i][j] == 'X')
						{
							life = true;
							system("color 40");
							text_print("***** MAYIN! *****\n");
						}
						
						else
							figure[i][j] = 0;
					}
				}
			}
			
			if(!cell)
			{
				text_print("Geçersiz bir hedef seçildi!\n");
			}
				
				
			if(life)
				show_mine();
				
			else
			{
				if(choice !=0 && cell == true)
					calculate_score();
				
				fill_map();
			}
			
			show_score();
		}
		
		temizle();
	}
	
	void calculate_score()
	{
		switch(size)
		{
			case 2:
				score += 150;
				break;
				
			case 3:
				score += 50;
				break;
				
			case 5:
				score += 30;
				break;
		}
	}
	
	void show_score()
	{
		text_print("--------------\n");
		cout<<"SKOR: "<<score<<endl;
		text_print("--------------\n");
		
		if(score == 300)
		{
			system("color 20");
			text_print("EN YÜKSEK SKORA ULAÞILDI, TEBRÝKLER, " + user.ad + " !");
			Sleep(1000);
		}	
	}
	
	void mayin_tarlasi_oyna()
	{
		int ans;
		
		do
		{
			score = 0;
			size = level_option();
			create_map();
			add_mine();
			fill_map();
			game_start();
			
			ans = soru("Tekrar oynamak ister misiniz?","MAYIN TARLASI");
			system("color 07");
			
		}while(ans == IDYES);
		
		temizle();
		text_print("Çýkýþ yapýlýyor...");
		Sleep(1000);
	}
	
	void save_score(string fileName, Bilgi game) //kullanýcýnýn puanýný txt dosyasýna yazdýrýr
	{
		ofstream file(fileName.c_str(), ios::app);
		
		file<<"-"<<game.id;
		file<<"-"<<game.kul_ad;
		file<<"-"<<score<<"-"<<endl;
		
		basarili("Skorunuz baþarýyla kaydedildi!","MAYIN TARLASI");
	
		file.close();
	}
	/*
	void show_highest_score(string kulAd) // kullanýcýlar arasýndan en yüksek skora ulaþan kullanýcý adý ve puaný gösterir
	{
		ifstream file;
		file.open("mayin-tarlasi.txt");
		
		string veriler[3];
		
		while(getline(file,veriler[0],'-') && getline(file,veriler[1],'-'))
		{
			getline(dosya,veriler[2],'-'); // score
			
		   if(id == 0)
			{
				if(veriler[1] == kulAd )
			    {
			    	score = veriler[4];
					return true;
				}
				  
			}
			else
			{
				if(veriler[1] == stringYap(id) )
				{
					detay.id = intYap(veriler[1] );
					detay.kul_ad = veriler[3];
					detay.ad = veriler[2];
					detay.sifre = veriler[4];
					
					return true;
				}
				  
			}	
			
		}
		
	//	hata("Kiþi bulunamadý ...","HATA");
	
		return false;
	}
	
	
	*/
	void show_user_score() // kullanýcýnýn son puanýný gösterir
	{
		
	}
	
	
};
