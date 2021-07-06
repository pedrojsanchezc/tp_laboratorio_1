#include "Inputs.h"
//*** VALIDACIONES - INICIO
int Validate_OnlyNumberInt(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isdigit(pData[i]) == 0) {
				if (i == 0) {
					if (pData[0] != '-') {
						rtn = 0;
						break;
					}
				} else {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyNumberFloat(char *pData) {
	int countSigno = 0;
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {

			if (pData[i] == '.' || pData[i] == ',') {
				countSigno++;
			} else {
				if (isdigit(pData[i]) == 0) {
					if (i == 0) {
						if (pData[0] != '-') {
							rtn = 0;
							break;
						}
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}

		if (countSigno > 1) {
			rtn = 0;
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabet(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				rtn = 0;
				break;
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_OnlyAlphabetWithSpaces(char *pData) {
	int rtn = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					rtn = 0;
					break;
				}
			}
		}
	} else {
		rtn = 0;
	}

	return rtn;
}

int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ) {
	int rtn = 0;
	char c;

	c = Get_Char(MSJ, ERROR_MSJ);
	c = toupper(c);

	while (c != 'S' && c != 'N') {
		puts("ERROR. OPCION NO VALIDA");
		c = Get_Char(MSJ, ERROR_MSJ);
		c = toupper(c);
	}

	if (c == 'S') {
		rtn = 1;
	}

	return rtn;
}
//*** VALIDACIONES - FIN

//*** GET - INICIO
int Get_Int(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	int rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberInt(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);

	return rtn;
}

int Get_IntPositive(char *MSJ,char *ERROR_MSJ){
	char buffer[TAM_BUFFER];
	int rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberInt(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atoi(buffer);

	return rtn;
}

int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX) {
	int rtn = Get_Int(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%d [MAX]=%d.\n", MIN, MAX);
		rtn = Get_Int(MSJ, ERROR_MSJ);
	}

	return rtn;
}

float Get_Float(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	float rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberFloat(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atof(buffer);

	return rtn;
}

float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX) {
	float rtn = Get_Float(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}

	return rtn;
}

double Get_Double(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	double rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (Validate_OnlyNumberFloat(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = atof(buffer);

	return rtn;
}

double Get_DoubleRange(char *MSJ, char *ERROR_MSJ, double MIN, double MAX) {
	double rtn = Get_Float(MSJ, ERROR_MSJ);

	while (rtn < MIN || rtn > MAX) {
		printf("ERROR. Fuera de rango -> [MIN]=%.2f [MAX]=%.2f.\n", MIN, MAX);
		rtn = Get_Float(MSJ, ERROR_MSJ);
	}

	return rtn;
}

char Get_Char(char *MSJ, char *ERROR_MSJ) {
	char buffer[TAM_BUFFER];
	char rtn;

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > 1 || Validate_OnlyAlphabet(buffer) == 0) {
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	rtn = buffer[0];

	return rtn;
}

void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0) {
		printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n", TAM);
		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| Validate_OnlyAlphabet(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}

void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString,
		int TAM) {
	char buffer[TAM_BUFFER];

	printf("%s", MSJ);
	fflush(stdin);
	gets(buffer);

	while (strlen(buffer) > TAM || strlen(buffer) == 0
			|| Validate_OnlyAlphabetWithSpaces(buffer) == 0) {

		if (strlen(buffer) > TAM || strlen(buffer) == 0) {
			printf("ERROR. Fuera de rango -> CARACTERES [MIN]=1 [MAX]=%d.\n",
					TAM);
		} else {
			printf("ERROR. Solo caracteres alfabeticos validos.\n");
		}

		printf("%s", ERROR_MSJ);
		fflush(stdin);
		gets(buffer);
	}

	strcpy(pString, buffer);
}
//*** GET - FIN

//*** UTILIDADES - INICIO
void ArrayPrint_Int(int *pArray, int TAM) {
	for (int i = 0; i < TAM; i++) {
		printf("%d\n", pArray[i]);
	}
}

void ArrayPrint_Float(float *pArray, int TAM) {
	for (int i = 0; i < TAM; i++) {
		printf("%.2f\n", pArray[i]);
	}
}

int ArraySort_Int(int *pArray, int TAM, int criterio) {
	int rtn = 0;
	int aux;

	if (pArray != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					if (pArray[i] > pArray[j]) {
						aux = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = aux;
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					if (pArray[i] < pArray[j]) {
						aux = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = aux;
					}
				}
			}
			rtn = 1;
			break;
		default:
			//Criterio de ordenamiento mal ingresado.
			rtn = 0;
			break;
		}
	}

	return rtn;
}
int ArraySort_Float(float *pArray, int TAM, int criterio) {
	int rtn = 0;
	float aux;

	if (pArray != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					if (pArray[i] > pArray[j]) {
						aux = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = aux;
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (int i = 0; i < TAM - 1; i++) {
				for (int j = i + 1; j < TAM; j++) {
					if (pArray[i] < pArray[j]) {
						aux = pArray[i];
						pArray[i] = pArray[j];
						pArray[j] = aux;
					}
				}
			}
			rtn = 1;
			break;
		default:
			//Criterio de ordenamiento mal ingresado.
			rtn = 0;
			break;
		}
	}

	return rtn;
}

void Format_NameLastname(char *pName, char *pLastname, char *pFormatName) {

	strcpy(pFormatName, pName);
	strcat(pFormatName, ", ");
	strcat(pFormatName, pLastname);

	strlwr(pFormatName);

	if (strlen(pName) > 0 && strlen(pLastname) > 0) {
		for (int i = 0; i < strlen(pFormatName); i++) {
			if (i == 0 && isspace(pFormatName[i]) == 0) {
				pFormatName[0] = toupper(pFormatName[0]);
			} else {
				if (isspace(pFormatName[i]) && i < strlen(pFormatName) - 1) {
					pFormatName[i + 1] = toupper(pFormatName[i + 1]);
				}
			}
		}
	}
}

void pedirNombre(char* nombre, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar=TAM;

    printf("INGRESE NOMBRE: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE NOMBRE: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (nombre, buffer);//DESCARGO EL BUFFER EN EL NOMBRE
}

void pedirApellido(char* apellido, int TAM)
{
    char buffer[1000];
    int maximosCharParaVerificar=TAM;

    printf("INGRESE APELLIDO: ");
    fflush(stdin);
    gets(buffer);

    while(strlen(buffer)>maximosCharParaVerificar||strlen(buffer)<1)
    {
        system("cls");
        printf("\n[ERROR 1 a %d CARACTERES MAX] REINGRESE APELLIDO: ", maximosCharParaVerificar-1);
        fflush(stdin);
        gets(buffer);

    }
    strlwr(buffer);//PASO TODO A MINUSCULA
    buffer[0]=toupper(buffer[0]); //CONVIERTO PRIMER CARACTER EN MAYUSCULA
    strcpy (apellido, buffer);//COMO SALI DESCARGO EL BUFFER EN EL NOMBRE

}
//*** UTILIDADES - FIN

int PedirEntero(char mensajeInicial[], char mensajeError[])
{
	char entero[50];
	int estado;
	int idInt;


	printf("%s \n",mensajeInicial);
	fflush(stdin);
	scanf("%s",entero);
	estado = ValidarEntero(entero);

	while (estado == -1)
	{
		printf("%s. %s \n",mensajeError, mensajeInicial);
		fflush(stdin);
		scanf("%s",entero);
		estado = ValidarEntero(entero);
	}

	idInt = atoi(entero);


	return idInt;
}

float PedirFlotante(char mensajeInicial[], char mensajeError[])
{
	char flotante[50];
	int estado;
	int idFloat;

	do
	{
		printf("%s \n",mensajeInicial);
		fflush(stdin);
		scanf("%s",flotante);
		estado = ValidarFlotante(flotante);

		if (estado == -1)
		{
			printf("%s. %s \n",mensajeError, mensajeInicial);
		}
	}while (estado == -1);

	idFloat = atof(flotante);


	return idFloat;
}

void PedirCadena(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;


	do
	{
		printf("%s \n", mensajeInicial);
		fflush(stdin);
		scanf("%[^\n]",auxCadena);
		estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);

		if (estadoTamano == -1)
		{
			printf("%s. \n", mensajeError);
		}

	}while (estadoTamano == -1);

	strcpy(cadenaADevolver,auxCadena);

}

void PedirCadenaSoloLetras(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[])
{
	char auxCadena[1000];
	int estadoTamano;
	int estadoLetras;


	do
	{
		printf("%s \n", mensajeInicial);
		fflush(stdin);
		scanf("%[^\n]",auxCadena);
		estadoTamano = ValidarTamanoCadena(auxCadena, maxCadena);
		estadoLetras = ValidarLetrasCadena(auxCadena);
		if (estadoTamano == -1 || estadoLetras != -1 )
		{
			printf("%s. \n", mensajeError);
		}

	}while (estadoTamano == -1 || estadoLetras != -1);

	strcpy(cadenaADevolver,auxCadena);

}

int ValidarLetrasCadena(char cadenaAValidar[])
{
	int i=0;
	int estado;

	estado = 1;

	while(cadenaAValidar[i] != '\0')
	{
		if((cadenaAValidar[i] != ' ') && (cadenaAValidar[i] < 'a' || cadenaAValidar[i] > 'z') && (cadenaAValidar[i] < 'A' || cadenaAValidar[i] > 'Z'))
		{
			i++;

		}
		else
		{
			estado = -1;
			break;
		}

	}

	return estado;
}



int ValidarEntero(char entero[])
{
	int i;
	int estado;

	estado = 1;

	for (i=0; i < strlen(entero); i++)
	{
		if (!(isdigit(entero[i])))
		{
			estado = -1;
			break;
		}

	}
	return estado;
}

int ValidarEnteroConRango(int entero, int min, int max)
{
	int estado;

	estado = -1;

	if (entero >= min && entero <= max)
	{
		estado = 1;
	}

	return estado;

}

int ValidarFlotante(char flotante[])
{
	int estado = 1;
	int esNegativo = 0;
	int contarSigno = 0;
	if(strlen(flotante) > 0)
	{
		for(int i = 0; i < strlen(flotante); i++)
		{
			if(flotante[0] == '-' && esNegativo == 0)
			{
				esNegativo = 1;
			}
			if(i > 0 || esNegativo == 1)
			{
				if(flotante[i] == '.' || flotante[i] == ',')
				{
					contarSigno++;

				}
				else
				{
					if(isdigit(flotante[i]) == 0)
					{
						estado = 1;
						break;
					}
				}
			}
		}
		if(contarSigno > 1)
		{
			estado = 1;
		}

	}
	else
	{
		estado = 1;
	}

	return estado;


}

int ValidarFlotanteConRangoMinimo(float flotante, float min)
{
	int estado;

	estado = -1;

	if (flotante >= min)
	{
		estado = 1;
	}

	return estado;
}

int ValidarTamanoCadena(char cadena[], int maxCadena)
{
	int estado;

	estado = 1;

	if (strlen(cadena) > maxCadena || strlen(cadena) == 0)
	{
		estado = -1;
	}


	return estado;
}

float CalcularPromedio(float precioTotal, int cantidadTotal)
{
	float promedio;

	promedio = precioTotal / cantidadTotal;

	return promedio;
}

int PedirConfirmacion(char mensajeInicial[], char mensajeError[])
{
	char respuesta;
	int estado;

	estado = -1;

	do
	{
		printf("%s \n",mensajeInicial);
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta = tolower(respuesta);

		if (respuesta != 's' && respuesta != 'n')
		{

			printf("%s \n",mensajeError);

		}
	}while (respuesta != 's' && respuesta != 'n');

	if(respuesta == 's')
	{
		estado = 1;

	}


	return estado;

}
