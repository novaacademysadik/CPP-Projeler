#include "includes.h"
#include "Print.h"
#include "battle.h"

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
				ans = int_input("Bir Zorluk Sec!\n1) Kolay\n2) Normal\n3) Zor\n");
				if(ans >= 4|| ans <= 0)
					print("Hatal� giri�!!\n");
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
			
			print("Oyun Ba�lat�l�yor");
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
				
				print("Can�n:");
				print(hp);
				print("\n\n");
				print("Soru:");
				print(number);
				print(Islem);
				print(number2);
				
				p_answer = int_input("\nCevab�n:");
				
				if(hp == 0){
					print("Kaybettin!!!");
					break;
				}
				
				if(p_answer != answer){
					print("Yanl�� Cevap!!");
					hp--;
					Sleep(400);
				}
				else{
					print("\nKazand�n!!!\n");
					Sleep(1000);
					break;
				}
			}while(true);
		}
};

void islem_oyunu_oyna()
{
	islem_game islem;
	
	islem.difficulty();
}

void savas_oyunu_oyna{
	savas_baslat();
}
