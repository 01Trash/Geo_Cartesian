#include <stdio.h>
#include <math.h>
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
	int i;

	// Hangi türe dönüştürülmek isteniyor soralım bir.
	printf("\n#=== Lütfen aşağıda belirtildiği gibi değişimin türünü seçiniz! ===#\n");
	printf("'Coğrafi koordinatlardan 3 boyutlu kartezyen koordinatlarına dönüşüm' için 1,\n");
	printf("'3 boyutlu kartezyen koordinatlardan coğrafi koordinatlara dönüşüm' için 2, tuşlayınız: ");
	scanf("%d", &x);
	if (x == 1)
	{
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

			//// Coğrafi Koordinatlardan 3 Boyutlu Kartezyen Koordinatlarına Dönüşüm!!!
		printf(" === Coğrafi koordinatlardan 3 boyutlu kartezyen koordinatlarına dönüşüm! === \n");
		// Hangi datum türü ile hesap yapılacak soralım bakalım bir.
		printf("\n#=== Lütfen aşağıda belirtildiği gibi datumu seçiniz! ===#\n");
		printf("'ED50 datumu' için 1,\n");
		printf("'WGS84 datumu' için 2,\n");
		printf("'GRS80 datumu' için 3, tuşlayınız: ");
		scanf("%d", &y);
		/// Datum Parametreleri;
		/* ED50 parametreleri;
		a = 6378388;
		b = 6356911.9461;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		if (y == 1)
		{
			a = 6378388;
			b = 6356911.9461;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* N değerinin hesaplanması
			N = a / (Sqrt(1 - (e2 * (sin(Enlem * PI / 180))^2))); */
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			/* Kartezyen koordinatlarının hesaplanması
			X, Y, Z;
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));*/
			//radiusX = (Enlem * ((PI) / 180)) * (PI / 180);
			//radiusY = (Boylam * ((PI) / 180)) * (PI / 180);
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			printf("X kartezyen değeri: %f\n", X);
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			printf("Y kartezyen değeri: %f\n", Y);
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));
			printf("Z kartezyen değeri: %f\n", Z);
		}
		/* WGS84 parametreleri;
		a = 6378137;
		b = 6356752.314;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 2)
		{
			a = 6378137;
			b = 6356752.314;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* N değerinin hesaplanması
			N = a / (Sqrt(1 - (e2 * (sin(Enlem * PI / 180))^2))); */
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			/* Kartezyen koordinatlarının hesaplanması
			X, Y, Z;
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));*/
			//radiusX = (Enlem * ((PI) / 180)) * (PI / 180);
			//radiusY = (Boylam * ((PI) / 180)) * (PI / 180);
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			printf("X kartezyen değeri: %f\n", X);
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			printf("Y kartezyen değeri: %f\n", Y);
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));
			printf("Z kartezyen değeri: %f\n", Z);
		}
		/* GRS80 parametreleri;
		a = 6378137;
		b = 6356752.298;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 3)
		{
			a = 6378137;
			b = 6356752.298;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* N değerinin hesaplanması
			N = a / (Sqrt(1 - (e2 * (sin(Enlem * PI / 180))^2))); */
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			/* Kartezyen koordinatlarının hesaplanması
			X, Y, Z;
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));*/
			X = (N + H) * cos(Enlem * ((PI) / 180)) * cos(Boylam * ((PI) / 180));
			printf("X kartezyen değeri: %f\n", X);
			Y = (N + H) * cos(Enlem * ((PI) / 180)) * sin(Boylam * ((PI) / 180));
			printf("Y kartezyen değeri: %f\n", Y);
			Z = ((1 - e2) * N + H) * (sin(Enlem * ((PI) / 180)));
			printf("Z kartezyen değeri: %f\n", Z);
		}
		else
		{
			printf("Yanlış bir değer tuşladınız lütfen baştan yapınız!\n");
		}
	}
	else if (x == 2)
	{
			/// Bilinenleri isteyelim.
		/*  Kartezyen Koordinatları
		X, Y, Z; */
		printf("X kartezyen değerini giriniz: ");
		scanf("%lf", &X);
		printf("Y kartezyen değerini giriniz: ");
		scanf("%lf", &Y);
		printf("Z kartezyen değerinin giriniz: ");
		scanf("%lf", &Z);
			////  3 Boyutlu Kartezyen Koordinatlardan Coğrafi Koordinatlara Dönüşüm!!!
		printf(" === 3 boyutlu kartezyen koordinatlardan coğrafi koordinatlara dönüşüm! === \n");
				// if parametrisi kullanılacak!!!
		// Hangi datum türü ile hesap yapılacak soralım bakalım bir.
		printf("\n#=== Lütfen aşağıda belirtildiği gibi datumu seçiniz! ===#\n");
		printf("'ED50 datumu' için 1,\n");
		printf("'WGS84 datumu' için 2,\n");
		printf("'GRS80 datumu' için 3, tuşlayınız: ");
		scanf("%d", &y);
		/// Datum Parametreleri;
		/* ED50 parametreleri;
		a = 6378388;
		b = 6356911.9461;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		if (y == 1)
		{
			a = 6378388;
			b = 6356911.9461;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				/// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* Coğrafi Koordinatı olan Enlem değerine 10 kez basit iterasyon yapılır.
			Enlem0 = atan(Z / (((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N0 = a / (Sqrt(1 - (e2 * ((sin(Enlem0 * ((PI) / 180))) ^ 2))));
			Enlem1 = (atan((Z + e2 * N0 * sin(Enlem0 * ((PI) / 180))) / Sqrt((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N1 = a / (Sqrt(1 - (e2 * ((sin(Enlem1 * ((PI) / 180))) ^ 2))));
			... */
			for (i == 1; i < 10; i++)
			{
				Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
				N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), 0.5));
				printf("Enlem: %0.15f\n", Enlem);
			}
				/* Farklı Datumlarda Coğrafi Koordinatlar Hesaplanır (ED50, WGS84, GRS80)
			Enlem( φ), Boylam (λ), Elipsoid Yüksekliği (H)
			Enlem = (atan((Z + e2 * N9 * sin(Enlem9 * ((PI) / 180))) / Sqrt((X^2) + (Y^2)))) * (180 / (PI));
			N = a / (Sqrt(1 – (e2 * ((sin(Enlem * ((PI) / 180)))^2))));
			Boylam = (atan(Y / X)) * (180 / PI);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N; */
			Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
			printf("Enlem: %f\n", Enlem);
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			Boylam = (atan(Y / X)) * (180 / PI);
			printf("Boylam: %f\n", Boylam);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N;
			printf("Elipsoid yüksekliği: %f\n", H);
		}
		/* WGS84 parametreleri;
		a = 6378137;
		b = 6356752.314;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 2)
		{
			a = 6378137;
			b = 6356752.314;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				/// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* Coğrafi Koordinatı olan Enlem değerine 10 kez basit iterasyon yapılır.
			Enlem0 = atan(Z / (((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N0 = a / (Sqrt(1 - (e2 * ((sin(Enlem0 * ((PI) / 180))) ^ 2))));
			Enlem1 = (atan((Z + e2 * N0 * sin(Enlem0 * ((PI) / 180))) / Sqrt((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N1 = a / (Sqrt(1 - (e2 * ((sin(Enlem1 * ((PI) / 180))) ^ 2))));
			... */
			for (i == 1; i < 10; i++)
			{
				Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
				N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), 0.5));
				//printf("Enlem: %0.15f\n", Enlem);
			}
				/* Farklı Datumlarda Coğrafi Koordinatlar Hesaplanır (ED50, WGS84, GRS80)
			Enlem( φ), Boylam (λ), Elipsoid Yüksekliği (H)
			Enlem = (atan((Z + e2 * N9 * sin(Enlem9 * ((PI) / 180))) / Sqrt((X^2) + (Y^2)))) * (180 / (PI));
			N = a / (Sqrt(1 – (e2 * ((sin(Enlem * ((PI) / 180)))^2))));
			Boylam = (atan(Y / X)) * (180 / PI);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N; */
			Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
			printf("Enlem: %f\n", Enlem);
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			Boylam = (atan(Y / X)) * (180 / PI);
			printf("Boylam: %f\n", Boylam);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N;
			printf("Elipsoid yüksekliği: %f\n", H);
		}
		/* GRS80 parametreleri;
		a = 6378137;
		b = 6356752.298;
		e2 =(Sqrt(a^2 - b^2) / a^2)^2; */
		else if (y == 3)
		{
			a = 6378137;
			b = 6356752.298;
			e2 = pow((pow((pow(a, 2) - pow(b, 2)), 0.5) / pow(a, 2)), 2);
				/// Bilinmeyenlerin hesaplanması.
			printf("\n\t=== Hesap sonuçları! === \n");
			/* Coğrafi Koordinatı olan Enlem değerine 10 kez basit iterasyon yapılır.
			Enlem0 = atan(Z / (((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N0 = a / (Sqrt(1 - (e2 * ((sin(Enlem0 * ((PI) / 180))) ^ 2))));
			Enlem1 = (atan((Z + e2 * N0 * sin(Enlem0 * ((PI) / 180))) / Sqrt((X ^ 2) + (Y ^ 2)))) * (180 / (PI));
			N1 = a / (Sqrt(1 - (e2 * ((sin(Enlem1 * ((PI) / 180))) ^ 2))));
			... */
			for (i == 1; i < 10; i++)
			{
				Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
				N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), 0.5));
				//printf("Enlem: %0.15f\n", Enlem);
			}
				/* Farklı Datumlarda Coğrafi Koordinatlar Hesaplanır (ED50, WGS84, GRS80)
			Enlem( φ), Boylam (λ), Elipsoid Yüksekliği (H)
			Enlem = (atan((Z + e2 * N9 * sin(Enlem9 * ((PI) / 180))) / Sqrt((X^2) + (Y^2)))) * (180 / (PI));
			N = a / (Sqrt(1 – (e2 * ((sin(Enlem * ((PI) / 180)))^2))));
			Boylam = (atan(Y / X)) * (180 / PI);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N; */
			Enlem = (atan((Z + e2 * N * sin(Enlem * ((PI) / 180))) / pow((pow(X, 2) + pow(Y, 2)), 0.5))) * (180 / (PI));
			printf("Enlem: %f\n", Enlem);
			N = a / (pow(1 - (e2 * pow((sin(Enlem * PI / 180)), 2)), (0.5)));
			Boylam = (atan(Y / X)) * (180 / PI);
			printf("Boylam: %f\n", Boylam);
			H = (X / ((cos(Enlem * ((PI) / 180))) * (cos(Boylam * ((PI) / 180))))) - N;
			printf("Elipsoid yüksekliği: %f\n", H);
		}
		else
		{
			printf("Yanlış bir değer tuşladınız lütfen baştan yapınız!\n");
		}
	}
	else
	{
		printf("Yanlış bir değer tuşladınız lütfen baştan yapınız!\n");
	}

	return 0;
}
