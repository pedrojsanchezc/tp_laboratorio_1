#include "Inputs.h"

int Get_Int (char* message, char* errorMessage, int* entero)
{
	char auxiliar[256];
	int rtn = 0;

	if (entero != NULL)
	{
		printf ("%s", message);
		fflush(stdin);
		scanf("%s", auxiliar);

		while (Validate_Int(auxiliar) == 0)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%s", auxiliar);
		}

		*entero = atoi(auxiliar);
		rtn = 1;
	}
	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_Int (char* numero)
{
	int rtn;

	rtn = Validate_Digit (numero);

	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_Digit (char* numero)
{
    int rtn;
    int i;

    rtn = 1;

	for (i=0; i<strlen(numero); i++)
	{
		if(!isdigit(*(numero+i)) && *(numero+i) != '-')
		{
			rtn = 0;
			break;
		}
		else
		{
			if(*(numero+i) == '-' && i != 0)
			{
				rtn = 0;
			    break;
			}
		}
	}
	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Get_Char(char* messege, char* errorMessege, char* caracter)
{
	char auxiliar[256];
	int rtn = 0;

	if (caracter != NULL)
	{
		printf("%s", messege);
		fflush(stdin);
		scanf ("%s", auxiliar);

		while (strlen(auxiliar)>1 || !isalpha(auxiliar[0]))
		{
			printf("%s", errorMessege);
			fflush(stdin);
			scanf ("%s", auxiliar);
		}

		strcpy (caracter, auxiliar);
		rtn = 1;
	}

	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Get_String(char* messege, char* errorMessege, char* string, int tam)
{
	int rtn = 0;
	char auxiliar[256];

	if (string != NULL)
	{
		printf("%s", messege);
		fflush(stdin);
		scanf("%[^\n]", auxiliar);

		while (strlen(auxiliar) > tam || strlen(auxiliar) == 0)
		{
			printf("Error! cantidad de caracteres ingresados incorrectos. MAX.%d.\n", tam);
			printf("%s", errorMessege);
			fflush(stdin);
			scanf("%[^\n]", auxiliar);
		}
		strcpy(string, auxiliar);
		rtn = 1;
	}
	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Get_Float (char* message, char* errorMessage, float* flotante)
{
	char auxiliar[256];
	int result;

	if (flotante != NULL)
	{
		printf ("%s", message);
		fflush(stdin);
		scanf("%s", auxiliar);

		while (Validate_Float(auxiliar) == 0)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%s", auxiliar);
		}

		*flotante = atof(auxiliar);
		result = 1;
	}

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_Float (char* numero)
{
	int i;
    int result;
    int flag;

    flag = 0;
    result = 1;

    for (i=0; i<strlen(numero); i++)
	{
		if(!isdigit(*(numero+i)) && (*(numero+i)) != '.' && (*(numero+i)) != '-')
		{
			result = 0;
			break;
		}
		else
		{
			if((*(numero+i)) == '.')
			{
				flag++;
			}
		}
		if(flag>1)
		{
			result = 0;
			break;
		}

		if(i !=0 && (*(numero+i)) == '-')
		{
		    result = 0;
			break;
		}
	}
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Get_IntMaxAndMin (char* message, char* errorMessage, int min, int max, int* entero)
{
	char auxiliar[256];
	int result;
	if (entero != NULL)
	{
		printf ("%s", message);
		fflush(stdin);
		scanf("%s", auxiliar);

		while (Validate_IntMinMax(auxiliar, min, max) == 0)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%s", auxiliar);
		}

		*entero = atoi(auxiliar);
		result = 1;
	}

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_IntMinMax (char* numero, int min, int max)
{
	int result;

	result = Validate_Digit (numero);

    if (result == 1)
    {
        result = Validate_MinMax (numero, min, max);
    }

	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_MinMax (char* numero, int min, int max)
{
    int rtn;
    int entero;

    rtn = 1;

    entero = atoi(numero);

    if(entero>max || entero<min)
	{
		rtn = 0;
	}
	return rtn;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////
int Validate_Salir(char* messege, char* errorMessege)
{
	int rtn;
	char opcion;

    rtn = 0;
	Get_Char(messege, errorMessege, &opcion);
	opcion = tolower(opcion);

	while (opcion != 's' && opcion != 'n')
	{
		printf("ERROR. indique una opcion correcta");
		Get_Char(messege, errorMessege, &opcion);
		opcion = tolower(opcion);
	}

	if (opcion == 's')
	{
		rtn = 1;
	}

	return rtn;
}
