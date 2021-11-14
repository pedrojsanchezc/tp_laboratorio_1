#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "Inputs.h"
#include "parser.h"
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int resultado = 1;
    int isEmpty = 0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            resultado = parser_EmployeeFromText(pFile, pArrayListEmployee);
            fclose(pFile);
        }
        else
        {
            resultado = 2;
        }
    }
    return resultado;
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
    int resultado = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;
    pFile = fopen(path,"rb");
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty == 1)
        {
            resultado = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
        }
        else
        {
            resultado = 2;
        }
    }
    fclose(pFile);
    return resultado;
}
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee,  int* id)
{
    int resultado = -1;
    int isEmpty = 0;
    char nombre[51];
    char salario[51];
    char horasTrabajadas[51];
    char idStr[51];
    Employee* nuevo_Empleado;
    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty != 1)
        {
                printf("CARGA DE EMPLEADOS:\n");
                utn_getNombre("INGRESE NOMBRE DEL EMPLEADO: ", "\nERROR", nombre, 2, 51);
                utn_getString("INGRESE HORAS TRABAJADAS DEL EMPLEADO: ", "\nError", horasTrabajadas, 2, 51);
                utn_getString("INGRESE SUELDO DEL EMPLEADO: ", "\nERROR", salario, 2, 51);
                sprintf(idStr, "%d", *id);
                nuevo_Empleado = employee_newParametrosTxt(idStr, nombre, horasTrabajadas, salario);
                printf("DATOS INGRESADOS:\n");
				printf("%4s %18s %20s %20s\n", "ID:", "NOMBRE:", "HORAS TRABAJADAS:", "SUELDO:");
				employee_getPrintEmployee(nuevo_Empleado);
                if(nuevo_Empleado != NULL)
                {
                	resultado=0;
					ll_add(pArrayListEmployee, nuevo_Empleado);
					*id = *id+1;
                }
        }
        else{
        	printf("INGRESE DATOS PRIMERO.");
        }
    }
    return resultado;
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
    int resultado = -1;
    int isEmpty = 0;
    int id;
    int opcion;
    char auxNombre [51];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* empleadoAModificar;
    if(pArrayListEmployee != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListEmployee);
        if(isEmpty!= 1)
        {
            printf("LISTADO DE EMPLEADOS: \n");
            controller_ListEmployee(pArrayListEmployee);
            utn_getNumero("INGRESE EL ID DEL EMPLEADO PARA MODIFICAR: \n", "\nERROR", &id, 2, 0, 99999);
            empleadoAModificar = controller_getEmployeeId(pArrayListEmployee, id);
            if(empleadoAModificar != NULL)
            {
                printf("EMPLEADO A MODIFICAR: \n");
                printf("%4s %18s %20s %20s\n", "ID:", "NOMBRE:", "HORAS TRABAJADAS:", "SUELDO:");
                employee_getPrintEmployee(empleadoAModificar);
                do
                {
                	if(utn_getNumero("INGRESE OPCION: \n 1. CAMBIAR NOMBRE.\n 2. CAMBIAR HORAS TRABAJADAS.\n 3. CAMBIAR SUELDO. \n 4. SALIR.\n",
                					"\nError", &opcion, 2, 1, 4)==0)
                	{
						switch(opcion)
						{
						case 1:
							utn_getString("INGRESE UN NOMBRE: ", "\nERROR", auxNombre, 0, 51);
							employee_setNombre(empleadoAModificar, auxNombre);
							break;
						case 2:
							utn_getNumero("INGRESE CANTIDAD DE HORAS TRABAJADAS: ", "\nERROR", &auxHorasTrabajadas, 2, 0, 99999);
							employee_setHorasTrabajadas(empleadoAModificar, auxHorasTrabajadas);

							break;
						case 3:
							utn_getNumero("INGRESE SUELDO: ", "\nERROR", &auxSueldo, 2, 0, 99999);
							employee_setSueldo(empleadoAModificar, auxSueldo);
							break;
						}
                	}
                }
                while(opcion != 4);
            }
            printf("\n");
            printf(" CAMBIOS REALIZADOS:\n");
            printf("%4s %18s %20s %20s\n", "ID:", "NOMBRE:", "HORAS TRABAJADAS:", "SUELDO:");
            employee_getPrintEmployee(empleadoAModificar);
            resultado=0;
        }
        else
        {
        	printf("INGRESE DATOS PRIMERO.");
        }
    }
    return resultado;
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
	 int resultado = -1;
	    int id;
	    int isEmpty = 0;
	    int confirmacion;
	    Employee* auxEmpleado;
	    int indiceEmpleado;
	    if(pArrayListEmployee != NULL)
	    {
	        isEmpty = ll_isEmpty(pArrayListEmployee);
	        if(isEmpty != 1)
	        {
	        	resultado=0;
	            printf("LISTADO DE EMPLEADOS:\n");
	            controller_ListEmployee(pArrayListEmployee);
	            utn_getNumero(" INGRESE ID DEL EMPLEADO A ELIMINAR: \n", "\n ERROR", &id, 2, 0, 99999);
	            auxEmpleado = controller_getEmployeeId(pArrayListEmployee, id);
	            if(auxEmpleado != NULL)
	            {
	                printf("%4s %18s %20s %20s\n", "ID:", "NOMBRE:", "HORAS TRABAJADAS:", "SUELDO:");
	                employee_getPrintEmployee(auxEmpleado);
	                utn_getNumero("\n ESTA SEGURO QUE DESEA ELIMINAR UN EMPLEADO? INGRESE (1) PARA SI Y (2) PARA NO:", "\n ERROR", &confirmacion, 2, 1, 2);
	                if(confirmacion == 1)
	                {
	                    indiceEmpleado = ll_indexOf(pArrayListEmployee, auxEmpleado);
	                    ll_remove(pArrayListEmployee, indiceEmpleado);
	                }
	                else if(confirmacion == 2)
	                {
	                    resultado = 1;
	                }
	            }
	        }
	        else
	        {
	            printf("INGRESE DATOS PRIMERAMENTE");
	        }
	    }
	    return resultado;
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
	 int resultado = -1;
	    int i;
	    int len;
	    int isEmpty = 0;
	    if(pArrayListEmployee != NULL)
	    {
	        resultado = 0;
	        isEmpty = ll_isEmpty(pArrayListEmployee);
	        if(isEmpty != 1)
	        {
	            len = ll_len(pArrayListEmployee);
	            Employee* auxEmpleado;
	            printf("%4s%20s%20s%22s\n","Id:","NOMBRE:","HORAS TRABAJADAS:","SUELDO:");
	            for(i=0; i<len; i++)
	            {
	                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
	                employee_getPrintEmployee(auxEmpleado);
	            }
	        }
	        else
	        {
	            printf("\n NO SE HAN CARGADO DATOS.\n");
	        }
	    }
	    return resultado;
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
	 int resultado = 1;
	    int opcion;
	    int orden;
	    int isEmpty = 0;
	    if(pArrayListEmployee != NULL)
	    {
	        isEmpty = ll_isEmpty(pArrayListEmployee);
	        resultado = 2;
	        if(isEmpty != 1)
	        {
	            do
	            {
	            	utn_getNumero("\n ORDENAR EMPLEADOS: \n 1. PARA ID. \n 2.PARA NOMBRE. \n 3. PARA HORAS TRABAJADAS. \n 4.PARA SUELDO. \n 5. PARA SALIR", "\n ERROR", &opcion, 2, 1, 5);
	                switch(opcion)
	                {
	                case 1:
	                	utn_getNumero("\nINGRESE (1)PARA ORDENAR ASCENDENTEMENTE Y (0) PARA ORDENAR DESCENDENTEMENTE:", "\n ERROR", &orden, 2, 0, 1);
	                    printf("ORDENANDO...");
	                	ll_sort(pArrayListEmployee, employee_compareIdEmployee, orden);
	                    controller_ListEmployee(pArrayListEmployee);
	                    break;
	                case 2:
	                    utn_getNumero("\nINGRESE (1)PARA ORDENAR ASCENDENTEMENTE Y (0) PARA ORDENAR DESCENDENTEMENTE:", "\n ERROR", &orden, 2, 0, 1);
	                    printf("ORDENANDO...");
	                    ll_sort(pArrayListEmployee, employee_compareNameEmployee, orden);
	                    controller_ListEmployee(pArrayListEmployee);
	                    break;
	                case 3:
	                	utn_getNumero("\n INGRESE (1)PARA ORDENAR ASCENDENTEMENTE Y (0) PARA ORDENAR DESCENDENTEMENTE:", "\n ERROR", &orden, 2, 0, 1);
	                	printf("ORDENANDO...");
	                	 ll_sort(pArrayListEmployee, employee_compareWorkedHours, orden);
	                	controller_ListEmployee(pArrayListEmployee);
	                    break;
	                case 4:
	                	utn_getNumero("\n INGRESE (1)PARA ORDENAR ASCENDENTEMENTE Y (0) PARA ORDENAR DESCENDENTEMENTE:", "\n ERROR", &orden, 2, 0, 1);
	                	printf("ORDENANDO...");
	                	ll_sort(pArrayListEmployee, employee_compareSueldo, orden);
	                	controller_ListEmployee(pArrayListEmployee);
	                    break;
	                }
	            }
	            while(opcion != 5);
	        }
	        else{
	        	printf("INGRESE EMPLEADOS");
	        }
	    }
	    return resultado;
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
	 int resultado = -1;
	    int len;
	    int i;
	    FILE* pFile;
	    Employee* auxEmployee = NULL;
	    int idStr;
	    char nombreStr[51];
	    int horasTrabajadasStr;
	    int sueldoStr;
	    if(pArrayListEmployee != NULL && path != NULL)
	    {
	        pFile = fopen(path, "w");
	        len = ll_len(pArrayListEmployee);
	        if(pFile != NULL)
	        {
	            fprintf(pFile, "Id,Nombre,Horas trabajadas,Salario\n");
	            for(i=0; i<len; i++)
	            {
	                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
	                employee_getId(auxEmployee, &idStr);
	                employee_getNombre(auxEmployee, nombreStr);
	                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadasStr);
	                employee_getSueldo(auxEmployee, &sueldoStr);
	                fprintf(pFile, "%d,%s,%d,%d\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
	            }
	        }
	        fclose(pFile);
	        resultado = 0;
	    }
	    return resultado;
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
	 int resultado = -1;
	    int len;
	    int i;
	    FILE* pFile;
	    Employee* auxEmployee = NULL;
	    if(pArrayListEmployee != NULL && path != NULL)
	    {
	        pFile = fopen(path, "wb");
	        len = ll_len(pArrayListEmployee);
	        if(pFile != NULL)
	        {
	            for(i=0; i<len; i++)
	            {
	                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
	                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
	            }
	        }
	        fclose(pFile);
	        resultado = 0;
	    }
	    return resultado;
}
int controller_getMaximunId(LinkedList* pArrayListEmployee)
{
    int resultado = -1;
    if(pArrayListEmployee != NULL)
    {
        int len;
        int flag = 0;
        int i;
        Employee* auxEmployee;
        len = ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
            if(flag == 0 || resultado < auxEmployee->id)
            {
                resultado = auxEmployee->id;
                flag = -1;
            }
        }
    }
    return resultado;
}
int controller_getSecondId(LinkedList* pArrayListEmployee)
{
    int resultado = -1;
    if(pArrayListEmployee != NULL)
    {
        resultado = controller_getMaximunId(pArrayListEmployee);
        resultado++;
    }
    return resultado;
}
void* controller_getEmployeeId(LinkedList* pArrayListEmployee, int id)
{
    int len;
    int i;
    Employee* auxEmployee = NULL;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
            if(id == auxEmployee->id)
            {
                break;
            }
        }
    }
    return auxEmployee;
}
