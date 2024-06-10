#include "Print.h"
#include "battle.h"

class islem_game{
	private:
		
		int highest;
		int lowest;
		
		char chars[4] = {'+','-','/','*'};
		
		int random_number(int highest, int lowest = 0){
			return rand() % highest + lowest;
		}
	public:
		void difficulty(string kullanici){
			int ans;
			int zorluk;
			srand(time(0));
			
			system("cls");
			do{
				ans = int_input("Bir Zorluk Sec!\n1) Kolay\n2) Normal\n3) Zor\nSeçim:");
				if(ans >= 4|| ans <= 0)
					print("Hatalý giriþ!!\n");
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
			
			print("Oyun Baþlatýlýyor");
			animate('.');
			
			game(kullanici,zorluk);
		}
		
		void game(string kullanici,int zorluk){
			int hp = 5;
				
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
				
				print("Canýn:");
				print(hp);
				print("\n\n");
				print("Soru:");
				print(number);
				print(Islem);
				print(number2);
				
				p_answer = int_input("\nCevabýn:");
				
				if(hp == 0){
					print("Kaybettin!!!");
					break;
				}
				
				if(p_answer != answer){
					print("Yanlýþ Cevap!!");
					hp--;
					Sleep(400);
				}
				else{
					print("\nKazandýn!!!\n");
					Sleep(1000);
					break;
				}
			}while(true);
			
			int skor = (hp * 5) * zorluk;
			
			string bos;
			string k_ad;
			string mevcut_skor;
			
			ofstream file("islem_oyunu/islem_skor.txt",ios::app);
			ifstream ifile("islem_oyunu/islem_skor.txt");
			
			string yaz;
			string yeni_yaz;
			
			for(;getline(ifile,bos,'-') && 	getline(ifile,k_ad,'-') && getline(ifile,mevcut_skor,'-');){
				
				if(skor > ToInt(mevcut_skor) && k_ad == kullanici){
					yeni_yaz = "-" + kullanici + "-" + ToStr(skor) + "-\n";	
				}
				
				else if(!check_file("islem_oyunu/islem_skor.txt",kullanici)){
					yeni_yaz = "-" + kullanici + "-" + ToStr(skor) + "-\n";
				}
				else{
					yaz = "-" + k_ad + "-" + mevcut_skor + "-\n";
				}
			}
			string yeni;
			
			yeni = yaz + yeni_yaz;
			
			file.clear();
			
			file<<yeni;
			
			file.close();
			ifile.close();
		}	
};

void islem_oyunu_oyna(string kullanici)
{
	islem_game islem;
	
	islem.difficulty(kullanici);
}

void savas_oyunu_oyna(){
	savas_baslat();
}
