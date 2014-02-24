// Nombre del programa: Structs de nodos
// Descripción: Programa que genera, imprime y pide struct de nodo
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 24-Febrero-2014
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Se declara una estructura de nodo
//---------------------------------------------------------------------------------------
struct nodo{
	int num;
	float s;
	char nom[15];
};

//--------------------------------------------------------------------------------------- 
// Función que imprime una estructura nodo
//---------------------------------------------------------------------------------------
void print_nodo(struct nodo n)
{
	cout << n.num << endl;
	cout << n.s << endl;
	cout << n.nom << endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que llena una estructura de nodo
//---------------------------------------------------------------------------------------
struct nodo llena_nodo()
{
	struct nodo n;

	cout << endl << "Ingrese un numero entero: ";
	cin >> n.num;
	cout << endl << "Ingrese un flotante: ";
	cin >> n.s;
	cout << endl << "Ingrese el nombre: ";
	cin >> n.nom;

	return n;
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	struct nodo n1, n2;

	n1=llena_nodo();
	print_nodo(n1);

	n2=llena_nodo();
	print_nodo(n2);

	// Fin del programa
	cout << "\n\n";
	system("pause");
	return 0;
}