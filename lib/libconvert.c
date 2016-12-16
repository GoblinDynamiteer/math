#include "libconvert.h"

/* V�nder p� en char-array. Anv�nds f�r konvefr�n hela decimaltal till bin�ra tal.void vand(char *str){
	//lower / upper index
	int lix, uix = strlen(str)-1;
	char temp;
	for(lix = 0; lix < uix; lix++, uix--){
		temp = str[uix];
		str[uix] = str[lix];
		str[lix] = temp;
	}
}

//Konverterar dec (int) till bin�r (char array)
char *convert_i_to_binary(int decimal){
	//Global variabel: char omvand[N];
	char *omvand = malloc(sizeof(char) * N);
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
	vand(omvand);
	return omvand;
}

//Konverterar float (double) till bin�r (char array)
char *convert_f_to_binary(double decimalfloat){
	//Global variabel: char binarfloat[N];
	char *binarfloat = malloc(sizeof(char) * N);
	//oix: omvandling index:
	int oix, counter = 0;
	binarfloat[0] = '0';
	binarfloat[1] = '.';
	oix = 2;
	for(decimalfloat=decimalfloat*2; decimalfloat != 0.0 || counter > DECIMALTECKEN; decimalfloat=decimalfloat*2){
		if(decimalfloat >= 1.0){
			decimalfloat = decimalfloat - 1.0;
			binarfloat[oix] = '1';
		}
		else{
			binarfloat[oix] = '0';
		}
		oix++;
		counter++;
		if(counter == 20){
			break;
		}
	}
	binarfloat[oix] = '\0';
	return binarfloat;
}

/* Anv�nder funktionerna convert_f_to_binary & convert_i_to_binarf�r att konvertera ett flyttal i decimalform till ett bin�rt flyttalchar *convert_to_binary(double decimal){
	char *binarD = malloc(sizeof(char) * N);
	char *binarF = malloc(sizeof(char) * N);
	int heltal = decimal;
	decimal = decimal - heltal;
	/* Om flyttal, anropas konverteringsfunktion, 
	annars s�tts str�ng till nolltecken	if(decimal > 0.00000000){
		binarF = convert_f_to_binary(decimal);
	}
	else{
		binarF[0] ='\0';
	}
	/* Om inmatat heltal �r st�rre �	annars s�tts str�ng till tecken 0	if(heltal > 0){
		binarD = convert_i_to_binary(heltal);
	}
	else{
		binarD[0] ='0';
		binarD[1] ='\0';
	}
	return strcat(binarD, binarF+1);
}