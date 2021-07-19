#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* aEmployee;

    aEmployee = (Employee*)calloc(1, sizeof(Employee));

    return aEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* aEmployee;
	int auxId;
	int auxHorasTrabajadas;
	int auxSueldo;

	aEmployee = employee_new();

	if (aEmployee != NULL)
	{
		auxId = atoi(idStr);
		employee_setId (aEmployee, &auxId);
		employee_setNombre (aEmployee, nombreStr);
		auxHorasTrabajadas = atoi(horasTrabajadasStr);
		employee_setHorasTrabajadas (aEmployee, &auxHorasTrabajadas);
		auxSueldo = atoi (sueldoStr);
		employee_setSueldo (aEmployee, &auxSueldo);
	}

	return aEmployee;
}


int employee_setId(Employee* this,int* id)
{
	int rtn;

	rtn = 0;

	if (id > 0 && this != NULL)
	{
		this->id = *id;
		rtn = 1;
	}
	return rtn;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int rtn;

	rtn = 0;

	if (this != NULL)
	{
		strcpy (this->nombre, nombre);
		rtn = 1;
	}
	return rtn;
}


int employee_setHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int rtn;

	rtn = 0;

	if (this != NULL && *horasTrabajadas > -1)
	{
		this->horasTrabajadas = *horasTrabajadas;
		rtn = 1;
	}
	return rtn;
}


int employee_setSueldo(Employee* this,int* sueldo)
{
	int rtn;

	rtn = 0;

	if (this != NULL && sueldo > 0)
	{
		this->sueldo = *sueldo;
		rtn = 1;
	}
	return rtn;
}


int employee_getId(Employee* this,int* id)
{
	int rtn;

	rtn = 0;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		rtn = 1;
	}
	return rtn;
}


int employee_getNombre(Employee* this,char* nombre)
{
    int rtn;

    rtn = 0;

    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);

        rtn = 1;
    }

    return rtn;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
     int rtn;

     rtn = 0;

    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        rtn = 1;
    }

    return rtn;
}


int employee_getSueldo(Employee* this,int* sueldo)
{
    int rtn;

    rtn = 0;

    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        rtn = 1;
    }

    return rtn;
}

void employee_delete(Employee* aEmployee)
{
	if(aEmployee != NULL)
	{
		free(aEmployee);
	}
}

int employee_printEmployee (Employee* this)
{
	int rtn = 0;
	int id;
	char nombre[30];
	int horasTrabajdas;
	int sueldo;

	if (this != NULL)
	{
		employee_getId (this, &id);
		employee_getNombre (this, nombre);
		employee_getHorasTrabajadas (this, &horasTrabajdas);
		employee_getSueldo (this, &sueldo);

		printf("%d  %s  %d  %d\n", id, nombre, horasTrabajdas, sueldo);
		rtn = 1;
	}
	return rtn;
}

int employee_SortId (void* employee1, void* employee2)
{
	int rtn = -2;
	int numero1;
	int numero2;

	if (employee1 != NULL && employee2 != NULL)
	{
		employee_getId ((Employee*)employee1, &numero1);
		employee_getId ((Employee*)employee2, &numero2);

		if (numero1 > numero2)
		{
			rtn = 1;
		}
		else
		{
			if (numero1 < numero2)
			{
				rtn = -1;
			}
			else
			{
				rtn = 0;
			}
		}
	}
	return rtn;
}

int employee_SortHours (void* employee1, void* employee2)
{
	int rtn = -2;
	int numero1;
	int numero2;

	if (employee1 != NULL && employee2 != NULL)
	{
		employee_getHorasTrabajadas ((Employee*)employee1, &numero1);
		employee_getHorasTrabajadas ((Employee*)employee2, &numero2);

		if (numero1 > numero2)
		{
			rtn = 1;
		}
		else
		{
			if (numero1 < numero2)
			{
				rtn = -1;
			}
			else
			{
				rtn = 0;
			}
		}
	}
	return rtn;
}

int employee_SortSalary (void* employee1, void* employee2)
{
	int rtn = -2;
	int numero1;
	int numero2;

	if (employee1 != NULL && employee2 != NULL)
	{
		employee_getSueldo ((Employee*)employee1, &numero1);
		employee_getSueldo ((Employee*)employee2, &numero2);

		if (numero1 > numero2)
		{
			rtn = 1;
		}
		else
		{
			if (numero1 < numero2)
			{
				rtn = -1;
			}
			else
			{
				rtn = 0;
			}
		}
	}
	return rtn;
}

int employee_SortName (void* employee1, void* employee2)
{
	int rtn;
	char string1[30];
	char string2[30];

	if (employee1 != NULL && employee2 != NULL)
	{
		employee_getNombre ((Employee*)employee1, string1);
		employee_getNombre ((Employee*)employee2, string2);
		rtn = strcmp (string1, string2);
	}
	return rtn;
}
