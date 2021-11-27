/*
 * Relaciones.h
 *
 *  Created on: 26 nov. 2021
 *      Author: pedro_000
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "Cliente.h"
#include "Localidad.h"
#include "Operador.h"
#include "Pedido.h"
#include "Inputs.h"
#ifndef RELACIONES_H_
#define RELACIONES_H_

/** \brief Para ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirLocalidadPendiente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Muestra la cantidad de kilos de polipropileno reciclado promedio por cliente
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPromedioPPCliente(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirClientesConPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief Se imprimirá una lista de los pedidos que se encuentren en estado “Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPedidosPendientes(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/** \brief : Se imprimirá una lista de los pedidos que se encuentren en estado “Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo de plástico
 * \param pedidoList Pedido* Pointer to array of Pedido
 * \param pedidoLen int Pedido array size
 * \param clienteList Cliente* Pointer to array of Cliente
 * \param clienteLen int Cliente array size
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int informe_imprimirPedidosProcesados(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);

int informe_imprimirMaximo(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);
int informe_imprimirClientesConMasCompletos(Pedido *pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen);


/**
 * @fn void Operador_MostrarKGxOperador(Operador, Pedido)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listaOperador Array donde leer
 * @param *pedidoList Array donde leer
 */
void Operador_MostrarKGxOperador(Operador listaOperador, Pedido *pedidoList);

/**
 * @fn int Operador_MostrarTotalKgXoperador(Cliente*, int, Pedido*, int, Operador*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param list Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @param *pedidoList Array donde lee los datos
 * @param pedidoLen Tamaño del array recibido
 * @param listaOperador Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int Operador_MostrarTotalKgXoperador(Cliente* list, int len, Pedido* *pedidoList, int pedidoLen, Operador* listaOperador, int TAM);

#endif /* RELACIONES_H_ */
