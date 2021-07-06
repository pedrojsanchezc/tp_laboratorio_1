/*
 * Clientes.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */
#include "Clientes.h"

void eClientes_Inicializar(eCliente listaClientes[], int tamC)
{
    int i;

    for(i=0; i<tamC; i++)
    {
        listaClientes[i].estadoCliente = VACIO;
    }

}

int eClientes_BuscarIDClientes(eCliente listaClientes[], int tamC, int idCliente)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamC; i++)
	{
		if (listaClientes[i].idCliente == idCliente)
		{
			index = i;
			break;
		}
	}
	return index;
}

int eClientes_BuscarLibreClientes(eCliente listaClientes[], int tamC)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaClientes != NULL)
	    {
			for(i=0; i<tamC; i++)
			{
				if(listaClientes[i].estadoCliente == VACIO || listaClientes[i].estadoCliente == BAJA)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

void eClientes_ImprimirClientes(eCliente listaClientes[], int tamC)
{
	int i;

	for(i=0;i<tamC;i++)
	{
		eClientes_ImprimirUnCliente(listaClientes[i]);
	}

}

void eClientes_ImprimirUnCliente(eCliente miCliente)
{
	if (miCliente.estadoCliente == OCUPADO)
	{
		printf("%d %s %s \n", miCliente.idCliente,
				miCliente.nombre,
				miCliente.apellido
				);
	}
}

void eClientes_HardcodeoDatosClientes(eCliente listaClientes[], int tamC, int minId)
{

    int i;
    eCliente listaAux[] = {
                                {minId++,"Pedro","Martinez", OCUPADO},
								{minId++,"Jose","Gomez", OCUPADO},
								{minId++,"Maria" ,"Renteria", OCUPADO},
								{minId++,"Pablo","Perez", OCUPADO},
								{minId++,"Teresa","Boca", OCUPADO}
    };

    for(i = 0; i < tamC; i++)
    {
    	listaClientes[i].idCliente = listaAux[i].idCliente;
    	strcpy(listaClientes[i].nombre,listaAux[i].nombre);
    	strcpy(listaClientes[i].apellido,listaAux[i].apellido);
    	listaClientes[i].estadoCliente = listaAux[i].estadoCliente;
    }

    printf("Hardcodeado correctamente\n");
}

