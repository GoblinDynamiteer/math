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
		printf("Ange bin�rt tal: ");
		strInput(binary, N);
		if(isBinaryFloatString(binary) || 1){
			printf("\nTalet �r bin�rt float!!\n");
			double f = binaryStrToDbl(binary);
			printf("float: %.6f\n", f);
		}
		else{
			printf("\nTalet �r inte bin�rt!\n");
		}
	}
	return 0;
}