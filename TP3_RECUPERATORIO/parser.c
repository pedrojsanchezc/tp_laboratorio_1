#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* theEmployee;
	char id[10];
	char nombre[30];
	char horasTrabajadas[10];
	char sueldo[10];

	if (pArrayListEmployee != NULL && pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
			theEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			ll_add(pArrayListEmployee, theEmployee);
			rtn = 1;
		}while (!feof(pFile));
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* aEmployee = NULL;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		do
		{
			aEmployee = employee_new();
			if (fread(aEmployee, sizeof(Employee), 1, pFile))
			{
				ll_add (pArrayListEmployee, aEmployee);
				rtn = 1;
			}
		}while (!feof(pFile));
	}
    return rtn;
}
