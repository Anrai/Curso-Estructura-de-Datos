// Nombre del programa: Algoritmo #6
// Descripci�n: Construir un algoritmo que dado como dato de entrada un numero, mande a escribir los 3 siguientes n�meros.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas Garc�a 
// Fecha: 22-Enero-2014                                       
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//--------------------------------------------------------------------------------------- 
int main(int argc, char** argv) {
	
	int a;
	
	cout << "Ingrese un numero entero: ";
	cin >> a;
	
	cout << "\nLos siguientes numeros enteros son: " << a+1 << ", " << a+2 << ", " << a+3 << "\n\n";
	
	system("pause");
	return 0;
}
