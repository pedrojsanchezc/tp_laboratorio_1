/*
 * Inputs.h
 *
 *  Created on: 15 nov. 2021
 *      Author: pedro_000
 */
#ifndef INPUTS_H_
#define INPUTS_H_
int utn_getString(char mensaje[], char mensajeError[], char pResultado[], int attemps, int limit);
int utn_getInt(char msg[], char msgError[], int *pResult, int attemps, int min, int max);
int menu(int *pResult, int attemps, int min, int max);
int utn_getFloat(char msg[], char msgError[], float *pResult, int attemps, int min, int max);
#endif /* INPUTS_H_ */
