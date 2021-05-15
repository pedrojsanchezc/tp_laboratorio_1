#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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


#endif /* INPUTS_H_ */
