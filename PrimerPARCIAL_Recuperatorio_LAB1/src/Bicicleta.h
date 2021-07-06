/*
 * Bicicleta.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_
#define MAX_MARCA 25
#define MAX_BICICLETAS 10
#define MIN_ID_BICICLETAS 25
#define MAX_COLOR 25
#include "Inputs.h"

typedef struct {
	int idBicicleta;
	int idCliente;
	char marcaBicicleta[MAX_MARCA];
	int rodadoBicicleta;
	char colorBicicleta[MAX_COLOR];
	int estadoBicicleta;
}eBicicleta;

void eBicicleta_Inicializar(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int BuscarLibreBicicletas(eBicicleta[], int)
 * @brief busca en el array listaBicicletas una posicion que tenga el campo estadoBicicleta = 0 o -1, asignando -1 a indexBL si
 * no fue exitosa la busqueda o una posicion si lo fue.
 *
 * @param listaBicicletas
 * @param tamB
 * @return indexBL
 */
int eBicicleta_BuscarLibreBicicletas(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int BuscarIDBicicletas(eBicicleta[], int, int)
 * @brief busca el campo idBicicleta con valor igual al parametro idBicicleta en cada elemento del array, asignando el indice a index si lo encuentra, y -1 si no
 *
 * @param listaBicicletas
 * @param tamB
 * @param idBicicletas
 * @return index
 */
int eBicicleta_BuscarIDBicicletas(eBicicleta listaBicicletas[], int tamB,int idBicicletas);
/**
 * @fn int ValidarArrayOcupadoBicicletas(eBicicleta[], int)
 * @brief si al menos hay un elemento en el array listaBicicletas que tenga en el campo estadoBicicleta el valor OCUPADO, asigna el valor 1 a estado, si no, -1.
 *
 * @param listaBicicletas
 * @param tamB
 * @return estado
 */
int eBicicleta_ValidarArrayOcupadoBicicletas(eBicicleta listaBicicletas[], int tamB);
/**
 * @fn int PedirBicicleta(int, int, int, int, int)
 * @brief
 *
 * @param indexBici
 * @param tamB
 * @param minID
 * @param maxMarca
 * @param maxColor
 * @return
 */
eBicicleta eBicicleta_PedirBicicleta(int indexBici, int tamB, int minID, int maxMarca, int maxColor);
/**
 * @fn int ValidarBicicletaRoja(eBicicleta miBicicleta);
 *
 * @brief Valida si la bicicleta recibida es roja
 *
 * @param miBicicleta
 *
 * @return estado (1 si la bicicleta es roja,
 * 					-1 si no)
 */
int eBicicleta_ValidarBicicletaRoja(eBicicleta miBicicleta);



#endif /* BICICLETA_H_ */
