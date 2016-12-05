/* 
Various functions for numbers
Converters
*/


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
			printf("a %% 10 = %d", a % 10);
			return 0;
		}
		a /= 10;
	}
	return 1;
}

//Converts int in binary form to decimal
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