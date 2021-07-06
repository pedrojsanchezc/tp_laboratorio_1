/*
 * Fecha.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef FECHA_H_
#define FECHA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#define ANIO_ACTUAL 2021



typedef struct {
	int anio;
	int mes;
	int dia;
}eFecha;



/**
 * @fn eFecha PedirFecha(int, int, int)
 * @brief solicita los datos para los campos anio, mes y dia de
 *
 * @param indexFecha
 * @param minAnio
 * @param maxAnio
 * @return miFecha
 */
eFecha PedirFecha(int anioActual);






#endif /* FECHA_H_ */
