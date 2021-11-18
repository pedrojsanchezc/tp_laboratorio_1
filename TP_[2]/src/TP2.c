/*
 ============================================================================
 Name        : TP2.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	Employee arrayEmployees[TAM_EMPLEADOS];
	if(initEmployees(arrayEmployees, TAM_EMPLEADOS)==0)
	{
		do
		{
			menu(&opcion, 2, 1, 5);
			switch(opcion)
			{
				case 1:
					if(employee_addEmployee(arrayEmployees, TAM_EMPLEADOS) == 0)
					{
						printf("\n AGREGADO EMPLEADO CORRECTAMENTE. \n");
					}
					else
					{
						printf("\n ERROR.");
					}
				break;
				case 2:
					if(employee_modifyEmployee(arrayEmployees, TAM_EMPLEADOS) == 0)
					{
						printf("\n MODIFIACION DE EMPLEADO CORRECTAMENTE.");
					}
					else
					{
						printf("\n ERROR.");
					}
				break;
				case 3:
					if(employee_removeEmployee(arrayEmployees, TAM_EMPLEADOS) == 0 )
					{
						printf(" ELIMINACION DE EMPLEADO CORRECTAMENTE.");
					}
					else
					{
						printf("\n ERROR.");
					}
				break;
				case 4:
					if(employee_Ordenamiento(arrayEmployees, TAM_EMPLEADOS) == 0)
					{
						printf("\n ORDENAMIENTO DE EMPLEADO CORRECTAMENTE.");
					}
					else
					{
						printf("\n ERROR.");
					}
				break;
			}
		}while(opcion != 5);
	}
	printf("\n GRACIAS POR USAR");
	printf("\n *****************************************");
	printf("\n *****************************************");
	printf("\n *****************************************");
	printf("\n *******************  FIN *********************");
	return EXIT_SUCCESS;
}
