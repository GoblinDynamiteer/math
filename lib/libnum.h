#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define N 300

bool isBinary(long long int a);
bool isBinaryFloatString(char *a);
bool isBinaryString(char *a);
int countDigits(long long int a);
int convertBinaryToDecimal(long long int b);
int convertBinaryStringToDecimal(char *a);
double convertBinaryStringToDecimalFloat(char *a);
double binaryStrToDbl(char *a);