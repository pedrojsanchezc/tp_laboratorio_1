/*
 * Auxiliar.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_
#include "Controller.h"


typedef struct {
	int idAuxiliar;
	int contador;
	float acumulador;
	char descripcion[MAX_DESCRIPCION];
	int estadoAuxiliar;
}eAuxiliar;

/**
 * @fn int BuscarIDAuxiliares(eAuxiliar[], int, int)
 * @brief Busca al ID proporcionado por idAuxiliar en el array listaAuxiliar, asignando -1 a estado si
 * no fue exitosa la busqueda o la posicion si lo fue.
 *
 * @param listaAuxiliar
 * @param tamAuxiliar
 * @param idAuxiliar
 * @return estado
 */
int eAuxiliar_BuscarIDAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar, int idAuxiliar);
/**
 * @fn void ImprimirAuxiliares(eAuxiliar[], int)
 * @brief muestra todos los campos de cada eAuxiliar menos estadoAuxiliar, si el elemento de la posicion tiene el campo estadoAuxiliar == 1
 *
 * @param listaAuxiliar
 * @param tamAuxiliar
 */
void eAuxiliar_ImprimirAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar);
/**
 * @fn void ImprimirUnAuxiliar(eAuxiliar)
 * @brief muestra todos los campos de un eAuxiliar menos estadoAuxiliar
 *
 * @param miAuxiliar
 */
void eAuxiliar_ImprimirUnAuxiliar(eAuxiliar miAuxiliar);


#endif /* AUXILIAR_H_ */
