#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Inputs.h"
/*  Secundarias */
static int employee_inicializadorId(void);
static int employee_buscarEspacio(Employee list[], int limit);
static int employee_print(Employee* list, int len);
static int sortEmployees(Employee *list, int len, int order);
static int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
static int findEmployeeById(Employee *list, int len, int id);
static int employee_average(Employee *list, int len, int salarioAverage, int *pResult);
static int employee_salarioTotal(Employee *list, int len, float *pemployee_salarioTotal, float *pAverage);
static int removeEmployee(Employee* list, int len, int id);
static int employee_buscarEmpty(Employee *list, int len);
static int employee_convertidorStrings(char *string);
/**
 * \brief Function to add an employee asking for name, last name, salary and sector. ID is generated automatically
 * \param Employee *list: Pointer to an employee array
 * \param int len: employee array length
 * \return (-1) if something went wrong, (0) if everything is OK.
 */
int employee_addEmployee(Employee *list, int len)
{
	int resultado = -1;
	Employee auxEmployee;
	if(list != NULL && len > 0)
	{
		if(employee_buscarEspacio(list, len) >= 0 && utn_getString("INGRESE NOMBRE DEL EMPLEADO: ",
				"\n ERROR. REINGRESE NOMBRE DEL EMPLEADO: ",
				auxEmployee.name, 2, TAM) == 0 &&
		   utn_getString("INGRESE APELLIDO DEL EMPLEADO: ",
				   "\n ERROR. REINGRESE APELLIDO DEL EMPLEADO: ",
				   auxEmployee.lastName, 2, TAM) == 0 &&
		   utn_getFloat("\n INGRESE SALARIO DEL EMPLEAD: ",
				   "\n ERROR. REINGRESE SALARIO VALIDO DEL EMPLEADO: ",
				   &auxEmployee.salary, 2, MENOR_SALARIO, LONG_MAX) == 0 &&
		   utn_getInt("\n INGRESE SECTOR DEL EMPLEADO EN NUMERO [0-999]: ",
				   "\n ERROR. REINGRESE SECTOR DEL EMPLEADO EN NUMERO [0-999]: ",
				   &auxEmployee.sector, 2, 0, 999) == 0)
		{
			auxEmployee.id = employee_inicializadorId();
			if(addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector) == 0)
			{
				resultado = 0;
			}
		}
	}
	return resultado;
}
/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \param int id: receive the id
 * \param char name[]: receive the name to give to a new employee
 * \param char lastName[]: receive the last name to give to a new employee
 * \param float salary: receive the salary to give to a new employee
 * \param int sector: receive the sector to give to a new employee
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */
static int addEmployee(Employee *list, int len, int id, char name[],char lastName[], float salary, int sector)
{
	int resultado = -1;
	int auxEmployee = employee_buscarEspacio(list, len);

	strncpy(list[auxEmployee].name, name, TAM);
	strncpy(list[auxEmployee].lastName, lastName, TAM);

	employee_convertidorStrings(list[auxEmployee].name);
	employee_convertidorStrings(list[auxEmployee].lastName);

	list[auxEmployee].id = id;
	list[auxEmployee].salary = salary;
	list[auxEmployee].sector = sector;
	list[auxEmployee].isEmpty = FALSE;

	resultado = 0;

	return resultado;
}
/**
 * \brief Function to modify an employee searched by ID
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int employee_modifyEmployee(Employee *list, int len)
{
	int resultado = -1;
	int auxEmployee;
	int id;
	int opcion;
	if(list != NULL && len > 0 && employee_buscarEmpty(list, len) == 0)
	{
		employee_print(list, len);
		if(utn_getInt("\n INGRESE ID A MODIFICAR DEL EMPLEADO: ",
				"\n ERROR. REINGRESE EL ID A MODIFICAR DEL EMPLEADO: ", &id, 2, 0, 999) == 0)
		{
			auxEmployee = findEmployeeById(list, len, id);
			if(auxEmployee >= 0)
			{
				printf("\n DATOS DE ID BUSCADO: \n NOMBRE: %s, APELLIDO: %s, SALARIO: %.2f, SECTOR: %d",
						list[auxEmployee].name,
						list[auxEmployee].lastName,
						list[auxEmployee].salary,
						list[auxEmployee].sector);
				do
				{
					if(list[auxEmployee].isEmpty == FALSE && utn_getInt("\n QUE DESEA CAMBIAR? \n 1) NOMBRE \n 2) APELLIDO \n 3) SALARIO \n 4) SECTOR \n 5) SALIR. ",
							"\n ERROR. REINGRESE UN NUMERO [1 - 5]:",
							&opcion, 2, 1, 5) == 0)
					{
						switch(opcion)
						{
							case 1:
								if(utn_getString("INGRESE NUEVO NOMBRE: ",
										"\n ERROR. REINGRESE NUEVO NOMBRE: ",
													list[auxEmployee].name, 2, TAM) == 0)
								{
									printf("\n NUEVO NOMBRE MODIFICADO, ES: %s", list[auxEmployee].name);
									resultado = 0;
								}
								else
								{
									printf("\n ERROR. REINTENTE: ");
								}
							break;
							case 2:
								if(utn_getString("INGRESE NUEVO APELLIDO: ",
										"\n ERROR. REINGRESE NUEVO APELLIDO: ",
													list[auxEmployee].lastName, 2, len) == 0)
								{
									printf("\n NUEVO APELLIDO MODIFICADO, ES: %s", list[auxEmployee].lastName);
									resultado = 0;
								}
								else
								{
									printf("\n ERROR. REINTENTE: ");
								}
							break;
							case 3:
								if(utn_getFloat("INGRESE NUEVO SALARIO: ",
										"\n ERROR. REINGRESE NUEVO SALARIO: ",
													&list[auxEmployee].salary, 2, MENOR_SALARIO, LONG_MAX) == 0)
								{
									printf("\n NUEVO SALARIO MODIFICADO, ES: %.2f",
											list[auxEmployee].salary);
									resultado = 0;
								}
								else
								{
									printf("\n ERROR. REINTENTE: ");
								}
							break;
							case 4:
							if(utn_getInt("INGRESE NUEVO SECTOR: ",
									"\n ERROR. REINGRESE NUEVO SECTOR: ",
													&list[auxEmployee].sector, 2, 0, 500) == 0)
								{
									printf("\n NUEVO SECTOR MODIFICADO, ES: %d", list[auxEmployee].sector);
									resultado = 0;
								}
								else
								{
									printf("\n ERROR. REINTENTE:");
								}
							break;
						}
					}
					break;
				}while(opcion != 5);
			}
			else
			{
				printf("\n ERROR. EL ID INGRESADO NO EXISTE, REINTENTE NUEVAMENTE: ");
			}
		}
	}
	return resultado;
}
/**
 * \brief Function to modify an employee searched by ID
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int employee_removeEmployee(Employee *list, int len)
{
	int resultado = -1;
	int id;
	if(list != NULL && len > 0 && employee_buscarEmpty(list, len) == 0)
	{
		employee_print(list, len);
		if(utn_getInt("\n INGRESE ID A ELIMINAR: ",
				"\n ERROR. REINGRESE ID EXISTENTE A ELIMINAR: ", &id, 2, 1, 999) == 0 &&
				removeEmployee(list, len, id) == 0)
		{
			resultado = 0;
			printf("\n ID CORRECTO, ELIMINANDO.");
		}
		else
		{
			printf("\n ERROR , ID NO ENCONTRADO.");
		}
	}
	return resultado;
}
/**
 * \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \param int id: receive an id
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
static int removeEmployee(Employee* list, int len, int id)
{
	int resultado = -1;
	int auxEmployee;
	if(list != NULL && len > 0)
	{
		auxEmployee = findEmployeeById(list, len, id);
		if(auxEmployee >= 0
				&& list[auxEmployee].isEmpty == FALSE)
		{
			list[auxEmployee].isEmpty = TRUE;
			resultado = 0;
		}
	}
	return resultado;
}
/**
 * \brief Function to print all the employees in the array
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
static int employee_print(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0)
	{
		printf("\n ************************************************************ ");
		printf("\n ************************************************************");
		printf("\n  ID  -    NOMBRE      -        APELLIDO      -            SALARIO    -       SECTOR");
		printf("\n ************************************************************");
		printf("\n ************************************************************");
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				printf("\n%-6d%-20s%-20s%-15.2f%-4d",
						list[i].id,
						list[i].name,
						list[i].lastName,
						list[i].salary,
						list[i].sector);
				retorno = 0;
			}
		}
		printf("\n ************************************************************ \n");
	}
	return retorno;
}
/**
 * \brief Function to report by printing: list of employees (ascendent or descendent), salary accumulated of all employees, the average of salary
 *        and how many emplooyes surpass the average
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int employee_Ordenamiento(Employee *list, int len)
{
	int resultado = -1;
	int order;
	int opcion;
	float salaryTotal;
	float salarioAverage;
	int contadorAverage;
	if(list != NULL && len > 0 &&
			employee_buscarEmpty(list, len) == 0)
	{
		if(utn_getInt("\n OPCION A ELEGIR: \n 1) ORDENAR LISTADO DE EMPLEADOS POR APELLIDO."
				"\n 2) TOTAL DE LOS SALARIOS Y SU PROMEDIO, CANTIDAD DE EMPLEADOS CON SALARIO PROMEDIO. \n",
				"\n ERROR! REINGRESE OPCION A ELEGIR:",
				&opcion, 2, 1, 3) == 0)
		{
			switch(opcion)
			{
			case 1:
				if(utn_getInt("\n INGRESE OPCIONA ORDENAR: \n 0) FORMA DESCENDENTE \n 1) FORMA ASCENDENTE ",
										  "\n ERROR. REINGRESE OPCION VALIDA DE ORDENAR:",
										  &order, 2, 0, 1) == 0 &&
				   sortEmployees(list, len, order) == 0)
				{
					employee_print(list, len);
				}
				resultado = 0;
			break;
			case 2:
				if(employee_salarioTotal(list, len, &salaryTotal, &salarioAverage) == 0 &&
						employee_average(list, len, salarioAverage, &contadorAverage) == 0)
				{
					printf("\n SALARIO TOTAL ES: %.2f",
							salaryTotal);
					printf("\n EL PROMEDIO DEL SALARIO TOTAL ES: %.2f",
							salarioAverage);
					printf("\n  CANTIDAD QUE SUPERAN EL SALARIO TOTAL ES DE  %d EMPLEADOS",
							contadorAverage);
				}
				resultado = 0;
			break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Function to search in the Employee array for an empty field
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
static int employee_buscarEmpty(Employee *list, int len)
{
	int resultado = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				resultado = 0;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Function to sort the list of employees by ascendent (0) or descendent(1)
 * \param Employee *list: Pointer the an Employee array
 * \param int len: Length of the array
 * \param int order: Number we receive to determine if the list is going to sort ascendent or descendent
 * \return (-1) if something went wrong, (0) if everything is OK
 */
static int sortEmployees(Employee *list, int len, int order)
{
	int resultado = -1;
	Employee auxEmployeeSwap;
	int auxEmployeeFlag;
	if(list != NULL
			&& len > 0
			&& (order == 1 || order == 0))
	{
		do
		{
			auxEmployeeFlag = 0;
			for(int i=0; i<len-1; i++)
			{
				if( (order == 1 && ( (strncmp(list[i].lastName,
						list[i+1].lastName, TAM) > 0) ||
					(strncmp(list[i].lastName,
							list[i+1].lastName, TAM) == 0 && list[i].sector > list[i+1].sector)))
						||
					(order == 0 && ( (strncmp(list[i].lastName,
							list[i+1].lastName, TAM) < 0) ||
					(strncmp(list[i].lastName, list[i+1].lastName, TAM) == 0 && list[i].sector < list[i+1].sector))))
				{
					auxEmployeeSwap = list[i];
					list[i] = list[i+1];
					list[i+1] = auxEmployeeSwap;
					auxEmployeeFlag = 1;
					resultado = 0;
				}
			}
		}while(auxEmployeeFlag);
	}
	return resultado;
}
/**
 * \brief Function to calculate the salary's accumulated of all employees and the average
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \param float *pemployee_salarioTotal: Pointer of the salary's total accumulated of all employees
 * \param float *pAverage: Pointer of the salary average
 * \return (-1) if something went wrong, (0) if everything is OK
 */
static int employee_salarioTotal(Employee *list, int len, float *pemployee_salarioTotal, float *pAverage)
{
	int resultado = -1;
	float acumuladorSalario=0;
	int contadorSalario=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumuladorSalario += list[i].salary;
				contadorSalario++;
			}
		}
		*pemployee_salarioTotal = acumuladorSalario;
		*pAverage = acumuladorSalario / contadorSalario;
		resultado = 0;
	}
	return resultado;
}
/**
 * \brief Function to calculate how many employees surpass the salary average
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \param int salarioAverage: receive the salary average
 * \param int *pResult: Pointer of the result of how many employees surpass the average
 *\return (-1) if something went wrong, (0) if everything is OK
 */
static int employee_average(Employee *list, int len, int salarioAverage, int *pResult)
{
	int resultado = -1;
	int contadorAverage=0;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty == FALSE &&
					list[i].salary > salarioAverage)
			{
				contadorAverage++;
			}
		}
		*pResult = contadorAverage;
		resultado = 0;
	}
	return resultado;
}
/**
 * \brief Function to init isEmpty to TRUE of an Employee array
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return (-1) if something went wrong, (0) if everything is OK
 */
int initEmployees(Employee* list, int len)
{
	int resultado = -1;
	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = TRUE;
			list[i].id = -1;
		}
		resultado = 0;
	}
	return resultado;
}
/**
 * \brief Function that returns the first auxEmployee found on an Employee array that is empty
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \return the auxEmployee of an empty employee or (-1) if something went wrong
 */
static int employee_buscarEspacio(Employee *list, int len)
{
	int resultado = -1;
	if(list != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE &&
					list[i].id == -1)
			{
				resultado = i;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Function to auto-generate an ID
 * \return the id
 */
static int employee_inicializadorId(void)
{
	static int id=0;
	id = id+1;
	return id;
}
/**
 * \brief Function to find an employee auxEmployee receiving an id
 * \param Employee *list: Pointer to an Employee array
 * \param int len: Length of the array
 * \param int id: receive the id to be searched
 * \return the auxEmployee or (-1) if something went wrong
 */
static int findEmployeeById(Employee *list, int len, int id)
{
	int resultado = -1;
	if(list != NULL &&
			len > 0 && id > 0)
	{
		for(int i=0; i < len; i++)
		{
			if(list[i].id == id &&
					list[i].isEmpty == FALSE)
			{
				resultado = i;
				break;
			}
		}
	}
	return resultado;
}
/**
 * \brief Function to converts an string to lowercase and it first letter to uppercase
 * \param char *string: receive an string, preferents a name
 */
static int employee_convertidorStrings(char *string)
{
	int resultado = -1;
	char auxEmployeeBuffName[TAM];
	strncpy(auxEmployeeBuffName, string, TAM);
	auxEmployeeBuffName[0] = toupper(auxEmployeeBuffName[0]);
	for(int i=1;i<TAM;i++)
	{
		auxEmployeeBuffName[i] = tolower(auxEmployeeBuffName[i]);
	}
	strncpy(string, auxEmployeeBuffName, TAM);
	resultado = 0;
	return resultado;
}
