/*
 * Costos.h
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Inputs.h"
#ifndef OPERADOR_H_
#define OPERADOR_H_
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

typedef struct{
	int id;
	int idPedido;
	char nombre[51];
	int dni;
	float salario;
	int isEmpty;
}Operador;

/**
 * @fn void hardcodearOperador(Operador*, int)
 * @brief Setea datos predefinidos en la estructura
 *
 * @param listaOperador Array donde escribir
 * @param TAM Tamaño del array
 */
void hardcodearOperador(Operador* listaOperador, int TAM);

/**
 * @fn void Operador_Inicializar(Operador*, int)
 * @brief Inicializa los indices como disponibles para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 */
void Operador_Inicializar(Operador* array, int TAM);

/**
 * @fn int Operador_ObtenerID(int)
 * @brief Recibe el ID inicial y lo incrementa tras cada entrada de datos
 *
 * @param lastID ID donde leer y escribir
 * @return ID actual
 */
int Operador_ObtenerID(int lastID);

/**
 * @fn int Operador_ObtenerIndexLibre(Operador*, int)
 * @brief Detecta cual es el primer indice disponible para escritura
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return El indice libre
 */
int Operador_ObtenerIndexLibre(Operador* array, int TAM);

/**
 * @fn int Operador_BuscarPorID(Operador*, int, int)
 * @brief Busca datos de un indice mediante su ID
 *
 * @param array Array donde escribir
 * @param TAM Tamaño del array
 * @return ID Recibe la ID a buscar
 * @return -1 si hubo un error; el indice si la busqueda fue exitosa
 */
int Operador_BuscarPorID(Operador* array, int TAM, int ID);

/**
 * @fn void Operador_MostrarUno(Operador)
 * @brief Imprime en pantalla todos los campos de la estructura del
 * indice del array recibido
 * @param listaOperador Array donde leer
 */
void Operador_MostrarUno(Operador listaOperador);

/**
 * @fn int Operador_MostrarTodos(Operador*, int)
 * @brief Muestra todos los datos cargados en un array de estructura
 *
 * @param array Array donde lee los datos
 * @param TAM Tamaño del array recibido
 * @return 0 si fue exitoso, 1 si falló
 */
int Operador_MostrarTodos(Operador* array, int TAM);

/**
 * @fn int Operador_Sort(Operador*, int, int)
 * @brief Ordena el array de datos por ascendente y descendente
 *
 * @param array Array que ordenar
 * @param TAM Tamaño del array recibido
 * @param criterio 1 para ascendente, -1 para descendente
 * @return 1 por ordenamiento exitoso, 0 por error
 */
int Operador_Sort(Operador* arrayS, int TAM, int criterio);
#endif /* OPERADOR_H_ */
