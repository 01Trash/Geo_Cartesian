#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");



		//// Coğrafi Koordinatlardan 3 Boyutlu Kartezyen Koordinatlarına Dönüşüm!!!
	printf(" === Coğrafi koordinatlardan 3 boyutlu kartezyen koordinatlarına dönüşüm! === \n");
	/// Bilinenleri isteyelim.
	/* ED50, WGS84, GRS80 datumunda coğrafi koordinatlar;
	Enlem (φ), Boylam (λ), Elipsoid Yüksekliği (h) */

	/* Datum Parametreleri;
	ED50 parametreleri;
	a = 6378388;
	b = 6356911.9461;
	e2 =(Sqrt(a^2 - b^2) / a^2)^2;
	WGS84 parametreleri;
	a = 6378137;
	b = 6356752.314;
	e2 =(Sqrt(a^2 - b^2) / a^2)^2;
	GRS80 parametreleri;
	a = 6378137;
	b = 6356752.298;
	e2 =(Sqrt(a^2 - b^2) / a^2)^2; */

	/* Enlem ve Boylam değerlerinin Dereceye dönüştürülmesi;
	Enlem = dereceφ + (dakikaφ / 60) + (saniyeφ / 3600);
	Boylam = dereceλ + (dakikaλ / 60) + (saniyeλ / 3600); */


	// Bilinmeyenlerin hesaplanması.
	printf("\n === Hesaplar! === \n");
	/* N değerinin hesaplanması
	N = a / (Sqrt(1 - (e2 * (Sin(Enlem * PI / 180))^2))); */

	/* Kartezyen koordinatlarının hesaplanması
	X, Y, Z;
	Y = (N + h) * Cos(Enlem * ((PI) / 180)) * Sin(Boylam * ((PI) / 180));
	X = (N + h) * Cos(Enlem * ((PI) / 180)) * Cos(Boylam * ((PI) / 180));
	Z = ((1 - e2) * N + h) * (Sin(Enlem * ((PI) / 180))); */




		////  3 Boyutlu Kartezyen Koordinatlardan Coğrafi Koordinatlara Dönüşüm!!!
	printf(" === 3 Boyutlu Kartezyen Koordinatlardan Coğrafi Koordinatlara Dönüşüm! === \n");
	/// Bilinenleri isteyelim.
	/* Datum parametreleri
	ED50 parametreleri

	a = 6378388;
	b = 6356911.9461;
	e2 = ((Sqrt(((a^2) - (b^2)) / (a^2)))^2);
	WGS84 parametreleri
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



	return 0;
}
