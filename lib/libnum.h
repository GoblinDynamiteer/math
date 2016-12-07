#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define N 300


char binString[N];

bool isBinary(long long int a);
bool isBinaryFloatString(char *a);
bool isBinaryIntString(char *a);
int countDigits(long long int a);
int convertBinaryToDecimal(long long int b);
int convertBinaryStringToDecimal(char *a);
double convertBinaryStringToDecimalFloat(char *a);
double binaryStrToDbl(char *a);
void convertDecimalIntToStringBinary(int d);