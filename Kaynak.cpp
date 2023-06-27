#include <iostream>  // temel girdi ��kt� i�lemleri i�in ekledim
#include <locale.h>  // T�rk�e karakterler kullanabilmek i�in ekledim
#include <cmath>	 // matematiksel i�lemler yapabilmek i�in ekledim
using namespace std;

const double PI = 3.14159;
void menu();  // kullan�c�ya sunuluacak men�y� fonksiyon i�ine yaz�p tan�m�n� main alt�na yapt�m

class karmasikSayi  //karma��k say� s�n�f� tan�mlad�m
{
private:	// sonras�nda de�i�tirilmemesi i�in reel ve sanal k�sm� private k�sm�na tan�mlad�m
	float reel;
	float sanal;

public:		// fonksiyonlar� public i�ine tan�mlad�m
	karmasikSayi(float _reel = 0, float _sanal = 0)
	{
		reel = _reel;
		sanal = _sanal;
	}
	void sayilariGir()		// kullan�c�ndan say�lar� girmesi i�in tan�mlad���m fonksiyon
	{
		cout << "Reel k�s�m: ";
		cin >> reel;
		cout << "Sanal k�s�m: ";
		cin >> sanal;
		cout << endl;
	}

	karmasikSayi operator+(karmasikSayi obj)	// karma��k say�lar� toplayabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		karmasikSayi toplam;					// karmasikSayi s�n�f� cinsinden toplam adl� bir de�i�ken tan�mlad�m
		toplam.reel = reel + obj.reel;			// say�n�n reel k�sm� ve parantez i�indeki say�n�n reel k�sm� toplan�r toplam�n reel k�sm�na atan�r
		toplam.sanal = sanal + obj.sanal;		// say�n�n sanal k�sm� ve parantez i�indeki say�n�n sanal k�sm� toplan�r toplam�n sanal k�sm�na atan�r
		return toplam;							// toplam de�erini d�nd�r�r
	}

	karmasikSayi operator-(karmasikSayi obj)	// karma��k say�lar� ��karabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		karmasikSayi sonuc;						// karmasikSayi s�n�f� cinsinden sonuc adl� bir de�i�ken tanmlad�m
		sonuc.reel = reel - obj.reel;			// say�n�n reel k�sm�ndan obj'nin reel k�sm� ��kart�l�p sonucun reel k�sm�na atan�r
		sonuc.sanal = sanal - obj.sanal;		// say�n�n sanal k�sm�ndan obj'nin sanal k�sm� ��kart�l�p sonucun sanal k�sm�na atan�r.
		return sonuc;							// sonuc de�eri d�nd�r�l�r
	}

	karmasikSayi operator*(karmasikSayi obj)				// karma��k say�lar� �arpabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		karmasikSayi carpim;								// karmasikSayi s�n�f� cinsinden carpim adl� bir de�i�ken tan�mlad�m
		carpim.reel = reel * obj.reel - sanal * obj.sanal;		// say�n�n reel k�sm� ve obj'nin reel k�sm� �arp�l�r ve bu �arp�mdan say�n�n sanal k�sm� ile obj'nin sanal k�sm�n�n �arp�m� ��kart�l�r(i^2 = -1 oldu�undan). carpim'in reel k�sm�na atan�r
		carpim.sanal = reel * obj.sanal + sanal * obj.reel;		// say�n�n reel k�sm� ve obj'nin sanal k�sm� �arp�l�r bu �arp�mla say�n�n sanal k�sm� ve obj'nin reel k�sm�n�n �arp�m� toplan�r. carpim'in sanal k�sm�na atan�r
		return carpim;										// carpim de�eri d�nd�r�l�r
	}

	karmasikSayi operator/(karmasikSayi obj)								// karma��k say�lar� b�lebilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		karmasikSayi bolum;													// karmasikSayi s�n�f� cinsinden bolum adl� bir de�i�ken tan�mlad�m
		float sayi = pow(obj.reel, 2) + pow(obj.sanal, 2);					// float tipinden sayi adl� bir de�i�ken tan�mlay�p obj'nin reel ve sanal k�sm�n�n karelerinin toplam�n� atad�m(b�l�m i�lemi yap�l�rken kesir, kesirin alt�ndaki say�n�n e�leni�iyle �arp�l�r paydan�n karesi al�nm�� olunur)
		bolum.reel = (reel * obj.reel - sanal * (-1 * obj.sanal)) / sayi;			// say�m�z�n reel k�sm�yla obj'nin reel k�sm� �arp�l�r bu �arp�mdan say�m�z�n sanal k�sm�yla obj'nin sanal k�sm�n�n negatifinin �arp�m� ��kart�l�r. En son sonu� sayi'ya b�l�n�r. bolumun reel k�sm�na atan�r.
		bolum.sanal = (reel * (-1 * obj.sanal) + sanal * obj.reel) / sayi;	// say�m�z�n reel k�sm�yla obj'nin sanal k�sm�n�n negatifi �arp�l�r bu �arp�mla say�m�z�n sanal k�sm� ve obj'nin reel k�sm� toplan�r, sonuc sayi'ya b�l�n�r. bolumun sanal k�sm�na atan�r.
		return bolum;														// bolum de�eri d�nd�r�l�r.
	}

	void operator+=(karmasikSayi obj)		// karma��k say�lar� toplayabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		reel += obj.reel;					// say�m�z�n reel k�sm�yla obj'nin reel k�sm� toplan�r say�m�z�n reel k�sm�na atan�r.
		sanal += obj.sanal;					// say�m�z�n sanal k�sm�yla obj'nin sanal k�sm� toplan�r say�m�z�n sanal k�sm�na atan�r.
	}

	void operator-=(karmasikSayi obj)		// karma��k say�lar� ��karabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m
	{
		reel -= obj.reel;					// say�n�n reel k�sm�ndan obj'nin reel k�sm� ��kart�l�p say�n�n reel k�sm�na atan�r
		sanal -= obj.sanal;					// say�n�n sanal k�sm�ndan obj'nin sanal k�sm� ��kart�l�p say�n�n sanal k�sm�na atan�r.
	}

	void operator*=(karmasikSayi obj)		// karma��k say�lar� �arpabilmek i�in operat�r a��r� y�klenmesi tan�mlad�m.(sonunda hem reel hem sanal k�s�m d�nd�r�lmesi gerekti�inden return edilmemesi i�in void fonksiyon yazd�m)
	{
		float geciciReel, geciciSanal;		// reel k�sm�n de�i�ip sanal� hesaplarken farkl� sonu� ��kmamas� i�in gecici reel ve sanal de�i�ken tan�mlay�p i�lemin sonunda i�lerindeki de�erleri reel ve sanal k�sma atad�m
		geciciReel = reel * obj.reel - sanal * obj.sanal;		// say�n�n reel k�sm� ve obj'nin reel k�sm�n�n �arp�m�ndan say�n�n sanal k�sm�yla obj'nin sanal k�sm�n�n �arp�m�n� ��kar�p say�n�n reel k�sm�na atad�m
		geciciSanal = sanal * obj.reel + reel * obj.sanal;		// say�n�n sanal k�sm�yla obj'nin reel k�sm�n�n �arp�m�yla say�n�n reel k�sm�yla obj'nin sanal k�sm�n�n �arp�m�n� toplay�p say�n�n sanal k�sm�na atad�m.
		reel = geciciReel;
		sanal = geciciSanal;
	}

	void operator/=(karmasikSayi obj)		// karma��k say�lar� b�lebilmek i�in operat�r a��r� y�klenmesi tan�mlad�m.(sonunda hem reel hem sanal k�s�m d�nd�r�lmesi gerekti�inden return edilmemesi i�in void fonksiyon yazd�m)
	{
		float geciciReel, geciciSanal, sayi;	// reel k�sm�n de�i�ip sanal� hesaplarken farkl� sonu� ��kmamas� i�in gecici reel ve sanal de�i�ken tan�mlay�p i�lemin sonunda i�lerindeki de�erleri reel ve sanal k�sma atad�m.
		sayi = pow(obj.reel, 2) + pow(obj.sanal, 2);		// kesir paydan�n e�leni�iyle �arp�ld���nda paydan�n karesi geldi�i i�in float tipinde sayi de�i�keni tan�mlay�p paydan�n karesini atad�m
		geciciReel = (reel * obj.reel - sanal * (-1 * obj.sanal)) / sayi;		// say�n�n reel k�sm� ve obj'nin reel k�sm�n�n �arp�m�ndan say�n�n sanal k�sm�yla obj'nin sanal k�sm�n�n negatifinin �arp�m�n� ��kar�p sayiya b�l�n�r. reel k�s�m bulunmu� olunur
		geciciSanal = (reel * (-1 * obj.sanal) + sanal * obj.reel) / sayi;		// say�n�n reel k�sm� ve obj'nin sanal k�sm�n�n negatifinin �arp�m�yla say�n�n sanal k�sm�yla obj'nin reel k�sm�n�n �arp�m� toplan�r. sonu� sayiya b�l�n�r. sanal k�s�m bulunmu� olunur
		reel = geciciReel;
		sanal = geciciSanal;
	}

	void kutupsalGosterim()		// karma��k say�n�n kutupsal g�sterimi i�in fonksiyon tan�mlad�m
	{
		float Z, aci;			// say�y� Z = a + bi �eklinde d���nd�m Z ve a��y� float cinsinden tan�mlad�m.
		Z = sqrt(pow(reel, 2) + pow(sanal, 2));		// Z'nin b�y�kl���n� bulmak i�in reel ve sanal k�s�mlar�n karesi toplan�r
		aci = asin(sanal / Z);		// sanal/Z sin�s de�erini verdi�inden ( dik ��gende sanal, a��n�n kar��s�ndaki de�er (y uzunlu�unu) ve Z hipoten�s� verir.) arcsin(sanal/Z) de bize a��y� verir
		aci = aci * (180 / PI);
		cout << Z << "(cos(" << aci << ") + i.sin(" << aci << "))" << endl;		// kutupsal g�sterim |Z|(cos@ + i.sin@) (@: a��) �eklinde oldu�undan ekrana bu �ekilde yazd�rmas�n� sa�lad�m
	}

	void yazdir()			// Karma��k say�y� yazd�rabilmek i�in fonksiyon tan�mlad�m
	{
		if (sanal > 0) {			//e�er sanal k�s�m 0'dan b�y�kse bu ko�ul �al��acak (Z = a + bi �eklinde bas�lacak ekrana)
			cout << "-----------------------------" << endl;
			cout << "Sonu�: " << reel << " + " << sanal << "i" << endl;
		}
		else if (sanal == 0) {			//e�er sanal k�s�m s�f�ra e�itse bu ko�ul �al���r.(sadece reel k�s�m bast�r�l�r Z = a)
			cout << "-----------------------------" << endl;
			cout << "Sonu�: " << reel << endl;
		}
		else {							// di�er durumlarda(sanal negatifken) bu ko�ul �al���r.( Z = a - bi)
			cout << "-----------------------------" << endl;
			cout << "Sonu�: " << reel << " " << sanal << "i" << endl;
		}
	}

};

int main()
{
	setlocale(LC_ALL, "Turkish");		// T�rk�e karakter kullan�m� i�in
	char secim;							// kullan�c� kendisine sunulan se�imde tek karakter giri� yapaca��ndan char tipinde tan�mlad�m
	float reel1, reel2, sanal1, sanal2;		// kullan�c�n�n girece�i say�lar ondal�kl� olabilece�inden float tipinde tan�mlad�m
	karmasikSayi kompleks1, kompleks2, sonuc;		// iki karma��k say�ya i�lem yapt�r�laca��ndan karmasikSayi s�n�f� cinsinden kompleks 1, kompleks 2 ve bunlara yapt�r�lan i�lemin atanmas� i�in sonuc ad�nda de�i�ken tan�mlad�m
	while (1)			// Kullan�c� ��k�� yapmak isteyene kadar tekrar tekrar men�ye d�nmesi i�in sonsuz d�ng� yazd�m
	{
		menu();		// Main alt�nda tan�mlad���m men� ekrana bast�r�l�r
		cin >> secim;		// Kullan�c�ya yapmak istedi�i i�lem sorulur

		if (secim == 'Q' || secim == 'q')		// Kullan�c� Q veya q girerse uygulamadan ��k�� yapar
			break;
		else if (secim == '+')					// kullan�c� '+' girerse karma��k say�lar� toplar
		{
			system("cls");						// ekran� temizler
			kompleks1.sayilariGir();			// kullan�c� 1. say�n�n reel ve sanal k�s�mlar�n� girer
			kompleks2.sayilariGir();			// kullan�c� 2. say�n�n reel ve sanal k�s�mlar�n� girer
			sonuc = kompleks1 + kompleks2;		// girilen 2 say�n�n toplamas� yap�l�r ve sonuc'a atan�r.
			sonuc.yazdir();						// sonuc de�eri ekrana yazd�r�l�r.

			system("pause");					// kullan�c� herhangi bir tu�a basana kadar bekletir
			system("cls");						// ekran temizlenir ve tekrardan men�ye d�ner
		}

		else if (secim == '-')					// '-' girerse ��karma i�lemi yap�l�r
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 - kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '*')					// '*' girilise �arpma i�lemi yap�l�r
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 * kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '/')				// '/' girilirse b�lme i�lemi yap�l�r
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 / kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '1')	// Kullan�c� '1' girerse 2 karma��k say�y� toplar 1.ye atar. (+= i�lemi)
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator+=(kompleks2);		// kompleks1 ve kompleks2 toplan�r sonu� kompleks1'e atan�r.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '2')		// kullan�c� '2' girerse (-=) i�lemi yap�l�r kompleks1'den kompleks 2 ��kar�l�r kompleks1'e atan�r.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator-=(kompleks2);			// kompleks1'den kompleks 2 ��kar�l�r kompleks1'e atan�r.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '3')			// '3' girilise *= i�lemi yap�l�r. �ki say� �arp�l�p kompleks1'e atan�r.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator*=(kompleks2);		// �ki say� �arp�l�p kompleks1'e atan�r.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '4')		// '4' girilirse /= i�lemi yap�l�r kompleks1, kompleks2'ye b�l�n�r kompleks1'e atan�r.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator/=(kompleks2);		//kompleks1, kompleks2'ye b�l�n�r kompleks1'e atan�r.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == 'Z' || secim == 'z')		// 'Z' veya 'z' girilirse say�n�n kutupsal g�sterimi ekrana yazd�r�l�r
		{
			system("cls");
			kompleks1.sayilariGir();		// kullan�c� say�n�n reel ve sanal k�s�mlar�n� girer
			kompleks1.kutupsalGosterim();	// kutupsal g�sterimi yazd�ran fonksiyon �a�r�l�r
			system("pause");
			system("cls");

		}

		else       // Kullan�c� men�deki se�eneklerin d���nda bir �ey girerse uyar� mesaj� g�nderir
		{
			cout << "Yanl�� tercih yap�ld�. Tekrar Deneyiniz." << endl;
			system("pause");
			system("cls");
		}
	}



	return 0;
}


void menu()		// kullan�c�ya sunulacak olan men�
{
	cout << "[+] Toplama i�lemi i�in.";
	cout << "\t[1] '+=' ��lemi i�in." << endl;
	cout << "[-] ��karma i�lemi i�in.";
	cout << "\t[2] '-=' ��lemi i�in." << endl;
	cout << "[*] �arpma i�lemi i�in.";
	cout << "\t\t[3] '*=' ��lemi i�in." << endl;
	cout << "[/] B�lme i�lemi i�in.";
	cout << "\t\t[4] '/=' ��lemi i�in." << endl;
	cout << "[Z] Kutupsal g�sterim i�in.";
	cout << "\t[Q] ��k�� yapmak i�in." << endl;
}