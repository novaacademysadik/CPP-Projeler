#include "Print.h"

int skorr = 0;
int zorluk;
int highest;
int lowest;
int question = 0;
int hp = 5;
		
class islem_game:public virtual Tanim
{
			

	char chars[4] = {'+','-','/','*'};
		
		int random_number(int highest, int lowest = 0){
			return rand() % highest + lowest;
		}
		
	public:
		
		int selection(){
			int ans;
			
			do{
				int_input("1) Oyunu Oyna\n2) Skor Tablosu");
				
				if(ans > 3 || ans < 0)
					print("Hatalı Giriş!!\n");
				
			}while(ans > 3 || ans < 0);
				
			
			return ans;
		}
		
		
		void difficulty(){
			int ans;
			
			
	
			system("cls");
			do{
				ans = int_input("Bir Zorluk Sec!\n1) Kolay\n2) Normal\n3) Zor\nSeçim:");
				if(ans >= 4|| ans <= 0)
					print("Hatalı giriş!!\n");
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
			
			print("Oyun Başlatılıyor");
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
			
			else if(islem == 3){
				Islem = '*';
				answer = number * number2;
			}
			do{
				system("cls");
				
				print("Canın:");
				print(hp);
				print("\n\n");
				print(question);
				print(". Soru:");
				print(number);
				print(Islem);
				print(number2);
				
				p_answer = int_input("\nCevabın:");
				
				if(hp == 0){
					return false;
				}
				
				if(p_answer != answer){
					print("Yanlış Cevap!!");
					hp--;
					Sleep(400);
				}
				else{
					print("\nDoğru Cevap!!!\n");
					Sleep(1000);
					return true;
				}
			}while(true);
		}
	void islem_oyunu_oyna(Bilgi kullanici){
		user = kullanici;
		difficulty();
		
		srand(time(0));
		
		if(selection() == 1){
			for(int i = 0; i < (zorluk * 2) + 2; i++){
				if(!game()){
					print("Kaybettin!!");
					Sleep(1000);
					break;
				}	
			}
			skorr = (hp * 5) * zorluk;
			print("\n");
			skor_kayit("islem_oyunu/islem_skor.txt",skorr);
			
			print("Aldığınız Skor:");
			print(skorr);
			Sleep(2000);
		}
		else{
			print("Yapım Aşamasında");
			Sleep(1000);
		}	
	}
};

void islem_oyna(Bilgi kullanici){

	islem_game islem;
	
	islem.islem_oyunu_oyna(kullanici);
}



