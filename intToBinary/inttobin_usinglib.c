/*
Test av funktionsbibliotek libconvert
*/

#include <stdio.h>
#include "..\lib\libconvert.h"
#include "..\lib\libinput.h"

int main(void){
	char *binstr;
	double decfloat = 0.1875;
/* 	int decimal = 1025;
	binstr = convert_i_to_binary(decimal);
	printf("\n%d: %s\n", decimal, binstr);
	double decfloat = 0.1875;
	binstr = convert_f_to_binary(decfloat);
	printf("\n%g: %s\n", decfloat, binstr); */
	while(1){
		decfloat = inputDouble("Ange decimaltal: ");
		binstr = convert_to_binary(decfloat);
		printf("%g(10) = %s(2)\n", decfloat, binstr);
	}
	return 0;
}