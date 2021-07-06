#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define OCUPADO 1
#define VACIO 0
#define BAJA -1

#define TAM_BUFFER 1000

//VALIDACIONES
int Validate_OnlyNumberInt(char *buffer);
int Validate_OnlyNumberFloat(char *buffer);
int Validate_OnlyAlphabet(char *buffer);
int Validate_OnlyAlphabetWithSpaces(char *buffer);
int Validate_Exit_SN(char *MSJ, char *ERROR_MSJ);

//GET
int Get_Int(char *MSJ, char *ERROR_MSJ);
int Get_IntPositive(char *MSJ,char *ERROR_MSJ);
int Get_IntRange(char *MSJ, char *ERROR_MSJ, int MIN, int MAX);
float Get_Float(char *MSJ, char *ERROR_MSJ);
float Get_FloatRange(char *MSJ, char *ERROR_MSJ, float MIN, float MAX);
double Get_Double(char *MSJ, char *ERROR_MSJ);
double Get_DoubleRange(char *MSJ, char *ERROR_MSJ, double MIN, double MAX);

char Get_Char(char *MSJ, char *ERROR_MSJ);
void Get_String(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);
void Get_OnlyAlphabetString(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);
void Get_OnlyAlphabetStringWithSpaces(char *MSJ, char *ERROR_MSJ, char *pString, int TAM);

//UTILIDADES
int ArraySort_Int(int *pArray, int TAM, int criterio);
int ArraySort_Float(float *pArray, int TAM, int criterio);
/***CRITERIO -> -1 = Menor a Mayor | 1 = Mayor a Menor***/
void ArrayPrint_Int(int *pArray, int TAM);
void ArrayPrint_Float(float *pArray, int TAM);
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName);
void pedirNombre(char* nombre, int TAM);
void pedirApellido(char* apellido, int TAM);

/**
 * @fn int PedirEntero(char[], char[])
 * @brief se solicita un entero, se lo valida, y si pasa la validación se lo retorna
 *
 * @param mensajeInicial
 * @param mensajeError
 * @return idInt
 */
int PedirEntero(char mensajeInicial[], char mensajeError[]);
/**
 * @fn float PedirFlotante(char[], char[])
 * @brief se solicita un flotante, se lo valida, y si pasa la validación se lo retorna
 *
 * @param mensajeInicial
 * @param mensajeError
 * @return idFloat
 */
float PedirFlotante(char mensajeInicial[], char mensajeError[]);
/**
 * @fn int ValidarEntero(char[])
 * @brief se valida si el caracter ingresado es un entero, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param entero
 * @return estado
 */
int ValidarEntero(char entero[]);
/**
 * @fn int ValidarEnteroConRango(int, int, int)
 * @brief se valida si entero esta dentro del min y el max, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param entero
 * @param min
 * @param max
 * @return estado
 */
int ValidarEnteroConRango(int entero, int min, int max);
/**
 * @fn int ValidarFlotante(char[])
 * @brief se valida si el caracter ingresado es un flotante, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param flotante
 * @return estado
 */
int ValidarFlotante(char flotante[]);
/**
 * @fn int ValidarFlotanteConRangoMinimo(float, float)
 * @brief se valida si flotante es igual o mayor al min, se asigna -1 a estado si no lo es, 1 si lo es.
 *
 * @param flotante
 * @param min
 * @return
 */
int ValidarFlotanteConRangoMinimo(float flotante, float min);
/**
 * @fn void PedirCadena(char[], int, char[], char[])
 * @brief se solicita una cadena, se valida si la cadena ingresada excede en tamaño al destino, y se copia el contenido de la cadena a cadenaADevolver
 *
 * @param cadenaADevolver
 * @param maxCadena
 * @param mensajeInicial
 * @param mensajeError
 */
void PedirCadena(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[]);
/**
 * @fn void PedirCadenaSoloLetras(char[], int, char[], char[])
 * @brief
 *
 * @param cadenaADevolver
 * @param maxCadena
 * @param mensajeInicial
 * @param mensajeError
 */
void PedirCadenaSoloLetras(char cadenaADevolver[], int maxCadena, char mensajeInicial[], char mensajeError[]);
/**
 * @fn int ValidarTamanoCadena(char[], int)
 * @brief se valida si la cadena ingresada excede en tamaño al destino, se asigna  -1 a estado si lo hace, 1 si no.
 *
 * @param cadena
 * @param maxCadena
 * @return estado
 */
int ValidarTamanoCadena(char cadena[], int maxCadena);
/**
 * @fn int ValidarLetrasCadena(char[])
 * @brief se valida si la cadena ingresada contiene solo letras y espacios, se asigna  -1 a estado si lo hace, 1 si no.
 *
 * @param cadenaAValidar
 * @return estado
 */
int ValidarLetrasCadena(char cadenaAValidar[]);
/**
 * @fn float CalcularPromedio(float, int)
 * @brief se calcula el promedio de una acumulacion, dividiendola por un contador.
 *
 * @param precioTotal
 * @param cantidadTotal
 * @return promedio
 */
float CalcularPromedio(float precioTotal, int cantidadTotal);
/**
 * @fn int PedirConfirmacion(char[], char[])
 * @brief se pide ingresar 's' o 'n' para confirmar algo segun los mensajes dados como parametro
 *
 * @param mensajeInicial
 * @param mensajeError
 * @return estado (1 si se ingreso 's',
 * 					-1 si se ingreso 'n')
 */
int PedirConfirmacion(char mensajeInicial[], char mensajeError[]);

#endif /* INPUTS_H_ */
