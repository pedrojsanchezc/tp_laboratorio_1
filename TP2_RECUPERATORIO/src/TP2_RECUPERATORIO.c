/*
 ============================================================================
 Name        : TP2_RECUPERATORIO.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define MAX_EMPLOYEES 1000
#define MAX_INTENTOS 3
#define TRUE 1
#define FALSE 0

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int flagAlta=FALSE;

	Employee arrayEmployees[MAX_EMPLOYEES];

	if(employees_init(arrayEmployees,MAX_EMPLOYEES)==0)
	{
		do
		{
			if(utn_getNumeroString("\n  1-Alta"
					"\n  2-Modificar"
					"\n  3-Baja "
				    "\n  4-Informe"
				    "\n  5-Salir\n"
				    "\n  Ingrese opción:",
					"Reingrese una opcion valida",&opcion,MAX_INTENTOS,1,5)==0)
			{
				switch(opcion)
				{
					case 1:
						   if(employee_createNew(arrayEmployees,MAX_EMPLOYEES)==0)
						   {
							   printf("ALTA DE EMPLEADO EXITOSA\n");
							   flagAlta=TRUE;
						   }
						   else
						   {
							   printf("NO SE REALIZO  CORRECTAMENTE LA ALTA DE EMPLEADO \n");
						   }
						break;
					case 2:
						if(flagAlta==TRUE)
						{
							if(employee_modifify(arrayEmployees,MAX_EMPLOYEES)==0)
							{
								printf("MODIFICACION DE EMPLEADO EXITOSA\n");
							}
							else
							{
								printf("MODIFICACION INCORRECTA\n");
							}
						}
						else
						{
							printf("NO DIO DE ALTA A NINGUN EMPLEADO\n");
						}
					break;
					case 3:
						if(flagAlta==TRUE)
						{
							if(employee_remove(arrayEmployees,MAX_EMPLOYEES)==0)
							{
								 printf("BAJA DE EMPLEADO EXITOSA\n");
							}
							else
							{
								printf("BAJA DE EMPLEADO INCORRECTA\n");
							}
						}
						else
						{
							printf("NO DIO DE ALTA A NINGUN EMPLEADO\n");
						}
					break;
					case 4:
						 if(flagAlta==TRUE)
						 {
							 employees_reporting(arrayEmployees,MAX_EMPLOYEES);
						 }
						 else
						 {
							 printf("NO DIO DE ALTA NINGUN EMPLEADO\n");
						 }
					break;
				}
			}
		}while(opcion!=5);
	}
	return EXIT_SUCCESS;
}
