/*
 ============================================================================
 Name        : ABM.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
#define TAM_ESTRUCTURA 1000

int main(void) {
	setbuf(stdout, NULL);

	int opc;
	int criterioDeOrdenamiento;

	eEmployee Employee[TAM_ESTRUCTURA];

	eEmployee_initEmployees(Employee, TAM_ESTRUCTURA);

	do {
		Menu();
		printf("INGRESE OPCION: ");
		scanf("%d", &opc);

		switch (opc)
		{
		case 0:
			opc = 0;
			break;
		case 1:
			if (eEmployee_addEmployees(Employee, TAM_ESTRUCTURA)) {
				puts(" * Employee DADO DE ALTA EXITOSAMENTE");
			} else {
				puts(" * ERROR. SIN ESPACIO PARA ALMACENAR MAS Employee");
			}
			system("pause");
			break;
		case 2:
			if (eEmployee_Modificacion(Employee, TAM_ESTRUCTURA)) {
				puts("\n * MODIFICACION DE Employee EXITOSA\n");
				eEmployee_printEmployees(Employee, TAM_ESTRUCTURA);
			} else {
				puts("\n * MODIFICACION DE Employee CANCELADA");
			}
			system("pause");
			break;
		case 3:
			if (eEmployee_removeEmployee(Employee, TAM_ESTRUCTURA)) {
				puts("\n * BAJA DE Employee EXITOSA");
				eEmployee_printEmployees(Employee, TAM_ESTRUCTURA);
			} else {
				puts("\n * BAJA DE Employee CANCELADA");
			}
			system("pause");
			break;
		case 4:
			if(CantidadEmpleados(Employee, TAM_ESTRUCTURA)){
				printf("\nLISTA DE EMPLEADOS\n\n");
				printf("%s\t\t\t\t\t%s\n", "[EMPLEADO]", "[SECTOR]");
				Orden(Employee, TAM_ESTRUCTURA);

				TotalSalario(Employee, TAM_ESTRUCTURA);
				PromedioSalario(Employee, TAM_ESTRUCTURA);

				printf("TOTAL Y PROMEDIO DE SUELDO\n");
                printf("TOTAL DE SALARIO");
                TotalSalario(Employee, TAM_ESTRUCTURA);
                printf("PROMEDIO DE SALARIO");
                PromedioSalario(Employee, TAM_ESTRUCTURA);
				system("pause");
				break;
			} else {
                printf("SIN DATOS PARA INFORMAR\n");
			system("pause");
			break;
        default:
            puts("OPCION NO VALIDA. REINGRESE DEL 1 AL 4\n");
            system("pause");
            system("cls");
            break;
			}
		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}

