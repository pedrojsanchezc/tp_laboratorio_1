/*
 * Inputs.h
 *
 *  Created on: 25 sep. 2021
 *      Author: EXO02
 */

#ifndef INPUTS_H_
#define INPUTS_H_

void MenuCalculadora(void);
float SumarFlotantes(float numeroUno,float numeroDos, float* pResultado);
float RestarFlotantes(float numeroUno,float numeroDos, float* pResultado);
float MultiplicarFlotantes(float numeroUno,float numeroDos, float* pResultado);
float DividirFlotantes(float numeroUno,float numeroDos, float* pResultado);
float FactorialFlotante(float operador,float *pResultado);
int utn_getInt(char* mensaje, char* mensajeError,int* pResultado, int reintentos, int minimo, int maximo);
int utn_getFloat(char *mensaje,char *mensajeError,float *pResultado,int reintentos);

#endif /* INPUTS_H_ */
