/* 
Various functions for numbers
Converters
*/

#include "libnum.h"

//Counts and returns number of digits in int
int countDigits(long long int a){
	int counter = 0;
	while(a != 0){
		counter++;
		//a is equal to integer division by 10 of itself
		a /= 10;
	}
	return counter;
}

//Function to check if int is in binary form (just consists of 1 and 0)
bool isBinary(long long int a){
	//check every last digit in integer with modulus 10, if rest is not 1 or 0,
	//the int is not in binary form.
	while(a != 0){
		if(a % 10 > 1){
			//Digit larger than 1 found, number is not in binary form
			return 0;
		}
		a /= 10;
	}
	return 1;
}

//Function to check if char array is in binary form (just consists of 1 and 0)
bool isBinaryString(char *a){
	int n = strlen(a);
	for(int i =0; i<n; i++){
		int number = a[i] - '0';
		if(number > 1){
			return 0;
		}
	}
	return 1;
}

//Converts string in binary form to decimal
//eg 101 = 1*2^0  + 0*2^1 + 1*2^2 = 5
int convertBinaryStringToDecimal(char *a){
	//Array starts at zero, therefore -1
	int n = strlen(a) - 1;
	int decimal = 0;
	//For power of
	int i = 0;
	while(n >= 0){
		//Digit in char - '0' is digit in int
		int lastDigit = a[n--] - '0';
		decimal += lastDigit * pow(2,i++);
	}
	return decimal;
}

//Converts int in binary form to decimal
//eg 101 = 1*2^0  + 0*2^1 + 1*2^2 = 5
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