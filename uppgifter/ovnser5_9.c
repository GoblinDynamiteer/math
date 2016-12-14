/*
Approximativa Tal
Uppgift: �vningsserie 5 - Uppgift 9, 10, 11

Ladda ner filerna bl�-motst�nd.txt och gula-motst�nd.txt fr�n Moodle!
De inneh�ller uppm�tta resistanser f�r ett antal 220 Ohms motst�nd.

09: G�r ett C-program (eller annan kod) som r�knar ut den genomsnittliga 
resistansen f�r ett typiskt gult motst�nd, och ett typiskt bl�tt motst�nd.

10: Anv�nd programmet f�r att ta reda p� genomsnittet p� gula och p� bl�
motst�nd. De gula motst�nden har kod r�d-r�d-brun-guld, de bl� har
kod r�d-r�d-svart-svart-brun. Notera resistansens avvikelse fr�n den
f�rgkodade resistansen p� motst�nden.

http://www.digikey.se/en/resources/conversion-calculators/
conversion-calculator-resistor-color-code-4-band
GULA: 220 Ohms 5%
BL�A: 220 Ohms 1%

11: Bygg ut ovanst�ende program s� att du kan ange ett motst�nd, och
ber�kna hur mycket det avviker ifr�n medeltalet.

*/

#include <stdio.h>
#include <math.h>
#define N 10
#define BLA 0
#define GUL 1
#define MARKVARDE 220

void skrivUtData(double summa, int antalResistorer, char *farg);
double medelvarde(double summa, int antal);
double avvikelse(double medelvarde);

int main(){
	char *farg[2] = {"bl�", "gula"};
	//Array med filpekare:
	FILE *resistorFil[2] = {
		fopen("txt/bla-motstand.txt", "r"), 
		fopen("txt/gula-motstand.txt", "r")
	};
	char a[N];
	int antalResistorer[2] = {0,0};
	double resistorVarde = 0, summa[2] = {0,0};
	for(int i=0;i<2;i++){
		/* L�ser in filradens text till resistorVarde som double,
		samt r�knar antal resistorer (rader) */
		while(fgets(a, N, resistorFil[i]) != NULL){
			antalResistorer[i]++;
			sscanf(a, "%lf", &resistorVarde);
			summa[i] += resistorVarde;
		}
		skrivUtData(summa[i], antalResistorer[i], farg[i]);
		printf("Avvikelse fr�n %d: %g\n", MARKVARDE,
			avvikelse(medelvarde(summa[i], antalResistorer[i])));
	}
	//Uppgift 11:
	while(1){
		printf("\nAnge resistorv�rde: ");
		scanf("%lf", &resistorVarde);
		printf("Avvikelse fr�n %d: %g\n", MARKVARDE,
			avvikelse(resistorVarde));
	}
	return 0;
}

//Skriver ut data om uppm�tta resistorv�rden, antal resistorer, medelv�rde, f�rg
void skrivUtData(double summa, int antalResistorer, char *farg){
	printf("Antal %s resistorer: %d, medelv�rde: %g Ohm\n", farg, 
		antalResistorer, medelvarde(summa,antalResistorer));
}

//Ber�knar de uppm�tta resistorernas medelv�rde
double medelvarde(double summa, int antal){
	return summa/antal;
}

/* Returnerar absolutv�rdet av avvikelsen fr�n m�rkv�rde 
av inmatad resistor eller ber�knat resistansv�rde fr�n filer */
double avvikelse(double medelvarde){
	return fabs(MARKVARDE-medelvarde);
}