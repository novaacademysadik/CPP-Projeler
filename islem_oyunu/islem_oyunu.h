#include "Print.h"
#include "battle.h"

int skor = 0;
int zorluk;
int highest;
int lowest;
int question = 0;
int hp = 5;
		
class islem_game{
			

	char chars[4] = {'+','-','/','*'};
		
		int random_number(int highest, int lowest = 0){
			return rand() % highest + lowest;
		}
		
	public:
		
		void difficulty(string kullanici){
			int ans;
			srand(time(0));
			
			system("cls");
			do{
				ans = int_input("Bir Zorluk Sec!\n1) Kolay\n2) Normal\n3) Zor\nSe�im:");
				if(ans >= 4|| ans <= 0)
					print("Hatal� giri�!!\n");
				else
					break;
			}while(true);
			
			if(ans == 1){
				highest = 100;
				lowest = 10;
				zorluk = 1;
			}
				
			else if(ans == 2){
				highest = 500;
				lowest = 50;
				zorluk = 2;
			}
				
			else{
				highest = 1000;
				lowest = 100;
				zorluk = 4;
			}		
			
			print("Oyun Ba�lat�l�yor");
			animate('.');
		}
		
		public:
		
		bool game(){
			question++;

			int	number;
			int number2;
			
			double p_answer;
			double answer;
			
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
				print(question);
				print(". Soru:");
				print(number);
				print(Islem);
				print(number2);
				
				p_answer = int_input("\nCevab�n:");
				
				if(hp == 0){
					return false;
				}
				
				if(p_answer != answer){
					print("Yanl�� Cevap!!");
					hp--;
					Sleep(400);
				}
				else{
					print("\nDo�ru Cevap!!!\n");
					Sleep(1000);
					return true;
				}
			}while(true);
		}	
};

void islem_oyunu_oyna(string kullanici){
	islem_game islem;
	
	islem.difficulty(kullanici);
	
	for(int i = 0; i < (zorluk * 2) + 2; i++){
		if(!islem.game()){
			print("Kaybettin!!");
			Sleep(1000);
			break;
		}	
	}
	
	skor = (hp * 5) * zorluk;
	
	print("Ald���n�z Skor:");
	print(skor);
	Sleep(2000);
}

void savas_oyunu_oyna(){
	savas_baslat();
}
