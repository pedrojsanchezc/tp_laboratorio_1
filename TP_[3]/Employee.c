#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "Inputs.h"
#include "LinkedList.h"
Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));
    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }
    return this;
}
Employee* employee_newParametrosTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(this != NULL)
        {
            employee_setId(this, atoi(idStr));
            employee_setNombre(this, nombreStr);
            employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
            employee_setSueldo(this, atoi(sueldoStr));
        }
    }
    return this;
}
void employee_delete(Employee* employee)
{
    free(employee);
    employee = NULL;
}
int employee_getPrintEmployee(Employee* employee)
{
    int resultado = -1;
    if(employee != NULL)
    {
        printf("%4d %18s %20d %20d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
        resultado = 0;
    }
    return resultado;
}
int employee_setId(Employee* this,int id)
{
    int resultado = -1;
    if(this != NULL)
    {
        this->id = id;
        resultado = 0;
    }
    return resultado;
}
int employee_getId(Employee* this,int* id)
{
    int resultado = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        resultado = 0;
    }
    return resultado;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int resultado = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        resultado = 0;
    }
    return resultado;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int resultado = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        resultado = 0;
    }
    return resultado;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int resultado = -1;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        resultado = 0;
    }
    return resultado;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int resultado = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        resultado = 0;
    }
    return resultado;
}
int employee_setSueldo(Employee* this,int sueldo)
{
    int resultado = -1;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        resultado = 0;
    }
    return resultado;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int resultado = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        resultado = 0;
    }
    return resultado;
}
int employee_compareIdEmployee(void* pElementOne, void* pElementTwo)
{
    int resultado = -1;
    int primerId;
    int segundoId;
    Employee* primerEmpleado = (Employee*) pElementOne;
    Employee* segundoEmpleado = (Employee*) pElementTwo;
    employee_getId(primerEmpleado, &primerId);
    employee_getId(segundoEmpleado, &segundoId);
    if(primerId > segundoId)
    {
        resultado = 1;
    }
    else
    {
        if(primerId == segundoId)
        {
            resultado = 0;
        }
    }
    return resultado;
}
int employee_compareSueldo(void* pElementOne, void* pElementTwo)
{
    int resultado = -1;
    int primerSueldo;
    int segundoSueldo;
    Employee* primerEmpleado = (Employee*) pElementOne;
    Employee* segundoEmpleado = (Employee*) pElementTwo;
    employee_getSueldo(primerEmpleado, &primerSueldo);
    employee_getSueldo(segundoEmpleado, &segundoSueldo);
    if(primerSueldo > segundoSueldo)
    {
        resultado = 1;
    }
    else
    {
        if(primerSueldo == segundoSueldo)
        {
            resultado = 0;
        }
    }
    return resultado;
}
int employee_compareNameEmployee(void* pElementOne, void* pElementTwo)
{
    int resultado =-1;
    int strnCmp;
    char nameFirst[50];
    char secondFirst[50];
    Employee* primerEmpleado = (Employee*) pElementOne;
    Employee* segundoEmpleado = (Employee*) pElementTwo;
    employee_getNombre(primerEmpleado, nameFirst);
    employee_getNombre(segundoEmpleado, secondFirst);
    strnCmp = strcmp(nameFirst, secondFirst);
    if(strnCmp > 0)
       {
           resultado = 1;
       }
       else
       {
           if(strnCmp == 0)
           {
               resultado = 0;
           }
       }
    return resultado;
}
int employee_compareWorkedHours(void* pElementOne, void* pElementTwo)
{
    int resultado = -1;
    int primerasHoras;
    int segundasHoras;
    Employee* primerEmpleado = (Employee*) pElementOne;
    Employee* segundoEmpleado = (Employee*) pElementTwo;
    employee_getHorasTrabajadas(primerEmpleado, &primerasHoras);
    employee_getHorasTrabajadas(segundoEmpleado, &segundasHoras);
    if(primerasHoras > segundasHoras)
    {
        resultado = 1;
    }
    else
    {
        if(primerasHoras == segundasHoras)
        {
            resultado = 0;
        }
    }
    return resultado;
}
