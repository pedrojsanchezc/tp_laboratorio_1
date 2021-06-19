#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int exit=0;

    pFile=(FILE*)malloc(sizeof(FILE));
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            exit=parser_EmployeeFromText(pFile , pArrayListEmployee);


        }


    }

    return exit;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int exit=0;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"rb");

        if(pFile!=NULL)
        {
            exit=parser_EmployeeFromBinary(pFile , pArrayListEmployee);
        }else
        {
            pFile=fopen(path,"wb");
        }
    }

    return exit;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int exit=0;
    int len;
    int id;
    char auxId[20];
    char auxNombre[128];
    char auxHorasTrabajadas[20];
    char auxSueldo[20];
    Employee* unEmpleado;


    len=ll_len(pArrayListEmployee);

    if(pArrayListEmployee!=NULL)
    {
        unEmpleado=employee_new();
        if(unEmpleado!=NULL)
        {
            id=len+2;
            employee_setId(unEmpleado,id);
            itoa(id,auxId,10);
            printf("Ingrese el nombre");
            fflush(stdin);
            scanf("%[^\n]",auxNombre);

            printf("Ingrese horas de trabajo Realizadas:");
            fflush(stdin);
            scanf("%[^\n]",auxHorasTrabajadas);

            printf("Ingrese el sueldo:");
            fflush(stdin);
            scanf("%[^\n]",auxSueldo);

            unEmpleado=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            ll_add(pArrayListEmployee,unEmpleado);
            printf("\nEmpleado cargado correctamente\n");
        }
        exit=1;
    }


    return exit;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int index;
    int opcion;
    char auxNombre[20];
    int auxHorasTrabajo;
    int auxSueldo;
    Employee* unEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del empleado a modificar:\n");
        scanf("%d",&auxId);

      if(index!=-1)
      {
        unEmpleado=(Employee*)ll_get(pArrayListEmployee,index);
        printf("OPCIÓN A MODIFICAR:\n");
        printf("1. PARA NOMBRE \n 2. PARA HORAS \n y 3. PARA SUELDO\n");
        printf("\nElija una opcion:");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>3)
        {
            printf("\nError, reingrese nuevamente");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                    printf("Ingrese nombre nuevo:");
                    fflush(stdin);
                    scanf("%[^\n]", auxNombre);
                    employee_setNombre(unEmpleado,auxNombre);
                    printf("Empleado modificado exitosamente\n");
            break;
            case 2:
                    printf("Ingrese horas de trabajo nuevas:\n");
                    scanf("%d", &auxHorasTrabajo);
                    employee_setHorasTrabajadas(unEmpleado,auxHorasTrabajo);
                    printf("Horas de trabajo modificadas exitosamente\n");
            break;
            case 3:
                    printf("Ingrese su nuevo sueldo: ");
                    scanf("%d", &auxSueldo);
                    employee_setSueldo(unEmpleado,auxSueldo);
                    printf("\nSueldo modificado con exito\n");
            break;
        }
      }
    }
    return index;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int auxId;
    int opcion;
    int index;
    Employee* auxEmpleado;

    if(pArrayListEmployee!=NULL)
    {
        controller_ListEmployee(pArrayListEmployee);

        printf("\nIngrese el ID del empleado a Eliminar:");
        scanf("%d",&auxId);
        printf("\nElija la opcion: ");
        scanf("%d",&opcion);

        while(opcion!=1 && opcion!=2)
        {
            printf("Error, reingrese la opcion:");
            printf("\nElija la opcion: ");
            scanf("%d",&opcion);
        }
        if(opcion==1)
        {
            if(index!=-1)
            {
                auxEmpleado=ll_pop(pArrayListEmployee,index);
                printf("\nEmpleado eliminado correctamente\n");
                printf("%5d %10s %6d %6d\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
            }
        }else
        {
          printf("Eliminacion no realizada correctamente\n");
        }
    }
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int exit;
    int len;
    int auxId;
    int auxHorasTrabajadas;
    int auxSueldo;
    char auxNombre[20];
    Employee* auxEmpleado;

    printf("ID - NOMBRE - HORAS - SUELDO\n\n");
    if(pArrayListEmployee!=NULL)
    {
        len=ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            auxEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(auxEmpleado,&auxId);
            employee_getNombre(auxEmpleado,auxNombre);
            employee_getHorasTrabajadas(auxEmpleado,&auxHorasTrabajadas);
            employee_getSueldo(auxEmpleado,&auxSueldo);
            printf("%2d %18s %7d %7d\n\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        }
        exit=1;
    }
    return exit;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    if(pArrayListEmployee!=NULL)
    {
        printf("\nComo le gustaria ordenar?\n");
        printf("\n1.Por Id ascendente\n2.Por Id descendente\n3.Por Nombre A->Z\n4.Por Nombre Z->A\n5.Por Sueldo ascendente\n6.Por Sueldo descendente\n7.Por Horas Trabajadas ascendente\n8.Por Horas Trabajadas descendente\n");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);

        while(opcion<1 || opcion>8)
        {
            printf("\nError, reingrese la opcion: ");
            scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                    ll_sort(pArrayListEmployee,employee_CompareById,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;
            case 2:
                    ll_sort(pArrayListEmployee,employee_CompareById,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;
            case 3:
                    ll_sort(pArrayListEmployee,employee_CompareByName,1);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;
            case 4:
                    ll_sort(pArrayListEmployee,employee_CompareByName,0);
                    controller_ListEmployee(pArrayListEmployee);
                    printf("\nEmpleados ordenados exitosamente\n");
            break;
        }
    }
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    FILE* pFile;
    Employee* Empleado;
    int len;
    int exit=0;
    int i;
    int auxId;
    char auxNombre[20];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");
        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<len;i++)
            {
                Empleado=(Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(Empleado,&auxId);
                employee_getNombre(Empleado,auxNombre);
                employee_getHorasTrabajadas(Empleado,&auxHorasTrabajadas);
                employee_getSueldo(Empleado,&auxSueldo);
                fprintf(pFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            }
            fclose(pFile);
        }
        exit = 1;
    }
    return exit;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* Empleado;
    int len;
    int exit=0;
    int i;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");
        if(pFile!=NULL)
        {
            len=ll_len(pArrayListEmployee);
            for(i=0;i<len;i++)
            {
                Empleado= (Employee*)ll_get(pArrayListEmployee,i);
                fwrite(Empleado,sizeof(Employee),1,pFile);
            }
            fclose(pFile);
        }
        exit=1;
    }
    return exit;
}
void Menu(void){
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf("10. Salir\n");
}
