#define N 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//Antal tecken f�r i bin�ra textstr�ngar
#define N 256

//Antal siffror efter kommatecken, f�r bin�ra flyttal
#define DECIMALTECKEN 10

void vand(char *str);
char *convert_i_to_binary(int decimal);
char *convert_f_to_binary(double decimal);
char *convert_to_binary(double decimal);