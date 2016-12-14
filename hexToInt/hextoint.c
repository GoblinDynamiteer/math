#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Applicerad Yrkesmatematik
	Gemensam programmering.
	Konvertera hexadecimalt tal till decimalt.
*/

int convert_to_decimal(char *tal, int bas);
int conv_digit(char ch);
int ipow(int bas, int exp);
int ipow_iter(int bas, int exp);

int main(int argc, char *argv[]){
	int tal, bas;
	//Temporär kommentering av agument till int
	/* bas = atoi(argv[2]);
	tal = convert_to_decimal(argv[1], bas); */
	bas = 16;
	tal = convert_to_decimal("A2C4", bas);
	/* Se till att antalet argument har angivits rätt! */
	printf("A2C4 (i bas %d) = %d\n", bas, tal);
	return 0;
}

//Funktion som konverterar tal med specifik nummerbas till decimalt
int convert_to_decimal(char *tal, int bas){
	int len = strlen(tal) - 1, summa = 0, faktor = 0;
	for(int i = 0; tal[i] != '\0'; i++){
		//printf("%d:'%c' = %d\n", len-i, tal[i], conv_digit(tal[i]));
		faktor = conv_digit(tal[i]) * ipow(bas, len-i);
		summa += faktor;
	}
	return summa;
}

//Funktion som konverterar enskilda char-tecken till heltal
int conv_digit(char ch){
	if ('0'<=ch && ch <='9'){
		return ch-'0';
	}
	if ('A'<=ch && ch <='F'){
		return ch-55;
	}
}

//Icke rekursiv funktion -- fixa
int ipow_iter(int bas, int exp){
	int product = 1;
	while(exp > 0){
		product = product * bas;
		exp--;
	}
	return product;

//Rekursiv funktion - "gummisnodd"
int ipow(int bas, int exp){
	if(exp == 0){
		return 1;
	}
	return bas * ipow(bas, exp-1);
}