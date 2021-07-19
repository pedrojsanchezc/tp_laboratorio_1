#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Inputs.h"

void Menu(void)
{
	printf ("        MENU DE CARGA DE DATOS   \n");
	printf (" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
	printf (" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
	printf (" 3. Alta de empleado\n");
	printf (" 4. Modificar datos de empleado\n");
	printf (" 5. Baja de empleado\n");
	printf (" 6. Listar empleados\n");
	printf (" 7. Ordenar empleados\n");
	printf (" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
	printf (" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
	printf (" 10. Salir\n");
}

void SubMenu(void)
{
	printf (" Sub-Menu de ordenamiento \n ");
	printf (" 1. Ordenar por ID\n ");
	printf (" 2. Ordenar por NOMBRE\n ");
	printf (" 3. Ordenar por Horas Trabajadas\n ");
	printf (" 4. Ordenar por Sueldo\n ");
}
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int rtn;
	FILE* pFile;

	rtn = 0;

	ll_clear(pArrayListEmployee);

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "r");

		if (pFile != NULL)
		{
			rtn = parser_EmployeeFromText(pFile , pArrayListEmployee);
			printf("Archivo leido.\n");
		}
		else
		{
			printf("el archivo no existe.\n");
		}
		fclose (pFile);
	}
	else
	{
		printf ("LinkedList o Archivo invalidos.\n");
	}
    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn;
	FILE* pFile;

	rtn = 0;

	ll_clear(pArrayListEmployee);

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "rb");

		if (pFile != NULL)
		{
			rtn = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
		else
		{
			printf("el archivo no existe");
		}

		fclose (pFile);
	}
	else
	{
		printf ("LinkedList o Archivo invalidos");
	}
    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* lastId)
{
    int rtn = 0;
    Employee* aEmployee;
    int id;
    char nombre[30];
    int horasTrabajadas;
    int sueldo;

    id = *lastId;
    id = id+1;
    aEmployee = employee_new();

    if (pArrayListEmployee != NULL && aEmployee != NULL)
    {
    	Get_String("ingrese el nombre: \n", "ERROR. ingrese el nombre\n", nombre, 30);
    	Get_Int("ingrese la cantidad de horas trabajadas: \n", "ERROR. ingrese la cantidad de horas trabajadas: \n", &horasTrabajadas);
    	Get_Int("ingrese el sueldo: \n", "ERROR. ingrese el sueldo: \n", &sueldo);
    	employee_setId(aEmployee, &id);
    	employee_setNombre(aEmployee, nombre);
    	employee_setHorasTrabajadas(aEmployee, &horasTrabajadas);
    	employee_setSueldo(aEmployee, &sueldo);
    	ll_add(pArrayListEmployee, aEmployee);
     	*lastId = id;
    	rtn = 1;
    }
    else
    {
    	printf ("no se ha podido leer LinkedList");
    }
    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* aEmployee;
	int i;

	if (pArrayListEmployee != NULL)
	{
		aEmployee = employee_new();
		for (i=0; i<ll_len(pArrayListEmployee); i++)
		{
			aEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (aEmployee != NULL)
			{
				employee_printEmployee(aEmployee);
				rtn = 1;
			}
		}
	}
	else
	{
		printf ("LinkedList invalida");
	}
	return rtn;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int rtn = 0;
	Employee* aEmployee;
	int id;
	char nombre[30];
	int horasTrabajadas;
	int sueldo;
	int opcion;
	int i;
	int auxId;

	if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
	{
		controller_ListEmployee(pArrayListEmployee);
		Get_Int("ingrese id a modificar", "ERROR. ingrese id a modificar", &id);
		for (i=0; i<ll_len(pArrayListEmployee); i++)
		{
			aEmployee = employee_new();
			aEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			employee_getId(aEmployee, &auxId);
			if (auxId == id)
			{
				employee_printEmployee(aEmployee);
				if (Validate_Salir("esta seguro que desea modificar este empleado? s/n:\n", "ERROR. elija una opcion validad. s/n:\n"))
				{
					do
					{
						printf("SUBMENU DE MODIFICACION\n 1.Nombre\n 2.Horas Trabajadas\n 3.Sueldo\n 4.Salir\n");
						Get_IntMaxAndMin("ingrese la opcion requerida:\n", "ERROR. ingrese una opcion correcta", 1, 4, &opcion);

						switch (opcion)
						{
							case 1:
								Get_String ("ingrese nuevo nombre:\n", "ERROR. ingrese nuevo nombre:\n", nombre, 30);
								if (Validate_Salir("esta seguro que desea realizar el cambio? s/n:\n","ERROR. ingrese una opcion valida s/n:\n" ))
								{
									employee_setNombre (aEmployee, nombre);
								}
								else
								{
									printf ("el cambio no ha sido realizado...");
								}

								break;

							case 2:
								Get_Int ("ingrese cantidad de horas trabajadas: \n", "ERROR. cantidad de horas trabajadas: \n", &horasTrabajadas);
								if (Validate_Salir("esta seguro que desea realizar el cambio? s/n:\n","ERROR. ingrese una opcion valida s/n:\n" ))
								{
									employee_setHorasTrabajadas (aEmployee, &horasTrabajadas);
								}
								else
								{
									printf ("el cambio no ha sido realizado...");
								}

								break;

							case 3:
								Get_Int ("ingrese nuevo sueldo: \n", "ERROR. ingrese nuevo sueldo: \n", &sueldo);
								if (Validate_Salir("esta seguro que desea realizar el cambio? s/n:\n","ERROR. ingrese una opcion valida s/n:\n" ))
								{
									employee_setSueldo (aEmployee, &sueldo);
								}
								else
								{
									printf ("el cambio no ha sido realizado...");
								}
								break;
						}
					}while (opcion != 4);
					ll_set(pArrayListEmployee, i, aEmployee);
					rtn = 1;
				}
				break;
			}
		}
	}
	else
	{
		printf ("ERROR. no hay datos cargados para modificar!");
	}
    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* aEmployee;
	int idIngresado;
	int idEnArray;
	int i;
	int size;

	size = ll_len(pArrayListEmployee);

	if (pArrayListEmployee != NULL &&  size!= 0)
	{
		controller_ListEmployee(pArrayListEmployee);
		Get_Int("ingrese id a dar de baja", "ERROR. ingrese id a dar de baja", &idIngresado);
		aEmployee = employee_new();
		if (aEmployee != NULL)
		{
			for (i=0; i<size; i++)
			{
				aEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(aEmployee, &idEnArray);
				if (idEnArray == idIngresado)
				{
					employee_printEmployee(aEmployee);
					if (Validate_Salir("esta seguro que desea eliminar este empleado? s/n:\n", "ERROR. seleccione una opcion valida. s/n:\n"))
					{
						ll_remove(pArrayListEmployee, i);
						employee_delete(aEmployee);
						rtn = 1;
					}
					else
					{
						printf ("edicion de empleado cancelada.");
					}
				}
				else
				{
					printf ("el ID ingresado no ha sido encontrado");
				}
			}
		}
		else
		{
			printf ("no se ha podido crear variable en memoria");
		}
	}
	else
	{
		printf ("LinkedList vacia o invalida");
	}
    return rtn;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	int option;
	int criterio;

	if (pArrayListEmployee != NULL)
	{
		SubMenu();
		Get_IntMaxAndMin("Seleccione una opcion de ordenamiento: \n", "ERROR. Seleccione una opcion de ordenamiento: \n", 1, 4, &option);
		Get_IntMaxAndMin("Seleccione un criterio de ordenamiento:\n1. Ascendente\n2. Descendente\n", "ERROR. Seleccione un criterio de ordenamiento:\n1. Ascendente\n2. Descendente\n", 1, 2, &criterio);
		printf ("ORDENANDO. por favor espere...");
		switch (option)
		{
			case 1:
				if (criterio == 1)
				{
					ll_sort (pArrayListEmployee, employee_SortId, 1);
				}
				else
				{
					ll_sort (pArrayListEmployee, employee_SortId, 0);
				}
				break;

			case 2:
				if (criterio == 1)
				{
					ll_sort (pArrayListEmployee, employee_SortName, 1);
				}
				else
				{
					ll_sort (pArrayListEmployee, employee_SortName, 0);
				}
				break;

			case 3:
				if (criterio == 1)
				{
					ll_sort (pArrayListEmployee, employee_SortHours, 1);
				}
				else
				{
					ll_sort (pArrayListEmployee, employee_SortHours, 0);
				}
				break;

			case 4:
				if (criterio == 1)
				{
					ll_sort (pArrayListEmployee, employee_SortSalary, 1);
				}
				else
				{
					ll_sort (pArrayListEmployee, employee_SortSalary, 0);
				}
				break;
		}
		controller_ListEmployee(pArrayListEmployee);
		printf ("LISTA ORDENADA CON EXITO!.\n");
		rtn = 1;
	}
	else
	{
		printf ("ERROR. La lista recibida no existe");
	}

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	Employee* aEmployee;
	int size;
	int i;
	int auxId;
	char auxNombre[30];
	int auxHorasTrabajadas;
	int auxSueldo;
	int rtn = 0;


	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			size = ll_len(pArrayListEmployee);

			for (i=0; i<size; i++)
			{
				aEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId (aEmployee, &auxId);
				employee_getNombre (aEmployee, auxNombre);
				employee_getHorasTrabajadas (aEmployee, &auxHorasTrabajadas);
				employee_getSueldo (aEmployee, &auxSueldo);
				fprintf (pFile, "%d, %s, %d, %d\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
			}
			fclose(pFile);
			rtn = 1;
		}
		else
		{
			printf ("no se pudo abrir archivo");
		}
	}
	else
	{
		printf ("LinkedList o Archivo invalidos");
	}
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	FILE* pFile;
	Employee* aEmployee;
	int i;
	int size;

	if (path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");

		if (pFile != NULL)
		{
			size = ll_len(pArrayListEmployee);

			for (i=0; i<size; i++)
			{
				aEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(aEmployee, sizeof(Employee), 1, pFile);
			}
			fclose(pFile);
			rtn = 1;
		}
		else
		{
			printf ("no se pudo abrir archivo");
		}
	}
	else
	{
		printf ("LinkedList o Archivo invalidos");
	}
	return rtn;
}

int controller_GetLastId (char* path, int* lastId)
{
	FILE* pFile;
	int rtn = -1;

	pFile = fopen(path, "rb");

	if (pFile != NULL)
	{
		lastId = (int*)malloc(sizeof(int));
		fread (lastId, sizeof(int), 1, pFile);
		rtn = *lastId;
	}
	fclose(pFile);
	return rtn;
}

int controller_SaveLastId (char* path, int* lastId)
{
	FILE* pFile;
	int rtn = 0;

	pFile = fopen(path, "wb");

	if (pFile != NULL && lastId != NULL)
	{
		fwrite(lastId, sizeof(int), 1, pFile);
		rtn = 1;
	}
	fclose(pFile);

	return rtn;
}
