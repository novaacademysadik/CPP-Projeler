class adress{
	public:
	
	struct addres_variable{
			string name;
			string country;
			string city;
			string street;
			string id;		
	};
	
	addres_variable adress;
	addres_variable detail;
	void adress_id(){
		int id;
		
		srand(time(0));
		id = rand() % 100000 + 899999;
		
		adress.id = ToStr(id);
	}
	void add_adress(){
		
		cin.ignore();
		
		adress.name = input("\nAdress name:");
		adress.country = input("Country:");
		adress.city = input("City:");
		adress.street = input("Street:");
		adress_id();
		
		ofstream file("adress.txt",ios::app);
		
		string str_id = adress.id;
		
		string last = "-" + adress.name + "-" + adress.country + "-" + adress.city + "-" + adress.street + "-" + str_id + "-";
		
		file<<last<<endl;
		
		print("\nAdress added succesfully\n");
		
		file.close();
	}
	
	void delete_adress(){
		
		cin.ignore();
		
		adress.id = input("\nEnter adress ID:");
		string bos;
		string id;
		string final;
		
		ifstream file("adress.txt");
		ofstream File("adresss.txt",ios::app);
		
		for(;getline(file,bos,'-');){
			getline(file,adress.name,'-');
			getline(file,adress.country,'-');
			getline(file,adress.city,'-');
			getline(file,adress.street,'-');
			getline(file,adress.id,'-');
			
			if(id != adress.id){
				string name = adress.name;
				string country = adress.country;
				string city = adress.city;
				string street = adress.street;
				
				string final = "-" + name + "-" + country + "-" + city + "-" + street + "-" + adress.id + "-";
				
				File<<final<<endl;
			}
		}
		
		ofstream ffile("adress.txt");
		ifstream FFile("adresss.txt");
		
		File<<" ";
		ffile<<" ";
		
		string change;
		
		FFile>>change;
		
		ffile<<change<<endl;
		File<<' ';
		print("\nAdress deleted succesfully!!");
		
		ffile.close();
		FFile.close();
		file.close();
		File.close();
	}
	
	void list_adress(){
		ifstream file("adress.txt");
		
		string empty;
		
		system("cls");
		
		for(int i = 0;getline(file,empty,'-');i++){
			getline(file,adress.name,'-');
			getline(file,adress.country,'-');
			getline(file,adress.city,'-');
			getline(file,adress.street,'-');
			getline(file,adress.id,'-');
	
			print(i+1);
			print(")");
			print(adress.name);
			
			print("\n");
			
			print("Country:");
			print(adress.country);
			
			print("\n");
			
			print("City:");
			print(adress.city);
			
			print("\n");
			
			print("Street:");
			print(adress.street);
			
			print("\n");
			
			print("Id:");
			print(adress.id);
			
			print("\n");
			print("\n");
			
		}
		file.close();
		Sleep(5000);
	}
	
	void change_adress(){
		
		cin.ignore();
		
		ifstream file("adress.txt");
		ofstream oFile("adresss.txt",ios::app);
		ofstream ofile("adress.txt",ios::app);
		ifstream File("adresss.txt");
		
		string id = input("Enter adress id wich will change:");
		
		string name = input("Enter new name:");
		string country = input("Enter new country:");
		string city = input("Enter new city:");
		string street = input("Enter new street:");
		int idd = rand() % 100000 + 899999;
		
		int count = 0;
		
		string save;
		string empty;
		
		for(;getline(file,empty,'-');){
			getline(file,empty,'-');
			getline(file,empty,'-');
			getline(file,empty,'-');
			getline(file,empty,'-');
			getline(file,empty,'-');
			
			count++;
			
		}
		
		
		for(int i = 0;i < count;i++){
			getline(file,empty,'-');
			getline(file,adress.name,'-');
			getline(file,adress.country,'-');
			getline(file,adress.city,'-');
			getline(file,adress.street,'-');
			getline(file,adress.id,'-');
			
			if(id != adress.id){
				
				save = '-' + adress.name + '-' + adress.country + '-' + adress.city + '-' + adress.street + '-' + adress.id + '-';
				
				oFile<<save;
			}
			
			else{
				save = '-' + name + '-' + country + '-' + city + '-' + street + '-' + ToStr(idd) + '-';
				
				oFile<<save;
			}	
		}
			
		ofile<<' ';
			
		string change;
			
		File>>change;
		
		ofile<<change<<endl;
		
		oFile<<' ';
		
		print("\nAdress Changed succesfully\n");
		Sleep(1000);
		ofile.close();
		oFile.close();
		file.close();
		File.close();	
	}
	
	void adress_menu(){
		int ans;
		
		for(;true;){
		system("cls");
			ans = int_input("1)Add adress\n2)Delete adress\n3)List\n4)Change adress","endl");
			
			if(ans == 1){
				system("cls");
				add_adress();
			}
			
			else if(ans == 2){
				system("cls");
				delete_adress();
			}
			
			else if(ans == 3){
				system("cls");
				list_adress();
			}
			
			else if(ans == 4){
				system("cls");
				change_adress();
			}
			
		}
	}
};

