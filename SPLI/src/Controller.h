/*
 * Controller.h
 *
 *  Created on: 30 nov. 2021
 *      Author: pedro_000
 */

#include "Libros.h"
#include "Editorial.h"
#include "LinkedList.h"
#include "Parser.h"
#include "Menu.h"
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

int controller_loadFromTextLibros(LinkedList* pArrayListLibros);
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales);
int controller_sortAutorAscendente(LinkedList* pArrayListLibros, LinkedList* pArrayListEditorial);
int controller_ListLibros(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_filtrarMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_mapeo(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
int controller_loadFromTextEditoriales(LinkedList* pArrayListEditoriales);


#endif /* CONTROLLER_H_ */
