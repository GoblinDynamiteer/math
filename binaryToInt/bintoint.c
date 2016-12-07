//Konvertera bin�rt tal till decimalt tal
//Converts binary to decimal

//Cant handle very long numbers
//Workaround would be to input binary as char array **FIXED

//compile with 
//gcc bintoint.c ..\lib\libnum.c -o output.exe

#include "../lib/libnum.h"
#include "../lib/libtxt.h"
#define N 300

int main(){
	//Det bin�ra talet 1011 ska bli 11 i decimalform.
	//Binary 1011 is 11 in decimal form
	char binary[N] = "1011";
	while(1){
		//User string input to char array binary
		printf("Ange bin�rt tal: ");
		strInput(binary, N);
		if(isBinaryIntString(binary)){
			printf("\nTalet �r bin�rt!\n");
			int decimal = convertBinaryStringToDecimal(binary);
			printf("\nDecimalt: %d\n", decimal);
		}
		else{
			printf("\nTalet �r inte bin�rt!\n");
		}
	}
	return 0;
}