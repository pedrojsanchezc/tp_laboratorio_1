/*
 ============================================================================
 Name        : TP1_RECUPERATORIO.c
 Author      : Pedro Sánchez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
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
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {
	setbuf(stdout,NULL);
	float primerOperando;
	float segundoOperando;
	int flagPrimerOperando = 0;
	int flagSegundoOperando = 0;
	int flagOperaciones = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	float resultadoDivision;
	float resultadoFactorialPrimerOperando;
	float resultadoFactorialSegundoOperando;
	int opcion;

	while(opcion!=5)
	{
		Menu();
		if(utn_getNumero("Ingrese una opción del Menú: \n", "Reingrese un numero del 1 al 5: \n ", &opcion, 3, 1, 6)==0)
		{
			switch(opcion)
			{
			case 1:
				if(utn_getNumeroFloat("Ingrese el primer operando: \n", "Reingrese el primer operando \n", &primerOperando,3) == 0)
				{
					  printf("   A=%.2f\n",primerOperando);
					  flagPrimerOperando=1;
				}
				break;
			  case 2:
				  if(utn_getNumeroFloat("Ingrese el segundo operando: \n", "Reingrese el segundo operando \n", &segundoOperando,3) == 0)
				  {
					  printf("   B=%.2f\n",segundoOperando);
					  flagSegundoOperando=1;
				  }
			  break;
			  case 3:
				  if(flagPrimerOperando==1 && flagSegundoOperando==1)
				  {
					  utn_sumaNumerosFloat(primerOperando,segundoOperando,&resultadoSuma);
					  utn_restaNumerosFloat(primerOperando,segundoOperando,&resultadoResta);
					  utn_multiplicacionNumerosFloat(primerOperando,segundoOperando,&resultadoMultiplicacion);
					  utn_divisionNumerosFloat(primerOperando,segundoOperando,&resultadoDivision);
					  utn_getFactorialFloat(primerOperando,&resultadoFactorialPrimerOperando);
					  utn_getFactorialFloat(segundoOperando,&resultadoFactorialSegundoOperando);
					  flagOperaciones=1;
				  }
				  else
				  {
					 printf("NO INGRESÓ VALORES PARA A o B.\n");
					 system("   PAUSE");
				  }
			  break;
			  case 4:
				  if(flagPrimerOperando==1 && flagSegundoOperando==1 && flagOperaciones==1)
				  {
					  printf("El resultado de %.2f+%.2f es: %.2f\n",primerOperando,segundoOperando,resultadoSuma);
					  printf("El resultado de %.2f-%.2f es: %.2f\n",primerOperando,segundoOperando, resultadoResta);
					  printf("El resultado de %.2f*%.2f es: %.2f\n",primerOperando,segundoOperando, resultadoMultiplicacion);
					  if(utn_divisionNumerosFloat(primerOperando,segundoOperando,&resultadoDivision)==0)
						{
							printf("El resultado de %.2f/%.2f es: %.2f\n",primerOperando,segundoOperando,resultadoDivision);
						}
						else
						{
							printf("NO SE PUEDE DIVIDIR POR 0\n");
						}
					  printf("El factorial de %.2f es %.2f y el factorial de %.2f es %.2f\n",primerOperando,resultadoFactorialPrimerOperando,segundoOperando,resultadoFactorialSegundoOperando);
				  }
				  else
				  {
					  printf("NO INGRESÓ VALORES PARA A o B.\n");
					  system("   PAUSE");
				  }
			  break;
			}
		}else{
			printf("GRACIAS POR USAR!!\n");
			break;
		}
	}
	return EXIT_SUCCESS;
}
