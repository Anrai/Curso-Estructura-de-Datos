// Nombre del programa: Ejercicio de Estructura de Pila con variables tipo Char
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 10-Febrero-2014                                       
  
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
	bool st = false;

	if(sp==MAX)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que indica si la pila está llena
//---------------------------------------------------------------------------------------
bool pila_llena(int sp)
{
	bool st = false;

	if(sp==0)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace push en la pila
//---------------------------------------------------------------------------------------
bool push(char stack[MAX], int *sp, char dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición
{
	bool st=false;

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
bool pop(char stack[MAX], int *sp, char *dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición, el dato se pasa por referencia
{
	bool st=false;

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
void pp(char stack[MAX], int sp)
{
	// Inicialización de una pila temporal de almacenamiento para los valores de la pila original
	char p1[MAX], d;
	int sp1=MAX;
	bool k;

	// Vacía la pila original, imprime sus valores, y los mete en una nueva pila
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
	char pila[MAX];
	int sp=MAX, d;
	bool k;

	push(pila, &sp, 'a');
	push(pila, &sp, 'b');
	push(pila, &sp, 'c');
	push(pila, &sp, 'd');
	push(pila, &sp, 'e');

	//pop(pila, &sp, &d);
	//pop(pila, &sp, &d);

	pp(pila, sp);
	cout << "\n\n";


	system("pause");
	return 0;
}