// Nombre del programa: Ejercicio de Estructura de Pila con variables tipo Char para comprobación de strings matemáticos con paréntesis
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 12-Febrero-2014                                       
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

#define MAX 50

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
// Función que pide una expresión matemática y detecta si los paréntesis están bien escritos
//---------------------------------------------------------------------------------------
void comprobacion()
{
	// Inicialización de una pila temporal
	char stack[MAX]; // Pila y dato a almacenar en la pila
	char dato;
	int sp=MAX; // Stack Pointer
	// Declaro un string "operacion" que almacenará la expresión matemática
	string operacion;

	cout << "Ingrese una expresion matematica: ";
	cin >> operacion;

	bool status = true; // Esta variable dice si la expresión es correcta

	for (int i=0; i<operacion.length(); ++i)
	{
		dato=operacion[i]; // Se mete el caracter en la variable dato para utilizarla
		if (dato=='(')
			push(stack, &sp, dato); // Se pushea cada párentesis de apertura en la pila
		else if (dato==')')
		{
			// Se borra cada párentesis de cierre en la pila
			if (!pop(stack, &sp, &dato)) // Si el primer paréntesis es de cierre la expresión es incorrecta
			{
				status=false;
				break;
			}
		}
	}

	if (pila_llena(sp)) // Checa si quedaron paréntesis sin cerrar
		status=false;

	if(status)
		cout << "\nLos parentesis de la expresion ingresada estan BIEN definidos";
	else
		cout << "\nLos parentesis de la expresion ingresada estan MAL definidos";
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	// Inicialización de una pila para almacenar los paréntesis de la expresión matemática
	char pila[MAX];
	int sp=MAX, d;
	bool k;
	/*
	push(pila, &sp, 'a');
	push(pila, &sp, 'b');
	push(pila, &sp, 'c');
	push(pila, &sp, 'd');
	push(pila, &sp, 'e');
	*/
	//pop(pila, &sp, &d);
	//pop(pila, &sp, &d);

	// pp(pila, sp); // Imprime todos los valores de una pila

	comprobacion();

	cout << "\n\n";
	system("pause");
	return 0;
}