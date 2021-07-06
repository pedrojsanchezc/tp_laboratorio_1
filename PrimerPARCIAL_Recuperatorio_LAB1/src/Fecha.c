/*
 * Fecha.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#include "Fecha.h"

eFecha PedirFecha(int anioActual)
{
    int validMes;
    int validDia;
    int estadoMes;
    int estadoDia;
    int estadoFecha;
    int auxDia;
    int auxMes;
    int auxAnio;
    eFecha miFecha;


    validMes = 0;
    validDia= 0;

    estadoFecha = 1;


    auxAnio = anioActual;


	do
	{
		auxMes = PedirEntero("Ingrese mes (desde 1 hasta 12):","Dato ingresado incorrecto.");
		estadoMes = ValidarEnteroConRango(auxMes, 1, 12);

		if (estadoMes == -1)
		{
			printf("Solo puede ingresar un mes desde el 1 al 12!!! \n");
			validMes++;
		}


		if (validMes ==3)
		{
			printf("Se ha llegado al maximo de intentos. Revise las condiciones de alta de fecha y reintente. \n");
			break;
		}

	}while(estadoMes == -1);

	if (validMes != 3)
	{
		do
		{
			if(auxMes != 2)
			{
				switch (auxMes)
				{
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
					case 12:
						auxDia = PedirEntero("Ingrese día (del 1 al 31):","Dato ingresado no válido.");
						estadoDia = ValidarEnteroConRango(auxDia, 1, 31);
						if (estadoDia == -1)
						{
							printf("Solo puede ingresar un dia desde el 1 al 31!!! \n");
							validDia++;
						}
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						auxDia = PedirEntero("Ingrese día (del 1 al 30):","Dato ingresado no válido.");
						estadoDia = ValidarEnteroConRango(auxDia, 1, 30);
						if (estadoDia == -1)
						{
							printf("Solo puede ingresar un dia desde el 1 al 30!!! \n");
							validDia++;
						}
						else
						{
							estadoFecha = 1;
						}
						break;
				}
			}
			else
			{
				if (auxAnio % 4 == 0)
				{
					auxDia = PedirEntero("Ingrese día (del 1 al 29):","Dato ingresado no válido.");
					estadoDia = ValidarEnteroConRango(auxDia, 1, 29);
					if (estadoDia == -1)
					{
						printf("Solo puede ingresar un dia desde el 1 al 29!!! \n");
						validDia++;
					}
					else
					{
						estadoFecha = 1;
					}
				}
				else
				{
					auxDia = PedirEntero("Ingrese día (del 1 al 28):","Dato ingresado no válido.");
					estadoDia = ValidarEnteroConRango(auxDia, 1, 28);
					if (estadoDia == -1)
					{
						printf("Solo puede ingresar un dia desde el 1 al 28!!! \n");
						validDia++;
					}
					else
					{
						estadoFecha = 1;
					}
				}
			}

			if (validDia == 3)
			{
				printf("Se ha llegado al máximo de intentos. Revise las condiciones de alta de fecha y reintente. \n");
				estadoFecha = -1;
				break;
			}

		}while(estadoDia == -1);
    }


    if (estadoFecha != -1)
    {

		miFecha.anio = auxAnio;
		miFecha.mes = auxMes;
		miFecha.dia = auxDia;

    }

    return miFecha;
}


