class Word_finder: public virtual Tanim
{
	private:
			string word;
			int counter, random_number, no;

			
			char letter;
			string hidden_word, guess;
			int life, score;
			char answer;	
	public:
		
		string random_word()
		{
			srand(time(0));
			
			counter = 0;
			
			ifstream read_file;
			read_file.open("kelimeler.txt");
			
			while(read_file >> word)
				counter++;
		
			read_file.close();
			
			random_number = rand() % counter ;
			
			string word_list[counter];
			
			read_file.open("kelimeler.txt");
			
			for(int i = 0; read_file >> word; i++)
				word_list[i] = word;
		
			read_file.close();
			
			word = word_list[random_number];
			
			return word;
		}	
		
		
		string hide_word(string word) // Kelime gizleme fonksiyonu
		{
			string hidded_word;
			for(int i = 0; i < word.size(); i++)
				hidded_word = hidded_word + '_';
			
			return hidded_word;
		}
		
		void word_find() // Kelime Bul Oyun Fonksiyonu
		{
	
			do
			{
				word = random_word();
		
				hidden_word = hide_word(word);
		
				text_print(hidden_word);
				
				cout<< endl;
				
				life = (word.size()/2) + 1;
				
				
				for(int i = 0; i < (word.size()/2)+1; i++)
				{
					text_print("Tahmin Hakkýnýz: ");
					cout<< life << endl;
					
					life--;
					
					letter = veriGiris("Kelimeyi tahmin ettiyseniz '1' giriniz)\nBir Harf girin: ", c);
					
					if(letter =='1')
						break;
						
					for(int j = 0; j < word.size(); j++)
					{
						if(word[j] == letter)
							hidden_word[j] = letter;
						
						else if(hidden_word[j] == ' ' || hidden_word[j] == '_')
							hidden_word[j] = '_';
					}
			
					for(int k = 0; k < word.size(); k++)
						cout<< hidden_word[k];
						
					cout<< endl;
				}	
				
				guess = veriGiris("\nKelime tahmininiz: ", guess);
				
				if(guess == word)
				{
					text_print("Tebrikler Doðru Tahmin :)\n");
					text_print("Skor: ");
					
					score = life * 10 + 10;
					cout<< score << endl;
//					save_score(user.ad,score);
				}


				else	
					text_print("Maalesef Yanlýþ!\nDoðru Cevap: " + word + "\n");
					
				
			}while(soru("Tekrar Oynamak Ýster Misiniz?","OYUN SONU") == IDYES);
			
			text_print("Oyundan Çýkýþ Yapýldý...\n\n");
			Sleep(500);
			temizle();
		}
		
		
//		void save_score(string user,int score) // 
//		{
//			ofstream print_score("kelime_oyunu_skor.txt");
//			print_score.open("kelime_oyunu_skor.txt");
//			
//			print_score << user << "-" << score << "-" << endl;
//			
//			print_score.close();
//		}

};
