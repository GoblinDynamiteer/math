//Converts fraction binary to float
//for testing:
//http://www.exploringbinary.com/binary-converter/

#include "../lib/libnum.h"
#include "../lib/libtxt.h"
//#define N 300

int main(){
	char binary[N] = "1011.011";
	while(1){
		//User string input to char array binary
		printf("------------------------------------\n");
		printf("Ange bin�rt tal: ");
		strInput(binary, N);
		if(isBinaryIntString(binary)){
			printf("\nTalet �r bin�rt!\nBin�r: %s", binary);
			int decimal = convertBinaryStringToDecimal(binary);
			printf("\nDecimalt: %d\n", decimal);
		}
		else if(isBinaryFloatString(binary)){
			printf("\nTalet �r bin�rt (float)!\nBin�r: %s", binary);
			double f = binaryStrToDbl(binary);
			printf("\nFloat: %.6f\n", f);
		}
		else{
			printf("\nTalet �r inte bin�rt!\n");
		}
	}
	return 0;
}