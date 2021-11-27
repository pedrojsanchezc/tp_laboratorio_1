/*
 * Pedido.c
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */
#include "Pedido.h"

static int generateNewId_Pedido(void);

static int generateNewId_Pedido(void)
{
	static int id = 6;
	id++;
	return  id;
}

int initPedido(Pedido* list, int len)
{
	int resultado = -1;

	if (list != NULL && len > 0)
	{
	  for (int i = 0; i < len; i++)
		{
		  list[i].isEmpty = TRUE_P;
		}
	  resultado = 0;
	}
	return resultado;
}

int findEmptyIndex_Pedido(Pedido *list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == TRUE_P)
			{
				resultado = i;
				break;
			}
		}
	}

	return resultado;
}


int cargarPedidoRecoleccion(Pedido *pedidoList, int pedidoLen, int *id, Cliente *clienteList, int clienteLen)
{
	int resultado = -1;
	Pedido buffer;
	int idClienteIngresado;
	int auxIndexPedido;

	if(pedidoList != NULL && pedidoLen > 0 && findEmptyIndex_Pedido(pedidoList, pedidoLen) != -1 && clienteList != NULL && clienteLen > 0)
	{

		if(utn_getNumero(&idClienteIngresado, "\nId del cliente existente: ", ERROR_MSG_P, 1, QTY_CLIENTE_P, QTY_REINTENTOS_P) == 0)
		{

			if(findClienteById(clienteList, clienteLen, idClienteIngresado) != -1 &&
		       utn_getFloat(&buffer.totalKg, "\nCantidad total de residuos (Kg): ", ERROR_MSG_P, MIN_KG, MAX_KG, QTY_REINTENTOS_P) == 0)
			{

				auxIndexPedido = findEmptyIndex_Pedido(pedidoList, pedidoLen);
				buffer.id = generateNewId_Pedido();
				buffer.kgHDPE = 0;
				buffer.kgLDPE = 0;
				buffer.kgPP = 0;
				strncpy(buffer.estadoPedido, PENDIENTE, ESTADO_LEN);
				buffer.idCliente = idClienteIngresado;
				pedidoList[auxIndexPedido] = buffer;
				printPedidosRecoleccion(pedidoList, pedidoLen);

			}
		}
		resultado = 0;
	}

	return resultado;
}


int addPedidoRecoleccion(Pedido* list, int len, int id, float kgHDPE, float kgLDPE, float kgPP, float totalKg, char estadoPedido[], int idCliente)
{
	int resultado = -1;
	int i;

	if(list != NULL && len > 0 && id > 0 && kgHDPE >= 0 && kgLDPE >= 0 && kgPP >= 0 && totalKg > 0 && estadoPedido != NULL && idCliente > 0)
	{
		i = findEmptyIndex_Pedido(list, len);
		if(i != -1)
		{
			list[i].id = id;
			list[i].kgHDPE = kgHDPE;
			list[i].kgLDPE = kgLDPE;
			list[i].kgPP = kgPP;
			list[i].totalKg = totalKg;
			strncpy(list[i].estadoPedido, estadoPedido, ESTADO_LEN);
			list[i].idCliente = idCliente;
			list[i].isEmpty = FALSE_P;
		}
		resultado = 0;
	}

	return resultado;
}


int procesarResiduos(Pedido* pedidoList, int pedidoLen)
{
	int resultado = -1;
	int idIngresado;
	int index;
	Pedido buffer;
	char response;
	float sumaKgTotal;

	if(pedidoList != NULL && pedidoLen > 0)
	{
		printPedidosRecoleccion(pedidoList, pedidoLen);

		if(utn_getNumero(&idIngresado, "\nSeleccione el id del pedido existente: ", ERROR_MSG_P, 1, QTY_PEDIDO, QTY_REINTENTOS_P) == 0)
		{
			index = findPedidoById(pedidoList, pedidoLen, idIngresado);

			if(index != -1
			   && strncasecmp(pedidoList[index].estadoPedido, PENDIENTE, ESTADO_LEN) == 0)
			{
				if(utn_getFloat(&buffer.kgHDPE, "\nCantidad de HDPE(Kg): ", ERROR_MSG_P, 0, MAX_KG, QTY_REINTENTOS_P) == 0 &&
					utn_getFloat(&buffer.kgLDPE, "\nCantidad de LDPE(Kg): ", ERROR_MSG_P, 0, MAX_KG, QTY_REINTENTOS_P) == 0 &&
				   utn_getFloat(&buffer.kgPP, "\nCantidad de PP(Kg): ", ERROR_MSG_P, 0, MAX_KG, QTY_REINTENTOS_P) == 0)
				{
					sumaKgTotal = buffer.kgHDPE + buffer.kgLDPE + buffer.kgPP;

					if(utn_getContinuar(&response, CONTINUAR, ERROR_MSG, QTY_REINTENTO) == 0 &&
					  (response == 'Y' || response == 'y') &&
					  sumaKgTotal == pedidoList[index].totalKg)
					{
						pedidoList[index].kgHDPE = buffer.kgHDPE;
						pedidoList[index].kgLDPE = buffer.kgLDPE;
						pedidoList[index].kgPP = buffer.kgPP;
						strncpy(pedidoList[index].estadoPedido, COMPLETADO, ESTADO_LEN);
						printf("\nSus residuos han sido procesados");
					}
					else
					{
						printf("\nLa suma total de residuos no es correcta \nSus residuos no han sido procesados");
					}
				}
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


int findPedidoById(Pedido* list, int len, int id)
{
	int resultado = -1;

	if(list != NULL && len > 0 && id > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE_P && list[i].id == id)
			{
				resultado = i;
				break;
			}
		}
	}

	return resultado;
}

int printPedidoRecoleccion(Pedido* pedido)
{
	int resultado = -1;

	if(pedido != NULL && pedido->isEmpty == FALSE_P)
	{
		printf("\n%d %12.2f %10.2f %11.2f %10.2f %14s %4d",pedido->id, pedido->kgHDPE, pedido->kgLDPE, pedido->kgPP, pedido->totalKg, pedido->estadoPedido, pedido->idCliente);
		resultado = 0;
	}

	return resultado;
}

int printPedidosRecoleccion(Pedido* pedidoList, int pedidoLen)
{
	int resultado = -1;

	if(pedidoList != NULL && pedidoLen > 0)
	{
		printf("\n%s %10s %10s %10s %10s %10s %10s", "ID_P", "KgHDPE", "KgLDPE", "KgPP", "TOTALKg", "ESTADO", "ID_CLI");
		for(int i = 0; i < pedidoLen; i++)
		{
			printPedidoRecoleccion(&pedidoList[i]);
		}
		resultado = 0;
	}

	return resultado;
}

int hardcodearData_PedidoRecoleccion(Pedido* list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		addPedidoRecoleccion(list, len, 1, 0, 0, 0, 400, PENDIENTE, 1);
		addPedidoRecoleccion(list, len, 2, 0, 0, 0, 300, PENDIENTE, 2);
		addPedidoRecoleccion(list, len, 3, 0, 0, 0, 300, PENDIENTE, 3);
		addPedidoRecoleccion(list, len, 4, 0, 0, 0, 400, PENDIENTE, 4);
		addPedidoRecoleccion(list, len, 5, 0, 0, 0, 500, PENDIENTE, 5);
		addPedidoRecoleccion(list, len, 6, 0, 0, 0, 350, PENDIENTE, 6);
		printPedidosRecoleccion(list, len);
		resultado = 0;
	}

	return resultado;
}

int hardcodear_PedidoProcesado(Pedido* list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		addPedidoRecoleccion(list, len, 7, 100, 100, 200, 400, COMPLETADO, 1);
		addPedidoRecoleccion(list, len, 8, 0, 0, 300, 300, COMPLETADO, 2);
		addPedidoRecoleccion(list, len, 9, 100, 100, 100, 300, COMPLETADO, 3);
		addPedidoRecoleccion(list, len, 10, 100, 200, 100, 400, COMPLETADO, 4);
		addPedidoRecoleccion(list, len, 11, 200, 300, 0, 500, COMPLETADO, 5);
		addPedidoRecoleccion(list, len, 12, 150, 100, 100, 350, COMPLETADO, 6);
		printPedidosRecoleccion(list, len);
		resultado = 0;
	}

	return resultado;
}


int alta_menu_Pedido(Pedido* pedidoList, int pedidoLen, Cliente* clienteList, int clienteLen)
{
	int resultado = -1;
	int option;
	int id;
	static int contadorHardcodeo = 0;

	if(pedidoList != NULL && pedidoLen > 0 && clienteList != NULL && clienteLen > 0)
	{
		do
		{
			if(utn_getNumero(&option, "\n1-Hardcodear pedido de recoleccion \n2-Cargar pedido de recoleccion \n3-Volver al menu principal", ERROR_MSG_P, 1, 3, QTY_REINTENTOS_P) == 0)
			{
				switch(option)
				{
					case 1:
						contadorHardcodeo++;

						if(contadorHardcodeo == 1)
						{
							if(hardcodearData_PedidoRecoleccion(pedidoList, pedidoLen) == 0)
							{
								printf("\nDatos hardcodeados exitosamente");
							}
						}
						else
						{
							printf("\nNo puede volver a hardcodear los datos");
						}

						break;
					case 2:
						if(printClientes(clienteList, clienteLen) == 0 &&
						   cargarPedidoRecoleccion(pedidoList, QTY_PEDIDO, &id, clienteList, QTY_CLIENTE) != -1)
						{
							printf("\nSe ha cargado el pedido exitosamente");
						}
						else
						{
							printf("\nNo se ha podido cargar el pedido");
						}
						break;
				}
			}
		}while(option!= 3);
		resultado = 0;
	}

	return resultado;
}

int isPedidoListEmpty(Pedido* list, int len)
{
	int resultado = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty == FALSE_P)
			{
				resultado = 0;
				break;
			}
		}
	}

	return resultado;
}



