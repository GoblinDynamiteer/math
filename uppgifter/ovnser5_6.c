/* 
Uppgift: Övningsserie 5 - Uppgift 6
*/

#include <stdio.h>

typedef struct _intervall_S{
	double golv;
	double tak;
}intervall; //intevall == struct intervall_S

//Funktion som returnerar struct intervall
intervall nytt_plus_minus(double median, double konf){
	intervall lokalintervall;
	lokalintervall.golv = median-konf;
	lokalintervall.tak = median+konf;
	return lokalintervall;
}

void skrivut_plus_minus(intervall itv){
	printf("%.4f ± %.4f\n", (itv.golv + itv.tak)/2, 
			(itv.tak - itv.golv)/2);
}

intervall multiplicera_plus_minus(intervall faktor1, intervall faktor2){
	intervall resultat;
	double varde[4], minsta, storsta;
	varde[0] = faktor1.golv * faktor2.golv;
	varde[1] = faktor1.tak * faktor2.golv;
	varde[2] = faktor2.golv * faktor1.tak;
	varde[3] = faktor2.tak * faktor1.tak;
	minsta = storsta = varde[0];
	for(int ix = 1; ix < 4; ix++){
		if(varde[ix]<minsta){
			minsta = varde[ix];
		}
		if(varde[ix]>storsta){
			storsta = varde[ix];
		}
	}
	resultat.golv = minsta;
	resultat.tak = storsta;
	return resultat;
}

int main(){
	intervall alfa, beta, gamma;
	alfa = nytt_plus_minus(23.546, 0.024);
	printf("[alfa = %lf / %lg ]\n", alfa.tak, alfa.golv);
	skrivut_plus_minus(alfa);
	beta = nytt_plus_minus(3.8, 0.2);
	printf("[beta = %lf / %lg ]\n", beta.tak, beta.golv);
	skrivut_plus_minus(beta);
	//lg "tar bort" nollorna efter decimaltecken
	gamma = multiplicera_plus_minus(alfa, beta);
	printf("[gamma = %lf / %lg ]\n", gamma.tak, gamma.golv);
	skrivut_plus_minus(gamma);
	return 0;
}