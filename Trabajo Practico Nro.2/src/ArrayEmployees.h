#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EGEN_H_
#define EGEN_H_

//*** DEFINE
#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

//*** ESTRUCTURA
typedef struct {
	 int id;
	 char name[51];
	 char lastName[51];
	 float salary;
	 int sector;
	 int isEmpty;

} eEmployee;
//***

/** INICIO CABECERAS DE FUNCION*/
void eEmployee_initEmployees(eEmployee array[], int TAM);
int eEmployee_ObtenerID(void);
int eEmployee_ObtenerIndexLibre(eEmployee array[], int TAM);
int eEmployee_findEmployeeById(eEmployee array[], int TAM, int ID);
void eEmployee_MostrarUno(eEmployee Employee);
int eEmployee_printEmployees(eEmployee array[], int TAM);
int eEmployee_MostrarDadosDeBaja(eEmployee array[], int TAM);
void Menu(void);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eEmployee_sortEmployees(eEmployee array[], int TAM, int criterio);

//ABM
eEmployee eEmployee_CargarDatos(void);
eEmployee eEmployee_ModificarUno(eEmployee Employee);
int eEmployee_addEmployees(eEmployee array[], int TAM);
int eEmployee_removeEmployee(eEmployee array[], int TAM);
int eEmployee_Modificacion(eEmployee array[], int TAM);
void OrdenApellido(eEmployee*, int TAM);
void PrioridadEmpleado(eEmployee*, int TAM);
void PrioridadSector(eEmployee*, int TAM);
void Orden(eEmployee*, int TAM);
int Cantidad(eEmployee*, int TAM);
int CantidadEmpleados(eEmployee*, int TAM);
float TotalSalario(eEmployee*, int TAM);
float PromedioSalario(eEmployee*, int TAM);
void MayorSueldo(eEmployee*, int TAM, float PromedioSalario);
/** FIN CABECERAS DE FUNCION*/
#endif
