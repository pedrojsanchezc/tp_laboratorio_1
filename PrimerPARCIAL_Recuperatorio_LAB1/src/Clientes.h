/*
 * Clientes.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

#define MAX_CLIENTES 5
#define MIN_ID_CLIENTES 1000
#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
#include "Inputs.h"

typedef struct{
	int idCliente;
	char nombre[50];
	char apellido[50];
	int estadoCliente;
}eCliente;
/**
 * @fn void eClientes_Inicializar(eCliente listaClientes[], int tamC);
 *
 * @brief setea en VACIO el estado de los clientes
 *
 * @param listaClientes
 * @param tamC
 */
void eClientes_Inicializar(eCliente listaClientes[], int tamC);
/**
 * @fn int BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente);
 *
 * @brief busca el id del cliente
 * @param listaClientes
 * @param tamC
 * @param idCliente
 * @return index ( retorna el indice si es que lo encuentra, sino -1)
 */
int eClientes_BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente);
/**
 * @fn int BuscarLibreClientes(eCliente listaClientes[], int tamC);
 *
 * @brief Busca un espacio libre en el array
 * @param listaClientes
 * @param tamC
 * @return index ( retorna el indice si es que lo encuentra, sino -1)
 */
int eClientes_BuscarLibreClientes(eCliente listaClientes[], int tamC);
/**
 * @fn void ImprimirClientes(eCliente listaClientes[], int tamC);
 *
 * @brief muestra los clientes
 * @param listaClientes
 * @param tamC
 */
void eClientes_ImprimirClientes(eCliente listaClientes[], int tamC);
/**
 * @fn void ImprimirUnCliente(eCliente miCliente);
 *
 * @brief muestra un cliente
 * @param miCliente
 */
void eClientes_ImprimirUnCliente(eCliente miCliente);
/**
 * @fn void eClientes_HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId);
 *
 * @brief crea, configura y almacena clientes
 * @param listaClientes
 * @param tamC
 * @param minId
 */
void eClientes_HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId);



#endif /* CLIENTES_H_ */
