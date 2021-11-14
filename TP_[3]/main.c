#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Inputs.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/
int main()
{
	setbuf(stdout,NULL);
	int opcion;
	int id=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	if(utn_getNumero("\n Menu"
							"\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto) "
							"\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario) "
							"\n3. Alta de empleado "
							"\n4. Modificar datos de empleado"
							"\n5. Baja de empleado"
							"\n6. Listar empleados"
							"\n7. Ordenar empleados"
							"\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
							"\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)"
							"\n10-SALIR","ERROR.\n",&opcion, 2, 1, 10)== 0){
				switch(opcion)
				{
				case 1:
					if(controller_loadFromText("data.csv", listaEmpleados)==0)
					{
						printf("\n EMPLEADOS CARGADOS CORRECTAMENTE");
						id= controller_getSecondId(listaEmpleados);
					}
					else{
						printf("\n NO SE PUDIERON CARGAR EMPLEADOS");
					}
					break;
				case 2:
					if(controller_loadFromBinary("data.bin", listaEmpleados)==0)
					{
						printf("\n EMPLEADOS CARGADOS CORRECTAMENTE");
						id= controller_getSecondId(listaEmpleados);
					}
					else{
						printf("\n NO SE PUDIERON CARGAR EMPLEADOS");
					}
					break;
				case 3:
					if(controller_addEmployee(listaEmpleados, &id)== -1)
					{
						printf("\n NO SE PUDIERON CARGAR EMPLEADOS");
					}
					break;
				case 4:
					if(controller_editEmployee(listaEmpleados)== -1)
					{
						printf("\n NO SE PUDIERON MODIFICAR EMPLEADOS");
					}
					break;
				case 5:
					if(controller_removeEmployee(listaEmpleados)== -1)
					{
						printf("\n NO SE PUDIERON ELIMINAR EMPLEADOS");
					}
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					if(controller_saveAsText("dataMod.csv", listaEmpleados)==0)
					{
						printf("\n ARCHIVO GUARDADO CORRECTAMENTE");
					}
					break;
				case 9:
					if(controller_saveAsBinary("data.bin", listaEmpleados)==0)
					{
						printf("\n ARCHIVO GUARDADO CORRECTAMENTE");
					}
					break;
				}
			}
		}while(opcion !=10);
return EXIT_SUCCESS;
}
