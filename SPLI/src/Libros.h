/*
 * Libros.h
 *
 *  Created on: 30 nov. 2021
 *      Author: pedro_000
 */

#ifndef LIBROS_H_
#define LIBROS_H_
#include "Inputs.h"
#include "Editorial.h"
typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    float precio;
    int idEditorial;
}eLibros;

eLibros* libros_new();
eLibros* libros_newParametros(char* id,char* titulo,char* autor, char* precio, char* idEditorial);
void libros_delete(eLibros* this);

int libros_setIdLibro(eLibros* this,int idLibro);
int libros_getIdLibro(eLibros* this,int* idLibro);

int libros_setTitulo(eLibros* this,char* titulo);
int libros_getTitulo(eLibros* this,char* titulo);

int libros_setAutor(eLibros* this,char* autor);
int libros_getAutor(eLibros* this,char* autor);

int libros_setPrecio(eLibros* this,float precio);
int libros_getPrecio(eLibros* this,float* precio);

int libros_setIdEditorial(eLibros* this,int idEditorial);
int libros_getIdEditorial(eLibros* this,int* idEditorial);

void libros_printLibros(eLibros* this, eEditorial* thisEditorial);
int libros_compareByAutor(void* emp1, void* emp2);
int libros_filtrarEditorialMinotauro(void* pElement);
int libros_preciosEditoriales(void* pElement);

#endif /* LIBROS_H_ */
