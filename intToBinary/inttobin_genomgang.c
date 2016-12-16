/*
Genomgång skolan - lärarledd programmering
Konvertera Int (dec) till Binär
*/

#include <stdio.h>
#define N 256
#include <string.h>

char *convert_to_binary(int decimal);
void vand(char *str);

int main(void){
	char *binstr;
	int decimal = 1025;
	binstr = convert_to_binary(decimal);
	printf("\n%d: %s\n", decimal, binstr);
	return 0;
}

void vand(char *str){
	//lower / upper index
	int lix, uix = strlen(str)-1;
	char temp;
	for(lix = 0; lix < uix; lix++, uix--){
		temp = str[uix];
		str[uix] = str[lix];
		str[lix] = temp;
	}
}

//Global
char omvand[N];

char *convert_to_binary(int decimal){
	//char omvand[N];
	//oix: omvandling index:
	int t, oix;
	oix = 0;
	for(t = decimal; t != 0; t=t/2){
		if(t%2 == 1){
			omvand[oix] = '1';
		}
		else{
			omvand[oix] = '0';
		}
		oix++;
	}
	omvand[oix] = '\0';
	//printf("Omvand: %s\n", omvand);
	vand(omvand);
	//printf("Omvand: %s\n", omvand);
	return omvand;
}