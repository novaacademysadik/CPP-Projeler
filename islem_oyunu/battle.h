
int skor = 0;

class warrior{
	public:
	int max_w_hp = 110;	
	int w_hp = 110;
	int w_damage = 20;
	double w_armor = 3;		
	int w_speed = 5;
	int w_pot = 3;

};
	
class assasin{
	public:
	
	int max_a_hp = 80;	
	int a_hp = 80;
	int a_damage = 60;
	double a_armor = 1.5;
	int a_speed = 25;
	int a_pot = 3;
		
};	
	
class savas_oyunu : public assasin , public warrior{
	
	public:
		
	void attack(int who){
		
		srand(time(0));
		
		int dodge = rand() % 100;
		
		if(who == 1){
			print("\nSuikast�i Sald�rd�!\n");
		}
		else{
			print("\nSava��� Sald�rd�\n");
		}
		
		
		if(who == 2){
			if(a_speed >= dodge){
				print("Suikast�i Bu Sald�r�dan S�yr�ld�!!!\n");
				Sleep(1000);
				return;
			}
		}
		
		else{
			if(w_speed >= dodge){
				print("Sava��� Bu Sald�r�dan S�yr�ld�!!!");
				Sleep(1000);
				return;
			}
		}
				
		if(who == 2)
			a_hp = a_hp - w_damage / a_armor;
		
		else
			w_hp = w_hp - a_damage / w_armor;
	}
	
	public:
	
	void guard(int who){
		
		if(who == 1){
			a_armor += 0.5;
		}
		else
			w_armor += 0.5;
	}
	
	public: 
	
	void use_pot(int who){
		
		if(who == 1){
			if(a_pot >= 1){
				
				print("Suikast�i �ksir Kulland�!\n");	
				print("Suikast�i ");
				print(a_pot);
				print(" �ksire Sahip!");
				
				if(a_hp + 40 > max_a_hp){
					for(int i = a_hp; i < max_a_hp;i++){
						a_hp++;
					}
					a_pot--;
				}
				else{
					a_hp += 40;
					a_pot --;	
				}	
			}
			
			else{
				print("Suikast�inin �ksiri Bitti!!");
			}
		}
		else{
			if(w_pot >= 1){
				
				print("Sava��� �ksir Kulland�!\n");	
				print("Sava��� ");
				print(w_pot);
				print(" �ksire Sahip!");
				
				
				if(w_hp + 40 > max_w_hp){
					for(int i = w_hp; i < max_w_hp;i++){
						w_hp++;
					}
					w_pot--;
				}
				else{
					w_hp += 40;
					w_pot--;
				}
				
			}
			else{
				print("Sava���n�n �ksiri Bitti!");
			}
		}		
	}
	
	void savas_baslat(){
		int character;
		
		system("cls");
		
		do{
			character = int_input("Bir Karakter Se�\n1)Suikast�i\n2)Sava���","endl");
			
			if(character == 1){
				print("Suikast�i Se�ildi!");
				break;
			}
			
			else if(character == 2){
				print("Sava��� Se�ildi!");
				break;
			}
			
			else
				print("Hatal� Giri�!");
		}while(true);
	
		mainloop(character);
	}
	
	void mainloop(int character){
		
		bool turn;
		
		int opp;
		int use;
			
		if(character == 1){
			opp = 2;
			turn = true;
		}
		else
			opp = 1;
			turn = false;		
			
		for(;true;){
			if(character == 1 && w_hp <= 0){
				print("Kazand�n!!!");
				print("\n\nSkorun:");
				
				skor = 100;
				
				print(skor);
				
				break;
			}
			else if(character == 1 && a_hp <= 0){
				print("Kaybettin!!!");
				
				skor = (w_hp * -1) + 40;
				if(skor < 0)
					skor = 0;
				
				print("\n\nSkorun:");
				print(skor);
				
				break;
			}
			
			else if(character == 2 && w_hp <= 0){
				print("Kaybettin!!!");
				
				skor = (a_hp * -1) + 40;
				if(skor < 0)
					skor = 0;
				
				print("\n\nSkorun:");
				print(skor);
				
				break;
			}
			
			else if(character == 2 && a_hp <= 0){
				print("Kazand�n!!!");
				print("\n\nSkorun:");
				
				skor = 100;
				
				print(skor);
				
				break;
			}
			
			print("\n\nSuikast�inin Can�:");
			print(a_hp);
			
			print("\nSava���n�n Can�:");
			print(w_hp);
	
			print("\n");
			
			if(turn){
				do{
					use = int_input("\n\n1)Sald�r\n2)Z�rh�n� G��lendir\n3)�ksir ��","endl");
					if(use == 1){
						attack(character);
	
						turn = false;
						break;
					}
						
					else if(use == 2){
						guard(character);
						
						print("Z�rh�n Artt�!\n");
						 
						turn = false;
						break;
					}
						
					else if(use == 3){
						use_pot(character);
	
						turn = false;
						break;
					}
						
					else
						print("Hatal� Giri�\n");
				}while(true);
			}
			else{
				
				if(opp == 2 && w_hp < max_w_hp / 2 && w_pot >= 1){
					use_pot(opp);
					
					turn = true;
				}
				
				else if(opp == 2 && w_hp > w_hp / 2){
					attack(opp);
					
					
					turn = true;
				}	
				
				else if(opp == 1 && a_hp < max_a_hp / 2 && a_pot >= 1){
					use_pot(opp);
					
					turn = true;
				}
				
				else{
					attack(opp);
					
					print("Rakibin Sald�rd�\n");
					
					turn = true;
				}	
			}
			Sleep(2000);
			system("cls");			
		}
	}
	
};

void savas_oyna(Bilgi kullanici){
	savas_oyunu oyun;
	
	oyun.savas_baslat();
}




