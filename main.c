#include <stdio.h>
#include "cdecl.h"

int PRE_CDECL suma_asm(int a, int b, int *resultado) POST_CDECL;

int main()
{
	int numA,numB,operacion,resultado;

	printf("Bienvenidos a la calculadora multimodulo\n");
	printf("por favor,Ingrese DOS NUMEROS:\n");
	printf("Primer Num:");
	scanf("%d",&numA);
	printf("Segundo Num:");
	scanf("%d",&numB);
	printf("Elija la operacion que desee realizar\n 1 SUMA \n 2 RESTA\n");
	printf("OPCION----");
	scanf("%d",&operacion);
	
	switch(operacion)
	{
		case 1:	
			suma_asm(numA,numB,&resultado);
			printf("%d\n",resultado);
			break;
		case 2:
		//Resultado=resta_asm();
			break;
		default:
			printf("Error operacion\n");	
			break;
	}
	return 0;
}
