//Konvertera binärt tal till decimalt tal
//Converts binary to decimal

//Cant handle very long numbers
//Workaround would be to input binary as char array


#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isBinary(long long int a);
int countDigits(long long int a);
int convertBinaryToDecimal(long long int b);

int main(){
	//Det binära talet 1011 ska bli 11 i decimalform.
	//Binary 1011 is 11 in decimal form
	long long int binary = 1011;
	while(1){
		printf("Ange binärt tal: ");
		scanf("%d", &binary);
		//printf("Talet har %d antal siffror!\n", countDigits(binary));
		if(isBinary(binary)){
			int decimal = convertBinaryToDecimal(binary);
			//%lld is format for long long int
			printf("Binära talet %lld är %d i decimal form.\n", binary, decimal);
		}
		else{
			printf("Talet är inte binärt!\n");
		}
	}
	return 0;
}

//Converts binary to decimal
int convertBinaryToDecimal(long long int b){
	//Gets number of digits
	int n = countDigits(b);
	int decimal = 0;
	for(int i = 0; i<n; i++){
		bool lastDigit = b % 10;
		decimal += lastDigit * pow(2,i);
		b /= 10;
	}
	return decimal;
}


//Function to check if int is in binary form (just consists of 1 and 0)
//Funktion som kontrollerar om int är i binär form (enbart 1 och 0)
bool isBinary(long long int a){
	//check every last digit in integer with modulus 10, if rest is not 1 or 0,
	//the int is not in binary form.
	while(a != 0){
		if(a % 10 > 1){
			printf("a %% 10 = %d", a % 10);
			return 0;
		}
		a /= 10;
	}
	return 1;
}

//Counts and returns number of digits in int
//Räknar och returnerar antalet siffror i int
int countDigits(long long int a){
	int counter = 0;
	while(a != 0){
		counter++;
		//a is equal to integer division by 10 of itself
		a /= 10;
	}
	return counter;
}