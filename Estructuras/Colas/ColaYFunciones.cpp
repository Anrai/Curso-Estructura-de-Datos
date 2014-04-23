// Nombre del programa: Estructura de Cola de enteros con funciones básicas
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 23-Febrero-2014
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

#define MAX 15

//--------------------------------------------------------------------------------------- 
// Función que indica si la cola está vacía
//---------------------------------------------------------------------------------------
bool empty(int cabeza, int cola)
{
	if(cabeza == cola) // Si los dos son iguales es porque no hay nada en la cola
		return true;
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Función que indica si la cola está llena
//---------------------------------------------------------------------------------------
bool full(int cabeza, int cola)
{
	if((cola+1 == cabeza) || (cabeza==0 && cola==MAX-1)) // Si la cola va atrás de la cabeza ya no se puede sobreescribir lo que está en cabeza
		return true;
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Función que hace push en la cola
//---------------------------------------------------------------------------------------
bool push_int(int queue[MAX], int cabeza, int *cola, int dato) // El nuevo dato se mete en la cola
{
	if(!full(cabeza, *cola))
	{
		queue[*cola]=dato; // El dato se mete en la cola
		
		// La cola aumenta en uno su valor, si ya pasó el límite de la cola, ésta regresa al 0
		if(*cola==MAX-1)
			*cola=0;
		else
			*cola=*cola+1;

		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Función que hace pop desde la cabeza
//---------------------------------------------------------------------------------------
bool pop_int(int queue[MAX], int *cabeza, int cola, int *dato)
{
	if(!empty(*cabeza, cola))
	{
		*dato=queue[*cabeza]; // Se extrae la cabeza y se pasa a "dato"

		if(*cabeza==MAX-1)
			*cabeza=0;
		else
			*cabeza=*cabeza+1;

		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Función que indica cuantos valores hay en la cola
//---------------------------------------------------------------------------------------
int largo_cola(int cabeza, int cola)
{
	int largo;

	if (cola>=cabeza)
		largo=cola-cabeza;
	else
		largo=MAX-cabeza+cola;

	return largo;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime todos los valores de una cola
//---------------------------------------------------------------------------------------
void pp_int(int queue[MAX], int cabeza, int cola)
{
	int d, i=0;

	// Vacía la cola original desde la cabeza, imprime sus valores, y los regresa a la cola
	while(i < largo_cola(cabeza, cola))
	{
		pop_int(queue, &cabeza, cola, &d);
		cout << d << endl;
		push_int(queue, cabeza, &cola, d);
		i+=1;
	}
}


//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	// Inicialización de una cola
	int queue[MAX], cabeza=0, cola=0, dato; // Cabeza es el primero en salir, Cola es en donde se va a escribir el siguiente

	push_int(queue, cabeza, &cola, 1);
	push_int(queue, cabeza, &cola, 2);
	push_int(queue, cabeza, &cola, 3);
	push_int(queue, cabeza, &cola, 4);
	push_int(queue, cabeza, &cola, 5);
	push_int(queue, cabeza, &cola, 6);
	push_int(queue, cabeza, &cola, 7);
	push_int(queue, cabeza, &cola, 8);
	push_int(queue, cabeza, &cola, 9);
	push_int(queue, cabeza, &cola, 10);
	push_int(queue, cabeza, &cola, 11);
	push_int(queue, cabeza, &cola, 12);
	push_int(queue, cabeza, &cola, 13);
	push_int(queue, cabeza, &cola, 14);
		pop_int(queue, &cabeza, cola, &dato);
		pop_int(queue, &cabeza, cola, &dato);
		pop_int(queue, &cabeza, cola, &dato);
		pop_int(queue, &cabeza, cola, &dato);
	push_int(queue, cabeza, &cola, 15);
	push_int(queue, cabeza, &cola, 16);
	push_int(queue, cabeza, &cola, 17);
	push_int(queue, cabeza, &cola, 18);
	push_int(queue, cabeza, &cola, 19);

	pp_int(queue, cabeza, cola);

	// Fin del programa
	cout << "\n\n";
	system("pause");
	return 0;
}