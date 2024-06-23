void loading(int time)
{
    int i = 0;
    cout << "Yukleniyor %  ";

    while (i <= 100)
    {
        Sleep(time);
        if (i < 10)
            cout << "\b" << i << flush;  // Tek haneli sayý için 1 karakter geri git ve sayýyý yazdýr
 		else
 			cout << "\b\b" << i << flush;  // ÇÝft haneli sayý için 2 karakter geri git ve sayýyý yazdýr
 			
        i++;
        if(i == 100)
            cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bYukleme tamamlandi %. ";
    }	
}
