class Word_register: public virtual Tanim
{
	private:
		string word;
		string word_on_list;
		int piece; //kaydedilecek kelime sayýsý
		
	public:
		void save_word()
		{
			ofstream print_file("kelime_oyunu/kelimeler.txt", ios::app);
			
			piece = veriGiris("Kaydedilecek Kelime Sayýsý: ", piece);
			
			for(int i = 0; i < piece; i++)
			{
				do
				{					
					cout<< i + 1;
					word = veriGiris(".Kelime: ", s);
					
				}while(word_control(word,"kelime_oyunu/kelimeler.txt"));
				
				
				
				print_file << word << endl;
			}
			
			print_file.close();
			
			cout<<"Kayýt baþarýlý..."<<endl;
			Sleep(1000);
			temizle();
		}
		
		
		bool word_control(string word_control,string file_name)
		{
			ifstream read_word(file_name.c_str());
			string listed_word;
			read_word.close();
			read_word.open(file_name.c_str());
			
			while(read_word >> listed_word)
			{

				if(word_control == listed_word)
				{
					text_print("Bu kelime listede mevcut...\n");
					return true;
				}
			}
				
			read_word.close();	
			
			return false;
		}

};

