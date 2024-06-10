class Word_finder: public virtual Tanim
{
	private:
			string word;
			int counter, random_number, no;
			string hidded_word;
			
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
					text_print("Tahmin Hakk�n�z: ");
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
					text_print("Tebrikler Do�ru Tahmin :)\n");
					text_print("Skor: ");
					
					score = life * 10 + 10;
					cout<< score << endl;
				}
	
				else	
					text_print("Maalesef Yanl��!\nDo�ru Cevap: " + word + "\n");
					
				answer = veriGiris("Tekrar Oynamak �ster Misiniz? [e/h]: ", answer);
				
			}while(answer == 'e');
			
			text_print("Oyundan ��k�� Yap�ld�...");
		}
	
	
	
		void text_print(string text) // kayan yaz� efekti fonksiyonu
		{
			for(int i = 0; i < text.size(); i++)
			{
				cout<<text[i];
				Sleep(1);
			}
		}
};
