/*
 * Inputs.h
 *
 *  Created on: 13 nov. 2021
 *      Author: pedro_000
 */

#ifndef INPUTS_H_
#define INPUTS_H_

float utn_getFloat(char *mensaje, char *mensajeError, float *pResultado,int reintentos,float min, float max);
int utn_getNumero(char* mensaje, char* mensajeError, int* pResultado,int reintentos,int minimo,int maximo);
int utn_getNombre(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getString(char* mensaje, char* mensajeError, char* pResultado,int reintentos, int limite);
int utn_getOrdenamiento(int array[], int len);




#endif /* INPUTS_H_ */
