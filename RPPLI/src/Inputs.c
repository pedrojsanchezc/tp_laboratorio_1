/*
 * Inputs.c
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */

#include "Inputs.h"

int getNumber(char* message){
	char auxiliar[256];
	int integer;
	printf("%s",message);
	scanf("%s",auxiliar);
	while(isalpha(*auxiliar)){
		printf("Error. Eso no es un numero. Ingrese un numero: ");
		scanf("%s",auxiliar);
	}
	integer = atoi(auxiliar);
	return integer;
}

float getFloatMessage(char* message)
{
    float auxiliar;
    printf("%s",message);
    scanf("%f",&auxiliar);
    return auxiliar;
}

int getInt(char* message)
{
    char aux[256];
    int integer;

    printf("%s", message);
    fflush(stdin);
    scanf("%s",aux);

    while(!isInt(aux))
    {
        printf("\nError! Eso no es un numero. Ingrese un numero: ");
        fflush(stdin);
        scanf("%s",aux);
        printf("\n");
    }
    if(isInt(aux) == 1)
    {
        integer = atoi(aux);
    }
    return integer;
 }

int isInt(char* string)
{
    int i;
    int returnValue = 1;

    for(i=0; string[i] != '\0'; i++)
    {
        if(string[i] < '0' || string[i] > '9')
        {
            returnValue = 0;
            return returnValue;
        }
    }
    return returnValue;
}

int getCharString(char* message, char* errorMessage, char* input)
{
    char aux[51];
    int returnValue = 0;
    printf(message);
    fflush(stdin);
    fgets(aux,sizeof(aux),stdin);
    while(charactersOnly(aux) == 0)
    {
        printf(errorMessage);
        fflush(stdin);
        fgets(aux,sizeof(aux),stdin);
    }
    if(charactersOnly(aux) == 1)
    {
        returnValue = 1;
        strcpy(input,aux);
        return returnValue;
    }
    return returnValue;
}

int charactersOnly(char* string)
{
    int i;
    int ifIsAlpha;
    int sz;

    sz = strlen(string)-1;

    for(i=0; i< sz; i++)
    {
        if((!(isalpha(string[i]) == 0)) || string[i] == ' ')
        {
            ifIsAlpha = 1;
        }
        else
        {
            ifIsAlpha = 0;
            break;
        }
    }
    return ifIsAlpha;
}

int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable)
{
    int input;
    int flagConfirmation = 0;
    int returnValue = 0;

    fflush(stdin);
    if(!scanf(floatMask, variable))
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Invalido.\n\nVuelva a intentarlo: ");
            fflush(stdin);
            if(scanf(floatMask, variable))
            {
                fflush(stdin);
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        fflush(stdin);
        return returnValue;
    }
    if(getchar() != '\n')
    {
        while(flagConfirmation == 0)
        {
            while((input = getchar()) != '\n' && input != EOF);
            printf("\nIngreso Invalido.\n\nVuelva a intentarlo: ");
            if(scanf(floatMask, variable))
            {
                flagConfirmation = 1;
                returnValue = 1;
            }
        }
        return returnValue;
    }
    return returnValue;
}

void getStr(char* message, int size, char* output){
    printf("%s", message);
    fflush(stdin);
    fgets(output, size, stdin);
}

int getLetterStr(char* message,int size, char* output){
    char aux[256];
    getStr(message, size, aux);
    if(onlyLetters(aux))
    {
        strcpy(output,aux);
        return 1;
    }
    return 0;
}

int onlyLetters(char* str){
    int i=0;

    for(i=0; str[i] != '\0'; i++)
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        {
            return 0;
        }
    }
    return 1;
}

void fstLettUppercase(char* array){
    int i;
    strlwr(array);
    for(i = 0; i < strlen(array); i++)
    {
        if(i == 0 || (array[i-1] == ' ' && array[i] >= 'a' && array[i] <= 'z'))
        {
        	array[i] = toupper(array[i]);
        }
    }
}

char removeLineBreak(char* array){
    int i;
    for(i=0;array[i] != '\0';i++)
    {
        if(array[i] == '\n')
        {
        	array[i] = '\0';
        }
    }
    return array[i];
}

char *strlwr(char *str){
  unsigned char *p = (unsigned char *)str;
  while (*p) {
     *p = tolower((unsigned char)*p);
      p++;
  }
  return str;
}

int chooseIndex(void){
	int index;
	index = getInt("\nIngrese el numero de índice donde guardarlo: ");
	return index;
}

void loadList(int* numbersList, int size){
	int userInput;
	int i;

	for(i=0; i<size; i++)
	 {
		userInput = getNumber("\nIngrese un numero: ");
		/*while(userInput < -1000 || userInput > 1000){
			printf("\nError. Numero fuera de rango.");
			userInput = getInt("\n\nIngrese un numero entre -1000 y 1000: ");
		}*/
		numbersList[i] = userInput;
		}
	 }

void positiveNumAscSorting(int* array, int size){
	int i,j, aux;
	for(i=0;i<size;i++){
		for(j=i+1; j<size; j++){
			if(array[i]>=0){
				if(array[i] > array[j]){
					aux = array[i];
					array[i] = array[i+1];
					array[i+1] = aux;
				}
			}
		}
	}
}

void negativeNumDescSorting(int* array, int size){
    int i,j, aux;
    for(i=0;i<size;i++){
    	for(j=i+1; j<size; j++){
    		if(array[i]>=0){
				if(array[i] < array[j]){
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;
				}
    		}
    	}
    }
}

void printList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
        printf("\nIndice %d: %d",i, array[i]);
    }
}

void printPositiveList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
    	if(array[i] >= 0){
			printf("\nIndice %d: %d",i, array[i]);
		}
    }
}

void printNegativeList(int* array,int size){
    int i;
    for(i=0; i<size; i++)
    {
        if(array[i] < 0){
        	printf("\nIndice %d: %d",i, array[i]);
        }
    }
}


void printPairNumList(int* array, int size){
	int i;
	for(i=0; i<size; i++){
		if(array[i]%2 == 0){
			printf("\nIndice %d: %d", i, array[i]);
		}
	}
}

void printOddNumList(int* array, int size){
	int i;
	for(i=0; i<size; i++){
		if(array[i]%2 != 0){
			printf("\nIndice %d: %d", i, array[i]);
		}
	}
}

int myGets(char* pString, int limite)
{
	int retorno = -1;
	char bufferString[4096];

	if(pString != NULL && limite > 0 && fgets(bufferString, sizeof(bufferString), stdin) != NULL)
	{
		fflush(stdin);
		if(bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] == '\n')
		{
			bufferString[strnlen(bufferString,sizeof(bufferString)) - 1] = '\0';
		}

		if(strnlen(bufferString,sizeof(bufferString)) <= limite)
		{
			strncpy(pString,bufferString,limite);
			retorno = 0;
		}
	}
	return retorno;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  NUMEROS  //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[60];

	if( pResultado != NULL &&
		!myGets(bufferString, sizeof(bufferString)) && 	//myGets(bufferString, sizeof(bufferString)) == 0
		utn_esNumerica(bufferString, sizeof(bufferString)))
	{
		*pResultado = atoi(bufferString);
		retorno = 0;
	}
	return retorno;
}

int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferFloat[60];

	if(pResultado != NULL &&
	   !myGets(bufferFloat, sizeof(bufferFloat)) &&
	   utn_esFloat(bufferFloat,sizeof(bufferFloat)))
	{
		*pResultado = atof(bufferFloat);
		retorno = 0;
	}

	return retorno;
}

/*
int utn_esNumerica(char* cadena, int len)
{
	int retorno = -1;
	int i = 0;

	if(cadena != NULL && len > 0)
	{
		retorno = 0;

		if(cadena[0] == '-' || cadena[0] == '+')
		{
			i = 1;
		}

		for( ; i < len && cadena[i] != '\0'; i++)
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
				retorno = 1;
			}
			else if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
*/


 int utn_esNumerica(char* cadena, int len)
 {
	int retorno = -1;
	int i;

	if(cadena != NULL && len > 0){
		retorno = 1;
		for(i = 0; i < len && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/*
int utn_esFloat(char* cadena, int len)
{
	int retorno = -1;
	int cantidadPuntos = 1;
	int cantidadSignos = 1;
	int i = 0;

	if(cadena != NULL && len > 0)
	{
		retorno = 0;
		for( ; i < len && cadena[i] != '\0'; i++)
		{
			if(cadena[i] >= '0' && cadena[i] <= '9')
			{
				if(i == 0 && cadena[i] == '-' && cantidadSignos)
				{
				  cantidadSignos = 0;
				}

				if(cadena[i] == '.' && cantidadPuntos)
				{
				  cantidadPuntos = 0;
				}

				retorno = 1;
			}
		}
	}

  return retorno;
}
*/


int utn_esFloat(char* cadena, int len)
{
	int retorno = -1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL && len > 0){
		retorno = 1;
		for(i = 0; i < len && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}



int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do{
			printf("%s", pMensaje);
			if(utn_getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);

		if(reintentos == 0)
		{
			printf(NO_REINTENTOS);
		}
	}

	return retorno;
}

int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo)
	{
		while(reintentos)
		{
			printf("%s", pMensaje);
			fflush(stdin);

			if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}

		if(reintentos == 0)
		{
			printf(NO_REINTENTOS);
		}
	}

  return retorno;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  CALCULOS  ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int utn_getSuma(float operandoA, float operandoB, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA + operandoB;
		retorno=0;
	}

	return retorno;
}


int utn_getResta(float operandoA, float operandoB, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA - operandoB;
		retorno = 0;
	}

	return retorno;
}

int utn_getMultiplicacion(float operandoA, float operandoB, float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL){
		*pResultado = operandoA * operandoB;
		retorno = 0;
	}

	return retorno;
}

int utn_getDivision(float operandoA, float operandoB, float* pResultado, char* pMensajeError)
{
	int retorno;

	if(pResultado != NULL && pMensajeError != NULL && operandoB != 0)
	{
		*pResultado = operandoA / operandoB;
		retorno = 0;
	}else{
		printf("%s", pMensajeError);
		retorno = -1;
	}

	return retorno;
}

int utn_getFactorial(double operandoA, double* pResultadoA){
	int retorno = -1;
	int i;
	double acumuladorFactorialA=1;

	if(operandoA >= 0 && pResultadoA != NULL){
		for(i = 1; i <= operandoA; i++)
		{
			acumuladorFactorialA*=i;
		}
		*pResultadoA = acumuladorFactorialA;
		retorno = 0;
	}

	return retorno;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  STRING  //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_getString(char* pResultado, char* pMensaje, char* pMensajeError, int len, int reintentos)
{
	int retorno = -1;
	char bufferString[len];

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && len > 0 && reintentos > 0)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			if(myGets(bufferString, len) == 0 && utn_isString(bufferString) == 1)
			{
				retorno = 0;
				strncpy(pResultado, bufferString, len);
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}while(reintentos);
	}
	return retorno;
}

int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char buffer[limite];

	if(pNombre != NULL && pMensaje != NULL && pMensajeError != NULL && limite > 0 && reintentos > 0)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);

			if(myGets(buffer, sizeof(buffer)) == 0 && validarNombre(buffer, sizeof(buffer)) == 1)
			{
				strncpy(pNombre, buffer, limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
				reintentos--;
			}
		}while(reintentos);
	}
	return retorno;
}

int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos)
{
    int retorno = -1;
    char letra[2];

    do{
        printf("%s", pMensaje);
        if(!myGets(letra, 1) && esLetra(letra) == 0)
        {
            *pResultado = *letra;
            retorno = 0;
            break;
        }
        printf("%s",pMensajeError);
        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}


int esLetra(char* letra){
    int retorno=-1;

    if(letra != NULL)
    {
    	if((*letra >= 'a' && *letra <= 'z') || (*letra >= 'A' && *letra <= 'Z'))
		{
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getCadenaEnMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[4000];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(bufferString, sizeof(bufferString)) == 0 && getMayusculas(bufferString, sizeof(bufferString)) == 0)
		{
			strncpy(pString, bufferString, limite);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getCadenaEnMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[4000];

	if(pString != NULL && limite > 0 && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);
		if(myGets(bufferString, sizeof(bufferString)) == 0 && getMinusculas(bufferString, sizeof(bufferString)) == 0)
		{
			strncpy(pString, bufferString, limite);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  OTRAS VALIDACIONES  ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[LEN_DNI];

	if(pDni != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(bufferString, sizeof(bufferString)) == 0 &&
		   validarDni(bufferString, sizeof(bufferString)) == 1)
		{
		  strncpy(pDni, bufferString, LEN_DNI);
		  retorno = 0;
		}
		else
		{
		  printf("%s", pMensajeError);
		}
	}

  return retorno;
}

int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char bufferString[limite];

	if(pCuit != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);

			if(myGets(bufferString, sizeof(bufferString)) == 0 &&
			validarCuit(bufferString, sizeof(bufferString)) == 1)
			{
				strncpy(pCuit, bufferString, limite);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
			}
		}while(reintentos);
	  }

	return retorno;
}

int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	int bufferInt;

	if(pEdad != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(utn_getInt(&bufferInt) == 0 && validarEdad(&bufferInt))
		{
			*pEdad = bufferInt;
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	float buffer;

	if(pPrecio != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(getFloat(&buffer) == 0 && validarPrecio(&buffer) == 1)
		{
			*pPrecio = buffer;
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char buffer[LEN_TELEFONO];

	if(pTelefono != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(buffer, sizeof(buffer)) == 0 &&
		   validarTelefono(buffer, sizeof(buffer)) == 1)
		{
			strncpy(pTelefono, buffer, LEN_TELEFONO);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char buffer[LEN_CELULAR];

	if(pCelular != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(buffer, sizeof(buffer)) == 0 && validarCelular(buffer, sizeof(buffer)) == 1)
		{
			strncpy(pCelular, buffer, LEN_CELULAR);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[LEN_EMAIL];

	if(pEmail != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(bufferString, sizeof(bufferString)) == 0 &&
		   validarEmail(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pEmail, bufferString, LEN_EMAIL);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}


int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError)
{
	int retorno = -1;
	char bufferString[LEN_TARJETA_CREDITO];

	if(pTarjeta != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);

		if(myGets(bufferString, sizeof(bufferString)) == 0 &&
		   validarTarjetaCredito(bufferString, sizeof(bufferString)) == 1)
		{
			strncpy(pTarjeta, bufferString, LEN_TARJETA_CREDITO);
			retorno = 0;
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura)
{
	int retorno = -1;
	char bufferDireccion[LEN_DIRECCION];
	char bufferDireccionAltura[LEN_DIRECCION_ALTURA];

	if(pDireccion != NULL && pMensaje != NULL && pMensajeError != NULL)
	{
		printf("%s", pMensaje);
		fflush(stdin);
		if(myGets(bufferDireccion, sizeof(bufferDireccion)) == 0 &&
		   validarDireccion(bufferDireccion, sizeof(bufferDireccion)) == 1)
		{
			printf("%s", pMensajeAltura);
			fflush(stdin);

			if(myGets(bufferDireccionAltura, sizeof(bufferDireccionAltura)) == 0 &&
			   validarDireccionAltura(bufferDireccionAltura, sizeof(bufferDireccionAltura)) == 1)
			{
				strcat(bufferDireccion, " ");
				strcat(bufferDireccion, bufferDireccionAltura);
				strncpy(pDireccion, bufferDireccion, LEN_DIRECCION);
				retorno = 0;
			}
			else
			{
				printf("%s", pMensajeErrorAltura);
			}
		}
		else
		{
			printf("%s", pMensajeError);
		}
	}

	return retorno;
}

int getMayusculas(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			cadena[i] = toupper(cadena[i]);
		}
		retorno = 0;
	}

	return retorno;
}

int getMinusculas(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; i < limite; i++)
		{
			cadena[i] = tolower(cadena[i]);
		}
		retorno = 0;
	}

	return retorno;
}

int validarDecimal(char* cadena, int limite)
{
	int retorno = -1;
	int cantidadPunto = 0;

	if(cadena != NULL && limite > 0)
	{
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(i == 0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}

			if(cantidadPunto == 0 && cadena[i] == '.')
			{
				cantidadPunto = 1;
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9' || (cantidadPunto == 1 && cadena[i] == '.'))
			{
				retorno = 0;
				break;
			}
		}
		retorno = 1;
	}

	return retorno;
}

int validarNombre(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if ((cadena[i] != ' ') && ((cadena[i] < 'A' || cadena[i] > 'z') || (cadena[i] < 'a' && cadena[i] > 'Z')) )
			{
				retorno = 0;
				break;
			}
			else
			{
				if((i == 0 || cadena[i - 1] == ' '))
				{
					if(cadena[i] >= 'A' && cadena[i] <= 'Z')
					{
						continue;
					}
					else if (cadena[i] >= 'a' && cadena[i] <= 'z')
					{
						cadena[i]=toupper(cadena[i]);
					}
				}
				else if((i != 0 || cadena[i - 1] != ' '))
				{
					if((cadena[i] >= 'a' && cadena[i] <= 'z') && cadena[i-1] != ' ')
					{
						continue;
					}
					else if(cadena[i] >= 'A' && cadena[i] <= 'Z')
					{
						cadena[i]=tolower(cadena[i]);
					}
				}
			}
		}
	}
	return retorno;
}

int validarDni(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}

		if(strlen(cadena) != 8)
		{
		retorno = 0;
		}
	}

	return retorno;
}

int validarCuit(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}

		if(strlen(cadena) != 11)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int validarEdad(int* pNumero)
{
	int retorno = -1;

	if(pNumero != NULL)
	{
		retorno = 1;
		if(*pNumero < 1 || *pNumero > 122)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int validarPrecio(float* pResultado)
{
	int retorno = -1;

	if(pResultado != NULL)
	{
		retorno = 1;
		if(*pResultado <= 0)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int validarTelefono(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[4] == '-')
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(cadena[4] == '-' && strlen(cadena) == 9)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 8)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int validarCelular(char* cadena, int limite)
{
	int retorno = -1;
	int cantidadSigno = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[2] == '-')
			{
				cantidadSigno = 1;
				continue;
			}

			if(cantidadSigno && cadena[7] == '-')
			{
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}
		if(cadena[2] == '-' && cadena[7] == '-' && strlen(cadena) == 12)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 10)
		{
			retorno = 0;
		}
	}

	return retorno;
}


int validarEmail(char* cadena, int limite)
{
	int retorno = -1;
	int i;
	int arroba = 0;
	int punto = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z') || (cadena[i] >= '0' && cadena[i] <= '9'))
			{
				retorno = 1;
			}
			else if(i > 0 && arroba == 0 && cadena[i] == '@')
			{
				arroba = 1;
				punto = 0;
			}
			else if(i > 0 && i < strlen(cadena) - 1 && cadena[i] == '.' &&
					cadena[i - 1] != '.' && cadena[i - 1] != '@' &&
					cadena[i - 1] != '-' && cadena[i - 1] != '_')
			{
				punto = 1;
				retorno = 1;
			}
			else if((cadena[i] == '-' && cadena[i - 1] != '-' && cadena[i - 1] != '_' && cadena[i - 1] != '.') || (cadena[i] == '_' && cadena[i - 1] != '_' && cadena[i - 1] != '-' && cadena[i - 1] != '.'))
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
				break;
			}
		}

		if(arroba == 0 || punto == 0 || cadena[i - 1] == '.')
		{
			retorno = 0;
		}
	}

	return retorno;
}


int validarTarjetaCredito(char* cadena, int limite)
{
	int retorno = -1;
	int signo = 0;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[4] == '-')
			{
				signo = 1;
				continue;
			}

			if(signo && cadena[9] == '-')
			{
				signo = 2;
				continue;
			}

			if(signo == 2 && cadena[14] == '-')
			{
				signo = 3;
				continue;
			}

			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}

		if(cadena[4] == '-' && cadena[9] == '-' && cadena[14] && strlen(cadena) == 19)
		{
			retorno = 1;
		}
		else if(strlen(cadena) != 16)
		{
			retorno = 0;
		}
	}

  return retorno;
}

int validarDireccion(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;
		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if((i == 0 || cadena[i - 1] == ' ') && cadena[i] >= 'A' && cadena[i] <= 'Z')
			{
				continue;
			}
			else if((cadena[i] >= 'a' && cadena[i] <= 'z') || cadena[i] == ' ')
			{
				continue;
			}
			else
			{
				retorno = 0;
				break;
			}
		}
	}

  return retorno;
}

int validarDireccionAltura(char* cadena, int limite)
{
	int retorno = -1;

	if(cadena != NULL && limite > 0)
	{
		retorno = 1;

		for(int i = 0; i < limite && cadena[i] != '\0'; i++)
		{
			if(cadena[i] < '0' || cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
		}

		if(strlen(cadena) < 1 || strlen(cadena) > 4)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int utn_getContinuar(char* pRespuesta, char* pMensaje, char* pMensajeError, int reintentos)
{
    int retorno = -1;
    char letra[2];

    do{
		 printf("%s [Y/N]", pMensaje);
		 //fflush(stdin);//va?

		if((!myGets(letra, 1) && esLetra(letra) == 0) &&
			(!strncmp(letra,"y",1) || !strncmp(letra,"Y",1) || !strncmp(letra,"n",1) || !strncmp(letra,"N",1)))
		{
			*pRespuesta = *letra;
			retorno = 0;
			break;
		}

		printf("%s",  pMensajeError);
        reintentos--;
    }while(reintentos >= 0);

    return retorno;
}

int utn_isIntSinSigno(char* cadena)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; i < sizeof(cadena) && cadena[i] != '\0'; i++)
		{
            if(cadena[i] >= '0' && cadena[i] <= '9')
            {
              retorno = 1;
            }
            else if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
	return retorno;
}



int utn_isAlfanumerico(char *cadena)
{
	int output = 1;

	if(cadena !=NULL){
		for(int i = 0; cadena[i] !='\0'; i++)
		{
			if( ((cadena[i] < '0' || cadena[i] > 'z') || (cadena[i] > '9' && cadena[i] < 'A') || (cadena[i] > 'Z' && cadena[i] < 'a')) && (cadena[i] != '_' && cadena[i] != '.') && cadena[i] == ' ')
			{
				output = -1;
				break;
			}
		}
	}
	return output;
}


int utn_isNumerico(char *cadena){
    int retorno = 1;

    if(cadena !=NULL){
        for(int i = 0; cadena[i] !='\0'; i++)
        {
            if(cadena[i] < '0' || cadena[i] > '9')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int utn_getAlfanumerico(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;

    if (pMensaje != NULL && pMensajeError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", pMensaje);
            fflush(stdin);//va?

            if ((myGets(pCadena, limite) == 0) && utn_isAlfanumerico(pCadena) == 1)
            {
                for(int i = 0; i < limite; i++)
                {
                    if(esLetra(pCadena) == 0)
                    {
                    	pCadena[i] = tolower(pCadena[i]);
                    }
                }
                retorno = 0;
                break;
            }
            else
            {
                reintentos--;
                printf("%s", pMensajeError);
            }
        } while(reintentos > 0);

        if (reintentos == 0)
		{
			printf(NO_REINTENTOS);
		}
    }
    return retorno;
}


int utn_getStringSoloNumeros(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos)
{
    int retorno = -1;

    if (pMensaje != NULL && pMensajeError != NULL && pCadena != NULL && limite > 0 && reintentos > 0)
    {
        do
        {
            printf("%s", pMensaje);
            fflush(stdin);//va?

            if (!(myGets(pCadena, limite)) && utn_isNumerico(pCadena))
            {
                for(int i = 0; i < limite; i++)
                {
                    pCadena[i] = toupper(pCadena[i]);
                }
                retorno = 0;
            }
            else
            {
            	 reintentos--;
            	 printf("%s", pMensajeError);

            }
        } while(retorno != 0 && reintentos > 0);

        if (reintentos == 0)
		{
			printf(NO_REINTENTOS);
		}
    }
    return retorno;
}


int utn_isString(char* cadena)
{
	int retorno = -1;

	if(cadena != NULL)
	{
		for(int i = 0; (cadena[i] != '\0'); i++)
		{
			if((cadena[i] == ',') ||((cadena[i] != ' ') && (cadena[i] < '!' || cadena[i] > '~')))
			{
				retorno = 0;
			}
			else
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

