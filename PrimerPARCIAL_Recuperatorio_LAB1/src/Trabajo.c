/*
 * Trabajo.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */


#include "Trabajo.h"

void eTrabajo_Inicializar(eTrabajo listaTrabajos[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaTrabajos[i].estadoTrabajo = VACIO;
    }


}

int eTrabajo_ObtenerIndexLibre(eTrabajo listaTrabajos[], int tamT)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaTrabajos != NULL)
	    {
			for(i=0; i<tamT; i++)
			{
				if(listaTrabajos[i].estadoTrabajo != OCUPADO)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

int eTrabajo_BuscarIDTrabajos(eTrabajo listaTrabajos[], int tamT, int idTrabajo)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamT; i++)
	{
		if (listaTrabajos[i].idTrabajo == idTrabajo)
		{
			index = i;
			break;
		}
	}


	return index;
}

int eTrabajo_ValidarArrayOcupadoTrabajos(eTrabajo listaTrabajos[], int tamT)
{
	int i;
	int estado;

	estado = -1;

	for(i=0; i < tamT; i++)
	{

		if(listaTrabajos[i].estadoTrabajo == OCUPADO)
		{
			estado = OCUPADO;
			break;
		}
	}

	return estado;
}

int eTrabajo_ValidarParaDarDeBajaTrabajo(eTrabajo TrabajoADarDeBaja)
{
	char respuesta;
	int estado;

	estado = -1;

	respuesta = PedirConfirmacion("Está seguro de que quiere eliminar el Trabajo %d? Escriba 's' o 'n' ", "Dato ingresado incorrecto");


	if(respuesta == 1)
	{
		estado = 1;

	}
	else
	{

		printf("Si respondio 'n' durante la confirmacion u ocurrio un inconveniente al eliminar el Trabajo.");
	}

	return estado;

}

void eTrabajo_HardcodeoDatosTrabajos(eTrabajo listaTrabajos[], int tamT, int minId, int minIdBicicleta, int anioActual)
{
    int i;
    eTrabajo listaAux[] = {
                                {minId++, minIdBicicleta++, 20000,{2021,12,15},OCUPADO},
								{minId++, minIdBicicleta++, 20000,{2020,12,20},OCUPADO},
								{minId++, minIdBicicleta++, 20000,{2019,1,22},OCUPADO},
								{minId++, minIdBicicleta++, 20001,{2021,12,24},OCUPADO},
								{minId++, minIdBicicleta++, 20001,{2020,12,15},OCUPADO},
								{minId++, minIdBicicleta++, 20002,{2019,1,15},OCUPADO},
								{minId++, minIdBicicleta++, 20002,{2021,12,24},OCUPADO},
								{minId++, minIdBicicleta++, 20003,{2020,8,22},OCUPADO}
    };


    for(i = 0; i < tamT; i++)
    {
    	listaTrabajos[i].idTrabajo = listaAux[i].idTrabajo;
    	listaTrabajos[i].idBicicleta = listaAux[i].idBicicleta;
    	listaTrabajos[i].idServicio = listaAux[i].idServicio;
    	listaTrabajos[i].fecha = listaAux[i].fecha;
    	listaTrabajos[i].estadoTrabajo = listaAux[i].estadoTrabajo;
    }

    printf("Hardcodeado con exito \n");
}






