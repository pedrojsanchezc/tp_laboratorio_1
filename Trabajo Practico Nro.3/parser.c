#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"
#include "parser.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int exito = 0;
	int lectura;
	char auxId[10];
	char auxNombre[128];
	char auxHorasTrabajadas[10];
	char auxSueldo[10];

	if(pFile!=NULL && pArrayListEmployee!=NULL){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
        while(!feof(pFile))
        {
        	lectura=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
            if(lectura==4)
            {
            	unEmpleado=employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                ll_add(pArrayListEmployee, unEmpleado);
                exito=1;
            }
            if(feof(pFile))
            {
                break;
            }

        }

        fclose(pFile);
        controller_ListEmployee(pArrayListEmployee);
        exito=1;
	}

    return exito;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int flag;
	int exito = 0;

	if(pFile!=NULL && pArrayListEmployee!=NULL){
        while(!feof(pFile))
        {
        	unEmpleado=employee_new();
            flag=fread(unEmpleado,sizeof(Employee),1,pFile);
            if(flag==1)
            {
                ll_add(pArrayListEmployee,unEmpleado);
            }

        }
        	exito=1;
        	fclose(pFile);
    }

    return exito;
}
