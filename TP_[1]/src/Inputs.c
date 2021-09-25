/*
 * Inputs.c
 *
 *  Created on: 25 sep. 2021
 *      Author: EXO02
 */
#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

void MenuCalculadora(void){
	printf("       MENU CALCULADORA\n");
	printf("1. Ingresar 1er operando (A=x)\n");
	printf("2. Ingresar 2do operando (B=y)\n");
	printf("3. Calcular todas las operaciones\n");
	printf("a) Calcular la suma (A+B)\n");
	printf("b) Calcular la resta (A-B)\n");
	printf("c) Calcular la division (A/B)\n");
	printf("d) Calcular la multiplicacion (A*B)\n");
	printf("e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("5. Salir\n");
}

float SumarFlotantes(float numeroUno,float numeroDos, float* pResultado)
{
    float suma;

    if(pResultado != NULL){
    	*pResultado= numeroUno + numeroDos;
    }

    return suma;
}

float RestarFlotantes(float numeroUno,float numeroDos, float* pResultado)
{
    float resta;

    if(pResultado != NULL){
    	*pResultado= numeroUno - numeroDos;
    }

    return resta;

}

float MultiplicarFlotantes(float numeroUno,float numeroDos, float* pResultado)
{
    float multiplicar;

    if(pResultado != NULL){
    *pResultado= numeroUno * numeroDos;
    }

    return multiplicar;

}

float DividirFlotantes(float operador1, float operador2, float *pResultado)
{
	int dividir = -1;

	if(pResultado!= NULL && operador2!= 0)
	{
		*pResultado = operador1 / operador2;
		dividir = 0;
	}
	return dividir;
}

float FactorialFlotante(float operador,float *pResultado)
{
	int retorno = -1;
	int i;
	int factorial = 1;

	if(pResultado != NULL )
	{
		if(operador == 0)
		{
			*pResultado = 1;
			retorno = 0;
		}
		if(operador > 0)
		{
			for (i = 1;i <= operador;i++)
			{
				factorial = (float)factorial * i;
			}
			*pResultado = factorial;
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	int numero;
	int respuestaScanF;

	if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>0)
	{
		while(reintentos>0)
		{
			printf("%s",mensaje);
			fflush(stdin);
			respuestaScanF=scanf("%d",&numero);
			if((respuestaScanF==1) && numero>=minimo && numero<maximo)
			{
				*pResultado = numero;
				retorno=0;
				break;
			}
			else
			{
				printf("%s\n",mensajeError);
				reintentos--;
			}
		}
		if(reintentos==0)
			{
				printf("   Se quedo sin intentos");
				retorno=-1;
				system("\nPAUSE");
			}
	}
	return retorno;
}

int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos)
{
	int retorno = -1;
	int respuestaScan;
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	respuestaScan = scanf("%f",&bufferFloat);
	while (respuestaScan == 0 && reintentos > 0)
	{
		reintentos--;
		printf("%s",mensajeError);
		fflush(stdin);
		respuestaScan = scanf("%f",&bufferFloat);

	}
	if(respuestaScan != 0)
	{
		*pResultado = bufferFloat;
		retorno = 0;
	}

	if(reintentos==0)
	{
		printf("   Se quedo sin intentos\n");
		retorno = -1;
		system("PAUSE");
	}
	return retorno;
}
