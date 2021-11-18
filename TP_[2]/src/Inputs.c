/*
 * Inputs.c
 *
 *  Created on: 15 nov. 2021
 *      Author: pedro_000
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_TAM 4096
#define NOMBRE_TAM 50
static int myGets(char cadena[], int longitud);
static int isString(char cadena[]);
static int isInt(char cadena[]);
static int isFloat(char string[]);
/**
 * \brief Funcion para obtener un string
 * \param char cadena[]: Donde se va a guardar el string
 * \param int longitud: El tamaño del array de caracteres para no sobrepasarlo
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
static int myGets(char cadena[], int longitud)
{
	int resultado=-1;
	if(cadena != NULL && longitud >0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush(stdin);
		if(cadena[strlen(cadena)-1] == '\n' && cadena[0] != '\n')
		{
		cadena[strlen(cadena)-1] = '\0';
		}
		resultado=0;
	}
	return resultado;
}
/**
 * \brief Funcion para validar si el array de caracteres que recibe es una cadena de texto y no otra cosa
 * \param char string[]: Es el string que vamos a validar
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
static int isString(char string[])
{
	int resultado = 1;
	if(string != NULL && strlen(string) > 0)
	{
		for(int i = 0;string[i] != '\0'; i++)
		{
			if((string[i] < 'a' || string[i] > 'z') && (string[i] < 'A' || string[i] > 'Z') && string[i] != 32)
			{
				resultado = 0;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Funcion para validar si la cadena de caracteres que recibimos corresponde a un float
 * \char string[]: Es la cadena de caracteres que vamos a validar
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
static int isFloat(char string[])
{
	int resultado = 1;
	int i = 0;
	int commaCounter=0;
	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}
		for(;string[i] != '\0' ; i++)
		{
			if(string[i] == '.')
			{
				commaCounter++;
			}
			if(commaCounter>1 || ((string[i] > '9' || string[i] < '0') && string[i] != '.'))
			{
				resultado = 0;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Funcion para validar si la cadena de caracteres que recibimos corresponde a un entero
 * \char string[]: Es la cadena de caracteres que vamos a validar
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
static int isInt(char string[])
{
	int resultado = 1;
	int i = 0;
	if(string != NULL && strlen(string) > 0)
	{
		if(string[0] == '-')
		{
			i = 1;
		}
		for(;string[i] != '\0' ; i++)
		{
			if(string[i] > '9' || string[i] < '0')
			{
				resultado = 0;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Funcion para pedirle al usuario un string
 * \param char msg[]: Puntero a una cadena de texto
 * \param char msgError[]: Puntero a una cadena de texto en caso de error
 * \param char pResult[]: El string que vamos a devolver
 * \param int attemps: Reintentos que va a tener la funcion en caso de error
 * \param int limit: Es el tamaño para no sobrepasar la cadena de texto
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int utn_getString(char msg[], char msgError[], char pResult[], int attemps, int limit)
{
	int resultado = -1;
	char bufferString[ARRAY_TAM];
	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0)
	{
		do
		{
			printf("\n%s", msg);
			if(myGets(bufferString, ARRAY_TAM) == 0 && isString(bufferString) == 1 && strnlen(bufferString, sizeof(bufferString)) < limit)
			{
				resultado = 0;
				strncpy(pResult, bufferString, limit);
				break;
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return resultado;
}
/**
 * \brief Funcion para pedirle al usuario un numero entero
 * \param char msg[]: Puntero a una cadena de texto
 * \param char msgError[]: Puntero a una cadena de texto en caso de error
 * \param int *pResult: Puntero del entero que vamos a devolver
 * \param int attemps: Reintentos que va a tener la funcion en caso de error
 * \param int min: Es el minimo permitido para el numero
 * \param int max: Es el maximo permitido para el numero
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int utn_getInt(char msg[], char msgError[], int *pResult, int attemps, int min, int max)
{
	int resultado = -1;
	char bufferString[ARRAY_TAM];
	int bufferInt;
	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_TAM) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					resultado = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return resultado;
}
/**
 * \brief Funcion para pedirle al usuario un numero flotante
 * \param char msg[]: Puntero a una cadena de texto
 * \param char msgError[]: Puntero a una cadena de texto en caso de error
 * \param float *pResult: Puntero del flotante que vamos a devolver
 * \param int attemps: Reintentos que va a tener la funcion en caso de error
 * \param int min: Es el minimo permitido para el numero
 * \param int max: Es el maximo permitido para el numero
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int utn_getFloat(char msg[], char msgError[], float *pResult, int attemps, int min, int max)
{
	int resultado = -1;
	char bufferString[ARRAY_TAM];
	float bufferFloat;
	if(msg != NULL && msgError != NULL && pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("%s", msg);
			if(myGets(bufferString, ARRAY_TAM) == 0 && isFloat(bufferString) == 1)
			{
				bufferFloat = atof(bufferString);
				if(bufferFloat >= min && bufferFloat<= max)
				{
					*pResult = bufferFloat;
					resultado = 0;
					break;
				}
				else
				{
					printf("%s", msgError);
					attemps--;
				}
			}
			else
			{
				printf("%s", msgError);
				attemps--;
			}
		}while(attemps >= 0);
	}
	return resultado;
}
/**
 * \brief Funcion que me imprime el menu en el main.c
 * \param int *pResult: Puntero que hace referencia a la opcion del menu elegida
 * \param int attemps: Cantidad de reintentos
 * \param int min: Es el minimo permitido para el numero
 * \param int max: Es el maximo permitido para el numero
 * \return (-1) si algo salio mal (0) si todo esta OK
 */
int menu(int *pResult, int attemps, int min, int max)
{
	int resultado = -1;
	char bufferString[ARRAY_TAM];
	int bufferInt;
	if(pResult != NULL && attemps >= 0 && min <= max)
	{
		do
		{
			printf("\n ELIJA UNA OPCION: \n 1)DAR DE ALTA UN EMPLEADO"
					"\n 2)MODIFICAR UN EMPLEADO"
					"\n 3)DAR BAJA UN EMPLEADO"
					"\n4)INFORMAR"
					"\n5)SALIR, GRACIAS POR USAR.");
			if(myGets(bufferString, ARRAY_TAM) == 0 && isInt(bufferString) == 1)
			{
				bufferInt = atoi(bufferString);
				if(bufferInt >= min && bufferInt<= max)
				{
					*pResult = bufferInt;
					resultado = 0;
					break;
				}
				else
				{
					printf("\n ERROR. INVALIDO.");
					attemps--;
				}
			}
			else
			{
				printf("ERROR. INVALIDO.");
				attemps--;
			}
		}while(attemps >= 0);
	}
	return resultado;
}
