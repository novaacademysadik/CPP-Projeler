void loading(int time)
{
    int i = 0;
    cout << "Yukleniyor %  ";

    while (i <= 100)
    {
        Sleep(time);
        if (i < 10)
            cout << "\b" << i << flush;  // Tek haneli say� i�in 1 karakter geri git ve say�y� yazd�r
 		else
 			cout << "\b\b" << i << flush;  // ��ft haneli say� i�in 2 karakter geri git ve say�y� yazd�r
 			
        i++;
        if(i == 100)
            cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\bYukleme tamamlandi %. ";
    }	
}
