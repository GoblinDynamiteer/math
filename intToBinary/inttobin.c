//Konvertera decimalt tal till bin�rt tal
//Converts decimal to binary

//compile with 
//gcc inttobin.c ..\lib\libnum.c -o output.exe

#include "../lib/libnum.h"
#include "../lib/libtxt.h"
#define N 300

//char binString[N];

int main(){
	//Det bin�ra talet 1011 ska bli 11 i decimalform.
	//Binary 1011 is 11 in decimal form
	char *binary;
	int decimal = 365;
	while(1){
		//User string input to char array binary
		printf("\n------------------------------------\n");
		printf("Ange decimalt heltal: ");
		scanf("%d", &decimal);
		convertDecimalIntToStringBinary(decimal);
		printf("\nBin�rt: %s", binString);
	}
	return 0;
}