#include "kontrol.h"

class TahminOyun : public Tanim
{
	public:
	    Ayar a;  // Ayar sýnýfýndan nesne
	    Mesaj m; // Mesaj sýnýfýndan nesne
	    kontrol k; // kontrol sýnýfýndan nesne
	    int z;  // Zorluk seviyesi
	    string zorluk = "Normal"; // Baþlangýç zorluk seviyesi
	    int tur = 3; // Baþlangýç tur sayýsý
	
		
	    // Zorluk ayarlarý fonksiyonu
	    void Zorluk() {
	        a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	        cout << "Güncel Zorluk : " << zorluk << endl; // Mevcut zorluk seviyesini yazdýr
	
	        // Kullanýcýdan geçerli bir zorluk seviyesi al
	        do {
	            z = veriGiris("Zorluk Ayarlayýn \n[1] Kolay\n[2] Normal\n[3] Zor ", z);
	
	            // Geçerli deðer kontrolü
	            if (z < 1 || z > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("Lütfen geçerli bir deðer girin ", "Tahmin Oyunu");
	            }
	        } while (z < 1 || z > 3);
	
	        // Seçilen zorluk seviyesine göre ayarlarý güncelle
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
	
	        Ayarlar(); // Ayarlar menüsüne geri dön
	    }
	
	    // Tur sayýsý ayarlarý fonksiyonu
	    void TurAyar() {
	        // Kullanýcýdan geçerli bir tur sayýsý al
	        do {
	            a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	            cout << "Güncel Tur Sayýsý : " << tur << endl; // Mevcut tur sayýsýný yazdýr
	            tur = veriGiris("Tur Sayýsýný Ayarlayýn", tur);
	
	            // Geçerli deðer kontrolü
	            if (tur < 0 || tur > 100) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("Tur sayýsý 100 'den büyük ya da 0'dan küçük olamaz !!! ", "Tahmin Oyunu");
	            }
	        } while (tur < 0 || tur > 100);
	
	        Ayarlar(); // Ayarlar menüsüne geri dön
	    }
	
	    // Ayarlar menüsü fonksiyonu
	    void Ayarlar() {
	        int secim;
	
	        // Kullanýcýdan geçerli bir seçim al
	        do {
	            a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	            secim = veriGiris("[1] Zorluk Ayarlarý\n[2] Tur Ayarlarý\n[3] Ana Menü", secim);
	
	            // Geçerli deðer kontrolü
	            if (secim < 1 || secim > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("Lütfen geçerli bir deðer girin ", "Tahmin Oyunu");
	            }
	        } while (secim < 1 || secim > 3);
	
	        // Kullanýcý seçimine göre iþlem yap
	        switch (secim) {
	        case 1:
	            Zorluk(); // Zorluk ayarlarý menüsüne git
	            break;
	        case 2:
	            TurAyar(); // Tur ayarlarý menüsüne git
	            break;
	        case 3:
	            menu(); // Ana menüye geri dön
	            break;
	        }
	    }
	
	    // Ana menü fonksiyonu
	    void menu() {
	        int secim;
	
	        // Kullanýcýdan geçerli bir seçim al
	        do {
	            a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	            secim = veriGiris("[1] Oyuna Baþla\n[2] Skor Görüntüle\n[3] Ayarlar", secim);
	
	            // Geçerli deðer kontrolü
	            if (secim < 1 || secim > 3) {
	                a.baslik("Tahmin Oyunu");
	                m.hata("Lütfen geçerli bir deðer girin ", "Tahmin Oyunu");
	            }
	        } while (secim < 1 || secim > 3);
	
	        // Kullanýcý seçimine göre iþlem yap
	        switch (secim) {
	        case 1:
	            Basla(); // Oyuna baþla
	            break;
	        case 2:
	            // Skor görüntüle fonksiyonu buraya eklenebilir
	            break;
	        case 3:
	            Ayarlar(); // Ayarlar menüsüne git
	            break;
	        }
	    }
	
	    // Oyun baþlama fonksiyonu
	    void Basla() {
	        srand(time(0)); // Rastgele sayý üreticisini baþlat
	        int id, as, npc = 0, plyr = 0, soru;
	
	        // Turlarýn döngüsü
	        for (int i = 0; i < tur; i++) {
	            a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	            cout << "=== " << i + 1 << ". Tur ===" << endl; // Mevcut turu yazdýr
	            // Zorluk seviyesine göre rastgele bir sayý seç
	            switch (z) {
	            case 1:
	                id = rand() % 10 + 1; // 1 ile 10 arasýnda rastgele sayý
	                cout<<"1 ile 10 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ";
	                cin>>as;
	                //as = veriGiris("1 ile 10 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ", as);
	                break;
	            case 2:
	                id = rand() % 100 + 1; // 1 ile 100 arasýnda rastgele sayý
	                cout<<"1 ile 100 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ";
	                cin>>as;
	                //as = veriGiris("1 ile 100 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ", as);
	                break;
	            case 3:
	                id = rand() % 1000 + 1; // 1 ile 1000 arasýnda rastgele sayý
	                cout<<"1 ile 1000 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ";
	                cin>>as;
					//as = veriGiris("1 ile 1000 Arasýnda Bir Sayý Tuttum Bakalým Bilebilecek misin? ", as);
	                break;
	            }
	
	            // Tahmin kontrolü
	            if (as == id) {
	                plyr++; // Oyuncunun skorunu arttýr
	                cout << "Kazandýn Skor : " << plyr << " - " << npc;
	                Sleep(1000); // 1 saniye bekle
	            } else {
	                npc++; // NPC'nin skorunu arttýr
	                cout << "Kaybettin Sayý " << id << " Olmalýydý Skor : " << plyr << " - " << npc;
	                Sleep(1000); // 1 saniye bekle
	            }
	        }
	
	        a.baslik("Tahmin Oyunu"); // Baþlýk ayarla
	        if (npc > plyr)
	            cout << "Maalesef Kaybettin :( "; // NPC kazandýysa
	        else
	            cout << "Waoow Kazandýn :))) "; // Oyuncu kazandýysa
	
	        // Tekrar denemek ister misiniz? sorusu
	        soru = MessageBox(0, "Tekrar Denemek Ýster misiniz ??", "Tahmin Oyunu", MB_ICONINFORMATION | MB_YESNO);
	        if (soru == IDYES)
	            menu(); // Ana menüye geri dön
	    }
};

