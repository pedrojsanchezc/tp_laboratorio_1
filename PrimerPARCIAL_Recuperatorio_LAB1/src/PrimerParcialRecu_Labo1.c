/*
 ============================================================================
 Name        : PrimerParcialRecu_Labo1.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"

int main(void) {

    setbuf(stdout, NULL);

    eTrabajo listaTrabajos[MAX_TRABAJOS];
    eServicio listaServicios[MAX_SERVICIOS];
    eBicicleta listaBicicletas[MAX_BICICLETAS];
    eCliente listaClientes[MAX_CLIENTES];

    int estado;
    int estadoOpcion;
    int estadoMenu;
    int opcion;

    eTrabajo_Inicializar(listaTrabajos, MAX_TRABAJOS);
    eServicio_Inicializar(listaServicios, MAX_SERVICIOS);
    eClientes_Inicializar(listaClientes, MAX_CLIENTES);
    eBicicleta_Inicializar(listaBicicletas, MAX_BICICLETAS);

    eServicio_HardcodeoDatosServicios(listaServicios, MAX_SERVICIOS, MIN_ID_SERVICIOS);
    eBicicleta_HardcodeoDatosBicicletas(listaBicicletas, MAX_BICICLETAS, MIN_ID_BICICLETAS, MIN_ID_CLIENTES);
    eTrabajo_HardcodeoDatosTrabajos(listaTrabajos, MAX_TRABAJOS, 1, MIN_ID_BICICLETAS, ANIO_ACTUAL);
    eClientes_HardcodeoDatosClientes(listaClientes, MAX_CLIENTES, MIN_ID_CLIENTES);



    do
    {
    	do
    	{
    		Menu();
			opcion = PedirEntero("Elija una opcion:","Dato ingresado no válido");
			estadoOpcion = ValidarEnteroConRango(opcion,1,13);
			if (estadoOpcion != -1)
			{
				switch (opcion)
				{
					default:
						estadoMenu = 1;
						break;
				}
			}
    	}while(estadoMenu != 1);


        switch(opcion)
        {
            case 1:
            	estado = CargarTrabajo(listaTrabajos,listaServicios, listaBicicletas, listaClientes, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, ANIO_ACTUAL , MAX_DESCRIPCION, MAX_MARCA, MIN_ID_BICICLETAS, MAX_COLOR);

            	if(estado != -1)
                {
                	printf("Trabajo cargado correctamente. \n");
                }
                else
                {
                	if (eTrabajo_ValidarArrayOcupadoTrabajos(listaTrabajos,MAX_TRABAJOS) != OCUPADO)
                	{
                		printf("ESPACIO OCUPADO. Elimine \n");
                	}
                	else
                	{
                		printf("Trabajo no cargado correctamente. Reintente nuevamente \n");
                	}

                }
            	break;
            case 2:
            	estado = ModificarTrabajo(listaTrabajos,listaServicios, listaBicicletas, MAX_TRABAJOS,MAX_SERVICIOS, MAX_BICICLETAS, ANIO_ACTUAL, MAX_DESCRIPCION, MAX_MARCA);
                if(estado != -1)
                {
                	printf("Trabajo modificado correctamente. \n");
                }
                else
                {
					printf("Trabajo no cargado correctamente. Reintente nuevamente  \n");
                }
            	break;
            case 3:
            	DarDeBajaTrabajo(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS,MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	break;
            case 4:
            	estado = ListarTrabajos(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);

            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;
            case 5:
            	eServicio_ImprimirServicios(listaServicios, MAX_SERVICIOS);
            	break;
            case 6:
				TotalEnPesosPorServicios(listaTrabajos, listaServicios, MAX_TRABAJOS, MAX_SERVICIOS, MAX_DESCRIPCION);
				break;
            case 7:
            	estado = TrabajosOrdenadosPorMarca(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;
           case 8:
            	estado = ServicioConMasTrabajosRealizados(listaTrabajos, listaServicios, MAX_TRABAJOS, MAX_SERVICIOS, MAX_DESCRIPCION);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar\n");
                }
            	break;
            case 9:
            	estado = ServiciosConDatosDeLasBicicletas(listaTrabajos, listaServicios, listaBicicletas, listaClientes, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_NOMBRE,MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;
            case 10:
            	estado = CantidadBicicletasColorRojoPorServicio(listaTrabajos, listaServicios, listaBicicletas, MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_DESCRIPCION, MAX_MARCA);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;
            case 11:
            	estado = ListarTrabajosSegunCliente(listaTrabajos,listaServicios,listaBicicletas,listaClientes,MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_COLOR, MAX_NOMBRE, MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;
            case 12:
            	estado = TotalServiciosPorCliente(listaTrabajos,listaServicios,listaBicicletas,listaClientes,MAX_TRABAJOS, MAX_SERVICIOS, MAX_BICICLETAS, MAX_CLIENTES, MAX_DESCRIPCION, MAX_MARCA, MAX_COLOR, MAX_NOMBRE, MAX_APELLIDO);
            	if (estado != 1)
                {
					printf("No hay nada para mostrar \n");
                }
            	break;

        }
    }while(opcion!=13);

	return EXIT_SUCCESS;
}
