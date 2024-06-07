template <typename X>

void print(X Print){
    cout<<Print;
}

string input(string String,string Endl = "yok"){
	
	string Input;
	
	cout<<String;
	
	if(Endl == "endl"){
		cout<<endl;
	}
	
	getline(cin,Input);
	
	return Input;
}

string input(){
	
	string Input;
	
	getline(cin,Input);
	
	return Input;
}

int int_input(string String,string Endl = "yok"){
	
	int Input;
	
	cout<<String;
	
	if(Endl == "endl"){
		cout<<endl;
	}
	
	cin>>Input;
	
	return Input;
}

int int_input(){
	int Input;
	
	cin>>Input;
	
	return Input;
}

void animate(char Char,int count = 3,int Time = 100){
	
	for(int i = 0; i < count; i++){
		print(Char);
		Sleep(Time);
	}
}

string ToStr(int Int){
	stringstream s1;
	
	s1<<Int;
	
	return s1.str();	
}

int ToInt(string Int){
	int a;
	
	stringstream s1(Int);
	
	s1>>a;
	
	return a;
}

int over(int x, int y){
	int Over = 1;
	 
	for(int i = 0; i < y; i++){
		Over *= x;
	}
	
	return Over;
}

void add_to_file(string String, string FileName){
	
    ofstream file(FileName.c_str(),ios::app);
    
    file<<String<<endl;
}

bool check_file(string FileName,string String){
	ifstream file(FileName.c_str());
	
	string check;
	
	for(;getline(file,check,'-');){
		
		if(check == String)
			return true;			
	}
	
	return false;
}


