/*
 ============================================================================
Se necesita gestionar una bicicletería y para eso se deberá desarrollar lo siguiente:
ENTIDADES:
Servicio:
● id (comienza en 20000, autoincremental)
● descripción (máximo 25 caracteres)
● precio
Trabajo:
● id (autoincremental)
● marcaBicicleta (Cadena) Validar
● rodadoBicicleta
● idServicio (debe existir) Validar
● fecha (Validar día, mes y año)
DATOS PREVIOS:
El array de servicios deberá ser hardcodeado.
Servicios (Limpieza: $250, Parche: $300, Centrado: $400, Cadena: $350)
MENU DE OPCIONES:
A. ALTA TRABAJO
B. MODIFICAR TRABAJO: Se ingresará el id, permitiendo en un submenú modificar:
● La marca de la bicicleta
● El servicio
C. BAJA TRABAJO: Se ingresará el id del trabajo y se realizará una baja lógica.
D. LISTAR TRABAJOS: Hacer un único listado de todos los trabajos ordenados por año y ante igualdad
de año por marca de la bicicleta.
E. LISTAR SERVICIOS
F. TOTAL en pesos por los servicios prestados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 4
#define tam10 10


int main(void)
{
	setbuf(stdout, NULL);

	int idServicio=20000;
	int idTrabajo=1;
	int mostrarMenu;
	char seguir;
	int valor=0;

	seguir="s";

	eServicios servicio[TAM];
	eTrabajo trabajo[tam10];
	InicializarTrabajo(trabajo, tam10);
	HardcodeoStructura(servicio, &idServicio, TAM);

	do
	{
		mostrarMenu = menu();
				switch(mostrarMenu)
				{
					case 1:
						InicializarTrabajo(trabajo, tam10, &idTrabajo, servicio, TAM);
						valor = 1;
						break;

					 case 2:
						 ModificarProducto(trabajo, servicio, tam10, TAM);
						 break;

					 case 3:
						 DarDeBaja(trabajo, tam10);
						 break;

					 case 4:
						if(valor == 1)
						{
							MostrarDatos(trabajo, tam10);
						}
						else
						{
							printf("ERROR! data invalida.\n");
						}

						break;

					 case 5:
						 total(trabajo, servicio, tam10, TAM);
						 break;

					case 6:
						seguir = 'n';
						break;
				}
	}while(seguir=="s");

	return EXIT_SUCCESS;

}
