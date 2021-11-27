/*
 * Cliente.h
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"
#include "Localidad.h"

#define TRUE 1
#define FALSE 0
#define ERROR_MSG "Error, reingrese el dato"
#define QTY_CLIENTE 100
#define QTY_REINTENTO 10
#define NOMBREEMPRESA_LEN 60
#define CUIT_LEN 12
#define DIRECCION_LEN 100
#define ID_NOEXISTE "\nEl id ingresado no existe"
#define CONTINUAR "Desea continuar?"
#define ERROR_ALTURA "\nError, reingrese la altura"
#define CLIENTE_NOTREMOVED "\nNo se ha eliminado ningun cliente"

typedef struct
{
	 int id;
	 char nombreEmpresa[NOMBREEMPRESA_LEN];
	 char cuit[CUIT_LEN];
	 char direccion[DIRECCION_LEN];
	 int idLocalidad;
	 int idOperador;
	 int isEmpty;
} Cliente;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Cliente* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initCliente(Cliente* list, int len);



/** \brief Searching an empty index
 * \param list Cliente* list Pointer to array of employees
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int findEmptyIndex(Cliente *list, int len);


/** \brief Asks the client's data
 * \param list Cliente* list Pointer to array of employees
 * \param int len Array length
 * \param int* id Pointer to id
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int cargarCliente(Cliente *list, int len, int *id);

/** \brief find an cliente by Id en returns the index position in array.
 *
 * \param list Cliente*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findClienteById(Cliente* list, int len, int id);


/** \brief prints the content of one Cliente
 *
 * \param list Cliente*
 * \return int 0 success, -1 error
 *
 */
int printCliente(Cliente* list);


/** \brief prints the content of cliente's list
 *
 * \param list Cliente*
 * \param length int
 * \return int 0 success, -1 error
 *
 */
int printClientes(Cliente* list, int length);


/** \brief for preloaded data
 *
 * \param list Cliente*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int hardcodearData(Cliente* list, int len);


/** \brief creates a menu for "alta"
 *
 * \param list Cliente*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
//int alta_menu(Cliente* list, int len);
int alta_menu(Cliente* list, int len, Localidad* localidadList, int localidadLen);

/** \brief identifies if there are any clients
 *
 * \param list Cliente
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int isClienteListEmpty(Cliente *list, int len);

/** \brief add in a existing list of clients the values received as parameters
 * in the first empty position
 * \param list Cliente*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */
//int addCliente(Cliente* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], char localidad[]);
int addCliente(Cliente* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], int idLocalidad);

/** \brief changes the different parameters of one client
 *
 * \param list Cliente*
 * \param len int
 * \return ; 0 success, -1 error
 *
 */
//int ModificarCliente(Cliente* list, int len);
int ModificarCliente(Cliente* list, int len, Localidad* localidadList, int localidadLen);

/** \brief Remove a client by Id (put isEmpty Flag in 1)
 *
 * \param list Cliente*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeCliente(Cliente* list, int len, int id);

#endif /* CLIENTE_H_ */
