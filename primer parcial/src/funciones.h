/*
 * funciones.h
 *
 *  Created on: 13 may. 2021
 *      Author: Patricio
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

typedef struct
{
	int idServicio;
	char descripcion[25];
	int precio;
}eServicios;

typedef struct
{
	int idTrabajo;
	char marcaBicicleta[50];
	int rodadoBicicleta;
	int fecha;
	eServicios idServicio;
	int idS;
	int isEmpty;
}eTrabajo;

void HardcodeoStructura (eServicios lista[],int* idServ, int TAM);
int AltaDeProducto(eTrabajo producto[], int size, int* id, eServicios lista[], int TAM);
int total(eTrabajo producto[], eServicios lista[], int TAM, int tam10);
int Modificar_Producto();
int ModificarProducto(eTrabajo producto[], eServicios lista[], int TAM, int tam10);
int BuscarId(eTrabajo producto[], int TAM, int id);
int DarDeBaja(eTrabajo producto[], int TAM);
void hardPrintS(eServicios lista);
int HardPrint(eServicios lista[], int TAM);
int MostrarDatos_s(eTrabajo producto);
int MostrarDatos (eTrabajo producto[], int TAM);

#endif /* FUNCIONES_H_ */
