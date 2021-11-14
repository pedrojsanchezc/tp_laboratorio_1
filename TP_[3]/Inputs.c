/*
 * Inputs.c
 *
 *  Created on: 13 nov. 2021
 *      Author: pedro_000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIMIT 4905
static int myGets(char *cadena, int longitud);
static int isNumber(char* cadena, int limite);
static int isFloat(float *pResultado);
static int isFloatChar(char *cadena);
static int isInt(int *pResultado);
/**
 * \brief solicita un enetero al ususario
 * \param char* mensaje, es el mensaje  a ser mostrado
 * \param char* mensajeError,
 * \param
 * \param
 * \return (-1) error / (0) OK
 */
float utn_isFloat(char *mensaje, char *mensajeError, float *pResultado,int reintentos,float min, float max)
{
	int resultado = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && min <= max && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(isFloat(&bufferFloat)==0)
			{
				if(bufferFloat >= min && bufferFloat <= max)
				{
					*pResultado = bufferFloat;
					resultado = 0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return resultado;
}
int utn_getOrdenamiento(int array[], int len)
{
	int resultado= -1;
	int aux;
	int i;
	int flagDesordenado = 1;
	if(array!=NULL && len > 0)
	{
		while(flagDesordenado==1)
		{
			flagDesordenado = 0;
			for(i=0; i<(len-1); i++)
			{
				if(array[i] > array[i+1])
				{
					aux = array[i];
					array[i] = array[i+1];
					array[i+1]= aux;
					flagDesordenado = 1;
				}
			}
		}
	}
	resultado = 0;
	return resultado;
}
/**
 * \brief Solicita un entero al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int minimo, valor minimo admitido
 * \param int minimo, valor maximo admitido
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNumero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo)
{
	int resultado = -1;
	int bufferInt;
	if(	mensaje != NULL && 	mensajeError != NULL &&	pResultado != NULL && reintentos >= 0 && maximo >= minimo)
	{
		do
		{
			printf("%s",mensaje);
			if(isInt(&bufferInt)==0 && bufferInt >=minimo && bufferInt <=maximo)
			{
				resultado =0;
				*pResultado = bufferInt;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return resultado;
}

static int isInt(int *pResultado)
{
	int resultado=-1;
	char bufferString[5000];
	if(pResultado !=NULL && myGets(bufferString,sizeof(bufferString))==0 && isNumber(bufferString,5000))
	{
		resultado =0;
		*pResultado = atoi(bufferString);
	}
	return resultado;
}
/**
 * \brief 	Verifica una cadena recibida como parametro para determinar
 * 			si es un nombre valido
 * \param char* cadena, Cadena a analizar
 * \param int limite, indica la cantidad de letras maxima de la cadena
 * \return (0) Indicar que no es un nombre valido / (1) Indica que que es un nombre valido
 *
 */
int esUnNombreValido(char* cadena,int limite)
{
	int respuesta = 1;
	for(int i=0; i<=limite && cadena[i] != '\0';i++)
	{
		if((cadena[i] < 'A' || cadena[i] > 'Z') && (cadena[i] < 'a' || cadena[i] > 'z') && cadena[i] != '.' && cadena[i] != ' ')
		{
			respuesta = 0;
			break;
		}
	}
	return respuesta;
}
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[4905];
	int resultado = -1;
	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite > 0)
	{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,4905) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite &&
				esUnNombreValido(bufferString,limite) != 0 )
			{
				resultado = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return resultado;

}
/**
 * \brief Solicita un nombre al usuario
 * \param char* mensaje, Es el mensaje a ser mostrado al usuario
 * \param char* mensaje, Es el mensaje de error a ser mostrado al usuario
 * \param int* pResultado, puntero al espacio de memoria donde se dejara el valor obtenido
 * \param int reintentos, cantidad de oportunidades para ingresar el dato
 * \param int limite, indica la cantidad de letras maxima del nombre
 * \return (-1) Error / (0) Ok
 *
 */
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite)
{
	char bufferString[LIMIT];
	int resultado = -1;
		if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && limite > 0)
		{
		do
		{
			printf("%s",mensaje);
			if( myGets(bufferString,LIMIT) == 0 &&
				strnlen(bufferString,sizeof(bufferString)-1)<= limite)
			{
				resultado = 0;
				strncpy(pResultado,bufferString,limite);
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return resultado;

}
static int myGets(char *cadena, int longitud)
{
	fflush(stdin);
	fgets (cadena, longitud, stdin);
	cadena[strlen (cadena) - 1] = '\0';
	return 0;
}
static int isNumber(char* cadena, int limite)
{
	int resultado = 1; // VERDADERO
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			resultado = 0;
			break;
		}
	}
	return resultado;
}
static int isFloat(float *pResultado)
{
	int resultado = -1;
	char buffer[460];

	if(pResultado != NULL)
	{
	  if(myGets(buffer,sizeof(buffer))==0 && isFloatChar(buffer)==1)
	  {
		  *pResultado= atof(buffer);
		   resultado = 0;
	  }
	}
	return resultado;
}
static int isFloatChar(char *cadena)
{
	int resultado = 1;
	int contadorPuntos= 0;
	if(cadena != NULL && strlen(cadena)> 0)
	{
		for(int i=0; cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
			    continue;
			}
	    	if(cadena[i]<  '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos ==0)
				{
					contadorPuntos++;
				}
				else
				{
					resultado=0;
					break;
				}
			 }
		  }
	}
  return resultado;
}
