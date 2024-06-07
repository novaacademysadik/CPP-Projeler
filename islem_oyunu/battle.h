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
	
class champions : public assasin , public warrior{
	
	public:
		
	void attack(int who){
		
		srand(time(0));
		
		int dodge = rand() % 100;
		
		if(who == 1){
			print("\nSuikastçi Saldýrdý!\n");
		}
		else{
			print("\nSavaþçý Saldýrdý\n");
		}
		
		
		if(who == 2){
			if(a_speed >= dodge){
				print("Suikastçi Bu Saldýrýdan Sýyrýldý!!!\n");
				Sleep(1000);
				return;
			}
		}
		
		else{
			if(w_speed >= dodge){
				print("Savaþçý Bu Saldýrýdan Sýyrýldý!!!");
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
				
				print("Suikastçi Ýksir Kullandý!\n");	
				print("Suikastçi ");
				print(a_pot);
				print(" Ýksire Sahip!");
				
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
				print("Suikastçinin Ýksiri Bitti!!");
			}
		}
		else{
			if(w_pot >= 1){
				
				print("Savaþçý Ýksir Kullandý!\n");	
				print("Savaþçý ");
				print(w_pot);
				print(" Ýksire Sahip!");
				
				
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
				print("Savaþçýnýn Ýksiri Bitti!");
			}
		}		
	}
};

void mainloop(int character);

void savas_baslat(){
	int character;
	
	system("cls");
	
	do{
		character = int_input("Bir Karakter Seç\n1)Suikastçi\n2)Savaþçý","endl");
		
		if(character == 1){
			print("Suikastçi Seçildi!");
			break;
		}
		
		else if(character == 2){
			print("Savaþçý Seçildi!");
			break;
		}
		
		else
			print("Hatalý Giriþ!");
	}while(true);
	
	mainloop(character);
}

void mainloop(int character){
	champions champ;
	
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
		if(character == 1 && champ.w_hp <= 0){
			print("Kazandýn!!!");
			break;
		}
		else if(character == 1 && champ.a_hp <= 0){
			print("Kaybettin!!!");
			break;
		}
		
		else if(character == 2 && champ.w_hp <= 0){
			print("Kaybettin!!!");
			break;
		}
		
		else if(character == 2 && champ.a_hp <= 0){
			print("Kaybettin!!!");
			break;
		}
		
		print("\n\nSuikastçinin Caný:");
		print(champ.a_hp);
		
		print("\nSavaþçýnýn Caný:");
		print(champ.w_hp);

		print("\n");
		
		if(turn){
			do{
				use = int_input("\n\n1)Saldýr\n2)Zýrhýný Güçlendir\n3)Ýksir Ýç","endl");
				if(use == 1){
					champ.attack(character);

					turn = false;
					break;
				}
					
				else if(use == 2){
					champ.guard(character);
					
					print("Zýrhýn Arttý!\n");
					 
					turn = false;
					break;
				}
					
				else if(use == 3){
					champ.use_pot(character);

					turn = false;
					break;
				}
					
				else
					print("Hatalý Giriþ\n");
			}while(true);
		}
		else{
			
			if(opp == 2 && champ.w_hp < champ.max_w_hp / 2 && champ.w_pot >= 1){
				champ.use_pot(opp);
				
				turn = true;
			}
			
			else if(opp == 2 && champ.w_hp > champ.w_hp / 2){
				champ.attack(opp);
				
				
				turn = true;
			}	
			
			else if(opp == 1 && champ.a_hp < champ.max_a_hp / 2 && champ.a_pot >= 1){
				champ.use_pot(opp);
				
				turn = true;
			}
			
			else{
				champ.attack(opp);
				
				print("Rakibin Saldýrdý\n");
				
				turn = true;
			}	
		}
		Sleep(2000);
		system("cls");			
	}
}






