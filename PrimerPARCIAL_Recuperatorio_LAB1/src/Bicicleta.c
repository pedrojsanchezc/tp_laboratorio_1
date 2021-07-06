/*
 * Bicicleta.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */
#include "Bicicleta.h"

void eBicicleta_Inicializar(eBicicleta listaBicicletas[], int tamB)
{
    int i;

    for(i=0; i<tamB; i++)
    {
        listaBicicletas[i].estadoBicicleta = VACIO;
    }

}

int eBicicleta_BuscarLibreBicicletas(eBicicleta listaBicicletas[], int tamB)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaBicicletas != NULL)
	    {
			for(i=0; i<tamB; i++)
			{
				if(listaBicicletas[i].estadoBicicleta == VACIO || listaBicicletas[i].estadoBicicleta == BAJA)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

int eBicicleta_BuscarIDBicicletas(eBicicleta listaBicicletas[], int tamB, int idBicicleta)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamB; i++)
	{
		if (listaBicicletas[i].idBicicleta == idBicicleta)
		{
			index = i;
			break;
		}
	}


	return index;
}




int eBicicleta_ValidarArrayOcupadoBicicletas(eBicicleta listaBicicletas[], int tamB)
{
	int i;
	int estado;

	estado = -1;

	for(i=0; i < tamB; i++)
	{

		if(listaBicicletas[i].estadoBicicleta == OCUPADO)
		{
			estado = OCUPADO;
			break;
		}
	}

	return estado;
}

eBicicleta eBicicleta_PedirBicicleta(int indexBici, int tamB, int minID, int maxMarca, int maxColor)
{
	int auxInt;
	int estadoRodado;
	int validRodado;

	eBicicleta auxBici;


	auxBici.idBicicleta = minID + indexBici;
	PedirCadena(auxBici.marcaBicicleta, maxMarca,"Ingrese marca de bicicleta:", "Dato ingresado incorrecto");

	do
	{
		auxInt = PedirEntero("Ingrese rodado de bicicleta (Opciones: 12, 14, 16, 18, 20, 22, 24, 26): ", "Dato ingresado incorrecto");

		switch(auxInt)
		{
			case 12:
			case 14:
			case 16:
			case 18:
			case 20:
			case 22:
			case 24:
			case 26:
				auxBici.rodadoBicicleta = auxInt;
				estadoRodado = 1;
				break;
			default:
				printf("Ingresar un rodado no disponible. Revise las opciones y reintente. \n");
				estadoRodado = -1;
				validRodado++;
		}

		if (validRodado == 3)
		{
			printf("Se ha llegado al maximo de intentos. Revise los ID disponibles y reintente. \n");
			break;
		}

	}while(estadoRodado != 1);

	PedirCadena(auxBici.colorBicicleta, maxColor,"Ingrese color de bicicleta:", "Dato ingresado incorrecto");

	auxBici.estadoBicicleta = OCUPADO;

	return auxBici;
}

int eBicicleta_ValidarBicicletaRoja(eBicicleta miBicicleta)
{
	int estado = 1;
	char rojo[10] = "rojo";
	int validacion;

	validacion = strcmp(miBicicleta.colorBicicleta,rojo);

	if (validacion != 0)
	{
		estado = -1;
	}

	return estado;
}


