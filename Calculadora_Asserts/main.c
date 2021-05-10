#include <stdio.h>
#include <stdlib.h>
#include "cdecl.h"
#include <getopt.h>
#include <string.h>

#define BOLDRED  "\033[1;31m"
#define RESET    "\033[0m"
#define BOLDCYAN "\033[1;36m"

int PRE_CDECL suma_asm(int a,int b,int *resultado) POST_CDECL;
int PRE_CDECL resta_asm(int a,int b,int *resultado) POST_CDECL;
int binarioADecimal(char *cadenaBinaria);

int main(int argc,char *argv[])
{
	int numA,numB,operacion,resultado;
	char * pEnd1;
   	char * pEnd2; //valores aux para convertir los chr en int
   	long int var1,var2;
	
 	if(*argv[1]=='d'){ //son numeros decimales
		numA=strtol(argv[2],&pEnd1,10);//num 1
                numB=strtol(argv[4],&pEnd2,10);//num 2
			if(*argv[3]=='+')
				suma_asm(numA,numB,&resultado);
			if(*argv[3]=='-')
				resta_asm(numA,numB,&resultado);
	printf("%d",resultado);}

	if(*argv[1]=='b'){//son numeros binarios, debo convertir
		numA=binarioADecimal(argv[2]);
		numB=binarioADecimal(argv[4]);
			if(*argv[3]=='+')
				suma_asm(numA,numB,&resultado);
			if(*argv[3]=='-')
				resta_asm(numA,numB,&resultado);
		printf("%d",resultado);	
	}
		
	return 0;
}

int binarioADecimal(char *cadenaBinaria)
{	
	int decimal = 0;
	int multiplicador = 1;
	char caracterActual;
	for (int i = strlen(cadenaBinaria) - 1; i >= 0; i--)
	{
		caracterActual = cadenaBinaria[i];
		if (caracterActual == '1')
		{
			decimal += multiplicador;
		}
	    multiplicador = multiplicador * 2;
	}
	return decimal;
}



