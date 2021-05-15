#include "ArrayEmployees.h"

int Employee_idIncremental = 0;

void eEmployee_initEmployees(eEmployee array[], int TAM) {
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			array[i].isEmpty = LIBRE;
		}
	}
}

int eEmployee_ObtenerID() {
	return Employee_idIncremental += 1;
}

int eEmployee_ObtenerIndexLibre(eEmployee array[], int TAM) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int eEmployee_findEmployeeById(eEmployee array[], int TAM, int ID) {
	int rtn = -1;
	int i;

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void eEmployee_MostrarUno(eEmployee Employee) {
	printf("%5d %25s %25s %5f %5d\n", Employee.id, Employee.name, Employee.lastName, Employee.salary, Employee.sector);
}

int eEmployee_printEmployees(eEmployee array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\n\t> LISTADO Employee");
	printf("%5d %25s %25s %5f %5d\n\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				eEmployee_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int eEmployee_MostrarDadosDeBaja(eEmployee array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	puts("\t> Employee\n");
	printf("%5d %25s %25s %5f %5d\n\n", "ID", "NOMBRE", "APELLIDO", "SALARIO", "SECTOR");

	if (array != NULL && TAM > 0) {
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == BAJA) {
				eEmployee_MostrarUno(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

eEmployee eEmployee_CargarDatos(void) {
	eEmployee auxiliar;

	pedirNombre(auxiliar.name, 51);
	pedirApellido(auxiliar.lastName, 51);
	auxiliar.salary = Get_FloatRange("INGRESE SALARIO: ", "ERROR. REINGRESE SALARIO: ", 1 ,5);
	auxiliar.sector = Get_IntRange("INGRESE SECTOR: ", "ERROR. REINGRESE SECTOR: ", 1 ,5);

	return auxiliar;
}

eEmployee eEmployee_ModificarUno(eEmployee Employee) {
	eEmployee auxiliar = Employee;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eEmployee_addEmployees(eEmployee array[], int TAM) {
	int rtn = 0;
	eEmployee auxEmployee;

	//BUSCO ESPACIO EN ARRAY
	int index = eEmployee_ObtenerIndexLibre(array, TAM);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1) {
		//PIDO DATOS - CARGO Employee AUXILIAR
		auxEmployee = eEmployee_CargarDatos();
		//SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxEmployee.id = eEmployee_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxEmployee.isEmpty = OCUPADO;
		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[index] = auxEmployee;

		//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = 1;
	}

	return rtn;
}

int eEmployee_removeEmployee(eEmployee* Employee, int TAM) {
	int flag=0;
    int eID;
    int i;
    int rtn=0;
    char confirmar='N';
    int comprobar=CantidadEmpleados(Employee, TAM);

    if (comprobar==0)
    {
        system("cls");
        puts("\n[ERROR] NINGUN EMPLEADO PARA DAR DE BAJA\n\n");
    }

    while(comprobar==1&&flag==0)
    {
        flag=1;
        system("cls");
        puts("\nBAJA EMPLEADO\n\n");
        eID=Get_Int("INGRESE LEGAJO A MODIFICAR:", "ERROR. REINGRESE LEGAJO A MODIFICAR:");
        system("cls");
        printf("\nLEGAJO: N%c %d\n", 248, eID);

        for(i=0; i<TAM; i++)
        {
            if(Employee[i].id==eID&&Employee[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] EMPLEADO ENCONTRADO\n");

                puts("\nSEGURO QUE DESEA ELIMINAR? [S] CONFIRMAR O [SALIR] CUALQUIER TECLA");

                while(confirmar=='S')
                {
                	Employee[i].isEmpty=OCUPADO;
                    rtn=1;
                    puts("\n[BAJA EXITOSA]");
                    break;
                }
                if(rtn!=1||confirmar!='S')
                {
                    puts("\n[BAJA CANCELADA] ");
                    rtn=1;
                }
            }

        }
        if (rtn==0)
        {
            puts("\n[ERROR] LEGAJO DE EMPLEADO NO ENCONTRADO\n");
            break;
        }
    }

    return rtn;
}

int eEmployee_Modificacion(eEmployee* Employee, int TAM) {
	int flag=0;
    int flagDos=0;
    int eID;
    int i;
    int rtn=0;
    int opcion;
    int comprobar=CantidadEmpleados(Employee, TAM);

    if (comprobar==0)
    {
        system("cls");
        puts("\n[ERROR] NINGUN EMPLEADO PARA MODIFICAR\n\n");
    }

    while(comprobar==1&&flag==0)
    {
        flag=1;
        system("cls");
        puts("\nMODIFICAR EMPLEADO\n\n");
        eID= Get_Int("INGRESE LEGAJO A MODIFICAR:", "ERROR. REINGRESE LEGAJO A MODIFICAR:");
        system("cls");
        printf("\nLEGAJO: N%c %d\n", 248, eID);

        for(i=0; i<TAM; i++)
        {
            if(Employee[i].id==eID&&Employee[i].isEmpty==OCUPADO)
            {
                puts("\n[EXITO] EMPLEADO ENCONTRADO\n");

                Menu();
                switch(opcion)

                {
                case 1:
                    system("cls");
                    pedirNombre(Employee[i].name, 51);
                    rtn=1;
                    break;
                case 2:
                    system("cls");
                    pedirApellido(Employee[i].lastName, 51);
                    rtn=1;
                    break;
                case 3:
                    system("cls");
                    Employee[i].salary=Get_Float("INGRESE SALARIO:", "ERROR. REINGRESE SALARIO:");
                    rtn=1;
                    break;
                case 4:
                    system("cls");
                    Employee[i].sector=Get_Int("INGRESE SECTOR:", "ERROR. REINGRESE SECTOR:");
                    rtn=1;
                    break;
                case 5:
                    system("cls");
                    pedirNombre(Employee[i].name, 51);
                    pedirApellido(Employee[i].lastName, 51);
                    Employee[i].salary = Get_Float("INGRESE SALARIO:", "ERROR. REINGRESE SALARIO:");
                    Employee[i].sector = Get_Int("INGRESE SECTOR:", "ERROR. REINGRESE SECTOR:");
                    rtn=1;
                    break;
                case 0:
                    puts("\n[EMPLEADO NO MODIFICADO]\n");
                    flagDos=1;
                    break;
                default:
                    puts("\n[ERROR] OPCION NO VALIDA\n");
                    flagDos=1;
                    break;
                }
            }

        }
        if (rtn==0&&flagDos==0)
        {
            puts("\n[ERROR] LEGAJO DE EMPLEADO NO ENCONTRADO\n");
            break;
        }
    }
    return rtn;
}

int eEmployee_sortEmployees(eEmployee array[], int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	eEmployee aux;

	/** EJEMPLO DE sortEmployees CON ID DE Employee
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)

	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id > array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id < array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		default:
			rtn = 0;
			break;
		}
	}
	return rtn;
}

void Menu(void){
	printf("MENU DE OPCIONES\n");
	printf("1.ALTAS: \n");
	printf("2.MODIFICAR:\n");
	printf("3.BAJAS:\n");
	printf("4.INFORMAR:\n");

}

void OrdenApellido(eEmployee* Employee, int TAM)
{

    int i;
    int j;
    eEmployee auxEmpleado;

    for(i=0; i<TAM-1; i++)
    {
        for (j=i+1; j<TAM; j++)
        {
            if(strcmp(Employee[i].lastName,Employee[j].lastName)>0)
            {
                auxEmpleado=Employee[i];
                Employee[i]=Employee[j];
                Employee[j]=auxEmpleado;
            }
        }
    }
}

void PrioridadEmpleado(eEmployee* Employee, int TAM)
{
    int i;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].isEmpty==OCUPADO)
        {
            printf("%c %s, %s\t\t\t\t\t%d\n", 250, Employee[i].lastName, Employee[i].name, Employee[i].sector);
        }
    }

}

void PrioridadSector(eEmployee* Employee, int TAM)
{
    int maxSector=0;
    int i;
    int j;
    int k;
    int flag=0;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].sector>maxSector&&Employee[i].isEmpty==OCUPADO)
        {
            maxSector=Employee[i].sector;
        }
    }

    for(j=0; j<maxSector; j++)
    {
        flag=0;
        for(k=0; k<TAM; k++)
        {
            if(Employee[k].sector==j&&Employee[j].isEmpty==OCUPADO)
            {
                if(flag==0)
                {
                    printf("\nSECTOR %d\n\n", j);
                    flag=1;
                }
                printf("\n%s, %s", Employee[k].lastName, Employee[k].name);
            }
        }

    }

}

void Orden(eEmployee* Employee, int TAM)
{
    OrdenApellido(Employee, TAM);
    PrioridadEmpleado(Employee, TAM);
}

int Cantidad(eEmployee* Employee, int TAM)
{

    int cantidad=0;
    int i;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].isEmpty==OCUPADO)
        {
        	cantidad++;
        }
    }

    return cantidad;
}

int CantidadEmpleados(eEmployee* Employee, int TAM)
{

    int cantidadEmpleados=0;
    int i;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].isEmpty==OCUPADO)
        {
        	cantidadEmpleados=1;
            break;
        }
    }

    return cantidadEmpleados;
}

float TotalSalario(eEmployee* Employee, int TAM)
{

    int i;
    float acumulador=0;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].isEmpty==OCUPADO)
        {
        	acumulador=acumulador+Employee[i].salary;
        }
    }
    return acumulador;
}

float PromedioSalario(eEmployee* Employee, int TAM)
{

    float promedio;
    float salario;
    int cantidadEmpleados;

    cantidadEmpleados = Cantidad(Employee, TAM);
    salario= TotalSalario(Employee, TAM);

    promedio=salario/cantidadEmpleados;

    return promedio;
}

void MayorSueldo(eEmployee* Employee, int TAM, float PromedioSalario)
{

    int i;

    for(i=0; i<TAM; i++)
    {
        if(Employee[i].isEmpty==OCUPADO && Employee[i].salary>=PromedioSalario)
        {
            printf("\n\t[%.2f]\t\t\t[%s, %s]\n", Employee[i].salary, Employee[i].lastName, Employee[i].name);
        }
    }
    puts("\n\n");
    system("pause");
}
