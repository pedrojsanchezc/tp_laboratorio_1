/*
 * Localidad.c
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */
#include "Localidad.h"

static int generateNewId(void);

static int generateNewId(void)
{
	static int id = 6;
	id++;
	return  id;
}

int initLocalidad(Localidad* list, int len)
{
	int resultado = -1;

	if (list != NULL && len > 0)
	{
	  for (int i = 0; i < len; i++)
		{
		  list[i].isEmpty = TRUE;
		}
	  resultado = 0;
	}
	return resultado;
}

int findEmptyIndexLocalidad(Localidad *list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE)
			{
				resultado = i;
				break;
			}
		}
	}

	return resultado;
}

int uploadLocalidad(Localidad *list, int len, int *id)
{
	int resultado = -1;
	Localidad buffer;

	if(list != NULL && len > 0 && findEmptyIndexLocalidad(list, len) != -1)
	{
		if(utn_getNombre(buffer.nombre, "\nLocalidad: ", ERROR_MSG_L, NOMBRE_LEN, QTY_REINTENTO_L) == 0
		   )
		{
			buffer.id = generateNewId();

			if(addLocalidad(list, len, buffer.id, buffer.nombre) == 0)
			{
				resultado = 0;
			}
		}
	}

	return resultado;
}

int addLocalidad(Localidad* list, int len, int id, char nombre[])
{
	int resultado = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && nombre != NULL)
	{
		i = findEmptyIndexLocalidad(list, len);
		list[i].id = id;
		strncpy(list[i].nombre, nombre, NOMBRE_LEN);
		list[i].isEmpty = FALSE;

		resultado = 0;
	}

	return resultado;
}


int findLocalidadById(Localidad* list, int len, int id)
{
	int resultado = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE && list[i].id == id)
			{
				resultado = i;
				break;
			}
		}
	}

	return resultado;
}

int printLocalidad(Localidad* cliente)
{
	int resultado = -1;

	if(cliente != NULL && cliente->isEmpty == FALSE)
	{
		printf("\n%4d %20s",cliente->id, cliente->nombre);
		resultado = 0;
	}

	return resultado;
}

int printLocalidades(Localidad* list, int length)
{
	int resultado = -1;

	if(list != NULL && length > 0)
	{
		printf("\n%4s %20s", "ID", "NOMBRE");
		for(int i = 0; i < length; i++)
		{
			printLocalidad(&list[i]);
		}
		resultado = 0;
	}

	return resultado;
}

int hardcodearData_localidad(Localidad* list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		addLocalidad(list, len, 1, "La Pera");
		addLocalidad(list, len, 2, "Manzana");
		addLocalidad(list, len, 3, "Munoz");
		addLocalidad(list, len, 4, "Peron");
		addLocalidad(list, len, 5, "La Matanza");
		addLocalidad(list, len, 6, "Cabrera");

		resultado = 0;
	}

	return resultado;
}

int alta_menuLocalidad(Localidad* list, int len)
{
	int resultado = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(list != NULL && len > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear localidades \n2-Cargar localidades \n3-Volver al menu principal", ERROR_MSG_L, 1, 3, QTY_REINTENTO_L) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData_localidad(list, len) == 0)
							{
								printLocalidades(list, len);
							}
						}
						else
						{
							printf("\nNo puede volver a harcodear los datos");
						}

						break;
					case 2:
						if(uploadLocalidad(list, len, &id) == 0 &&
						   printLocalidades(list, len) == 0)
						{
							printf("\nLocalidad cargada exitosamente");
						}
						else
						{
							printf("\nNo se ha podido cargar la localidad");
						}
						break;
				}
			}
		}while(option!= 3);
		resultado = 0;
	}

	return resultado;
}

int isLocalidadListEmpty(Localidad *list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
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

int ModificarLocalidad(Localidad* list, int len)
{
	int resultado = -1;
	int idIngresado;
	int index;
	int option;
	Localidad buffer;
	char response;

	if(list != NULL && len > 0)
	{
		printLocalidades(list, len);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id de la localidad a modificar: ", ERROR_MSG_L, 1, QTY_LOCALIDAD, QTY_REINTENTO_L) == 0)
		{
			index = findLocalidadById(list, len, idIngresado);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				do
				{
					if(utn_getNumero(&option, "\nQue desea modificar? \n1-Direccion \n2-Localidad \n3-Volver al menu principal", ERROR_MSG_L, 1, 5, QTY_REINTENTO_L) == 0)
					{
						if(utn_getNombre(buffer.nombre, "\nIngrese el nuevo nombre de la localidad: ", ERROR_MSG_L, NOMBRE_LEN, QTY_REINTENTO_L) == 0)
						{
							if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG_L, QTY_REINTENTO_L) == 0 &&
							  (response == 'Y' || response == 'y'))
							{

								strncpy(list[index].nombre, buffer.nombre, NOMBRE_LEN);
								printf("\nEl nombre de la localidad ha sido modificada exitosamente");
							}
							else
							{
								printf("\nEl nombre de la localidad no ha sido modificada");
							}
						}

					}

				}while(option != 5);
			}
			else
			{
				printf(ID_NOEXISTE_L);
			}
		}
		resultado = 0;
	}

	return resultado;
}

int removeLocalidad(Localidad* list, int len, int id)
{
	int resultado = -1;
	int index;
	char respuesta;

	if(list != NULL && len > 0)
	{
		printLocalidades(list, len);

		if(utn_getNumero(&id, "\nSeleccione el id de la localidad a dar de baja: ", ERROR_MSG_L, 1, QTY_LOCALIDAD, QTY_REINTENTO_L) == 0)
		{
			index = findLocalidadById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG_L, QTY_REINTENTO_L) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE;
					printf("\nLocalidad eliminada exitosamente\n");
					printLocalidades(list, len);
				}
				else
				{
					printf(LOCALIDAD_NOTREMOVED);
				}
			}
			else
			{
				printf(ID_NOEXISTE_L);
				printf(LOCALIDAD_NOTREMOVED);
			}
		}
		resultado = 0;
	}

	return resultado;
}



