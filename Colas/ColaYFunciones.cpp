// Nombre del programa: Generador de Cola con funciones básicas
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 21-Febrero-2014
  
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
// Función que hace push en la pila
//---------------------------------------------------------------------------------------
bool push_int(int queue[MAX], int, cabeza, int *cola, int dato) // El nuevo dato se mete en la cola
{
	if(!full(cabeza, *cola))
	{
		// La cola aumenta en uno su valor, si ya pasó el límite de la cola, ésta regresa al 0
		if(*cola==MAX-1)
			*cola=0;
		else
			*cola=*cola+1;

		queue[*cola]=dato;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Función que hace pop en la cola
//---------------------------------------------------------------------------------------
bool pop_int(int queue[MAX], int, *cabeza, int cola, int *dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición, el dato se pasa por referencia
{
	int st=false;

	if(!pila_vacia(*sp))
	{
		*dato=stack[*sp];
		*sp=*sp+1;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime todos los valores de una pila
//---------------------------------------------------------------------------------------
void pp_int(int stack[MAX], int sp)
{
	// Inicialización de una pila temporal de almacenamiento para los valores de la pila original
	int p1[MAX], sp1=MAX, d;
	bool k;

	// Vacía la pila original, imiprime sus valores, y los mete en una nueva pila
	while(pop_int(stack, &sp, &d))
	{
		cout << "\n" << d;
		k = push_int(p1, &sp1, d);
	}

	// Regresa los valores a la pila original
	while(pop_int(p1, &sp1, &d))
	{
		k = push_int(stack, &sp, d);
	}

}


//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	// Inicialización de una cola
	int queue[MAX], cabeza=0, cola=0, dato; // Cabeza es el primero en salir, Cola es en donde se va a escribir el siguiente

	push_int(queue, &cabeza, &cola, 9);
	push_int(queue, &cabeza, &cola, 8);
	push_int(queue, &cabeza, &cola, 7);
	push_int(queue, &cabeza, &cola, 6);
	push_int(queue, &cabeza, &cola, 5);
	push_int(queue, &cabeza, &cola, 4);
	push_int(queue, &cabeza, &cola, 3);

	pop_int(queue, &cabeza, &cola, &dato); // d vale 9
	pop_int(queue, &cabeza, &cola, &dato); // d vale 7

	cout << dato << endl;

	//pp_int(pila, sp); // Para imprimir todos los elementos

	// Fin del programa
	cout << "\n\n";
	system("pause");
	return 0;
}