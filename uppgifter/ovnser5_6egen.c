/*
Approximativa Tal
Uppgift: �vningsserie 5 - Uppgift 6, 7, 8


G�r ett C-program som inneh�ller structar som best�r av ett
n�rmev�rde a(streck) och ett fel delta-alpha.

Utf�r addition 13,007 � 0,004 + 2,115 � 0,017

G�r funktioner som utf�r operationer p� tv� approximativa
tal.

Operationer: addition, division, multiplikation, division

Problem:
Division/Subtraktion-operation kan ge felaktiga v�rden till
a/b(tak) och a/b(golv) etc

*/


#include <stdio.h>

typedef struct approx{
	double narmevarde;
	double fel;
}approx_tal;

double minstaTal(approx_tal a);
double storstaTal(approx_tal a);
double medelvarde(double a, double b);
double plusMinus(double a, double b);
double opAdd(double a, double b);
double opSub(double a, double b);
double opDiv(double a, double b);
double opMulti(double a, double b);
approx_tal operation(approx_tal a, approx_tal b, double(*fp)(double a, double b));
void skrivUtApproxTal(approx_tal a);


int main(){
	approx_tal a, b, c;
	//Array med pekare till operationsfunktionerna, tv� st opAdd f�r att kunna "strunta" i index 0
	double(*op[5])(double a, double b)  = {opAdd, opAdd, opSub, opMulti, opDiv};
	int opVal;
	while(1){
		//Osnygg, men funktionsduglig inmatning av approximativa tal:
		//Sl� in 123 123 f�r 123�123
		printf("Skriv in approximativt tal 1: ");
		scanf("%lf %lf", &a.narmevarde, &a.fel);
		printf("Skriv in approximativt tal 2: ");
		scanf("%lf %lf", &b.narmevarde, &b.fel);
		//Val av operation, inslagen siffra anv�nds f�r index i funktionspekararrayen op
		printf("\nOperation [1:Add] [2:Sub] [3:Multi] [4:Div]\nVal:");
		scanf("%d", &opVal);
		//Resultatet av operationen s�tts till c, som skrivs ut.
		c = operation(a,b,op[opVal]);
		printf("\nResultat: ");
		skrivUtApproxTal(c);
	}
	return 0;
}

/* Ber�knar operation mellan tv� approximativa tal. 
double(*fp)(double a, double b) �r en pekare till operationsfunktion:
opAdd / opDiv / opMulti / opSub
Som retur ges en struct approx med narmev�rde och �fel */
approx_tal operation(approx_tal a, approx_tal b, double(*fp)(double a, double b)){
	approx_tal resultat;
	double a_golv = minstaTal(a);
	double a_tak = storstaTal(a);
	double b_golv = minstaTal(b);
	double b_tak = storstaTal(b);
	// (*fp) �r en pekare till den operationsfunktion som ska anv�ndas
	// OBS Detta kommer antagligen bli fel vid division och/eller subtraktion, fixa check!
	double op_tak = (*fp)(a_tak, b_tak);
	double op_golv = (*fp)(a_golv, b_golv);
	resultat.narmevarde = medelvarde(op_tak, op_golv);
	resultat.fel = plusMinus(op_tak, op_golv);
	return resultat;
}

/* Skriver ut ett approximativt tal, i formatet 
123.123 � 0.22 */
void skrivUtApproxTal(approx_tal a){
	printf("%g � %g\n", a.narmevarde, a.fel);
}

//Returnerar det minsta talet (golvet) i intervallet f�r ett approximativt tal
double minstaTal(approx_tal a){
	return a.narmevarde - a.fel;
}

//Returnerar det st�rsta talet (taket) i intervallet f�r ett approximativt tal
double storstaTal(approx_tal a){
	return a.narmevarde + a.fel;
}

//Returnerar medelv�rde av tv� tal
double medelvarde(double a, double b){
	return (a+b)/2;
}

//Retunerar felet mellan tv� tal
//OBS bygg check om b �r st�rre �n a, ev anv�nd fabs();
double plusMinus(double a, double b){
	return (a-b)/2;
}


//Operationsfunktioner:
double opAdd(double a, double b){
	return a+b;
}

double opSub(double a, double b){
	return a-b;
}

double opDiv(double a, double b){
	return a/b;
}

double opMulti(double a, double b){
	return a*b;
}
