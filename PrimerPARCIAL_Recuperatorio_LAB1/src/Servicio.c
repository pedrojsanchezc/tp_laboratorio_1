#include "Servicio.h"

void eServicio_Inicializar(eServicio listaServicios[], int tamS)
{
    int i;

    for(i=0; i<tamS; i++)
    {
        listaServicios[i].estadoServicio = VACIO;
    }

}

int eServicio_ObtenerIndexLibre(eServicio listaServicios[], int tamS)
{

	    int i;
	    int indexBL;

	    indexBL = -1;

	    if (listaServicios != NULL)
	    {
			for(i=0; i<tamS; i++)
			{
				if(listaServicios[i].estadoServicio == VACIO || listaServicios[i].estadoServicio == BAJA)
				{
					indexBL = i;
					break;
				}
			}
	    }

	    return indexBL;
}

int eServicio_BuscarIDServicios(eServicio listaServicios[], int tamS, int idServicio)
{
	int i;
	int index;

	index = -1;


	for (i=0; i < tamS; i++)
	{
		if (listaServicios[i].idServicio == idServicio)
		{
			index = i;
			break;
		}
	}


	return index;
}


void eServicio_ImprimirServicios(eServicio listaServicios[], int tamS)
{
	int i;

	for(i=0;i<tamS;i++)
	{
		eServicio_ImprimirUnServicio(listaServicios[i]);
	}

}

void eServicio_ImprimirUnServicio(eServicio miServicio)
{
	printf("%d %s %f \n", miServicio.idServicio,
			miServicio.descripcion,
			miServicio.precio);
}

void eServicio_HardcodeoDatosServicios(eServicio listaServicios[], int tamS, int minId)
{
    int i;
    eServicio listaAux[] = {
                                {minId++, "Limpieza", 250, OCUPADO},
								{minId++, "Parche", 300, OCUPADO},
								{minId++, "Centrado", 400, OCUPADO},
								{minId++, "Cadena", 350, OCUPADO}
    };

    for(i = 0; i < tamS; i++)
    {
    	listaServicios[i].idServicio = listaAux[i].idServicio;
    	strcpy(listaServicios[i].descripcion,listaAux[i].descripcion);
    	listaServicios[i].precio = listaAux[i].precio;
    	listaServicios[i].estadoServicio = listaAux[i].estadoServicio;
    }

    printf("Hardcodeado con exito \n");
}

int eServicio_ValidarArrayOcupadoServicios(eServicio listaServicios[], int tamS)
{
	int i;
	int estado;

	estado = -1;

	for(i=0; i < tamS; i++)
	{

		if(listaServicios[i].estadoServicio == OCUPADO)
		{
			estado = OCUPADO;
			break;
		}
	}

	return estado;
}

