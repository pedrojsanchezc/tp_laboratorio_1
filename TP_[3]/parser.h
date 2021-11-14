/*
 * parser.h
 *
 *  Created on: 13 nov. 2021
 *      Author: pedro_000
 */
#ifndef PARSER_H_
#define PARSER_H_
#include "LinkedList.h"
/** \brief Esta funcion realiza la carga de datos desde un archivo a una lista dinamica, en modo texto
 *
 * \param pFile FILE* El puntero al archivo desde donde se realiza la carga
 * \param pArrayListEmployee LinkedList* La lista dinamica a cargar
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, devuelve 0 si pudo realizar la carga de datos
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
/** \brief Esta funcion realiza la carga de datos desde un archivo a una lista dinamica, en modo binario
 *
 * \param pFile FILE* El puntero al archivo desde donde se realiza la carga
 * \param pArrayListEmployee LinkedList* La lista dinamica a cargar
 * \return int Devuelve -1 si la lista o el puntero al archivo son nulos, devuelve 0 si pudo realizar la carga de datos
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
#endif /* PARSER_H_ */
