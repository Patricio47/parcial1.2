/*
 * funciones.c
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
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"
#define VACIO 0
#define OCUPADO 1

void HardcodeoStructura (eServicios lista[],int* idServ, int TAM)
{
	char auxDescripcion [4][25]={"limpieza", "parche", "centrado", "cadena"};
	int auxPrecio [4]={250, 300, 400, 350};
	int i;

	for(i=0;i<TAM;i++)
	{
		lista[i].idServicio = *idServ;
		strcpy(lista[i].descripcion, auxDescripcion[i]);
		lista[i].precio=auxPrecio[i];
		(*idServ)++;
	}

}

int menu(void)
{
	int opciones;

	printf("1 Alta de Producto\n");
	printf("2. Modificador Trabajo\n");
	printf("3. Baja Trabajo\n");
	printf("4. Listar Trabajo\n");
	printf("5. Salir\n");
	scanf("%d",&opciones);

	return opciones;
}

int InicializarTrabajo(eTrabajo producto[], int TAM)
{
	int i;
	int todobien = -1;
	if(producto!= NULL && TAM>0)
	{
		for(i=0;i<TAM;i++)
		{
			producto[i].isEmpty=VACIO;
			todobien = 0;
		}
	}
	return todobien;
}

int BuscarVacio(eTrabajo producto[], int TAM, int *index)
{
	int i;
	int todobien = -1;

	if(producto!= NULL && TAM>0 && index!= NULL)
	{
		for(i=0;i<TAM;i++)
		{

			if(producto[i].isEmpty==VACIO)
			{
				*index=i;
				todobien = 0;
				break;
			}

		}
	}
	return todobien;
}
int AltaDeProducto(eTrabajo producto[], int size, int* id, eServicios lista[], int TAM)
{

	int index;
	int todobien = -1;

	if(producto != NULL && TAM>0 && id !=NULL && lista !=NULL && size>0)
	{
		if(!BuscarVacio(producto, size, &index ))
		{
			printf("El id del producto: %d\n", *id);
			printf("Ingrese el rodado:\n");
			scanf("%d", &producto[index].rodadoBicicleta);
			printf("Ingrese la marca:\n");
			fflush(stdin);
			gets(producto[index].marcaBicicleta);
			hardprint(lista, TAM);
			printf("Ingrese el servicio: ");
			scanf("%d", &producto[index].idS);

			producto[index].isEmpty = OCUPADO;
			producto[index].idTrabajo = *id;
			(*id)++;
			todobien = 1;
			todobien=0;
		}
		else
		{
			printf("No hay mas espacio libre.\n");
		}
	}
	return todobien;
}
int MostrarDatos (eTrabajo producto[], int TAM)
{
	int i;
	int bandera;
	bandera=0;

	for(i=0;i<TAM;i++)
	{
		if(producto[i].isEmpty == OCUPADO)
		{
			MostrarDatos_s(producto[i]);
			bandera=1;
		}
	}
	if(bandera==0)
	{
		printf("No hay productos");
	}
	return 0;
}

int MostrarDatos_s(eTrabajo producto)
{
	printf("ID: %d\n", producto.idTrabajo);
	printf("Marca: %s\n", producto.marcaBicicleta);
	printf("Rodado: %d\n", producto.rodadoBicicleta);

	return 0;
}


int HardPrint(eServicios lista[], int TAM)
{
	int i;
	int bandera;
	bandera=0;

		for(i=0;i<TAM;i++)
		{

			HardPrintS(lista[i]);
			bandera=1;
		}
		return bandera;
}

void hardPrintS(eServicios lista)
{
	printf("ID: %d\n", lista.idServicio);
	printf("Marca: %s\n", lista.descripcion);
	printf("Rodado: %d\n", lista.precio);
}

int DarDeBaja(eTrabajo producto[], int TAM)
{
	int id;
	int aux;

	MostrarDatos(producto, TAM);

	printf("Ingrese el ID del producto que quiera borrar:\n");
	scanf("%d", &id);

	aux = BuscarId(producto, TAM, id);

	if(aux != -1)
	{
		producto[aux].isEmpty = 0;
	}
	return aux;
}

int BuscarId(eTrabajo producto[], int TAM, int id)
{
	int i;
	int aux;
	aux = -1;

	for(i=0;i<TAM;i++)
	{
		aux = i;
		break;
	}
	return aux;
}

int ModificarProducto(eTrabajo producto[], eServicios lista[], int TAM, int tam10)
{
	int id;
		int index;
		char confirmation[8];

		eTrabajo nuevaT;
		eServicios nuevaS;

		data_print(producto, TAM);

		printf("Ingrese la ID del producto que desee modificar: \n");
		scanf("%d", &id);

		index = id_search(producto, TAM, id);

		if(index != -1)
		{
			data_print_s(producto[index]);
			printf("esta bien?");
			scanf("%s", confirmation);

			if(stricmp(confirmation,"yes") == 0)
			{
				nuevaT = producto[index];
				nuevaS = lista[index];
				switch(mod_menu())
				{
					case 1:
						printf("Ingrese el nuevo servicio:  \n");
						scanf("%[^\n]", nuevaS.descripcion);
						break;

					case 2:
						printf("Ingrese el nuevo rodado: \n");
						scanf("%d", &nuevaT.rodadoBicicleta);
						break;

				}

				producto[index] = nuevaT;
				lista[index] = nuevaS;

			}
		}
		return index;
}

int Modificar_Producto()
{
	int opciones;

	printf("1. Nuevo Servicio");
	printf("2. Nuevo rodado");
	scanf("%d", &opciones);

	return opciones;
}

int total(eTrabajo producto[], eServicios lista[], int TAM, int tam10)
{

	int total = 0;
	int i;
	int j;

	for(i = 0; i < TAM; i ++)
	{
		for(j = 0; j < tam10; j ++)
		{
			if(producto[i].idS == lista[j].idServicio)
			{
				total += lista[j].precio;
			}
		}
	}

	printf("el total es: %d", total);


	return 0;
}
