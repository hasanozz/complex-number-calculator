#include <iostream>  // temel girdi çýktý iþlemleri için ekledim
#include <locale.h>  // Türkçe karakterler kullanabilmek için ekledim
#include <cmath>	 // matematiksel iþlemler yapabilmek için ekledim
using namespace std;

const double PI = 3.14159;
void menu();  // kullanýcýya sunuluacak menüyü fonksiyon içine yazýp tanýmýný main altýna yaptým

class karmasikSayi  //karmaþýk sayý sýnýfý tanýmladým
{
private:	// sonrasýnda deðiþtirilmemesi için reel ve sanal kýsmý private kýsmýna tanýmladým
	float reel;
	float sanal;

public:		// fonksiyonlarý public içine tanýmladým
	karmasikSayi(float _reel = 0, float _sanal = 0)
	{
		reel = _reel;
		sanal = _sanal;
	}
	void sayilariGir()		// kullanýcýndan sayýlarý girmesi için tanýmladýðým fonksiyon
	{
		cout << "Reel kýsým: ";
		cin >> reel;
		cout << "Sanal kýsým: ";
		cin >> sanal;
		cout << endl;
	}

	karmasikSayi operator+(karmasikSayi obj)	// karmaþýk sayýlarý toplayabilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		karmasikSayi toplam;					// karmasikSayi sýnýfý cinsinden toplam adlý bir deðiþken tanýmladým
		toplam.reel = reel + obj.reel;			// sayýnýn reel kýsmý ve parantez içindeki sayýnýn reel kýsmý toplanýr toplamýn reel kýsmýna atanýr
		toplam.sanal = sanal + obj.sanal;		// sayýnýn sanal kýsmý ve parantez içindeki sayýnýn sanal kýsmý toplanýr toplamýn sanal kýsmýna atanýr
		return toplam;							// toplam deðerini döndürür
	}

	karmasikSayi operator-(karmasikSayi obj)	// karmaþýk sayýlarý çýkarabilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		karmasikSayi sonuc;						// karmasikSayi sýnýfý cinsinden sonuc adlý bir deðiþken tanmladým
		sonuc.reel = reel - obj.reel;			// sayýnýn reel kýsmýndan obj'nin reel kýsmý çýkartýlýp sonucun reel kýsmýna atanýr
		sonuc.sanal = sanal - obj.sanal;		// sayýnýn sanal kýsmýndan obj'nin sanal kýsmý çýkartýlýp sonucun sanal kýsmýna atanýr.
		return sonuc;							// sonuc deðeri döndürülür
	}

	karmasikSayi operator*(karmasikSayi obj)				// karmaþýk sayýlarý çarpabilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		karmasikSayi carpim;								// karmasikSayi sýnýfý cinsinden carpim adlý bir deðiþken tanýmladým
		carpim.reel = reel * obj.reel - sanal * obj.sanal;		// sayýnýn reel kýsmý ve obj'nin reel kýsmý çarpýlýr ve bu çarpýmdan sayýnýn sanal kýsmý ile obj'nin sanal kýsmýnýn çarpýmý çýkartýlýr(i^2 = -1 olduðundan). carpim'in reel kýsmýna atanýr
		carpim.sanal = reel * obj.sanal + sanal * obj.reel;		// sayýnýn reel kýsmý ve obj'nin sanal kýsmý çarpýlýr bu çarpýmla sayýnýn sanal kýsmý ve obj'nin reel kýsmýnýn çarpýmý toplanýr. carpim'in sanal kýsmýna atanýr
		return carpim;										// carpim deðeri döndürülür
	}

	karmasikSayi operator/(karmasikSayi obj)								// karmaþýk sayýlarý bölebilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		karmasikSayi bolum;													// karmasikSayi sýnýfý cinsinden bolum adlý bir deðiþken tanýmladým
		float sayi = pow(obj.reel, 2) + pow(obj.sanal, 2);					// float tipinden sayi adlý bir deðiþken tanýmlayýp obj'nin reel ve sanal kýsmýnýn karelerinin toplamýný atadým(bölüm iþlemi yapýlýrken kesir, kesirin altýndaki sayýnýn eþleniðiyle çarpýlýr paydanýn karesi alýnmýþ olunur)
		bolum.reel = (reel * obj.reel - sanal * (-1 * obj.sanal)) / sayi;			// sayýmýzýn reel kýsmýyla obj'nin reel kýsmý çarpýlýr bu çarpýmdan sayýmýzýn sanal kýsmýyla obj'nin sanal kýsmýnýn negatifinin çarpýmý çýkartýlýr. En son sonuç sayi'ya bölünür. bolumun reel kýsmýna atanýr.
		bolum.sanal = (reel * (-1 * obj.sanal) + sanal * obj.reel) / sayi;	// sayýmýzýn reel kýsmýyla obj'nin sanal kýsmýnýn negatifi çarpýlýr bu çarpýmla sayýmýzýn sanal kýsmý ve obj'nin reel kýsmý toplanýr, sonuc sayi'ya bölünür. bolumun sanal kýsmýna atanýr.
		return bolum;														// bolum deðeri döndürülür.
	}

	void operator+=(karmasikSayi obj)		// karmaþýk sayýlarý toplayabilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		reel += obj.reel;					// sayýmýzýn reel kýsmýyla obj'nin reel kýsmý toplanýr sayýmýzýn reel kýsmýna atanýr.
		sanal += obj.sanal;					// sayýmýzýn sanal kýsmýyla obj'nin sanal kýsmý toplanýr sayýmýzýn sanal kýsmýna atanýr.
	}

	void operator-=(karmasikSayi obj)		// karmaþýk sayýlarý çýkarabilmek için operatör aþýrý yüklenmesi tanýmladým
	{
		reel -= obj.reel;					// sayýnýn reel kýsmýndan obj'nin reel kýsmý çýkartýlýp sayýnýn reel kýsmýna atanýr
		sanal -= obj.sanal;					// sayýnýn sanal kýsmýndan obj'nin sanal kýsmý çýkartýlýp sayýnýn sanal kýsmýna atanýr.
	}

	void operator*=(karmasikSayi obj)		// karmaþýk sayýlarý çarpabilmek için operatör aþýrý yüklenmesi tanýmladým.(sonunda hem reel hem sanal kýsým döndürülmesi gerektiðinden return edilmemesi için void fonksiyon yazdým)
	{
		float geciciReel, geciciSanal;		// reel kýsmýn deðiþip sanalý hesaplarken farklý sonuç çýkmamasý için gecici reel ve sanal deðiþken tanýmlayýp iþlemin sonunda içlerindeki deðerleri reel ve sanal kýsma atadým
		geciciReel = reel * obj.reel - sanal * obj.sanal;		// sayýnýn reel kýsmý ve obj'nin reel kýsmýnýn çarpýmýndan sayýnýn sanal kýsmýyla obj'nin sanal kýsmýnýn çarpýmýný çýkarýp sayýnýn reel kýsmýna atadým
		geciciSanal = sanal * obj.reel + reel * obj.sanal;		// sayýnýn sanal kýsmýyla obj'nin reel kýsmýnýn çarpýmýyla sayýnýn reel kýsmýyla obj'nin sanal kýsmýnýn çarpýmýný toplayýp sayýnýn sanal kýsmýna atadým.
		reel = geciciReel;
		sanal = geciciSanal;
	}

	void operator/=(karmasikSayi obj)		// karmaþýk sayýlarý bölebilmek için operatör aþýrý yüklenmesi tanýmladým.(sonunda hem reel hem sanal kýsým döndürülmesi gerektiðinden return edilmemesi için void fonksiyon yazdým)
	{
		float geciciReel, geciciSanal, sayi;	// reel kýsmýn deðiþip sanalý hesaplarken farklý sonuç çýkmamasý için gecici reel ve sanal deðiþken tanýmlayýp iþlemin sonunda içlerindeki deðerleri reel ve sanal kýsma atadým.
		sayi = pow(obj.reel, 2) + pow(obj.sanal, 2);		// kesir paydanýn eþleniðiyle çarpýldýðýnda paydanýn karesi geldiði için float tipinde sayi deðiþkeni tanýmlayýp paydanýn karesini atadým
		geciciReel = (reel * obj.reel - sanal * (-1 * obj.sanal)) / sayi;		// sayýnýn reel kýsmý ve obj'nin reel kýsmýnýn çarpýmýndan sayýnýn sanal kýsmýyla obj'nin sanal kýsmýnýn negatifinin çarpýmýný çýkarýp sayiya bölünür. reel kýsým bulunmuþ olunur
		geciciSanal = (reel * (-1 * obj.sanal) + sanal * obj.reel) / sayi;		// sayýnýn reel kýsmý ve obj'nin sanal kýsmýnýn negatifinin çarpýmýyla sayýnýn sanal kýsmýyla obj'nin reel kýsmýnýn çarpýmý toplanýr. sonuç sayiya bölünür. sanal kýsým bulunmuþ olunur
		reel = geciciReel;
		sanal = geciciSanal;
	}

	void kutupsalGosterim()		// karmaþýk sayýnýn kutupsal gösterimi için fonksiyon tanýmladým
	{
		float Z, aci;			// sayýyý Z = a + bi þeklinde düþündüm Z ve açýyý float cinsinden tanýmladým.
		Z = sqrt(pow(reel, 2) + pow(sanal, 2));		// Z'nin büyüklüðünü bulmak için reel ve sanal kýsýmlarýn karesi toplanýr
		aci = asin(sanal / Z);		// sanal/Z sinüs deðerini verdiðinden ( dik üçgende sanal, açýnýn karþýsýndaki deðer (y uzunluðunu) ve Z hipotenüsü verir.) arcsin(sanal/Z) de bize açýyý verir
		aci = aci * (180 / PI);
		cout << Z << "(cos(" << aci << ") + i.sin(" << aci << "))" << endl;		// kutupsal gösterim |Z|(cos@ + i.sin@) (@: açý) þeklinde olduðundan ekrana bu þekilde yazdýrmasýný saðladým
	}

	void yazdir()			// Karmaþýk sayýyý yazdýrabilmek için fonksiyon tanýmladým
	{
		if (sanal > 0) {			//eðer sanal kýsým 0'dan büyükse bu koþul çalýþacak (Z = a + bi þeklinde basýlacak ekrana)
			cout << "-----------------------------" << endl;
			cout << "Sonuç: " << reel << " + " << sanal << "i" << endl;
		}
		else if (sanal == 0) {			//eðer sanal kýsým sýfýra eþitse bu koþul çalýþýr.(sadece reel kýsým bastýrýlýr Z = a)
			cout << "-----------------------------" << endl;
			cout << "Sonuç: " << reel << endl;
		}
		else {							// diðer durumlarda(sanal negatifken) bu koþul çalýþýr.( Z = a - bi)
			cout << "-----------------------------" << endl;
			cout << "Sonuç: " << reel << " " << sanal << "i" << endl;
		}
	}

};

int main()
{
	setlocale(LC_ALL, "Turkish");		// Türkçe karakter kullanýmý için
	char secim;							// kullanýcý kendisine sunulan seçimde tek karakter giriþ yapacaðýndan char tipinde tanýmladým
	float reel1, reel2, sanal1, sanal2;		// kullanýcýnýn gireceði sayýlar ondalýklý olabileceðinden float tipinde tanýmladým
	karmasikSayi kompleks1, kompleks2, sonuc;		// iki karmaþýk sayýya iþlem yaptýrýlacaðýndan karmasikSayi sýnýfý cinsinden kompleks 1, kompleks 2 ve bunlara yaptýrýlan iþlemin atanmasý için sonuc adýnda deðiþken tanýmladým
	while (1)			// Kullanýcý çýkýþ yapmak isteyene kadar tekrar tekrar menüye dönmesi için sonsuz döngü yazdým
	{
		menu();		// Main altýnda tanýmladýðým menü ekrana bastýrýlýr
		cin >> secim;		// Kullanýcýya yapmak istediði iþlem sorulur

		if (secim == 'Q' || secim == 'q')		// Kullanýcý Q veya q girerse uygulamadan çýkýþ yapar
			break;
		else if (secim == '+')					// kullanýcý '+' girerse karmaþýk sayýlarý toplar
		{
			system("cls");						// ekraný temizler
			kompleks1.sayilariGir();			// kullanýcý 1. sayýnýn reel ve sanal kýsýmlarýný girer
			kompleks2.sayilariGir();			// kullanýcý 2. sayýnýn reel ve sanal kýsýmlarýný girer
			sonuc = kompleks1 + kompleks2;		// girilen 2 sayýnýn toplamasý yapýlýr ve sonuc'a atanýr.
			sonuc.yazdir();						// sonuc deðeri ekrana yazdýrýlýr.

			system("pause");					// kullanýcý herhangi bir tuþa basana kadar bekletir
			system("cls");						// ekran temizlenir ve tekrardan menüye döner
		}

		else if (secim == '-')					// '-' girerse çýkarma iþlemi yapýlýr
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 - kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '*')					// '*' girilise çarpma iþlemi yapýlýr
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 * kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '/')				// '/' girilirse bölme iþlemi yapýlýr
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			sonuc = kompleks1 / kompleks2;
			sonuc.yazdir();

			system("pause");
			system("cls");
		}

		else if (secim == '1')	// Kullanýcý '1' girerse 2 karmaþýk sayýyý toplar 1.ye atar. (+= iþlemi)
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator+=(kompleks2);		// kompleks1 ve kompleks2 toplanýr sonuç kompleks1'e atanýr.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '2')		// kullanýcý '2' girerse (-=) iþlemi yapýlýr kompleks1'den kompleks 2 çýkarýlýr kompleks1'e atanýr.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator-=(kompleks2);			// kompleks1'den kompleks 2 çýkarýlýr kompleks1'e atanýr.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '3')			// '3' girilise *= iþlemi yapýlýr. Ýki sayý çarpýlýp kompleks1'e atanýr.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator*=(kompleks2);		// Ýki sayý çarpýlýp kompleks1'e atanýr.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == '4')		// '4' girilirse /= iþlemi yapýlýr kompleks1, kompleks2'ye bölünür kompleks1'e atanýr.
		{
			system("cls");
			kompleks1.sayilariGir();
			kompleks2.sayilariGir();
			kompleks1.operator/=(kompleks2);		//kompleks1, kompleks2'ye bölünür kompleks1'e atanýr.
			kompleks1.yazdir();
			system("pause");
			system("cls");
		}

		else if (secim == 'Z' || secim == 'z')		// 'Z' veya 'z' girilirse sayýnýn kutupsal gösterimi ekrana yazdýrýlýr
		{
			system("cls");
			kompleks1.sayilariGir();		// kullanýcý sayýnýn reel ve sanal kýsýmlarýný girer
			kompleks1.kutupsalGosterim();	// kutupsal gösterimi yazdýran fonksiyon çaðrýlýr
			system("pause");
			system("cls");

		}

		else       // Kullanýcý menüdeki seçeneklerin dýþýnda bir þey girerse uyarý mesajý gönderir
		{
			cout << "Yanlýþ tercih yapýldý. Tekrar Deneyiniz." << endl;
			system("pause");
			system("cls");
		}
	}



	return 0;
}


void menu()		// kullanýcýya sunulacak olan menü
{
	cout << "[+] Toplama iþlemi için.";
	cout << "\t[1] '+=' Ýþlemi için." << endl;
	cout << "[-] Çýkarma iþlemi için.";
	cout << "\t[2] '-=' Ýþlemi için." << endl;
	cout << "[*] Çarpma iþlemi için.";
	cout << "\t\t[3] '*=' Ýþlemi için." << endl;
	cout << "[/] Bölme iþlemi için.";
	cout << "\t\t[4] '/=' Ýþlemi için." << endl;
	cout << "[Z] Kutupsal gösterim için.";
	cout << "\t[Q] Çýkýþ yapmak için." << endl;
}