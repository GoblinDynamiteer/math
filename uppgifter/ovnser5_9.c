/*
Approximativa Tal
Uppgift: Övningsserie 5 - Uppgift 9, 10, 11

Ladda ner filerna blå-motstånd.txt och gula-motstånd.txt från Moodle!
De innehåller uppmätta resistanser för ett antal 220 Ohms motstånd.

09: Gör ett C-program (eller annan kod) som räknar ut den genomsnittliga 
resistansen för ett typiskt gult motstånd, och ett typiskt blått motstånd.

10: Använd programmet för att ta reda på genomsnittet på gula och på blå
motstånd. De gula motstånden har kod röd-röd-brun-guld, de blå har
kod röd-röd-svart-svart-brun. Notera resistansens avvikelse från den
färgkodade resistansen på motstånden.

http://www.digikey.se/en/resources/conversion-calculators/
conversion-calculator-resistor-color-code-4-band
GULA: 220 Ohms 5%
BLÅA: 220 Ohms 1%

11: Bygg ut ovanstående program så att du kan ange ett motstånd, och
beräkna hur mycket det avviker ifrån medeltalet.

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
	char *farg[2] = {"blå", "gula"};
	//Array med filpekare:
	FILE *resistorFil[2] = {
		fopen("txt/bla-motstand.txt", "r"), 
		fopen("txt/gula-motstand.txt", "r")
	};
	char a[N];
	int antalResistorer[2] = {0,0};
	double resistorVarde = 0, summa[2] = {0,0};
	for(int i=0;i<2;i++){
		/* Läser in filradens text till resistorVarde som double,
		samt räknar antal resistorer (rader) */
		while(fgets(a, N, resistorFil[i]) != NULL){
			antalResistorer[i]++;
			sscanf(a, "%lf", &resistorVarde);
			summa[i] += resistorVarde;
		}
		skrivUtData(summa[i], antalResistorer[i], farg[i]);
		printf("Avvikelse från %d: %g\n", MARKVARDE,
			avvikelse(medelvarde(summa[i], antalResistorer[i])));
	}
	//Uppgift 11:
	while(1){
		printf("\nAnge resistorvärde: ");
		scanf("%lf", &resistorVarde);
		printf("Avvikelse från %d: %g\n", MARKVARDE,
			avvikelse(resistorVarde));
	}
	return 0;
}

//Skriver ut data om uppmätta resistorvärden, antal resistorer, medelvärde, färg
void skrivUtData(double summa, int antalResistorer, char *farg){
	printf("Antal %s resistorer: %d, medelvärde: %g Ohm\n", farg, 
		antalResistorer, medelvarde(summa,antalResistorer));
}

//Beräknar de uppmätta resistorernas medelvärde
double medelvarde(double summa, int antal){
	return summa/antal;
}

/* Returnerar absolutvärdet av avvikelsen från märkvärde 
av inmatad resistor eller beräknat resistansvärde från filer */
double avvikelse(double medelvarde){
	return fabs(MARKVARDE-medelvarde);
}