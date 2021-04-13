#include <stdio.h>
#include "cdecl.h"

#define BOLDRED  "\033[1;31m"
#define RESET    "\033[0m"
#define BOLDCYAN "\033[1;36m"

int PRE_CDECL suma_asm(int a,int b,int *resultado) POST_CDECL;
int PRE_CDECL resta_asm(int a,int b,int *resultado) POST_CDECL;

int main()
{
	int numA,numB,operacion,resultado;

	printf(BOLDRED "Bienvenidos a la calculadora multimodulo\n");
	printf("por favor,Ingrese DOS NUMEROS:\n");
	printf("Primer Num:");
	scanf("%d",&numA);
	printf("Segundo Num:");
	scanf("%d",&numB);
	printf("Elija la operacion que desee realizar\n 1 SUMA \n 2 RESTA\n");
	printf("OPCION----"RESET);
	scanf("%d",&operacion);
	
	switch(operacion)
	{
		case 1:
				
			suma_asm(numA,numB,&resultado);
			printf(BOLDCYAN "El resultado de la suma es:%d\n",resultado);	
			break;
		case 2:
			resta_asm(numA,numB,&resultado);
			printf(BOLDCYAN "El resultado de la resta es:%d\n",resultado);	
			break;
		default:
			printf("Error operacion\n");	
			break;
	}
	return 0;
}
