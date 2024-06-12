#include "kontrol.h"

class TahminOyun : public Tanim
{
	public:
	    Ayar a;  // Ayar s�n�f�ndan nesne
	    Mesaj m; // Mesaj s�n�f�ndan nesne
	    kontrol k; // kontrol s�n�f�ndan nesne
	    int z;  // Zorluk seviyesi
	    string zorluk = "Normal"; // Ba�lang�� zorluk seviyesi
	    int tur = 3; // Ba�lang�� tur say�s�
	
		
	    // Zorluk ayarlar� fonksiyonu
	    void Zorluk() {
	        a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	        cout << "G�ncel Zorluk : " << zorluk << endl; // Mevcut zorluk seviyesini yazd�r
	
	        // Kullan�c�dan ge�erli bir zorluk seviyesi al
	        do {
	            z = veriGiris("Zorluk Ayarlay�n \n[1] Kolay\n[2] Normal\n[3] Zor ", z);
	
	            // Ge�erli de�er kontrol�
	            if (z < 1 || z > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("L�tfen ge�erli bir de�er girin ", "Tahmin Oyunu");
	            }
	        } while (z < 1 || z > 3);
	
	        // Se�ilen zorluk seviyesine g�re ayarlar� g�ncelle
	        switch (z) {
	        case 1:
	            zorluk = "Kolay";
	            break;
	        case 2:
	            zorluk = "Normal";
	            break;
	        case 3:
	            zorluk = "Zor";
	            break;
	        }
	
	        Ayarlar(); // Ayarlar men�s�ne geri d�n
	    }
	
	    // Tur say�s� ayarlar� fonksiyonu
	    void TurAyar() {
	        // Kullan�c�dan ge�erli bir tur say�s� al
	        do {
	            a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	            cout << "G�ncel Tur Say�s� : " << tur << endl; // Mevcut tur say�s�n� yazd�r
	            tur = veriGiris("Tur Say�s�n� Ayarlay�n", tur);
	
	            // Ge�erli de�er kontrol�
	            if (tur < 0 || tur > 100) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("Tur say�s� 100 'den b�y�k ya da 0'dan k���k olamaz !!! ", "Tahmin Oyunu");
	            }
	        } while (tur < 0 || tur > 100);
	
	        Ayarlar(); // Ayarlar men�s�ne geri d�n
	    }
	
	    // Ayarlar men�s� fonksiyonu
	    void Ayarlar() {
	        int secim;
	
	        // Kullan�c�dan ge�erli bir se�im al
	        do {
	            a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	            secim = veriGiris("[1] Zorluk Ayarlar�\n[2] Tur Ayarlar�\n[3] Ana Men�", secim);
	
	            // Ge�erli de�er kontrol�
	            if (secim < 1 || secim > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("L�tfen ge�erli bir de�er girin ", "Tahmin Oyunu");
	            }
	        } while (secim < 1 || secim > 3);
	
	        // Kullan�c� se�imine g�re i�lem yap
	        switch (secim) {
	        case 1:
	            Zorluk(); // Zorluk ayarlar� men�s�ne git
	            break;
	        case 2:
	            TurAyar(); // Tur ayarlar� men�s�ne git
	            break;
	        case 3:
	            menu(); // Ana men�ye geri d�n
	            break;
	        }
	    }
	
	    // Ana men� fonksiyonu
	    void menu() {
	        int secim;
	
	        // Kullan�c�dan ge�erli bir se�im al
	        do {
	            a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	            secim = veriGiris("[1] Oyuna Ba�la\n[2] Skor G�r�nt�le\n[3] Ayarlar", secim);
	
	            // Ge�erli de�er kontrol�
	            if (secim < 1 || secim > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("L�tfen ge�erli bir de�er girin ", "Tahmin Oyunu");
	            }
	        } while (secim < 1 || secim > 3);
	
	        // Kullan�c� se�imine g�re i�lem yap
	        switch (secim) {
	        case 1:
	            Basla(); // Oyuna ba�la
	            break;
	        case 2:
	            // Skor g�r�nt�le fonksiyonu buraya eklenebilir
	            break;
	        case 3:
	            Ayarlar(); // Ayarlar men�s�ne git
	            break;
	        }
	    }
	
	    // Oyun ba�lama fonksiyonu
	    void Basla() {
	        srand(time(0)); // Rastgele say� �reticisini ba�lat
	        int id, as, npc = 0, plyr = 0, soru;
	
	        // Turlar�n d�ng�s�
	        for (int i = 0; i < tur; i++) {
	            a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	            cout << "=== " << i + 1 << ". Tur ===" << endl; // Mevcut turu yazd�r
	            // Zorluk seviyesine g�re rastgele bir say� se�
	            switch (z) {
	            case 1:
	                id = rand() % 10 + 1; // 1 ile 10 aras�nda rastgele say�
	                cout<<"1 ile 10 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ";
	                cin>>as;
	                //as = veriGiris("1 ile 10 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ", as);
	                break;
	            case 2:
	                id = rand() % 100 + 1; // 1 ile 100 aras�nda rastgele say�
	                cout<<"1 ile 100 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ";
	                cin>>as;
	                //as = veriGiris("1 ile 100 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ", as);
	                break;
	            case 3:
	                id = rand() % 1000 + 1; // 1 ile 1000 aras�nda rastgele say�
	                cout<<"1 ile 1000 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ";
	                cin>>as;
					//as = veriGiris("1 ile 1000 Aras�nda Bir Say� Tuttum Bakal�m Bilebilecek misin? ", as);
	                break;
	            }
	
	            // Tahmin kontrol�
	            if (as == id) {
	                plyr++; // Oyuncunun skorunu artt�r
	                cout << "Kazand�n Skor : " << plyr << " - " << npc;
	                Sleep(1000); // 1 saniye bekle
	            } else {
	                npc++; // NPC'nin skorunu artt�r
	                cout << "Kaybettin Say� " << id << " Olmal�yd� Skor : " << plyr << " - " << npc;
	                Sleep(1000); // 1 saniye bekle
	            }
	        }
	
	        a.baslik("Tahmin Oyunu"); // Ba�l�k ayarla
	        if (npc > plyr)
	            cout << "Maalesef Kaybettin :( "; // NPC kazand�ysa
	        else
	            cout << "Waoow Kazand�n :))) "; // Oyuncu kazand�ysa
	
	        // Tekrar denemek ister misiniz? sorusu
	        soru = MessageBox(0, "Tekrar Denemek �ster misiniz ??", "Tahmin Oyunu", MB_ICONINFORMATION | MB_YESNO);
	        if (soru == IDYES)
	            menu(); // Ana men�ye geri d�n
	    }
};

