#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int resultado = -1;
    Employee* this = NULL;
    char idStr[20];
    char nombreStr[51];
    char horasTrabajadasStr[51];
    char sueldoStr[20];
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            this = employee_newParametrosTxt(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
            ll_add(pArrayListEmployee, this);
        }
        resultado = 0;
    }
    return resultado;
}
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int resultado = -1;
    Employee* this = NULL;
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            this = employee_new();
            if(this != NULL)
            {
                fread(this, sizeof(Employee), 1, pFile);
                if(feof(pFile))
                {
                    resultado = -1;
                    break;
                }
                ll_add(pArrayListEmployee, this);
            }
        }
        resultado = 0;
    }
    return resultado;
}
