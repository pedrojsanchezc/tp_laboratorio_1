/*
 * Cliente.c
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */
#include "Cliente.h"

static int generateNewId(void);

static int generateNewId(void)
{
	static int id = 6;
	id++;
	return  id;
}

int initCliente(Cliente* list, int len)
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

int findEmptyIndex(Cliente *list, int len)
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

int cargarCliente(Cliente *list, int len, int *id)
{
	int resultado = -1;
	Cliente buffer;

	if(list != NULL && len > 0 && findEmptyIndex(list, len) != -1)
	{
		if(utn_getNombre(buffer.nombreEmpresa, "\nNombre de la empresa: ", ERROR_MSG, NOMBREEMPRESA_LEN, QTY_REINTENTO) == 0 &&
		   utn_getCuit(buffer.cuit, "\nCUIT: ", ERROR_MSG, CUIT_LEN, QTY_REINTENTO) == 0 &&
		   utn_getDireccion(buffer.direccion, "\nDireccion - Calle: ", "\nAltura", ERROR_MSG, ERROR_ALTURA) == 0 &&
		   utn_getNumero(&buffer.idLocalidad, "\nId de Localidad: ", ERROR_MSG, 1, 100, QTY_REINTENTO) == 0
		   )
		{
			buffer.id = generateNewId();

			if(addCliente(list, len, buffer.id, buffer.nombreEmpresa, buffer.cuit, buffer.direccion, buffer.idLocalidad) == 0)
			{
				resultado = 0;
			}
		}
	}

	return resultado;
}

int findClienteById(Cliente* list, int len, int id)
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

int printCliente(Cliente* cliente)
{
	int resultado = -1;

	if(cliente != NULL && cliente->isEmpty == FALSE)
	{
		printf("\n%4d %20s %15s %20s %15d",cliente->id, cliente->nombreEmpresa, cliente->cuit, cliente->direccion, cliente->idLocalidad);
		resultado = 0;
	}

	return resultado;
}

int printClientes(Cliente* list, int length)
{
	int resultado = -1;

	if(list != NULL && length > 0 && list->isEmpty == FALSE)
	{
		printf("\n%4s %20s %10s %25s %15s", "ID", "NOMBRE EMPRESA", "CUIT", "DIRECCION", "IDLOCALIDAD");
		for(int i = 0; i < length; i++)
		{
			printCliente(&list[i]);
		}
		resultado = 0;
	}

	return resultado;
}

int hardcodearData(Cliente* list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		addCliente(list, len, 1, "TOYOTA", "99992122111", "Av Paz 1790", 1);
		addCliente(list, len, 2, "BMX", "33992122144", "Munoz 200", 2);
		addCliente(list, len, 3, "LOL", "45549921221", "Juncal 1200", 3);
		addCliente(list, len, 4, "RPX", "51359921221", "Av Cabrera 900", 4);
		addCliente(list, len, 5, "BITCOIN", "73279921221", "Av Peron 1700", 5);
		addCliente(list, len, 6, "ETHER", "82389921221", "Av Chuchu 300", 6);

		resultado = 0;
	}

	return resultado;
}

int alta_menu(Cliente* list, int len, Localidad* localidadList, int localidadLen)
{
	int resultado = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(list != NULL && len > 0 && localidadList && localidadLen > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear clientes \n2-Cargar cliente \n3-Cargar localidades \n4-Volver al menu principal", ERROR_MSG, 1, 4, QTY_REINTENTO) == 0)
			{
				switch(option)
				{

					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData(list, len) == 0 && hardcodearData_localidad(localidadList, localidadLen) == 0)
							{
								printClientes(list, len);
							}
						}
						else
						{
							printf("\nNo puede volver a harcodear los datos");
						}

						break;
					case 2:

						if(
							printLocalidades(localidadList, localidadLen) == 0 &&
							cargarCliente(list, len, &id) == 0 &&
						   printClientes(list, len) == 0
						   )
						{
							printf("\nCliente cargado exitosamente");

						}
						else
						{
							printf("\nNo se ha podido cargar el cliente");
						}
						break;
					case 3:
						if(
							uploadLocalidad(localidadList, localidadLen, &id) == 0 &&
						   printLocalidades(localidadList, localidadLen) == 0
						   )
						{
							printf("\nCliente cargado exitosamente");

						}
						else
						{
							printf("\nNo se ha podido cargar el cliente");
						}
						break;
				}
			}
		}while(option!= 4);
		resultado = 0;
	}

	return resultado;
}

int isClienteListEmpty(Cliente *list, int len)
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

int addCliente(Cliente* list, int len, int id, char nombreEmpresa[], char cuit[], char direccion[], int idLocalidad, Pedido *pedidoList, Operador listaOperador, int idOperador)
{
	int resultado = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && nombreEmpresa != NULL && cuit != NULL && direccion != NULL && idLocalidad > 0)
	{
		i = findEmptyIndex(list, len);
		list[i].id = id;
		strncpy(list[i].nombreEmpresa, nombreEmpresa, NOMBREEMPRESA_LEN);
		strncpy(list[i].cuit, cuit, CUIT_LEN);
		strncpy(list[i].direccion, direccion, DIRECCION_LEN);
		list[i].idLocalidad = idLocalidad;
		list[i].idOperador = idOperador;
		list[i].isEmpty = FALSE;

		resultado = 0;
	}

	return resultado;
}

int ModificarCliente(Cliente* list, int len, Localidad* localidadList, int localidadLen, Pedido *pedidoList, Operador listaOperador, int idOperador)
{
	int resultado = -1;
	int idIngresado;
	int index;
	int option;
	Cliente buffer;
	char response;

	if(list != NULL && len > 0 && localidadList && localidadLen > 0)
	{
		printClientes(list, len);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del cliente a modificar: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findClienteById(list, len, idIngresado);

			if(index != -1 && list[index].isEmpty == FALSE) //dentro del findclientebyid -->repetido
			{
				do
				{
					if(utn_getNumero(&option, "\nQue desea modificar? \n1-Direccion \n2-Localidad \n3-Volver al menu principal", ERROR_MSG, 1, 5, QTY_REINTENTO) == 0)
					{
						switch(option)
						{
							case 1:
								if(utn_getDireccion(buffer.direccion, "\nNueva direccion: ", "\nNueva altura: ", ERROR_MSG, ERROR_ALTURA) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{

										strncpy(list[index].direccion, buffer.direccion, CUIT_LEN);
										printf("\nLa direccion ha sido modificada exitosamente");
									}
									else
									{
										printf("\nLa direccion no ha sido modificada");
									}
								}
								break;
							case 2:
								if(printLocalidades(localidadList, localidadLen) == 0 &&
									utn_getNumero(&buffer.idLocalidad, "\nIngrese el id de la localidad a modificar", ERROR_MSG, 1, 100, QTY_REINTENTO) == 0)
								{
									if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
									  (response == 'Y' || response == 'y'))
									{
										list[index].idLocalidad = buffer.idLocalidad;
										printf("\nLa localidad ha sido modificada exitosamente");
									}
									else
									{
										printf("\nLa localidad no ha sido modificada");
									}
								}
								break;
						}
					}
				}while(option != 5);
			}
			else
			{
				printf(ID_NOEXISTE);
			}
		}
		resultado = 0;
	}

	return resultado;
}

int removeCliente(Cliente* list, int len, int id, Pedido *pedidoList, Operador listaOperador, int idOperador)
{
	int resultado = -1;
	int index;
	char respuesta;

	if(list != NULL && len > 0)
	{
		printClientes(list, len);

		if(utn_getNumero(&id, "\nSeleccione el id del empleado a dar de baja: ", ERROR_MSG, 1, QTY_CLIENTE, QTY_REINTENTO) == 0)
		{
			index = findClienteById(list, len, id);

			if(index != -1 && list[index].isEmpty == FALSE)
			{
				if(utn_getContinuar(&respuesta, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
				  (respuesta == 'Y' || respuesta == 'y'))
				{
					list[index].isEmpty = TRUE;
					printf("\nCliente eliminado exitosamente\n");
					printClientes(list, len);
				}
				else
				{
					printf(CLIENTE_NOTREMOVED);
				}
			}
			else
			{
				printf(ID_NOEXISTE);
				printf(CLIENTE_NOTREMOVED);
			}
		}
		resultado = 0;
	}

	return resultado;
}
