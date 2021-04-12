/*
 ============================================================================
 Name        : trabajo_practico_1.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
 -Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
 -En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 -Deberán contemplarse los casos de error (división por cero, etc)
 -Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagResultado = 0;
	int numeroIngresado;
	int numeroIngresadoDos;
	int suma;
	int resta;
	int division;
	int multiplicacion;
	int factorial;
	int opcion;
	setbuf(stdout, NULL);

	do{
		printf("                      CALCULADORA UTN                      \n");
		printf("          MENU\n");
		printf("1. Ingresar primer operando \n");
		printf("2. Ingresar segundo operando \n");
		printf("3. Calcular todas las operaciones (Suma, Resta, División, Multiplicación, Factorial)\n");
		printf("4. Informar resultados\n");
		printf("5. Salir\n");
		printf("Ingrese una opción:");
		scanf("%d",&opcion);

		switch(opcion){
		case 1:
			printf("Ingresar 1er operando:");
			fflush(stdin);
			scanf("%d", &numeroIngresado);
				 flagPrimerOperando=1;
			break;
		case 2:
			printf("Ingresar 2do operando:");
			fflush(stdin);
			scanf("%d", &numeroIngresadoDos);
				 flagSegundoOperando=1;
			break;
		case 3:
			if(flagPrimerOperando == 1 && flagSegundoOperando == 1){
			suma = SumarNumeros(numeroIngresado, numeroIngresadoDos);
			resta = RestarNumeros(numeroIngresado, numeroIngresadoDos);
			division = DivisionNumeros(numeroIngresado, numeroIngresadoDos);
			multiplicacion = MultiplicacionNumeros(numeroIngresado, numeroIngresadoDos);
			factorial = CalcularFactorial(numeroIngresado);
				flagResultado = 1;
			}else {
				printf("No se ingresaron valores en los operandos\n");
			}
			break;
		case 4:
			if(flagPrimerOperando == 1 && flagSegundoOperando == 1 && flagResultado == 1){
			printf("El resultado de %d+%d es: %d\n",numeroIngresado, numeroIngresadoDos, suma);
			printf("El resultado de %d-%d es: %d\n",numeroIngresado, numeroIngresadoDos, resta);
			printf("El resultado de %d*%d es: %d\n",numeroIngresado, numeroIngresadoDos, multiplicacion);
			if(DivisionNumeros(numeroIngresado, numeroIngresadoDos, division) == 0){
				printf("El resultado de %d/%d es: %d\n",numeroIngresado, numeroIngresadoDos, division);
			}else{
				printf("No se puede dividir por 0\n");
			}
			printf("El factorial de %d es: %d\n",numeroIngresado, factorial);
			}
			break;
		case 5:
			printf("    GRACIAS POR USAR, HASTA PRONTO.");
			break;
		}

	}while(opcion!=5);
	return EXIT_SUCCESS;
}


