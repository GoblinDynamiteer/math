#include "libelectronics.h"

//Calculates total resistance of resistor values in int-array
//Stops when array value is 0
float resistorParallellCalc(int resistors[]){
	double resistanceTotal = 0;
	for(int i = 0; resistors[i] != 0; i++){
		resistanceTotal += 1.0/(double)resistors[i];
	}
	resistanceTotal = 1.0/resistanceTotal;
	return resistanceTotal;
}