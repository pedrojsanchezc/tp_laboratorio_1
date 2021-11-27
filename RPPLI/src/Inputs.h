/*
 * Inputs.h
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */

#ifndef INPUTS_H_
#define INPUTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NO_REINTENTOS "No hay mas reintentos disponibles\n"
#define ERROR_PARAMETROS "Error, no hay parametros validos\n"
#define LEN_DNI 9
#define LEN_CUIT 12
#define LEN_TELEFONO 10
#define LEN_CELULAR 13
#define LEN_EMAIL 64
#define LEN_TARJETA_CREDITO 20
#define LEN_DIRECCION 64
#define LEN_DIRECCION_ALTURA 10

int getNumber(char* message);

float getFloatMessage(char* message);

/**
 * \brief Asks for an integer number and calls isInt function to validate it,
            shows error message if it isn't an integer number
 * \param message It is the entry request message
 * \return The integer value
 *
 */
int getInt(char* message);

/**
 * \brief Takes the integer given by getInt function and verifies if it is a valid input
 * \param string It is the array with the number to be analized
 * \return 1 if it is a valid integer; 0 if it is not an integer
 *
 */
int isInt(char* string);

/**
 * \brief Allows the entry of a text string
 * \param message It is the entry request message
 * \param errorMessage It is the error message in case of an invalid entry
 * \param input It is the array where text to be loaded up
 * \return 1 if the text only contains letters and spaces
 *
 */
int getCharString(char* message, char* errorMessage, char* input);

/**
 * \brief Verifies if the received value contains only letters and spaces
 * \param string It is the array with the string to be analized
 * \return 1 if the text only contains letters and spaces; 0 if there is more than letters and spaces
 *
 */
int charactersOnly(char* string);

/**
 * \brief Asks for an integer and float number and verifies it
 * \param floatMask It is the mask to put into the scanf function
 * \param variable It is the variable where to place the validated number
 * \return 1 if it is a valid number; 0 if it isn't
 *
 */
int getAndValidateIntAndFloatNumber(const char* floatMask, void* variable);

void getStr(char* message, int size, char* output);

int getLetterStr(char* message,int size, char* output);

int onlyLetters(char* str);

/**
 * \brief Converts the first character of one or more words to uppercase
 * \param string It is the array in which to search
 * \return A confirmation value of the modify
 *
 */
void fstLettUppercase(char* array);

/**
 * \brief Looks for a newline character inside the array and replaces it with a '\0'
 * \param string It is the array in which to search
 * \return The modified string
 *
 */
char removeLineBreak(char* array);

char *strlwr(char *str);

int chooseIndex(void);

void loadList(int* numbersList, int size);

void positiveNumAscSorting(int* array, int size);

void negativeNumDescSorting(int* array, int size);

void printList(int* array,int size);

void printPositiveList(int* array,int size);

void printNegativeList(int* array,int size);

void printPositivesCount(int* array,int size);

void printNegativesCount(int* array,int size);

void printPairNumSum(int* array, int size);

void printBiggestOddNum(int* array, int size);

void printPairNumList(int* array, int size);

void printOddNumList(int* array, int size);

void printPositivesAverage(int* array, int size);

void printNegNumPredecessorsAddition(int* array, int size);


/**
* \brief Recibe un string, lo recorre verificando que no quede un '\n' antes de la penultima posici�n y la valida
* \param char* string Puntero al espacio de memoria donde se copiar� la cadena obtenida
* \param int limite Define el tama�o de la cadena
* \return Retorna 0 si se valida el string y -1 si no es valido
*/
int myGets(char* string, int limite);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  NUMEROS  //////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Transforma una cadena de caract�res a n�meros si es posible
 * \param int* pResultado Puntero donde se almacenar� el n�mero ingresado
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entero o -1 (ERROR) si no
*/
int utn_getInt(int *pResultado);

/**
 * \brief Transforma una cadena de caract�res a n�meros decimales si es posible
 * \param float* pResultado Puntero donde se almacenar� el n�mero ingresado
 * \return Retorna 0 (EXITO) si se obtiene un n�mero decimal o -1 (ERROR) si no
*/
int getFloat(float *pResultado);

/**
 * \brief Verifica que la cadena recibida contenga solamente n�meros positivos o negativos
 * \param char* cadena Cadena de caracteres a ser analizada
 *  \param int len Define el tama�o de la cadena
 * \return Retorna 1 (verdadero) si la cadena es num�rica, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
*/
int utn_esNumerica(char* cadena, int len);

/**
 * \brief Verifica que la cadena recibida contenga solamente n�meros decimales positivos o negativos
 * \param char* cadena Cadena de caracteres a ser analizada
 * \param int len Define el tama�o de la cadena
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
*/
int utn_esFloat(char* cadena, int len);

/**
 * \brief Solicita un n�mero de tipo int al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aqu� se guarda el n�mero ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int minimo Valor m�nimo para el ingreso de n�meros
 * \param int maximo Valor m�ximo para el ingreso de n�meros
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
 */
int utn_getNumero(int* pResultado, char* pMensaje, char* pMensajeError, int minimo, int maximo, int reintentos);

/**
 * \brief Solicita un n�mero de tipo float al usuario, lo valida, verifica y devuelve el resultado
 * \param int* pResultado Puntero al resultado. Aqu� se guarda el n�mero ingresado por el usuario
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param float minimo Valor m�nimo para el ingreso de n�meros
 * \param float maximo Valor m�ximo para el ingreso de n�meros
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
 */
int utn_getFloat(float* pResultado, char* pMensaje, char* pMensajeError, float minimo, float maximo, int reintentos);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  CALCULOS  ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief A partir de 2 n�meros, realiza una suma
 * \param float operandoA Primer n�mero que ingres� el usuario previamente
 * \param float operandoB Segundo n�mero que ingres� el usuario previamente
 * \param float* pResultado Puntero donde se guardar� la suma
 * \return 0 si la funci�n fue exitosa, -1 si da error
 */
int utn_getSuma(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 n�meros, realiza una resta
 * \param float operandoA Primer n�mero que ingres� el usuario previamente
 * \param float operandoB Segundo n�mero que ingres� el usuario previamente
 * \param float* pResultado Puntero donde se guardar� la resta
 * \return 0 si la funci�n fue exitosa, -1 si da error
 */
int utn_getResta(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 n�meros, realiza una multiplicaci�n
 * \param float operandoA Primer n�mero que ingres� el usuario previamente
 * \param float operandoB Segundo n�mero que ingres� el usuario previamente
 * \param float pResultado Puntero donde se guardar� la multiplicaci�n
 * \return 0 si la funci�n fue exitosa, -1 si da error
 */
int utn_getMultiplicacion(float operandoA, float operandoB, float* pResultado);

/**
 * \brief A partir de 2 n�meros, realiza una divisi�n. Valida si el divisor es 0
 * \param float operandoA Primer n�mero que ingres� el usuario previamente
 * \param float operandoB Segundo n�mero que ingres� el usuario previamente
 * \param float* pResultado Puntero donde se guardar� la divisi�n
 * \param char* pMensajeError  Puntero al mensaje a ser mostrado en caso de error
 * \return 0 si la funci�n fue exitosa, -1 si da error
 */
int utn_getDivision(float operandoA, float operandoB, float* pResultado, char* pMensajeError);

/**
 * \brief A partir de 1 n�mero, realiza el factorial.
 * \param double operandoA Primer n�mero que ingres� el usuario previamente
 * \param double* pResultadoA Puntero donde se guardar� el factorial
 * \return Devuelve 0 si la funci�n fue exitosa, -1 si da error
 */
int utn_getFactorial(double operandoA, double* pResultadoA);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////  STRING  ////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita al usuario una cadena de caracteres, la valida y verifica que no quede un enter
 * \param char* pResultado Puntero donde se almacena la cadena de caracteres
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int len Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
*/
int utn_getString(char* pResultado, char* pMensaje, char* pMensajeError, int len, int reintentos);

/**
 * \brief Solicita al usuario que ingrese un nombre
 * \param char* pNombre Puntero donde se almacenar� el nombre ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el nombre o -1 (ERROR) si no
 */
int utn_getNombre(char* pNombre, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Solicita al usuario un caracter y lo valida
 * \param char* pResultado Puntero donde se almacena la cadena de caracteres
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
*/
int utn_getChar(char* pResultado, char* pMensaje, char* pMensajeError, int reintentos);


/**
 * \brief Recibe un caracter y valida que este entre a y z
 * \param char* letra: Puntero donde se almacena el caracter
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
*/
int esLetra(char* letra);

/**
 * \brief Solicita al usuario el ingreso de un texto y lo convierte en mayusculas
 * \param char* pString Puntero donde se almacenar� el texto ingresado en mayusculas
 * \param int limite Define el tama�o de la cadena
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el texto en may�sculas o -1 (ERROR) si no
 */
int utn_getCadenaEnMayusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario el ingreso de un texto y lo convierte en min�sculas
 * \param char* pString Puntero donde se almacenar� el texto ingresado en minusculas
 * \param int limite Define el tama�o de la cadena
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el texto en min�sculas o -1 (ERROR) si no
 */
int utn_getCadenaEnMinusculas(char* pString, int limite, char* pMensaje, char* pMensajeError);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////  OTRAS VALIDACIONES  ///////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


/**
 * \brief Solicita al usuario el ingreso de un DNI
 * \param char* pDni: Puntero donde se almacenar� el DNI ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el DNI o -1 (ERROR) si no
 */
int utn_getDni(char* pDni, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un CUIT
 * \param char* pCuit Puntero donde se almacenar� el CUIT ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int limite Define el tama�o de la cadena
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el CUIT o -1 (ERROR) si no
 */
int utn_getCuit(char* pCuit, char* pMensaje, char* pMensajeError, int limite, int reintentos);

/**
 * \brief Solicita al usuario que ingrese una edad
 * \param int* pEdad Puntero donde se almacenar� la edad ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene la edad o -1 (ERROR) si no
 */
int utn_getEdad(int* pEdad, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un precio
 * \param float* pPrecio Puntero donde se almacenar� el precio ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el precio o -1 (ERROR) si no
 */
int utn_getPrecio(float* pPrecio, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un tel�fono
 * \param char* pTelefono Puntero donde se almacenar� el telefono ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el tel�fono o -1 (ERROR) si no
 */
int utn_getTelefono(char* pTelefono, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un celular
 * \param char* pCelular Puntero donde se almacenar� el celular ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el celular o -1 (ERROR) si no
 */
int utn_getCelular(char* pCelular, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario que ingrese un email
 * \param char* pEmail Puntero donde se almacenar� el email ingresado
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene el email o -1 (ERROR) si no
 */
int utn_getEmail(char* pEmail, char* pMensaje, char* pMensajeError);

/**
 * \brief Le pide al usuario que ingrese una tarjeta de cr�dito
 * \param char* pTarjeta Puntero donde se almacenar� la tarjeta de cr�dito ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \return Retorna 0 (EXITO) si se obtiene la tarjeta de cr�dito o -1 (ERROR) si no
  */
int utn_getTarjetaCredito(char* pTarjeta, char* pMensaje, char* pMensajeError);

/**
 * \brief Solicita al usuario el ingreso de una direcci�n
 * \param char* pDireccion Puntero donde se almacenar� la direccion ingresada
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeAltura Puntero al texto que informa que se debe ingresar una altura
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pMensajeErrorAltura Puntero al mensaje a ser mostrado en caso de que no se ingrese la altura de la direcci�n
 * \return Retorna 0 (EXITO) si se obtiene la direcci�n o -1 (ERROR) si no
 */
int utn_getDireccion(char* pDireccion, char* pMensaje, char* pMensajeAltura, char* pMensajeError, char* pMensajeErrorAltura);

/**
 * \brief Solicita un texto al usuario y lo convierte en may�sculas
 * \param char* cadena Puntero donde se almacenar� el texto en may�sculas
 * \param int limite Limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 0 (EXITO) si se convierte en may�sculas o -1 (ERROR) si no
 */
int getMayusculas(char* cadena, int limite);

/**
 * \brief Solicita un texto al usuario y lo convierte en min�sculas
 * \param char* cadena Puntero donde se almacenar� el texto en min�sculas
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 0 (EXITO) si se convierte en min�sculas o -1 (ERROR) si no
 */
int getMinusculas(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga solamente n�meros decimales positivos o negativos
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es decimal, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarDecimal(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un nombre o apellido v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un nombre o apellido, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarNombre(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un DNI v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un DNI, 0 (falso) si no o -1 si hubo alg�n error en los argumentos
 */
int validarDni(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un CUIT v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un CUIT, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarCuit(char* cadena, int limite);

/**
 * \brief Valida que el n�mero ingresado sea una edad v�lida
 * \param int* pNumero Puntero donde se almacenar� la edad correcta
 * \return Retorna 1 (verdadero) si es una edad v�lida, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarEdad(int* pNumero);

/**
 * \brief Valida que el n�mero ingresado sea un precio v�lido
 * \param float* pResultado Puntero donde se almacenar� el precio
 * \return Retorna 1 (verdadero) si es un precio v�lido, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarPrecio(float* pResultado);

/**
 * \brief Valida que la cadena recibida sea un tel�fono v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un tel�fono, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
  */
int validarTelefono(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida sea un celular v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un celular, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarCelular(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga un email v�lido
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es un email, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarEmail(char* cadena, int limite);


/**
 * \brief Valida que la cadena recibida sea una tarjeta de cr�dito v�lida
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una tarjeta de cr�dito, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarTarjetaCredito(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una direcci�n v�lida
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una direcci�n, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarDireccion(char* cadena, int limite);

/**
 * \brief Valida que la cadena recibida contenga una altura v�lida de una direcci�n
 * \param char* cadena Puntero a la cadena de caracteres a ser analizada
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \return Retorna 1 (verdadero) si la cadena es una altura de direcci�n, 0 (falso) si no o -1 si hubo alg�n error con los argumentos
 */
int validarDireccionAltura(char* cadena, int limite);

/**
 * \brief Pregunta al usuario si desea continuar y valida que ingres Y/y o N/n
 * \param char* pResultado Puntero donde se almacena el caracter
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return Retorna 0 (EXITO) si se obtiene un n�mero entre el rango o -1 (ERROR) si no
*/
int utn_getContinuar(char* pRespuesta, char* pMensaje, char* pMensajeError, int reintentos);

/**
 * \brief Verifica que una cadena de caracteres sea un numero entero sin signo
 * \param char* cadena Puntero donde se almacenar� el n�mero ingresado
 * \return Retorna 1 (EXITO) si es un entero; 0(NO) si el string no es un numero; -1 (ERROR) si es nulo
*/
int utn_isIntSinSigno(char* cadena);

/**
 * \brief Funcion que chequea si una cadena es alfanumerica
 * \param char* cadena Puntero a char que se recorre para corroborar si es alfanumerico
 * \return (0) Error (1)  OK
 */
int utn_isAlfanumerico(char *cadena);

/**
 * \brief Funcion que chequea si una cadena es numerica
 * \param char* cadena Puntero a char que se recorre para corroborar si es numerico
 * \return (0) Error (1) OK
 */
int utn_isNumerico(char *cadena);

/**
 * \brief Solicita por medio del archivo stdin el ingreso de una cadena que permite letras y numeros
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pCadena Puntero a char donde se guarda la cadena
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return (-1) Error (0)  OK
 */
int utn_getAlfanumerico(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos);

/**
 * \brief Solicita por medio del archivo stdin el ingreso de una cadena que permite solo numeros
 * \param char* pMensaje Puntero al mensaje a ser mostrado
 * \param char* pMensajeError Puntero al mensaje a ser mostrado en caso de error
 * \param char* pCadena Puntero a char donde se guardar la cadena
 * \param int limite Valor maximo de caracteres que se pueden ingresar
 * \param int reintentos Cantidad de reintentos en caso de error
 * \return (-1) Error (0)  OK
 */
int utn_getStringSoloNumeros(char *pMensaje, char *pMensajeError, char *pCadena, int limite, int reintentos);

/**
 * \brief Valida que la cadena recibida sea una cadena de caracteres sin comas
 * \param char* cadena Puntero a la cadena a validar
 * \return (-1) Error (1)  OK  (0) Caracteres Invalidos
 */
int utn_isString(char* cadena);

#endif /* INPUTS_H_ */
