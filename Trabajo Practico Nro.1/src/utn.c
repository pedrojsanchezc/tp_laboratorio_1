/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: EXO02
 */

#include "utn.h"

/* Pide un número
 * Devuelve mensaje de error si no se ingreso un numero.
 * Valida el numero ingresado
 * Retorna el numero ingresado
 * */
int PedirEntero(char mensaje[], char mensajeError[], int minimo, int maximo){

	int numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
	while(numeroIngresado < minimo || numeroIngresado>maximo){
		printf("Error. %s", mensajeError);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}
/* Pide un número
 * Devuelve mensaje de error si no se ingreso un numero.
 * Valida el numero ingresado
 * Retorna el numero ingresado flotante
 * */
float PedirFlotante(char mensaje[], char mensajeError[], int minimo, int maximo){
	float numeroIngresado;

	printf("%s", mensaje);
	scanf("%d", &numeroIngresado);
	while(numeroIngresado < minimo || numeroIngresado>maximo){
		printf("Error. %s", mensajeError);
		scanf("%d", &numeroIngresado);
	}

	return numeroIngresado;
}

/* Recibe como parametros dos numeros entereos
 * Se guarda la operacion de suma entre ambos numeros en la variable resultado
 * Retorna el resultado
 * */
int SumarNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno + numeroDos; //Va a devolver ese valor
	//Parametros formales

	return resultado;
}
/* Recibe como parametros dos numeros entereos
 * Se guarda la operacion de resta entre ambos numeros en la variable resultado
 * Retorna el resultado
 * */
int RestarNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno - numeroDos;

	return resultado;
}
/* Recibe como parametros dos numeros entereos
 * Se guarda la operacion de division entre ambos numeros en la variable resultado
 * Retorna el resultado
 * */
int DivisionNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno / numeroDos;

	return resultado;
}
/* Recibe como parametros dos numeros entereos
 * Se guarda la operacion de multiplicacion entre ambos numeros en la variable resultado
 * Retorna el resultado
 * */
int MultiplicacionNumeros(int numeroUno, int numeroDos){
	int resultado;

	resultado = numeroUno * numeroDos;

	return resultado;
}
/* Recibe como parametro el primer numero ingresado
 * Se guarda la operacion de factorial en la variable resultado
 * Retorna el resultado
 * */
int CalcularFactorial(int numeroUno){
	int resultado;

	if(numeroUno == 0){
		resultado = 1;
	}else{
		resultado = numeroUno * CalcularFactorial(numeroUno-1);
	}

	return resultado;
}
