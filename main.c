#include <stdio.h>



int main()
{
	int numA,numB,operacion,resultado;

	printf("Bienvenidos a la calculadora multimodulo\n");
	printf("por favor,Ingrese DOS NUMEROS:\n");
	printf("Primer Num:");
	scanf("%d",&numA);
	printf("Segundo Num:");
	scanf("%d",&numB);
	printf("Elija la operacion que desee realizar\n 1 SUMA \n 2 RESTA");
	scanf("%d",&operacion);
	switch(operacion)
	{
		case 1:
	
	//resultado=suma_asm();
			break;
		case 2:
	//esultado=resta_asm();
			break;
		default:
			printf("Error operacion\n");	
			break;
	}
	return 0;
}
