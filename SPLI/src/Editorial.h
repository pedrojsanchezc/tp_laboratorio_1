/*
 * Editorial.h
 *
 *  Created on: 30 nov. 2021
 *      Author: pedro_000
 */
#include "Inputs.h"
#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
    int idEditorial;
    char nombre[128];
}eEditorial;

eEditorial* editorial_new();
eEditorial* editorial_newParametros(char* id,char* nombre);
void editorial_delete(eEditorial* this);
int editorial_setIdEditorial(eEditorial* this,int idEditorial);
int editorial_getIdEditorial(eEditorial* this,int* idEditorial);
int editorial_setNombre(eEditorial* this,char* nombre);
int editorial_getNombre(eEditorial* this,char* nombre);


#endif /* EDITORIAL_H_ */
