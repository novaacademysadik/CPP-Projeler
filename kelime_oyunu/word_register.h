class Word_register: public virtual Tanim
{
	private:
		string word;
		int piece; //kaydedilecek kelime say�s�
		
	public:
		void save_word()
		{
			ofstream print_file("kelimeler.txt", ios::app);
			
			piece = veriGiris("Kaydedilecek Kelime Say�s�: ", piece);
			
			for(int i = 0; i < piece; i++)
			{
				cout<< i + 1;
				word = veriGiris(".Kelime: ", s);
				
				print_file << word << endl;
			}
			
			print_file.close();
		}

};

