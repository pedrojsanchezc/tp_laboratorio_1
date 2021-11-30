/*
 * Parser.h
 *
 *  Created on: 30 nov. 2021
 *      Author: pedro_000
 */
#include "LinkedList.h"
#include "Editorial.h"
#include "Libros.h"
#ifndef PARSER_H_
#define PARSER_H_

int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros);
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial);


#endif /* PARSER_H_ */
