/*
 * utn.h
 *
 *  Created on: 16 jul. 2021
 *      Author: EXO02
 */

#ifndef UTN_H_
#define UTN_H_

void Menu(void);

int utn_getNumero(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
int utn_getNumeroFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);

float utn_sumaNumerosFloat(float operador1, float operador2, float* pResultado);
float utn_restaNumerosFloat(float operador1, float operador2, float *pResultado);
float utn_multiplicacionNumerosFloat(float operador1, float operador2, float *pResultado);
float utn_divisionNumerosFloat(float operador1, float operador2, float *pResultado);
float utn_getFactorialFloat(float operador,float *pResultado);

#endif /* UTN_H_ */
