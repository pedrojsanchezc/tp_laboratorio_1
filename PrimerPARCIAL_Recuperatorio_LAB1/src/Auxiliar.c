/*
 * Auxiliar.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#include "Auxiliar.h"

int eAuxiliar_BuscarIDAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar,int idAuxiliar)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamAuxiliar; i++)
	{
		if (listaAuxiliar[i].idAuxiliar == idAuxiliar)
		{
			index = i;
			break;
		}
	}


	return index;
}

void eAuxiliar_ImprimirAuxiliares(eAuxiliar listaAuxiliar[], int tamAuxiliar)
{
	int i;

	for(i=0;i<tamAuxiliar;i++)
	{
		eAuxiliar_ImprimirUnAuxiliar(listaAuxiliar[i]);
	}

}

void eAuxiliar_ImprimirUnAuxiliar(eAuxiliar miAuxiliar)
{
	printf("%d %d %f %s \n", miAuxiliar.idAuxiliar,
			miAuxiliar.contador,
			miAuxiliar.acumulador,
			miAuxiliar.descripcion
			);
}
