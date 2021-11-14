#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Inputs.h"
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;
Employee* employee_new();
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();
int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int employee_getPrintEmployee(Employee* employee);
int employee_compareIdEmployee(void* pElementOne, void* pElementTwo);
int employee_compareSueldo(void* pElementOne, void* pElementTwo);
int employee_compareNameEmployee(void* pElementOne, void* pElementTwo);
int employee_compareWorkedHours(void* pElementOne, void* pElementTwo);

#endif // employee_H_INCLUDED
