/*
 * Controller.h
 *
 *  Created on: 4 jul. 2021
 *      Author: EXO02
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Fecha.h"
#include "Auxiliar.h"
#include "Bicicleta.h"
#include "Clientes.h"

/**
 * @fn void Menu(void)
 * @brief Muestra el menu de todo el listado
 *
 */
void Menu(void);
/**
 * @fn int CargarTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int, int, int)
 * @brief se llama a la función  BuscarLibreTrabajos, y si hay lugar en el array listaTrabajos, se llama a PedirDatos,
 * luego se le asigna un entero automaticamente a idTrabajo
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @param maxMarca
 * @return index
 */
int CargarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor);
/**
 * @fn eTrabajo PedirDatos(eServicio[], eFecha[], int, int, int, int, int)
 * @brief Se solicitan enteros y cadenas segun el campo y se retorna un eTrabajo con campos poblados por los datos antes solicitados
 *
 * @param listaServicios
 * @param listaFechas
 * @param maxMarca
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @return eTrabajo
 */
eTrabajo PedirDatos(eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamS, int tamB, int tamC, int anioActual, int maxDescripcion, int maxMarca, int minID, int maxColor);
/**
 * @fn int ModificarTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int, int, int)
 * @brief solicita un campo a modificar, y luego pide los datos para modificarlo. asigna -1 a estado si la modificación no fue exitosa, 1 si lo fue.
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param minAnio
 * @param maxAnio
 * @param maxDescripcion
 * @return estado
 */
int ModificarTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamT, int tamS,  int tamB, int anioActual, int maxDescripcion, int maxMarca);
/**
 * @fn int ImprimirTrabajos(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief muestra todos los campos de cada eTrabajo en el array menos estadoTrabajo, mientras tengan el campo estadoTrabajo == OCUPADO
 * y asigna el valor 1 a estado si el array no esta vacío, -1 si lo está
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 * @return estado
 */
int ImprimirTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void ImprimirUnTrabajo(eTrabajo, eServicio[], eFecha[], int, int, int)
 * @brief muestra todos los campos de cada eTrabajo en el array menos estadoTrabajo, mientras tengan el campo estadoTrabajo == OCUPADO
 * y busca los valores iguales de  idFecha e idServicio con los id de las estructuras eFecha y eServicio en listaFechas y listaServicios para mostrar
 * la fecha separada por / y la descripcion del servicio
 *
 * @param miTrabajo
 * @param listaServicios
 * @param listaFechas
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void ImprimirUnTrabajo(eTrabajo miTrabajo, eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamS,  int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void DarDeBajaTrabajo(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief muestra todos los trabajos con estadoTrabajo == OCUPADO y solicita el id del trabajo que se desea dar de baja, si el id se encuentra en el array listaTrabajos
 * se solicita confirmación, si se confirma se asigna BAJA a estadoTrabajo del elemento del array
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void DarDeBajaTrabajo(eTrabajo listaTrabajos[], eServicio listaServicios[],  eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn void TotalEnPesosPorServicios(eTrabajo[], eServicio[], eFecha[], int, int, int, int)
 * @brief se muestra el total en $ por servicio en trabajos registrados
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 */
void TotalEnPesosPorServicios(eTrabajo listaTrabajos[], eServicio listaServicios[],  int tamT, int tamS, int maxDescripcion);
/**
 * @fn int ListarTrabajos(eTrabajo[], eServicio[], eFecha, int, int, int, int, int)
 * @brief ordena desde el a�o mas reciente (si tienen el mismo año, por marca) los trabajos cargados, asigna 1 a estado si hay datos para mostrar, -1 si no
 *
 * @param listaTrabajos
 * @param listaServicios
 * @param listaFechas
 * @param tamT
 * @param tamS
 * @param tamF
 * @param maxDescripcion
 * @param maxMarca
 * @return estado
 */

int ListarTrabajos(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamT, int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn int ServicioConMasTrabajosRealizados(eTrabajo listaTrabajos[],eServicio listaServicios[], int tamT, int tamS, int maxDescripcion);
 *
 * @brief verifica y muestra al servicio relacionado con la mayor cantidad de trabajos
 * @param listaTrabajos
 * @param listaServicios
 * @param tamT
 * @param tamS
 * @param maxDescripcion
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int ServicioConMasTrabajosRealizados(eTrabajo listaTrabajos[],eServicio listaServicios[], int tamT, int tamS, int maxDescripcion);
/**
 * @fn int TrabajosOrdenadosPorMarca(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamS, int tamB, int tamT, int maxDescripcion, int maxMarca);
 *
 * @brief ordena y muestra los trabajos por marca
 * @param listaTrabajos
 * @param listaServicios
 * @param listaBicicletas
 * @param tamS
 * @param tamB
 * @param tamT
 * @param maxDescripcion
 * @param maxMarca
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int TrabajosOrdenadosPorMarca(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], int tamS, int tamB, int tamT, int maxDescripcion, int maxMarca);
/**
 * @fn int CantidadBicicletasColorRojoPorServicio(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],int tamT,int tamS, int tamB, int maxDescripcion, int maxMarca);
 *
 * @brief calcula y muestra la cantidad de bicicletas rojas
 * @param listaTrabajos
 * @param listaServicios
 * @param listaBicicletas
 * @param tamT
 * @param tamS
 * @param tamB
 * @param maxDescripcion
 * @param maxMarca
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int CantidadBicicletasColorRojoPorServicio(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],int tamT,int tamS, int tamB, int maxDescripcion, int maxMarca);
/**
 * @fn int ServiciosConDatosDeLasBicicletas(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxNombre, int maxApellido);
 *
 * @brief busca y muestra los servicios con los datos de las bicicletas a las que se los hicieron
 * @param listaTrabajos
 * @param listaServicios
 * @param listaBicicletas
 * @param listaClientes
 * @param tamT
 * @param tamS
 * @param tamB
 * @param tamC
 * @param maxDescripcion
 * @param maxMarca
 * @param maxNombre
 * @param maxApellido
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int ServiciosConDatosDeLasBicicletas(eTrabajo listaTrabajos[], eServicio listaServicios[], eBicicleta listaBicicletas[], eCliente listaClientes[], int tamT, int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxNombre, int maxApellido);
/**
 * @fn void ImprimirBicicletas(eBicicleta[], int)
 * @brief muestra todos los campos de cada eBicicleta en el array menos estadoBicicleta, mientras tengan el campo estadoBicicleta == OCUPADO
 *
 * @param listaBicicletas
 * @param tamB
 */
void ImprimirBicicletas(eBicicleta listaBicicletas[], eCliente listaClientes[], int tamB, int tamC);
/**
 * @fn void ImprimirUnBicicleta(eBicicleta)
 * @brief muestra todos los campos de un eBicicleta en el array menos estadoBicicleta
 *
 * @param miBicicleta
 */
void ImprimirUnaBicicleta(eBicicleta miBicicleta,eCliente listaClientes[], int tamC);
/**
 * @fn void eBicicleta_HardcodeoDatosBicicletas(eBicicleta[], int, int)
 * @brief asigna valores especificos a cada campo de un numero determinado elementos de listaBicicletas
 *
 * @param listaBicicletas
 * @param tamB
 * @param minId
 */
void eBicicleta_HardcodeoDatosBicicletas(eBicicleta listaBicicletas[], int tamB, int minId, int minIdC);
/**
 * @fn int ListarTrabajosSegunCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);
 *
 * @brief Lista los trabajos ordenados segun cliente
 * @param listaTrabajos
 * @param listaServicios
 * @param listaBicicletas
 * @param listaClientes
 * @param tamT
 * @param tamS
 * @param tamB
 * @param tamC
 * @param maxDescripcion
 * @param maxMarca
 * @param maxColor
 * @param maxNombre
 * @param maxApellido
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int ListarTrabajosSegunCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);
/**
 * @fn int TotalServiciosPorCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);
 *
 * @brief calcula y lista el total de lo que deben los usuarios
 * @param listaTrabajos
 * @param listaServicios
 * @param listaBicicletas
 * @param listaClientes
 * @param tamT
 * @param tamS
 * @param tamB
 * @param tamC
 * @param maxDescripcion
 * @param maxMarca
 * @param maxColor
 * @param maxNombre
 * @param maxApellido
 * @return estado (-1 si hubo algun inconveniente, 1 si se tuvo exito)
 */
int TotalServiciosPorCliente(eTrabajo listaTrabajos[],eServicio listaServicios[],eBicicleta listaBicicletas[],eCliente listaClientes[],int tamT,int tamS, int tamB, int tamC, int maxDescripcion, int maxMarca, int maxColor, int maxNombre, int maxApellido);



#endif /* CONTROLLER_H_ */
