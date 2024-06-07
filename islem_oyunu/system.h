#include "includes.h"
#include "Print.h"
#include "battle.h"
#include "adress.h"
#include "islem.h"

class member :public adress,islem_game{
	public:
	
	int exit = 100;
	
	int err_code;
	
	public:
	
	void log_menu(string name, string id){
		system("cls");
		print("Welcome ");
		print(name);
		
		print("!\n");
		print("Id:");
		print(id);
		print("\n");
		
		int ans;
		
		do{
			ans = int_input("\n1) Games\n2) Adress Menu\n3) Exit Program\n4) Log out","endl");
			
			if(ans == 4){
				ofstream file("logged.txt");
				
				file<<' ';
				
				system("cls");
				
				menu();
			}
			else if(ans == 3){
				exit = 1;
				return;
			}
			else if(ans == 1){
				do{
					system("cls");
					ans = int_input("1) Turn Based Game\n2) Math Game\n");
					
					if(ans == 1)
						character_choose();	
					else if(ans == 2){
						start_islem();
					}
					else{
						print("Bad Input!!\n");
						Sleep(400);
					}
						
				}while(true);	
			}
			else if(ans == 2){
				system("cls");
				adress_menu();
			}
			else{
				print("Bad Input!!!");
			}	
		}while(true);
	}
	
	
	void menu(){
		int ans;
		system("cls");
		do{
			if(exit == 1){
			return;
			}
			ans = int_input("1) Register\n2) Log in","endl");
			
			try{
				if(ans == 1){
					
					print("You are transfering to Register");
					
					animate('.',3,400);
					
					Register();
				}
				
				else if(ans == 2){
					
					print("You are transfering to Log in");
					
					animate('.',3,400);
					
					login();
				}
				
				else if(ans == 121){
					print("Admin list:\n");
					list();
				}
				else{
					err_code = 3;
					
					throw(err_code);
				}
			}
			
		catch(int err_code){

			if(err_code == 3){
				print("\nWrong enter!!!");
			}
		}	
		
		}while(true);
	}
		
	private:	
		struct variables{
			
			int id;
			
			string name;
			string password;
			
		};
		
	private:
			
	void Register(){
		
		variables member;
		
		string name;
		
		string pass;
		
		string final;
		
		cin.ignore();
		
		do{	
			member.name = input("\nEnter a Nickname:");
			
			name = input("\nEnter a Nickname again:");
			
			try{
				if(member.name == name && name_check(name)){
					break;
				}
				else{
					err_code = 1;
					
					throw(err_code);
				}	
			}
		
			catch(int err_code){	
				if(err_code == 1 && name_check(name) == true){
					print("\nNames do not matching!!\n");
					Sleep(1000);
				}
			}
			

		}while(true);	
		do{
			
			system("cls");
			
			member.password = input("\nEnter a Password:");
			pass = input("\nEnter a password again:");
			
			try{
				if(member.password == pass && pass_check(pass)){
					break;
				}
				else{
					err_code = 2;
					
					throw(err_code);
				}
			}
			catch(int err_code){
				if(err_code == 2){
					print("\nPasswords do not matching\n");
					Sleep(1000);
				}
			}
		
		}while(true);
		
		srand(time(0));
		member.id = rand() % 899999 + 100000;
		
		final = "-" + member.name + "-" + member.password + "-" + ToStr(member.id) + "-";
		
		add_to_file(final,"members.txt");
		
		print("\nYou registered succesfuly!\n");
		
		Sleep(2000);
		
		menu();
		
		}
		
		void login(){
			
			system("cls");
			
			ifstream file("members.txt");
			
			variables member;
			
			string empty;
			
			string name;
			
			string pass;
			
			bool name_check = false;
			bool pass_check = false;
			
			cin.ignore();
			
			do{
				
				name = input("\nEnter your Nickname:");
			
				pass = input("Enter your Password:");
			
				for(;getline(file,empty,'-');){
					
					getline(file,member.name,'-');
					
					if(member.name== name){
						name_check = true;	
					}
					
					getline(file,member.password,'-');
					
					if(member.password == pass){
						pass_check = true;
					}
					
					string idStr;
					
					getline(file,idStr,'-');
					
					member.id = ToInt(idStr);
					
					if(name_check && pass_check){
						break;
					}
				}
				
				try{
					if(name_check == false){
						err_code = 4;
						
						throw(err_code);
					}
					
					else if(pass_check == false){
						err_code = 5;
						
						throw(err_code);
						
					}
					
					else if(name_check = false && pass_check == false){
						err_code = 6;
						
						throw(err_code);
					}
					else
						break;
				}
				catch(int err_code){
					
					if(err_code == 4){
						print("\nIncorrect name!!!\n");
					}
					
					else if(err_code == 5){
						print("\nIncorrect password!!!");
					}
					
					else if(err_code == 6){
						print("\nIncorrect password and name!!!\n");
					}
				}
				
				}while(name_check == false || pass_check == false);
				
				file.close();
				
				ofstream File("logged.txt");
				
				string log = "-true-" + name + '-' + ToStr(member.id);
				
				File<<log;
				
				print("Logged in!!");
				Sleep(1000);
				
				log_menu(member.name,ToStr(member.id));
		}
		
		void list(){
			string bos;
			
			string name;
			string pass;
			string id;
			
			ifstream file("members.txt");
			
			// Getting all accounts
			
			for(int i = 1;getline(file,bos,'-');i++){
				
				getline(file,name,'-'); // Acc Name
				getline(file,pass,'-'); // Acc Password
				getline(file,id,'-');	// Acc Id
				getline(file,bos,'-');
				
				print("\n");
				print(i);
				print(")");
				
				print(name);
				print("-");
				print(pass);
				print("-");
				print(id);
				
				print("\n\n");
			}
		}
		
		bool name_check(string name){
			
			// Checking names lenght
			
			if(name.size() < 5){
				print("Name is too short!!");
				return false;
			}
				
			
			if(name.size() > 15){
				print("Name is too long!!");
				return false;
			}
			
			
			if(check_file("members.txt",name)){
				print("This Nickname already taken!!");
				return false;
			}
			return true;
		}
		
		bool pass_check(string pass){
			
			// Checking Password lenght
			
			if(pass.size() < 5){
				print("Password is too short!!");
				return false;
			}
				
			
			if(pass.size() > 15){
				print("Password is too long!!");
				return false;
 			}
			return true;
		}
		
};

void start(){
	
	member mem;

	// Remember last acc	
	
	if(check_file("logged.txt","true")){
		string name;
		string id;
		string bos;
		
		ifstream file("logged.txt");
				
		for(;getline(file,bos,'-');){
			getline(file,bos,'-');
			getline(file,name,'-');
			getline(file,id,'-');
		}
		
		mem.log_menu(name,id);
	}
	
	if(mem.exit == 1){
		return;
	}

	mem.menu();	
}
