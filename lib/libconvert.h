#define N 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Gloval char-array för hållande av binärsträng
#define N 256
char omvand[N];
char binarfloat[N];

//Antal siffror efter kommatecken, för binära flyttal
#define DECIMALTECKEN 10

void vand(char *str);
char *convert_i_to_binary(int decimal);
char *convert_f_to_binary(double decimal);
char *convert_to_binary(double decimal);