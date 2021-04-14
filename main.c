#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cdecl.h"

#define BOLDRED  "\033[1;31m"
#define RESET    "\033[0m"
#define BOLDCYAN "\033[1;36m"
#define TAM_BIN_MAX 16

int PRE_CDECL suma_asm(int a,int b,int *resultado) POST_CDECL;
int PRE_CDECL resta_asm(int a,int b,int *resultado) POST_CDECL;
int binarioADecimal(char *cadenaBinaria);
int verificar_Argumento_int(char *numA,char *numB,int *numeroA,int *numeroB);
int verificar_Argument_binario(char *num);
void verificar_tam_binario(char *numA,char *numB);

int main()
{
	int numeroA,numeroB;
	int operacion,tipo_num,resultado;
	char numA[TAM_BIN_MAX],numB[TAM_BIN_MAX];

	printf(BOLDRED "Bienvenidos a la calculadora multimodulo\n\n"RESET);
	printf("Ingrese tipo de numero");	
	printf("\n 1 Numero binario\n 2 Numero decimal");
	printf(BOLDRED"\nOPCION: "RESET);
	scanf("%d",&tipo_num);
	printf("Ingrese dos numeros\n");
	printf("Numero A: ");
	scanf("%s",numA);
	printf("Numero B: ");	
	scanf("%s",numB);
	printf("Elija la operacion que desee realizar\n 1 SUMA \n 2 RESTA");
	printf(BOLDRED"\nOPCION: "RESET);
	scanf("%d",&operacion);
	
	switch(tipo_num)
	{
		case 1:
			verificar_tam_binario(numA,numB);
			if (verificar_Argument_binario(numA) == 0 && verificar_Argument_binario(numB) == 0)
			{
				numeroA=binarioADecimal(numA);						
				numeroB=binarioADecimal(numB);				
			}
			else
			{
				printf("Por favor ingrese un numero binario correctamente, por ejemplo 1000\n");
				exit(0);
			}		
							
			break;					
		case 2:			
			if (!verificar_Argumento_int(numA,numB,&numeroA,&numeroB) == 0)
			{
				printf("Por favor ingrese un numero decimal correctamente, por ejemplo 10\n");
				exit(0);
			}		
			break;
		default:
			printf("Invalido tipo de numero\n");
			break;
	}
	switch(operacion)
	{		
		case 1:				
			suma_asm(numeroA,numeroB,&resultado);
			printf(BOLDCYAN "El resultado de la suma es:%d\n",resultado);	
			break;
		case 2:
			resta_asm(numeroA,numeroB,&resultado);
			printf(BOLDCYAN "El resultado de la resta es:%d\n",resultado);	
			break;
		default:
			printf("Error operacion\n");	
			break;
	}
	return 0;
}
void verificar_tam_binario(char *numA,char *numB)
{
	if (! (strlen(numA) < TAM_BIN_MAX && strlen(numB) < TAM_BIN_MAX))
	{
		printf("Error maximo tamaño del numero binario. 16 tam maximo\n");
		exit(0);
	}

}
int verificar_Argumento_int(char *numA,char *numB,int *numeroA,int *numeroB)
{			
	if ((*numeroA=atoi(numA)) == 0 || (*numeroB=atoi(numB)) == 0)
	{
		return 1;
	}	
	return 0;
}
int verificar_Argument_binario(char *num)
{		
	for (int i=0;i<strlen(num);i++)
	{		
		if (num[i]=='1' && num[i]=='0')
			return 1; 	
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