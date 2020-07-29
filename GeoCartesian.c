#include <stdio.h>
#include <math.h>

#include<stdlib.h>
#include<conio.h>

#include <locale.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164

int main()
{
	setlocale(LC_ALL, "Turkish");

	double EnlemDer, EnlemDak, EnlemSan, BoylamDer, BoylamDak, BoylamSan, H;
	double Enlem, Boylam;
	int x, y;
	double a, b, e2;
	double N, X, Y, Z;

	/// Bilinenleri isteyelim.
	// Enlem ile boylamı derece, dakika ve saniye olarak isteyelim. Sonra ise dereceye çevirelim.
	/* ED50, WGS84, GRS80 datumunda coğrafi koordinatlar;
	Enlem, Boylam, Elipsoid yüksekliği. */
	printf("Enlem derece değerini giriniz: ");
	scanf("%lf", &EnlemDer);
	printf("Enlem dakika değerini giriniz: ");
	scanf("%lf", &EnlemDak);
	printf("Enlem saniye değerinin giriniz: ");
	scanf("%lf", &EnlemSan);
	printf("Boylam derece değerini giriniz: ");
	scanf("%lf", &BoylamDer);
	printf("Boylam dakika değerini giriniz: ");
	scanf("%lf", &BoylamDak);
	printf("Boylam saniye değerini giriniz: ");
	scanf("%lf", &BoylamSan);
	printf("Elipsoid yüksekliği değerini giriniz: ");
	scanf("%lf", &H);
	/* Enlem ve Boylam değerlerinin Dereceye dönüştürülmesi;
	Enlem = EnlemDer + (EnlemDak / 60) + (EnlemSan / 3600);
	Boylam = BoylamDer + (BoylamDak / 60) + (BoylamSan / 3600);*/
	Enlem = EnlemDer + (EnlemDak / 60) + (EnlemSan / 3600);
	//Burada mod alma yapılabilir!
	printf("Girilen enlem değeri: %f\n", Enlem);
	Boylam = BoylamDer + (BoylamDak / 60) + (BoylamSan / 3600);
	//Burada mod alma yapılabilir!
	printf("Girilen boylam değeri: %f\n", Boylam);

	// Hangi türe dönüştürülmek isteniyor soralım bir.
	printf("\n=== Lütfen aşağıda belirtildiği gibi değişimin türünü seçiniz! ===\n");
	printf("'Coğrafi koordinatlardan 3 boyutlu kartezyen koordinatlarına dönüşüm' için 1,\n");
	printf("3 boyutlu kartezyen koordinatlardan coğrafi koordinatlara dönüşüm için 2, tuşlayınız: \n");
	scanf("%d", x);
	if (x == 1)
	{
			//// Coğrafi Koordinatlardan 3 Boyutlu Kartezyen Koordinatlarına Dönüşüm!!!
		printf(" === Coğrafi koordinatlardan 3 boyutlu kartezyen koordinatlarına dönüşüm! === \n");
		// Hangi datum türü ile hesap yapılacak soralım bakalım bir.
		printf("\n=== Lütfen aşağıda belirtildiği gibi datumu seçiniz! ===\n");
		printf("'ED50 datumu' için 1,\n");
		printf("'WGS84 datumu' için 2,\n");
		printf("'GRS80 datumu' için 3, tuşlayınız: \n");
		scanf("%d", y);
		/// Datum Parametreleri;
		/* ED50 parametreleri;
		a = 6378388;
		b = 6356911.9461;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		if (y == 1)
		{
			a = 6378388;
			b = 6356911.9461;
			e2 =pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
		}
		/* WGS84 parametreleri;
		a = 6378137;
		b = 6356752.314;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 2)
		{
			a = 6378137;
			b = 6356752.314;
			e2 =pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
		}
		/* GRS80 parametreleri;
		a = 6378137;
		b = 6356752.298;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 3)
		{
			a = 6378137;
			b = 6356752.298;
			e2 =pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
		}
		else
		{
			printf("Yanlış bir değer tuşladınız lütfen baştan yapınız!\n");
		}

		// Bilinmeyenlerin hesaplanması.
		printf("\n === Hesaplar! === \n");
		/* N değerinin hesaplanması
		N = a / (Sqrt(1 - (e2 * (sin(Enlem * PI / 180))^2))); */
		N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
		/* Kartezyen koordinatlarının hesaplanması
		X, Y, Z;
		Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
		X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
		Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180))); */
		Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
		X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
		Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));
	}
	else if (x == 2)
	{
			////  3 Boyutlu Kartezyen Koordinatlardan Coğrafi Koordinatlara Dönüşüm!!!
		printf(" === 3 boyutlu kartezyen koordinatlardan coğrafi koordinatlara dönüşüm! === \n");
		/// Bilinenleri isteyelim.
				// if parametrisi kullanılacak!!!
		/* Datum parametreleri
		ED50 parametreleri;
		a = 6378388;
		b = 6356911.9461;
		e2 = ((Sqrt(((a^2) - (b^2)) / (a^2)))^2);
		WGS84 parametreleri;
		a = 6378137;
		b = 6356752.314;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2;
		GRS80 parametreleri;
		a = 6378137;
		b = 6356752.298;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2;
		Kartezyen Koordinatları;
		X, Y, Z; */

		/// Bilinmeyenlerin hesaplanması.
		printf("\n === Hesaplar! === \n");
		/* Coğrafi Koordinatı olan Enlem değerine 10 kez basit iterasyon yapılır.
		Enlem0 =Atan(Z / (((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
		N0 = a / (Sqrt(1 - (e2 * ((Sin(Enlem0 * ((PI) / 180))) ^ 2))));
		Enlem1 = (Atan((Z + e2 * N0 * Sin(Enlem0 * ((PI) / 180))) / Sqrt((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
		N1 = a / (Sqrt(1 - (e2 * ((Sin(Enlem1 * ((PI) / 180))) ^ 2)))); */

		/* Farklı Datumlarda Coğrafi Koordinatlar Hesaplanır (ED50, WGS84, GRS80)
		Enlem( φ), Boylam (λ), Elipsoid Yüksekliği (h)
		Enlem = (Atan((Z + e2 * N9 * Sin(Enlem9 * ((PI) / 180))) / Sqrt((X^2) + (Y^2)))) * (180 / (PI))
		N = a / (Sqrt(1 – (e2 * ((Sin(Enlem * ((PI) / 180)))^2))));
		Boylam = (Atan(Y / X)) * (180 / PI);
		h = (X / ((Cos(Enlem * ((PI) / 180))) * (Cos(Boylam * ((PI) / 180))))) – N; */
	}
	else
	{
		printf("Yanlış bir değer tuşladınız lütfen baştan yapınız!\n");
	}

	return 0;
}
