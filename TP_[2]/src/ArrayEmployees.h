/*
 * ArrayEmployees.h
 *
 *  Created on: 15 nov. 2021
 *      Author: pedro_000
 */
#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define TAM 51
#define MENOR_SALARIO 0.00
#define MAYOR_SALARIO 99999999.00
#define TAM_EMPLEADOS 999
typedef struct
{
	int id;
	char name[TAM];
	char lastName[TAM];
	float salary;
	int sector;
	int isEmpty;
}Employee;
int initEmployees(Employee* list, int len);
int employee_addEmployee(Employee *list, int len);
int employee_modifyEmployee(Employee *list, int len);
int employee_removeEmployee(Employee *list, int len);
int employee_Ordenamiento(Employee *list, int len);
#endif /* ARRAYEMPLOYEES_H_ */
