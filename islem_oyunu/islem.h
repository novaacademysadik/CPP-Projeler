class islem_game{
	private:
		
		int highest;
		int lowest;
		
		char chars[4] = {'+','-','/','*'};
		
		int random_number(int highest, int lowest = 0){
			srand(time(0));
			return rand() % highest + lowest;	
		}
		
		void difficulty(){
			int ans;
			
			system("cls");
			do{
				ans = int_input("Choose a difficulty!\n1) Easy\n2) Normal \n3) Difficult\n");
				if(ans >= 4|| ans <= 0)
					print("Bad Input!!\n");
				else
					break;
			}while(true);
			
			if(ans == 1){
				highest = 100;
				lowest = 10;
			}
				
			else if(ans == 2){
				highest = 500;
				lowest = 50;
			}
				
			else{
				highest = 1000;
				lowest = 100;
			}		
			
			print("Game starting");
			animate('.');
			game();
		}
		
		void game(){
			int hp = 5;
				
			int	number;
			int number2;
			
			int p_answer;
			int answer;
			
			int islem = random_number(4);
			char Islem;
			
			if(islem == 0){
				
				number = random_number(highest,lowest);
				number2 = random_number(highest,lowest);
														
				Islem = '+';
				answer = number + number2;
			}
			
			else if(islem == 1){
				
				number = random_number(highest,lowest);
				number2 = random_number(highest,lowest);
					
				Islem = '-';
				
				answer = number - number2;
			}
			
			else if(islem == 2){
				
				do{
					number = random_number(highest,lowest);
					number2 = random_number(highest,lowest);	
				}while(number % number2 != 0 && number < number2);
				
				Islem = '/';
				
				answer = number / number2;
			}
			
			else{
				Islem = '*';
				answer = number * number2;
			}
			do{
				system("cls");
				
				print("Your hp:");
				print(hp);
				print("\n\n");
				print("question:");
				print(number);
				print(Islem);
				print(number2);
				
				p_answer = int_input("\nYour Answer:");
				
				if(hp == 0){
					print("You lose!!!");
					break;
				}
				
				if(p_answer != answer){
					print("Wrong Answer!!");
					hp--;
					Sleep(400);
				}
				else{
					print("\nYou win!!!\n");
					Sleep(1000);
					break;
				}
			}while(true);
		}
		
		public:
			
		void start_islem(){
			difficulty();
		}
};
