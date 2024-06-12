#include "inc.h"

class TasKagitMakas
{
    private:
        int kulSecim;
        int pcSecim;
        int kulPuan = 0;
        int pcPuan = 0;

        int rastgelesecim()
        {			
			return rand() % 3 + 1;
        }

    public:
    	
        void kullaniciSeciminiAl()
        {
        	do
        	{
        		cout<<"Bir seçim yapýnýz: ";
            	cout<<"Tas[1]-Kagýt[2]-Makas[3]: ";
            	cin >> kulSecim;
            	if(kulSecim > 3)
            		cout<<"hatalý seçim\n";
            		
			}while(kulSecim > 3); 
			cout<<"--------------------\n";
			cout<<"Kullanýcý secimi: "<<kulSecim<<endl;
        }

        void pcSeciminiAl()
        {
            pcSecim = rastgelesecim();
            cout<<"PC secimi: "<<pcSecim<<endl;
        }

        int round()
        {
            int round;
            cout<<"Kaç round oynamak istersiniz? ";
            cin>>round;
            return round;
        }

        void kazanan()
        {
            if(kulSecim == pcSecim) 
            {
                cout<<"Berabere!"<<endl;
            } 
            else if((kulSecim == 1 && pcSecim == 3) ||
                     (kulSecim == 2 && pcSecim == 1) ||
                     (kulSecim == 3 && pcSecim == 2)) 
            {
                cout << "Kullanýcý kazandý!" << endl;
                kulPuan++;
                cout<<"Kullanýcý "<<kulPuan<<" - "<<pcPuan<<" Bilgisayar"<<endl;
                cout<<"--------------------\n";
            } 
            else 
            {
                cout<<"Bilgisayar kazandý!"<<endl;
                pcPuan++;
                cout<<"Kullanýcý "<<kulPuan<<" - "<<pcPuan<<" Bilgisayar"<<endl;
                cout<<"--------------------\n";
            }
        }
		
        void genelKazanan()
        {
			int cevap;
            if(kulPuan > pcPuan)
            {
                MessageBox(0,"kazandýnýz tebrikler","kazandýnýz",MB_OK);
            }
            else if(pcPuan > kulPuan)
            {
                MessageBox(0,"pc kazandý","kaybettiniz",MB_OK);
            }
            else
            {
                MessageBox(0,"berabere","berabere",MB_YESNO);
            }
        }
        
        void oyunuBaslat()
        {
        	set();
        	
		    int cevap;
			do
			{
				TasKagitMakas oyun;
			    srand(time(0));
			    int round = oyun.round();
				
			    for (int i = 0; i < round; i++)
			    {
			        oyun.kullaniciSeciminiAl();
			        oyun.pcSeciminiAl();
			        oyun.kazanan();
			    }
			
			    oyun.genelKazanan();
			    
			    cevap = MessageBox(0,"tekrar denemek istermisiniz","yeni oyun",MB_YESNO);
			    system("cls");
			}while(cevap == IDYES);
			cout<<"iyi günler...";
		}
};

int main()
{
    TasKagitMakas oyun;
    oyun.oyunuBaslat();	
}
