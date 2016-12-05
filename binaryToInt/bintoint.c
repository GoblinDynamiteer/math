//Konvertera bin�rt tal till decimalt tal
//Converts binary to decimal

//Cant handle very long numbers
//Workaround would be to input binary as char array


#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "../lib/libnum.h"

int main(){
	//Det bin�ra talet 1011 ska bli 11 i decimalform.
	//Binary 1011 is 11 in decimal form
	long long int binary = 1011;
	while(1){
		printf("Ange bin�rt tal: ");
		scanf("%d", &binary);
		//printf("Talet har %d antal siffror!\n", countDigits(binary));
		if(isBinary(binary)){
			int decimal = convertBinaryToDecimal(binary);
			//%lld is format for long long int
			printf("Bin�ra talet %lld �r %d i decimal form.\n", binary, decimal);
		}
		else{
			printf("Talet �r inte bin�rt!\n");
		}
	}
	return 0;
}