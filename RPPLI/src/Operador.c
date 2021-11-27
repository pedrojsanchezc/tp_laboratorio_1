/*
 * Costos.c
 *
 *  Created on: 25 nov. 2021
 *      Author: pedro_000
 */

#include "Operador.h"

void hardcodearOperador(Operador* listaOperador, int TAM){
	int id[5] = {1, 2, 3, 4, 5};
	int idPedido[5] = {27, 26, 29, 25, 28};
	char nombre[5][51] = {"Pedro Sanchez", "Jose Contreras", "Marisol Heit", "Cristina Heit", "Pavel Heit"};
	int dni[5] = {32738094, 24837021, 28146269, 34094325, 18554987};
	float salario[5] = {5000, 3000, 2546, 1323, 8940};
	int isEmpty[5] = {OCUPADO, OCUPADO, OCUPADO, OCUPADO, OCUPADO};

	for(int i=0;i<TAM;i++){
		listaOperador[i].id = id[i];
		listaOperador[i].idPedido = idPedido[i];
		strcpy(listaOperador[i].nombre, nombre[i]);
		listaOperador[i].dni = dni[i];
		listaOperador[i].salario = salario[i];
		listaOperador[i].isEmpty=isEmpty[i];
	}
}

void Operador_Inicializar(Operador* array, int TAM) {
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//SET ESTADO DE "LIBRE"
			array[i].isEmpty = LIBRE;
		}
	}
}

int Operador_ObtenerID(int lastID) {
	//INCREMENTA PARAMETRO RECIBIDO CADA VEZ QUE SE LLAMA ESTA FUNCION
	return lastID += 1;
}

int Operador_ObtenerIndexLibre(Operador* array, int TAM) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR EL ESTADO "LIBRE"
			if (array[i].isEmpty == LIBRE) {
				//OBTENGO EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int Operador_BuscarPorID(Operador* array, int TAM, int ID) {
	int rtn = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++) {
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].id == ID && array[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void Operador_MostrarUno(Operador listaOperador){
	printf("%d %22s %d %13s %2.f \n", listaOperador.id, listaOperador.nombre, listaOperador.dni, listaOperador.salario);
}

int Operador_MostrarTodos(Operador* array, int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	//CABECERA
	puts("\n\t> listaOperador       ");
	printf("ID             NOMBRE            DNI       SALARIO\n\n"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		//RECORRO TODO EL ARRAY
		Operador_Sort(array, TAM, -1);
		for (i = 0; i < TAM; i++) {
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == OCUPADO) {
				//MUESTRO UN SOLO OPERADOR
				Operador_MostrarUno(array[i]);
				//CONTADOR DE OPERADORS
				cantidad++;
			}
		}
	}

	//SI CANTIDAD == 0 - NO HUBO        PARA MOSTRAR (ARRAY SIN ALTAS)
	if (cantidad == 0) {
		puts("\n\t> NO HAY        PARA MOSTRAR");
		rtn = 1;
	}

	return rtn;
}

int Operador_Sort(Operador* array, int TAM, int criterio) {
	int rtn = 0;
	int i;
	int j;
	Operador aux;

	/** EJEMPLO DE SORT CON ID DE OPERADOR
	    MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO
	    CASE -1 -> MENOR A MAYOR (ASCENDENTE)
	    CASE  1 -> MAYOR A MENOR (DESCENDENTE)
	    UTILIZAR strcmp(...) PARA COMPARAR CADENAS
	*/

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0) {
		switch (criterio) {
		case -1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id > array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						if(array[i].id > array[j].id){
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			rtn = 1;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++) {
				for (j = i + 1; j < TAM; j++) {
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO) {
						//CRITERIO DE ORDENAMIENTO
						if (array[i].id < array[j].id) {
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
						if(array[i].id < array[j].id){
						aux = array[i];
						array[i] = array[j];
						array[j] = aux;
					}
					}
				}
			}
			rtn = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			puts("\nCRITERIO DE ORDENAMIENTO MAL INGRESADO");
			rtn = 0;
			break;
		}
	}
	return rtn;
}
