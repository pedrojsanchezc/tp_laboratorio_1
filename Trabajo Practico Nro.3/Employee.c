#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Inputs.h"

int employee_setId(Employee* this,int id){
	int setter = 0;
	if(this!=NULL && id >0){
		this -> id = id;
		setter = 1;
	}
	return setter;
}

int employee_getId(Employee* this,int* id){
	int getter = 0;
	if(this!=NULL && id!=NULL){
		*id = this -> id;
		getter = 1;
	}
	return getter;
}

int employee_setNombre(Employee* this,char* nombre){
	int setter = 0;
	if(this!=NULL){
		strcpy(this->nombre, nombre);
		setter = 1;
	}
	return setter;
}

int employee_getNombre(Employee* this,char* nombre){
	int getter = 0;
	if(this!=NULL && nombre!=NULL){
		strcpy(nombre, this->nombre); //
		getter = 1;
	}
	return getter;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int setter= 0;
	if(this!=NULL && horasTrabajadas>0){
		this->horasTrabajadas = horasTrabajadas;
		setter = 1;
	}
	return setter;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int getter = 0;
	if(this!=NULL && horasTrabajadas!=NULL){
		*horasTrabajadas = this -> horasTrabajadas;
		getter = 1;
	}
	return getter;
}

int employee_setSueldo(Employee* this,int sueldo){
	int setter = 0;
	if(this!=NULL && sueldo>0){
		this->sueldo = sueldo;
		setter = 1;
	}
	return setter;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int getter = 0;
	if(this!=NULL && sueldo!=NULL){
		*sueldo = this ->sueldo;
		getter = 1;
	}
	return getter;
}

Employee* employee_new(){
	Employee* pListaEmployess;

	pListaEmployess = (Employee*)malloc(sizeof(Employee));

	return pListaEmployess;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo){
	Employee* pEmployee;

	pEmployee = employee_new();

	if(pEmployee != NULL){
        employee_setNombre(pEmployee,nombreStr);
        employee_setSueldo(pEmployee,atoi(sueldo));
        employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
        employee_setId(pEmployee,atoi(idStr));
	}
	return pEmployee;
}

int employee_CompareByName(void* e1, void* e2){
	Employee* empleadoUno;
	Employee* empleadoDos;

	char auxNombreUno[25];
	char auxNombreDos[25];

	empleadoUno=(Employee*)e1;
	empleadoDos=(Employee*)e2;

	employee_getNombre(empleadoUno, auxNombreUno);
	employee_getNombre(empleadoDos, auxNombreDos);

	return strcmp(auxNombreUno, auxNombreDos);
}

int employee_CompareById(void* e1, void* e2){
	Employee* empleadoUno;
	Employee* empleadoDos;
	int comparar = 0;
	int auxIdUno;
	int auxIdDos;

	empleadoUno=(Employee*)e1;
	empleadoDos=(Employee*)e2;

	employee_getId(empleadoUno, auxIdUno);
	employee_getId(empleadoDos, auxIdDos);

	if(auxIdUno > auxIdDos){
		comparar = 1;
	} else{
		if(auxIdUno < auxIdDos){
			comparar = -1;
		}
	}

	return comparar;
}
