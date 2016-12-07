//Konvertera decimalt tal till binärt tal
//Converts decimal to binary

//compile with 
//gcc inttobin.c ..\lib\libnum.c -o output.exe

#include "../lib/libnum.h"
#include "../lib/libtxt.h"
#define N 300

//char binString[N];

int main(){
	int decimal = 1;
	while(1){
		//User string input to char array binary
		printf("\n------------------------------------\n");
		printf("Ange decimalt heltal: ");
		scanf("%d", &decimal);
		char *binary = convertDecimalIntToStringBinary(decimal);
		printf("\nBinärt: %s", binary);
		//frees string from memory
		free(binary);
	}
	return 0;
}