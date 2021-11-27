/*
 * Localidad.h
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Inputs.h"

#define TRUE 1
#define FALSE 0
#define ERROR_MSG_L "Error, reingrese el dato"
#define QTY_REINTENTO_L 10
#define NOMBRE_LEN 60
#define DIRECCION_LEN 100
#define ID_NOEXISTE_L "\nEl id ingresado no existe"
#define CONTINUAR "Desea continuar?"
#define LOCALIDAD_NOTREMOVED "\nNo se ha eliminado ninguna localidad"
#define QTY_LOCALIDAD 100

typedef struct
{
	 int id;
	 char nombre[NOMBRE_LEN];
	 int isEmpty;
} Localidad;


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Cliente* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initLocalidad(Localidad* list, int len);



/** \brief Searching an empty index
 * \param list Cliente* list Pointer to array of employees
 * \param int len Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int findEmptyIndexLocalidad(Localidad *list, int len);


/** \brief Asks the client's data
 * \param list Cliente* list Pointer to array of employees
 * \param int len Array length
 * \param int* id Pointer to id
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - return the empty id if Ok
 *
 */
int uploadLocalidad(Localidad *list, int len, int *id);


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
int addLocalidad(Localidad* list, int len, int id, char nombre[]);

/** \brief find an cliente by Id en returns the index position in array.
 *
 * \param list Cliente*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findLocalidadById(Localidad* list, int len, int id);


/** \brief prints the content of one Cliente
 *
 * \param list Cliente*
 * \return int 0 success, -1 error
 *
 */
int printLocalidad(Localidad* list);


/** \brief prints the content of cliente's list
 *
 * \param list Cliente*
 * \param length int
 * \return int 0 success, -1 error
 *
 */
int printLocalidades(Localidad* list, int length);


/** \brief for preloaded data
 *
 * \param list Cliente*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int hardcodearData_localidad(Localidad* list, int len);


/** \brief creates a menu for "alta"
 *
 * \param list Cliente*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int alta_menuLocalidad(Localidad* list, int len);


/** \brief identifies if there are any clients
 *
 * \param list Cliente
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int isLocalidadListEmpty(Localidad *list, int len);



/** \brief changes the different parameters of one client
 *
 * \param list Cliente*
 * \param len int
 * \return int 0 success, -1 error
 *
 */
int ModificarLocalidad(Localidad* list, int len);


/** \brief Remove a client by Id (put isEmpty Flag in 1)
 *
 * \param list Cliente*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeLocalidad(Localidad* list, int len, int id);

#endif /* LOCALIDAD_H_ */
