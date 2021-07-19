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
    setbuf(stdout, NULL);
    int opcion;

    int lastId;

    lastId = controller_GetLastId ("lastid.bin", &lastId);

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	Menu();

    	Get_IntMaxAndMin("Seleccione una opcion del Menu:\n","ERROR. Seleccione una opcion correcta: \n", 1, 10, &opcion);

        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);
                break;

            case 2:
            	controller_loadFromBinary("data.bin", listaEmpleados);
                break;

            case 3:
            	controller_addEmployee(listaEmpleados, &lastId);
                break;

            case 4:
            	controller_editEmployee(listaEmpleados);
                break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
                break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
                break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	controller_SaveLastId ("lastid.bin", &lastId);
                break;

            case 9:
            	controller_saveAsBinary("data.bin", listaEmpleados);
            	controller_SaveLastId ("lastid.bin", &lastId);
                break;

            case 10:
            	if (Validate_Salir ("esta seguro que desea salir? s/n\n", "ERROR. ingrese una opcion valida. s/n:\n"))
            	{
            		opcion = 0;
            	}
        }
    }while(opcion != 0);

    ll_deleteLinkedList(listaEmpleados);
    printf ("GRACIAS POR USAR");
    return 0;
}

