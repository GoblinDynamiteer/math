//Program to calculate various electronics

#include <stdio.h>
#include "../lib/libelectronics.h"

#define RMAX 30 

int main(){
	//Resistors in parallell
	int resistors[RMAX], number = 0, resistorValue;
	printf("Use 0 to cancel!\n");
	//Loops while user doesn't enter 0
	while(1){
		printf("Enter resistor value: ");
		scanf("%d", &resistorValue);
		if(!resistorValue){
			//function resistorParallellCalc, needs a 0 value after
			//entered resistor values.
			resistors[number] = 0;
			break;
		}
		if(resistorValue < 0){
			printf("Error: Value need to be positive!\n ");
			continue;
		}
		resistors[number] = resistorValue;
		number++;
	}
	printf("You entered %d resistors with values: \n", number);
	for(int i = 0; i<number; i++){
		printf("Resistor %d: %d \n", i+1, resistors[i]);
	}
	printf("Total resistance: %.2f", resistorParallellCalc(resistors));
	return 0;
}