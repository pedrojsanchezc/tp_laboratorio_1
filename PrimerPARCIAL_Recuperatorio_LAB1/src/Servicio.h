/*
 * Servicio.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#ifndef SERVICIO_H_
#define SERVICIO_H_
#define MAX_DESCRIPCION 30
#define MAX_SERVICIOS 4
#define MIN_ID_SERVICIOS 20000

typedef struct{
	int idServicio;
	char descripcion[MAX_DESCRIPCION];
	float precio;
	int estadoServicio;
}eServicio;

/**
 * @fn void InicializarServicios(eServicio[], int)
 * @brief asigna VACIO al campo estadoServicio de cada elemento del array
 *
 * @param listaServicios
 * @param tamServicios
 */
void eServicio_Inicializar(eServicio listaServicios[], int tamServicios);
/**
 * @fn int BuscarLibreServicios(eServicio[], int)
 * @brief busca en el array listaServicios una posicion que tenga el campo estadoServicio = 0 ó -1, asignando -1 a indexBL si
 * no fue exitosa la busqueda o una posicion si lo fue.
 *
 * @param listaServicios
 * @param tamServicios
 * @return indexBL
 */
int eServicio_ObtenerIndexLibre(eServicio listaServicios[], int tamServicios);
/**
 * @fn int BuscarIDServicios(eServicio[], int, int)
 * @brief busca el campo idServicio con valor igual al parametro idServicio en cada elemento del array, asignando el indice a index si lo encuentra, y -1 si no
 *
 * @param listaServicios
 * @param tamServicios
 * @param idServicios
 * @return index
 */
int eServicio_BuscarIDServicios(eServicio listaServicios[], int tamServicios,int idServicios);
/**
 * @fn void ImprimirServicios(eServicio[], int)
 * @brief muestra todos los campos de cada eServicio en el array menos estadoServicio, mientras tengan el campo estadoServicio == OCUPADO
 *
 * @param listaServicios
 * @param tamServicios
 */
void eServicio_ImprimirServicios(eServicio listaServicios[], int tamServicios);
/**
 * @fn void ImprimirUnServicio(eServicio)
 * @brief muestra todos los campos de un eServicio en el array menos estadoServicio
 *
 * @param miServicio
 */
void eServicio_ImprimirUnServicio(eServicio miServicio);
/**
 * @fn void HardcodeoDatosServicios(eServicio[], int, int)
 * @brief asigna valores especificos a cada campo de un numero determinado elementos de listaServicios
 *
 * @param listaServicios
 * @param tamS
 * @param minId
 */
void eServicio_HardcodeoDatosServicios(eServicio listaServicios[], int tamS, int minId);
/**
 * @fn int ValidarArrayOcupadoServicios(eServicio[], int)
 * @brief si al menos hay un elemento en el array listaServicios que tenga en el campo estadoServicio el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaServicios
 * @param tamServicios
 * @return estado
 */
int eServicio_ValidarArrayOcupadoServicios(eServicio listaServicios[], int tamServicios);


#endif /* SERVICIO_H_ */
