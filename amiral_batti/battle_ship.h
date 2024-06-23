class BattleShip: public virtual Tanim
{
	public:
		
		int size;
		int level;
		char game[5][5];
		string shape[5][5];
		int score, pc_score;
		int score_counter;
		int type;
		
		void game_struct()
		{
			size = level;
			score_counter = level * level;
			game[size][size];
			shape[size][size];

		}
		
		int game_level()
		{
			text_print("***** Amiral Batt� Oyununa Ho� Geldiniz *****\n");
			level = veriGiris("1.Kolay\n2.Orta\n3.Zor\n4.�ok Zor\n\nBir seviye se�iniz: ",i);
			
			switch(level)
			{
				case 1:
					text_print("Oyun ");
					loading(1);
					level = 2;
					break;
					
				case 2: 
					text_print("Oyun ");
					loading(2);
					level = 3;
					break;
					
				case 3:
					text_print("Oyun ");
					loading(3);
					level = 4;
					break;
				
				case 4:
					
					text_print("Oyun ");
					loading(4);
					level = 5;
					break;
			}
			
			return level;
		}
		
		int game_type()
		{
			text_print("Oyun �ekli\n");
			type = veriGiris("1.Solo Oyna\n2.Bilgisayara Kar�� Oyna\n\nSe�im: ", type);
			
			return type;
		}
		
		void create_field()
		{
			int h = 1;
			
			for(int i = 0; i < size; i++)
			{
				for(int j = 0 ; j < size; j++)
				{
					shape[i][j] = stringYap(h);
					h++;
				}		
			}
			
			for(int i = 0; i < size; i++)
			{
				for(int j = 0 ; j < size; j++)
				{
					game[i][j] = 'X';
				}		
			}	
		}
		
		void show_shape()
		{
			for(int i = 0; i < size; i++)
			{
				for(int j = 0 ; j < size; j++)
				{
					cout<< "["<<shape[i][j] << "] ";
				}
				
				cout<< endl;
			}
		}
		
		int random_number()
		{
			return rand() % size;
		}
		
		void add_ship()
		{
			srand(time(0));
			
			int line;
			int column;
			
			for(int i = 0; i < size; i++)
			{
				do
				{
					line = random_number();
					column = random_number();
				
				}while(game[line][column] == 'T');
				
				game[line][column] = 'T';
			}
		}
		
		void show_ship() // gemileri g�steren fonksiyon
		{
			for(int i = 0; i < size; i++)
			{
				for(int j = 0 ; j < size; j++)
					cout<< "["<< game[i][j] << "]";
	
				cout<< endl;
			}
		}
		
		void start_game()
		{
			srand(time(0));
			bool target = false;
			bool is_target = false;
			int selection;
			int selection_pc;
			int counter = 0;
			int target_counter = 0;
			score = 0;
			pc_score = 0;
			int list_counter = 0;
			
			bool status;
			int list[25];
			
			for(int i = 0; i < 25; i++)
				list[i] = 0;
				

		
			while(counter < (size * size))
			{
				temizle();
				show_shape();
				cout<<"\n---------------\n";
				text_print("Skorunuz: ");
				cout<< score << endl;
				
				text_print("CPU skor: ");
				cout<< pc_score << endl;
				cout<<"---------------\n";

				do
				{
					text_print("Sizin S�ran�z!\n");
					Sleep(500);
					is_target = false;
					do
					{
						status = false;
						
						selection = veriGiris("Bir h�cre se�in: ", selection);
						
						for(int j = 0; j < 25; j++)
						{
							if(list[j] == selection)
								status = true;
						}
						
						if(status == true)
							text_print("Bu h�cre daha �nce se�ildi\n");
	
					}while(status);
					
					list[list_counter] = selection;
					list_counter++;
			
					for(int i = 0; i < size; i++)
					{	
						for(int j = 0; j < size; j++)
						{						
							if(shape[i][j] == stringYap(selection))
							{
	
								if(game[i][j] == 'X')
								{
									target = false;
									shape[i][j] = " ";
									text_print("Yapt���n�z At��: �SABETS�Z!!!\n");
									Sleep(2000);
									score_counter--;
								}
		
								else
								{
									shape[i][j] = "T";
									text_print("Yapt���n�z At��: �SABETL�!!!\n");
									Sleep(2000);
									target_counter++;
									score = score + score_counter * level;
									is_target = true;
									if(target_counter == size)
										goto result;
								}	
							}
						}		
					}
					
				temizle();
				show_shape();
				cout<<"\n---------------\n";
				text_print("Skorunuz: ");
				cout<< score << endl;
				
				text_print("CPU skor: ");
				cout<< pc_score << endl;
				cout<<"---------------\n";
					
				}while(is_target == true);
				

				
				// bilgisayar�n oynad��� k�s�m
				do
				{
					text_print("Bilgisayar�n S�ras�!\n");
					Sleep(500);
					is_target = false;
					do
					{
						status = false;
						selection_pc = rand() % (level * level) + 1;
						
						for(int j = 0; j < 25; j++)
						{
							if(list[j] == selection_pc)
								status = true;
						}
							
						if(counter == size * size)
							break;
	
					}while(status);
					
					list[list_counter] = selection_pc;
					list_counter++;
					
					
					for(int i = 0; i < size; i++) // bilgisayar i�in d�ng�
					{					
						for(int j = 0; j < size; j++)
						{
							if(shape[i][j] == stringYap(selection_pc))
							{
								if(game[i][j] == 'X')
								{
									target = false;
									shape[i][j] = " ";
									text_print("B�lgisayar�n Se�imi: " + stringYap(selection_pc) + "\n�SABETS�Z!!!\n");
									Sleep(2000);
									score_counter--;
								}
								else
								{
									shape[i][j] = "T";
									text_print("B�lgisayar�n Se�imi: " + stringYap(selection_pc) + "\n�SABETL�!!!\n");
									Sleep(2000);
									target_counter++;
									pc_score = pc_score + score_counter * level;
									is_target = true;
									if(target_counter == size)								
										goto result2;
								}	
							}
						}		
					}

				}while(is_target == true);
				
				list[list_counter] = selection;
				list_counter++;

				counter++;

				result:
				result2:
				if(target_counter == size)
				{
					temizle();
					show_shape();
					cout<<"-------------------\n";
					text_print("Hedefler Yok edildi\n");
					cout<<"-------------------\n\n";
					counter = size * size;
					
					text_print("*** OYUN SONU ***\n");
					cout<<"-----------------\n";
					text_print("Skorunuz: ");
					cout<< score << endl;
					
					text_print("CPU Skoru: ");
					cout<< pc_score << endl;
					cout<<"-----------------\n";
				}
				
			}
			if(pc_score > score)
				basarili("Bilgisayar Kazand�!", "Oyun Sonu");
			else
				basarili("Tebrikler Kazand�n�z!", "Oyun Sonu");
				
			skor_kayit("amiral_batti/amiral_batti_skor.txt",score);
		}

		
		void play_game()
		{
			int answer;

			do
			{
				temizle();
				dilAyar(); // bunu men�ye ta��
				game_level();
				temizle();
				game_struct();
				create_field();
				add_ship();
				
				//show_ship();
				start_game();
				
				answer = soru("Tekrar Oynamak �ster Misiniz?"," AM�RAL BATTI");
				
			}while(answer == IDYES);
			
			temizle();
			text_print("Oyun Men�s�ne D�n�l�yor...\n");
			Sleep(1000);
		}
	
};
