/*
 * Controller.c
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#include "Controller.h"

void Menu(void){
	printf("1. ALTA\n");
	printf("2. MODIFICACION\n");
	printf("3. BAJA\n");
	printf("4. LISTA  TRABAJOS\n");
	printf("5. LISTA  SERVICIOS\n");
	printf("6. TOTAL DE SERVICIOS PRESTADOS\n");
	printf("7. LISTA DE  TRABAJOS POR MARCA\n");
	printf("8. LISTA DE SERVICIO/S CON MAS TRABAJOS\n");
	printf("9. LISTA DE SERVICIO/S CON DATOS DE BICICLETAS QUE SE LO REALIZARON\n");
	printf("10. CANTIDAD BICICLETA/S DE COLOR ROJO QUE REALIZARON UN SERVICIO (Elegir cuál servicio)\n");
	printf("11. LISTA DE TRABAJOS ORDENADOS POR CLIENTE\n");
	printf("12. TOTAL POR CLIENTE\n");
	printf("13. SALIR\n");
}

int CargarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor)
{
    int index;

    index = eTrabajo_ObtenerIndexLibre(listaTrabajos, tamT);

    if(index != -1)
    {
        listaTrabajos[index] = PedirDatos(listaServicios, listaBicicletas, listaClientes, tamS, tamB, tamC, anioActual, maxDescripcion, maxMarca, minID, maxColor);
        listaTrabajos[index].idTrabajo = index + 1;
    }
    return index;
}

int ModificarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int anioActual, int maxDescripcion, int maxMarca)
{
	int estado;
	int indexID;
	int auxInt;
	int indexServicios;
	int idTrabajo;
	int estadoImprimir;
	int estadoValidarOpcion;
	int contadorValidarOpcion;
	int contadorValidarId;
	int validIDServicios;
	int opcionSegun;

	estado = -1;
	validIDServicios = 0;

	estadoImprimir = ImprimirTrabajos(listaTrabajos, listaServicios, listaBicicletas, tamT, tamS, tamB, maxDescripcion, maxMarca);

	if (estadoImprimir == OCUPADO)
	{
		do
		{

			idTrabajo = PedirEntero("Ingrese ID de Trabajo a modificar:", "Dato ingresado no válido");
			indexID = eTrabajo_BuscarIDTrabajos(listaTrabajos, tamT, idTrabajo);

			if(indexID == -1)
			{
				printf("ID no disponible. Ingrese alguna de las opciones mostradas anteriormente. \n");
				contadorValidarId++;
			}
			else
			{
				estado = 1;
			}

			if (contadorValidarId == 3)
			{
				printf("Se ha llegado al máximo de intentos. Revise las opciones disponibles y reintente. \n");
				break;
			}

		}while(indexID == -1);

		if (indexID != -1)
		{
			do
			{
				printf("Campos disponibles: \n");
				printf("1. ID SERVICIO\n");
				printf("2. FECHA \n");
				printf("3. Salir \n");
				opcionSegun = PedirEntero("Ingrese una opción:", "Dato ingresado inválido");
				estadoValidarOpcion = ValidarEnteroConRango(opcionSegun, 1, 3);

				if (estadoValidarOpcion == -1)
				{
					printf("Ingrese una opción disponible!!! \n");
					contadorValidarOpcion++;
				}

				if (contadorValidarOpcion == 3)
				{
					printf("Se ha llegado al máximo de intentos. Revise las opciones disponibles y reintente. \n");
					break;
				}

			}while(estadoValidarOpcion == -1);

			if (contadorValidarOpcion < 3)
			{
				switch (opcionSegun)
				{
					case 1:
						do
						{
							eServicio_ImprimirServicios(listaServicios, tamS);
							auxInt = PedirEntero("Ingrese ID Servicio: ", "Dato ingresado no válido");
							indexServicios = eServicio_BuscarIDServicios(listaServicios, tamS, auxInt);

							if (indexServicios == -1)
							{
								printf("No se encontro ID. Revise lista de IDs disponibles y reintente. \n");
								validIDServicios++;

								if (validIDServicios == 3)
								{
									printf("Se ha llegado al máximo de intentos. Revise los ID disponibles y reintente. \n");
									break;
								}
							}
							else
							{
								listaTrabajos[indexID].idServicio = auxInt;
								estado = 1;
							}

						}while(indexServicios == -1);
						break;
					case 2:
						listaTrabajos[indexID].fecha = PedirFecha(anioActual);
						break;
					default:
						break;
				}
			}
		}
	}

	return estado;
}

eTrabajo PedirDatos(eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor)

{
    eTrabajo TrabajoNuevo;
    int indexServicios;
    int auxInt;
    int validIDServicios;
    int validacion;
    int contadorValidacion;
    int opcion;

    validIDServicios = 0;
    TrabajoNuevo.estadoTrabajo = VACIO;

    do{

		ImprimirBicicletas(listaBicicletas, listaClientes,tamB,tamC);
		opcion = PedirEntero("Ingrese el id de la bicicleta:","Dato Ingresado no válido");
		validacion = ValidarEnteroConRango(opcion,25,32);
		if (validacion <0)
		{
			printf("Ingrese una opcion válida!!! \n");
			contadorValidacion++;
			if (contadorValidacion == 3)
			{
				printf("Se han acabado el máximo de intentos. Revise las opciones disponibles y reintente. \n");
				break;
			}
		}
    }while(validacion<0);

    if (contadorValidacion <3)
    {
		do
		{
			eServicio_ImprimirServicios(listaServicios, tamS);
			auxInt = PedirEntero("Ingrese ID Servicio: ", "Dato ingresado no válido");
			indexServicios = eServicio_BuscarIDServicios(listaServicios, tamS, auxInt);
			if (indexServicios == -1)
			{
				printf("No se encontro ID. Revise lista de IDs disponibles y reintente. \n");
				validIDServicios++;
				if (validIDServicios == 3)
				{
					printf("Se ha llegado al máximo de intentos. Revise los ID disponibles y reintente. \n");
					break;
				}
			}
			else
			{
				TrabajoNuevo.idServicio = auxInt;
			}
		}while(indexServicios == -1);
		if (indexServicios != -1)
		{
			TrabajoNuevo.fecha= PedirFecha(anioActual);
			TrabajoNuevo.estadoTrabajo = OCUPADO;
		}
    }
    return TrabajoNuevo;
}

int ImprimirTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca)
{
	int i;
	int estado;

	estado = -1;

	if (eTrabajo_ValidarArrayOcupadoTrabajos(listaTrabajos,tamT) == OCUPADO)
	{

		for(i=0;i<tamT;i++)
		{
			if (listaTrabajos[i].estadoTrabajo == OCUPADO)
			{
				ImprimirUnTrabajo(listaTrabajos[i], listaServicios, listaBicicletas, tamS, tamB, maxDescripcion, maxMarca);
			}
		}

		estado = 1;
	}

	return estado;

}

void ImprimirUnTrabajo(eTrabajo miTrabajo, eServicio listaServicios[], eBicicleta listaBicicletas[],int tamS, int tamB, int maxDescripcion, int maxMarca)
{

	int indexIDServicio;
	int indexBici;
	int miDia;
	int miMes;
	int miAnio;
	char miMarcaBicicleta[maxMarca];
	int miRodadoBicicleta;
	char miServicio[maxDescripcion];


	indexIDServicio = eServicio_BuscarIDServicios(listaServicios, tamS, miTrabajo.idServicio);
	strcpy(miServicio, listaServicios[indexIDServicio].descripcion);
	indexBici = eBicicleta_BuscarIDBicicletas(listaBicicletas, tamB, miTrabajo.idBicicleta);
	strcpy(miMarcaBicicleta,listaBicicletas[indexBici].marcaBicicleta);
	miRodadoBicicleta = listaBicicletas[indexBici].rodadoBicicleta;
	miDia = miTrabajo.fecha.dia;
	miMes = miTrabajo.fecha.mes;
	miAnio = miTrabajo.fecha.anio;


	printf("%d %s %d %s %d/%d/%d\n", miTrabajo.idTrabajo,
			miMarcaBicicleta,
			miRodadoBicicleta,
			miServicio,
			miDia,
			miMes,
			miAnio);
}

void DarDeBajaTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca)
{
	int idTrabajo;
	int indexTrabajo;
	int estadoMostrarTrabajos;
	int estadoValidacionTrabajo;

	estadoMostrarTrabajos = ImprimirTrabajos(listaTrabajos, listaServicios, listaBicicletas, tamT, tamS, tamB, maxDescripcion, maxMarca);

	if (estadoMostrarTrabajos != -1)
	{
		idTrabajo = PedirEntero("Ingrese ID de Trabajo a eliminar:", "Dato ingresado no válido");

		indexTrabajo = eTrabajo_BuscarIDTrabajos(listaTrabajos, tamT, idTrabajo);

		if(indexTrabajo != -1)
		{
			estadoValidacionTrabajo = eTrabajo_ValidarParaDarDeBajaTrabajo(listaTrabajos[indexTrabajo]);

			if (estadoValidacionTrabajo != -1)
			{
				listaTrabajos[indexTrabajo].estadoTrabajo = BAJA;
				printf("El Trabajo se eliminó correctamente.\n");
			}
		}
		else
		{
			printf("No existe un Trabajo con ese ID\n");
		}
	}
	else
	{
		printf("No hay Trabajos para eliminar.\n");
	}

}

void TotalEnPesosPorServicios(eTrabajo listaTrabajos[], eServicio listaServicios[], int tamT, int tamS, int maxDescripcion)
{
	int i;
	eAuxiliar listaAuxServicios[tamS];
	int indexIDAuxiliar;

	for (i=0;i<tamS;i++)
	{
		listaAuxServicios[i].idAuxiliar = listaServicios[i].idServicio;
		listaAuxServicios[i].contador = 0;
		listaAuxServicios[i].acumulador = 0;
		strcpy(listaAuxServicios[i].descripcion,listaServicios[i].descripcion);
		listaAuxServicios[i].estadoAuxiliar = OCUPADO;
	}

	for (i=0;i<tamT;i++)
	{
		indexIDAuxiliar = eServicio_BuscarIDServicios(listaServicios,tamS,listaTrabajos[i].idServicio);
		if (indexIDAuxiliar != -1)
		{
			listaAuxServicios[indexIDAuxiliar].contador++;
			listaAuxServicios[indexIDAuxiliar].acumulador += listaServicios[indexIDAuxiliar].precio;
		}
	}

	printf("Este es el total en $ según tipo de servicio: \n");
	printf("ID	CANTIDAD	PRECIO	DESCRIPCION \n");
	eAuxiliar_ImprimirAuxiliares(listaAuxServicios, tamS);

}


int ListarTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca)
{
	int i;
	int j;
	int indexBici;
	int indexBiciDos;
	int estado;
	eTrabajo auxTrabajo;

	for (i=0;i<tamT-1;i++)
	{
		for(j=i+1;j<tamT;j++)
		{
			if(listaTrabajos[i].fecha.anio < listaTrabajos[j].fecha.anio)
			{
				auxTrabajo = listaTrabajos[i];
				listaTrabajos[i] = listaTrabajos[j];
				listaTrabajos[j] = auxTrabajo;
			}
		}
	}

	for (i=0;i<tamT-1;i++)
	{
		for(j=i+1;j<tamT;j++)
		{
			if(listaTrabajos[i].fecha.anio == listaTrabajos[j].fecha.anio)
			{
				indexBici = eBicicleta_BuscarIDBicicletas(listaBicicletas, tamB, listaTrabajos[i].idBicicleta);
				indexBiciDos = eBicicleta_BuscarIDBicicletas(listaBicicletas, tamB, listaTrabajos[j].idBicicleta);
				printf("valor id: %d \n", indexBici);
				if (strcmp(listaBicicletas[indexBici].marcaBicicleta,listaBicicletas[indexBiciDos].marcaBicicleta) < 0)
				{
					auxTrabajo = listaTrabajos[i];
					listaTrabajos[i] = listaTrabajos[j];
					listaTrabajos[j] = auxTrabajo;
				}
			}
		}
	}

	estado = ImprimirTrabajos(listaTrabajos, listaServicios, listaBicicletas, tamT, tamS, tamB, maxDescripcion, maxMarca);


	return estado;
}

int TrabajosOrdenadosPorMarca(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca)
{
	int estado = -1;
	int i;
	int j;
	int indexBici;
	int indexBiciDos;
	int diferencia;
	eTrabajo auxTrabajo;

	for (i=0;i<tamT-1;i++)
	{
		for(j=i+1;j<tamT;j++)
		{
			indexBici = eBicicleta_BuscarIDBicicletas(listaBicicletas, tamB, listaTrabajos[i].idBicicleta);
			indexBiciDos = eBicicleta_BuscarIDBicicletas(listaBicicletas, tamB, listaTrabajos[j].idBicicleta);

			diferencia = strcmp(listaBicicletas[indexBici].marcaBicicleta,listaBicicletas[indexBiciDos].marcaBicicleta);

			if (diferencia < 0)
			{
				auxTrabajo=listaTrabajos[i];
				listaTrabajos[i]=listaTrabajos[j];
				listaTrabajos[j]=auxTrabajo;
			}
		}
	}

	estado = ImprimirTrabajos(listaTrabajos, listaServicios, listaBicicletas, tamT, tamS, tamB, maxDescripcion, maxMarca);


	return estado;

}

int ServicioConMasTrabajosRealizados(eTrabajo listaTrabajos[],eServicio listaServicios[], int tamT, int tamS, int maxDescripcion)
{
	int estado = -1;
	int idServicio;
	int i;
	eAuxiliar servicioLimpieza;
	eAuxiliar servicioParche;
	eAuxiliar servicioCentrado;
	eAuxiliar servicioCadena;

	servicioLimpieza.contador = 0;
	strcpy(servicioLimpieza.descripcion,"Limpieza");
	servicioParche.contador = 0;
	strcpy(servicioParche.descripcion,"Parche");
	servicioCentrado.contador = 0;
	strcpy(servicioCentrado.descripcion,"Centrado");
	servicioCadena.contador = 0;
	strcpy(servicioCadena.descripcion,"Cadena");

	for (i=0;i<tamT;i++)
	{
		idServicio = listaTrabajos[i].idServicio;

		switch (idServicio)
		{
			case 20000:
				servicioLimpieza.contador++;
				break;
			case 20001:
				servicioParche.contador++;
				break;
			case 20002:
				servicioCentrado.contador++;
				break;
			case 20003:
				servicioCadena.contador++;
				break;
		}

		estado = 1;

	}

	if ( servicioLimpieza.contador >= servicioParche.contador && servicioLimpieza.contador >= servicioCentrado.contador && servicioLimpieza.contador >= servicioCadena.contador)
	{
		printf("El servicio con más trabajos realizados es el de %s con %d trabajos cargados.\n",servicioLimpieza.descripcion,servicioLimpieza.contador);
	}

	if (servicioParche.contador >= servicioLimpieza.contador &&  servicioParche.contador >= servicioCentrado.contador && servicioParche.contador >= servicioCadena.contador)
	{
		printf("El servicio con más trabajos realizados es el de %s con %d trabajos cargados.\n",servicioParche.descripcion,servicioParche.contador);
	}

	if (servicioCentrado.contador >= servicioParche.contador && servicioCentrado.contador >= servicioLimpieza.contador && servicioCentrado.contador >= servicioCadena.contador)
	{
		printf("El servicio con más trabajos realizados es el de %s con %d trabajos cargados.\n",servicioCentrado.descripcion,servicioCentrado.contador);
	}

	if (servicioCadena.contador >= servicioParche.contador && servicioCadena.contador >= servicioCentrado.contador && servicioCadena.contador  >= servicioLimpieza.contador)
	{
		printf("El servicio con más trabajos realizados es el de %s con %d trabajos cargados.\n",servicioLimpieza.descripcion,servicioLimpieza.contador);
	}



	return estado;

}

int ServiciosConDatosDeLasBicicletas(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxNombre, int maxApellido)
{
	int estado = -1;
	int i;
	int indexBici;
	int indexServicio;

	for(i=0;i<tamT;i++)
	{
		if (listaTrabajos[i].estadoTrabajo == OCUPADO)
		{
			indexBici=eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,listaTrabajos[i].idBicicleta);
			indexServicio=eServicio_BuscarIDServicios(listaServicios,tamS,listaTrabajos[i].idServicio);

			printf("----------------------------------\n");
			printf("Se realizó el siguiente servicio: \n");

			eServicio_ImprimirUnServicio(listaServicios[indexServicio]);

			printf("En la siguiente Bicicleta: \n");

			ImprimirUnaBicicleta(listaBicicletas[indexBici],listaClientes,tamC);
			printf("----------------------------------\n");
		}
	}

	if (indexBici > 0 && indexServicio > 0)
	{
		estado = 1;
	}

	return estado;
}

int CantidadBicicletasColorRojoPorServicio(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],int tamT,int tamS, int tamB, int maxDescripcion, int maxMarca)
{
	int estado = -1;
	int indexBici;
	int indexServicios;
	int opcion;
	int validacion;
	int cantBicicletasRojas = 0;
	int i;

	opcion = PedirEntero("Elija un servicio:\n1.LIMPIEZA\n2.PARCHE\n3.CENTRADO\n4.CADENA\n","Dato ingresado no válido");

	estado = ValidarEnteroConRango(opcion,1,4);

	if (estado >0)
	{
		switch (opcion)
		{
			case 1:
				opcion = 20000;
				break;
			case 2:
				opcion = 20001;
				break;
			case 3:
				opcion = 20002;
				break;
			default:
				opcion = 20003;
				break;
		}

		for (i=0;i<tamT;i++)
		{
			if(listaTrabajos[i].idServicio == opcion)
			{
				indexServicios = eServicio_BuscarIDServicios(listaServicios,tamS,opcion);
				indexBici = eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,listaTrabajos[i].idBicicleta);
				validacion = eBicicleta_ValidarBicicletaRoja(listaBicicletas[indexBici]);
				if(validacion > 0)
				{
					cantBicicletasRojas++;
				}
			}
		}
	}

	printf("La cantidad de bicicletas rojas a las que se les hizo el servicio de %s es de: %d. \n",listaServicios[indexServicios].descripcion,cantBicicletasRojas);

	return estado;

}

void ImprimirBicicletas(eBicicleta listaBicicletas[], eCliente listaClientes[], int tamB, int tamC)
{
	int i;

	for(i=0;i<tamB;i++)
	{
	    ImprimirUnaBicicleta(listaBicicletas[i], listaClientes, tamC);
	}

}

void ImprimirUnaBicicleta(eBicicleta miBicicleta,eCliente listaClientes[], int tamC)
{
	int auxIdCliente;

	auxIdCliente = eClientes_BuscarIDClientes(listaClientes,tamC,miBicicleta.idCliente);

	printf("%d %s %s %s %d %s \n", miBicicleta.idBicicleta,
			listaClientes[auxIdCliente].nombre,
			listaClientes[auxIdCliente].apellido,
			miBicicleta.marcaBicicleta,
			miBicicleta.rodadoBicicleta,
			miBicicleta.colorBicicleta);
}

void eBicicleta_HardcodeoDatosBicicletas(eBicicleta listaBicicletas[], int tamB, int minId, int minIdC)
{

    int i;
    eBicicleta listaAux[] = {
                                {minId++,1000,"BMX",12,"rojo", OCUPADO},
								{minId++,1001,"MONTANERA",22,"rojo", OCUPADO},
								{minId++,1002,"BMX" ,20,"azul", OCUPADO},
								{minId++,1003,"MONTANERA",26,"verde", OCUPADO},
								{minId++,1004,"BMX",18,"negro", OCUPADO},
								{minId++,1000,"MONTANERA",26,"rojo", OCUPADO},
								{minId++,1001,"BMX",18,"rojo", OCUPADO},
								{minId++,1002,"MONTANERA",26,"rojo", OCUPADO},
                                {minId++,1003,"BMX",22,"marron", OCUPADO},
                                {minId++,1004,"MONTANERA",14,"gris", OCUPADO}
    };

    for(i = 0; i < tamB; i++)
    {
    	listaBicicletas[i].idBicicleta = listaAux[i].idBicicleta;
    	listaBicicletas[i].idCliente = listaAux[i].idCliente;
    	strcpy(listaBicicletas[i].marcaBicicleta,listaAux[i].marcaBicicleta);
    	listaBicicletas[i].rodadoBicicleta = listaAux[i].rodadoBicicleta;
    	strcpy(listaBicicletas[i].colorBicicleta,listaAux[i].colorBicicleta);
    	listaBicicletas[i].estadoBicicleta = listaAux[i].estadoBicicleta;
    }

    printf("Hardcodeado con exito \n");
}

int ListarTrabajosSegunCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido)
{
	int estado = -1;
	int estadoTrabajo;
	int estadoTrabajoJ;
	int idTrabajo;
	char descServicio[maxDescripcion];
	char nombreCliente[maxNombre];
	char apellidoCliente[maxApellido];
	int idBicicleta;
	int idBicicletaJ;
	int idServicio;
	int idCliente;
	int idClienteJ;
	int indexBici;
	int indexBiciJ;
	int indexServicio;
	int indexCliente;
	char marcaBici[maxMarca];
	char colorBici[maxColor];
	int rodadoBici;
	float precioServicio;
	eTrabajo auxTrabajo;
	int i;
	int j;

	for(i=0;i<tamT-1;i++)
	{
		for(j=i+1;j<tamT;j++)
		{
			estadoTrabajo = listaTrabajos[i].estadoTrabajo;
			estadoTrabajoJ = listaTrabajos[j].estadoTrabajo;

			if (estadoTrabajo == OCUPADO && estadoTrabajoJ == OCUPADO)
			{
				idBicicleta = listaTrabajos[i].idBicicleta;
				idBicicletaJ = listaTrabajos[j].idBicicleta;
				indexBici = eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,idBicicleta);
				indexBiciJ = eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,idBicicletaJ);
				idCliente=listaBicicletas[indexBici].idCliente;
				idClienteJ=listaBicicletas[indexBiciJ].idCliente;

				if(idCliente < idClienteJ)
				{
					auxTrabajo = listaTrabajos[i];
					listaTrabajos[i] = listaTrabajos[j];
					listaTrabajos[j] = auxTrabajo;
				}
			}
		}
	}

	for(i=0;i<tamT;i++)
	{
		estadoTrabajo = listaTrabajos[i].estadoTrabajo;

		if (estadoTrabajo == OCUPADO )
		{
			idBicicleta = listaTrabajos[i].idBicicleta;
			indexBici= eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,idBicicleta);
			idServicio= listaTrabajos[i].idServicio;
			indexServicio = eServicio_BuscarIDServicios(listaServicios,tamS,idServicio);
			idCliente = listaBicicletas[indexBici].idCliente;
			indexCliente = eClientes_BuscarIDClientes(listaClientes,tamC,idCliente);
			idTrabajo = listaTrabajos[i].idTrabajo;
			strcpy(descServicio,listaServicios[indexServicio].descripcion);
			strcpy(nombreCliente,listaClientes[indexCliente].nombre);
			strcpy(apellidoCliente,listaClientes[indexCliente].apellido);
			strcpy(marcaBici,listaBicicletas[indexBici].marcaBicicleta);
			strcpy(colorBici,listaBicicletas[indexBici].colorBicicleta);
			rodadoBici = listaBicicletas[indexBici].rodadoBicicleta;
			precioServicio = listaServicios[indexServicio].precio;

			if(i==0)
			{
				printf("|-------------------------------------------------------------------------------------------------------|\n");
				printf("| ID TRABAJO | DESC. SERVICIO | N Y A CLIENTE | MARCA BICI | COLOR BICI | RODADO BICI | PRECIO SERVICIO |\n");
				printf("|____________|________________|_______________|____________|____________|_____________|_________________|\n");
			}
			if(idBicicleta == listaBicicletas[indexBici].idBicicleta)
			{
				printf("| %d | %s | %s %s | %s | %s | %d | $%f |\n",idTrabajo,descServicio,nombreCliente,apellidoCliente,marcaBici,colorBici,rodadoBici,precioServicio);
				printf("|-------------------------------------------------------------------------------------------------------|\n");
			}
			estado = 1;
		}
	}
	return estado;
}

int TotalServiciosPorCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido)
{
	int estado = -1;
	int estadoTrabajo;
	int idBicicleta;
	int idServicio;
	int idCliente;
	int idAuxCliente;
	int indexBici;
	int indexServicio;
	float precioServicio;
	eAuxiliar auxCliente[tamC];
	int i;
	int j;

	for(i=0;i<tamC;i++)
	{
		auxCliente[i].idAuxiliar = listaClientes[i].idCliente;
		auxCliente[i].acumulador = 0;
		auxCliente[i].contador = 0;
		strcpy(auxCliente[i].descripcion,listaClientes[i].nombre);
		strcat(auxCliente[i].descripcion," ");
		strcat(auxCliente[i].descripcion,listaClientes[i].apellido);
	}

	for(i=0;i<tamT;i++)
	{
		estadoTrabajo = listaTrabajos[i].estadoTrabajo;

		if (estadoTrabajo == OCUPADO )
		{
			idBicicleta = listaTrabajos[i].idBicicleta;
			indexBici= eBicicleta_BuscarIDBicicletas(listaBicicletas,tamB,idBicicleta);
			idServicio= listaTrabajos[i].idServicio;
			indexServicio = eServicio_BuscarIDServicios(listaServicios,tamS,idServicio);
			idCliente = listaBicicletas[indexBici].idCliente;
			precioServicio = listaServicios[indexServicio].precio;

			for (j=0;j<tamC;j++)
			{
				idAuxCliente = auxCliente[j].idAuxiliar;
				if (idCliente == idAuxCliente)
				{
					auxCliente[j].acumulador += precioServicio;
				}
			}
		}
	}
	for(i=0;i<tamC;i++)
	{
		if(i==0)
		{
			printf("|------------------------------------|\n");
			printf("| ID CLIENTE | N Y A CLIENTE | TOTAL |\n");
			printf("|____________|_______________|_______|\n");
		}
		if(idBicicleta == listaBicicletas[indexBici].idBicicleta)
		{
			printf("| %d | %s | $%f |\n",auxCliente[i].idAuxiliar,auxCliente[i].descripcion,auxCliente[i].acumulador);
			printf("|---------------|\n");
		}
		estado = 1;
	}
	return estado;
}
