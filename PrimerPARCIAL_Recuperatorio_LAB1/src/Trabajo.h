/*
 * Trabajo.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#define MAX_TRABAJOS 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Fecha.h"

typedef struct {
	int idTrabajo;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int estadoTrabajo;
}eTrabajo;

/**
 * @fn void InicializarTrabajos(eTrabajo[], int)
 * @brief asigna el valor VACIO al campo de estadoTrabajo de cada elemento del array
 *
 * @param listaTrabajos
 * @param tamT
 */


void eTrabajo_Inicializar(eTrabajo listaTrabajos[], int tamT);

/**
 * @fn int BuscarLibreTrabajos(eTrabajo[], int)
 * @brief busca en el array listaTrabajos una posicion que tenga el campo estadoTrabajo = 0 ó -1, asignando -1 a indexBL si
 * no fue exitosa la busqueda o una posicion si lo fue.
 *
 * @param listaTrabajos
 * @param tamT
 * @return indexBL
 */
int eTrabajo_ObtenerIndexLibre(eTrabajo listaTrabajos[], int tamT);
/**
 * @fn int BuscarIDTrabajos(eTrabajo[], int, int)
 * @brief busca el campo idTrabajo con valor igual al parametro idTrabajo en cada elemento del array, asignando el indice a index si lo encuentra, y -1 si no
 *
 * @param listaTrabajos
 * @param tamT
 * @param idTrabajo
 * @return index
 */
int eTrabajo_BuscarIDTrabajos(eTrabajo listaTrabajos[], int tamT, int idTrabajo);
/**
 * @fn int ValidarArrayOcupadoTrabajos(eTrabajo[], int)
 * @brief si al menos hay un elemento en el array listaTrabajos que tenga en el campo estadoTrabajo el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaTrabajos
 * @param tamT
 * @return estado
 */
int eTrabajo_ValidarArrayOcupadoTrabajos(eTrabajo listaTrabajos[], int tamT);
/**
 * @fn int ValidarParaDarDeBajaTrabajo(eTrabajo)
 * @brief solicita confirmacion para dar de baja un producto, si se responde 's', se asigna 1 a estado, caso contrario, se le asigna -1
 *
 * @param TrabajoADarDeBaja
 * @return estado
 */
int eTrabajo_ValidarParaDarDeBajaTrabajo (eTrabajo TrabajoADarDeBaja);
/**
 * @fn void HardcodeoDatosTrabajos(eTrabajo[], int, int)
 * @brief asigna valores especificos a cada campo de un numero determinado elementos de listaTrabajos
 *
 * @param listaTrabajos
 * @param tamT
 * @param minId
 */
void eTrabajo_HardcodeoDatosTrabajos(eTrabajo listaTrabajos[], int tamT, int minId, int minIdBicicleta, int anioActual);




#endif /* TRABAJO_H_ */
