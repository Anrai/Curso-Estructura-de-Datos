// Nombre del programa: Ejercicio de Estructura de Pila
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 5-Febrero-2014                                       
  
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
// Función que indica si la pila está vacía
//---------------------------------------------------------------------------------------
bool pila_vacia(int sp)
{
	int st = false;

	if(sp==MAX)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que indica si la pila está llena
//---------------------------------------------------------------------------------------
bool pila_llena(int sp)
{
	int st = false;

	if(sp==0)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace push en la pila
//---------------------------------------------------------------------------------------
bool push_int(int stack[MAX], int *sp, int dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición
{
	int st=false;

	if(!pila_llena(*sp))
	{
		*sp=*sp-1;
		stack[*sp]=dato;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace pop en la pila
//---------------------------------------------------------------------------------------
bool pop_int(int stack[MAX], int *sp, int *dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición, el dato se pasa por referencia
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
	while(pop(stack, &sp, &d))
	{
		cout << "\n" << d;
		k = push (p1, &sp1, d);
	}

	// Regresa los valores a la pila original
	while(pop(p1, &sp1, &d))
	{
		k = push (stack, &sp, d);
	}

}


//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	// Inicialización de una pila
	int pila[MAX], sp=MAX, d;
	bool k;

	push(pila, &sp, 7);
	push(pila, &sp, 9);
	push(pila, &sp, 8);
	push(pila, &sp, 1);
	push(pila, &sp, 6);
	push(pila, &sp, 4);
	push(pila, &sp, 3);
	push(pila, &sp, 7);
	push(pila, &sp, 9);
	push(pila, &sp, 8);
	push(pila, &sp, 1);
	push(pila, &sp, 6);
	push(pila, &sp, 4);
	push(pila, &sp, 3);
	push(pila, &sp, 7);
	push(pila, &sp, 9);
	push(pila, &sp, 8);
	push(pila, &sp, 1);
	push(pila, &sp, 6);
	push(pila, &sp, 4);
	push(pila, &sp, 3);
	//pop(pila, &sp, &d); // d vale 9
	//pop(pila, &sp, &d); // d vale 7

	pp_int(pila, sp);
	cout << "\n\n";


	system("pause");
	return 0;
}