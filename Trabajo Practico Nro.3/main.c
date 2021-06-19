#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
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
    LinkedList* lista;
    int opcion;
    int exit;

    lista = ll_newLinkedList();

    do
    {
    	Menu();
        printf("\nElija una opcion:");
        scanf("%d",&opcion);
        while(opcion<1 || opcion>10)
        {
            printf("\nError, reingrese la opcion: ");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
            	exit=controller_loadFromText("data.csv" , lista);
                     if(exit==1)
                    {
                        printf("\nCarga exitosa\n");
                    }else
                    {
                        printf("\nArchivo Inexistene\n");
                    }
            break;
            case 2:
            	exit=controller_loadFromBinary("data.dat" , lista);
                     if(exit==1)
                    {
                         printf("\nCarga exitosa\n");
                    }else
                    {
                       printf("\nArchivo Inexistene, se creara un archivo\n");
                    }
            break;
            case 3:
                    controller_addEmployee(lista);
            break;
            case 4:
                    controller_editEmployee(lista);
            break;
            case 5:
                    controller_removeEmployee(lista);
            break;
            case 6:
                    controller_ListEmployee(lista);
            break;
            case 7:
                    controller_sortEmployee(lista);
            break;
            case 8:
            	exit=controller_saveAsText("data.csv" , lista);
                    if(exit==1)
                    {
                        printf("\nGuardado con exito\n");
                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }
            break;
            case 9:
            	exit=controller_saveAsBinary("data.dat" , lista);
                    if(exit==1)
                    {
                        printf("\nGuardado con exito\n");
                    }else
                    {
                       printf("\nNo se pudo mostrar\n");
                    }
            break;
            case 10:
                    printf("\nFinalizado\n");
            break;
        }
    }while(opcion!=10);
    return 0;
}

