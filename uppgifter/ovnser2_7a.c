/* Uppgift: Övningsserie 2 - Uppgift 7a

Två motstånd: R1 och R2.
Summan av dessa måste vara 400 Ohm

Hur ska man sätta R1 och R2 så att att Rtot blir så liten som möjligt
i en parallellkoppling?! */

#include <stdio.h>
#include <limits.h>

int main(){
	int R1 = 1, R1C, R2C;
	float rsummin = 401.0;
	while(R1 != 400){
		int R2 = 400 - R1;
		double rtot = 1.0/((1.0/(float)R1)+(1.0/(float)R2));
		printf("rtot = %.2f R1 = %3d R2 = %3d\n", rtot, R1, R2);
		if(rtot < rsummin){
			rsummin = rtot;
			R1C = R1;
			R2C = R2;
		}
		R1++;
	}
	printf("\nSVAR: rtot = %.2f R1 = %3d R2 = %3d\n", rsummin, R1C, R2C);
	return 0;
}