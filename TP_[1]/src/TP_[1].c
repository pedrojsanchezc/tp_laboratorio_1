/*
 ============================================================================
 Name        : TP_[1].c
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
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Inputs.h"

int main(void) {
	setbuf(stdout, NULL);

	float primerOperando;
	float segundoOperando;
	int primerFlag=0;
	int segundoFlag=0;
	int calculosFlag=0;
	int opcion;
	float sumaResultado;
	float restaResultado;
	float multiplicacionResultado;
	float divisionResultado;
	float primerFactorial;
	float segundoFactorial;

	while(opcion!=5)
	{
		MenuCalculadora();
		if(utn_getInt("\n INGRESE UNA OPCIÓN: ","\n ERROR. REINGRESE UNA OPCIÓN (1-5): ",&opcion,4,1,6)==0 )
		{
		  	switch(opcion)
			{
				  case 1:
					  if(utn_getFloat("1. Ingresar 1er operando: ","\n ERROR. REINGRESE UN NUMERO: ",&primerOperando,4) == 0)
					  {
						  printf("   A=%.2f\n",primerOperando);
						  primerFlag=1;
					  }
				  break;
				  case 2:
					  if(utn_getFloat("2. Ingresar 2do operando: ","\n ERROR. REINGRESE UN NUMERO:",&segundoOperando,4) == 0)
					  {
						  printf("   B=%.2f\n",segundoOperando);
						  segundoFlag=1;
					  }
				  break;
				  case 3:
					  if(primerFlag==1 && segundoFlag==1)
					  {
						  SumarFlotantes(primerOperando,segundoOperando,&sumaResultado);
						  RestarFlotantes(primerOperando,segundoOperando,&restaResultado);
						  MultiplicarFlotantes(primerOperando,segundoOperando,&multiplicacionResultado);
						  DividirFlotantes(primerOperando,segundoOperando,&divisionResultado);
						  FactorialFlotante(primerOperando,&primerFactorial);
						  FactorialFlotante(segundoOperando,&segundoFactorial);
						  calculosFlag=1;
					  }
					  else
					  {
						 printf(" NO SE INGRESARON VALORES PARA A Y/O B.\n");
					  }
				  break;
				  case 4:
					  if(primerFlag==1 && segundoFlag==1 && calculosFlag==1)
					  {
						  printf("\n   El resultado de %.2f+%.2f es: %.2f",primerOperando,segundoOperando,sumaResultado);
						  printf("\n   El resultado de %.2f-%.2f es: %.2f",primerOperando,segundoOperando, restaResultado);
						  printf("\n   El resultado de %.2f*%.2f es: %.2f",primerOperando,segundoOperando, multiplicacionResultado);
						  if(DividirFlotantes(primerOperando,segundoOperando,&divisionResultado)==0)
							{
								printf("\n   El resultado de %.2f/%.2f es: %.2f",primerOperando,segundoOperando,divisionResultado);
							}
							else
							{
								printf("NO SE PUEDE  DIVIDIR POR 0 \n");
							}
						  printf("\n   El factorial de %.2f es %.2f y el factorial de %.2f es %.2f"
								  ,primerOperando,primerFactorial,segundoOperando,segundoFactorial);
					  }
					  else
					  {
						  printf("NO SE REALIZÓ NINGUNA OPCIÓN VALIDA O NO SE INGRESARON VALORES PARA A Y/O B.\n");
					  }
				  break;
			}
		}
	}

	return EXIT_SUCCESS;
}


