// Nombre del programa: Algoritmo #4
// Descripción: Construir un algoritmo que dados como datos de entrada los precios de 3 productos, incremente los precios de los primeros dos en un 8% e incremente el precio del tercer producto en un 12%. Mande a escribir el importe total para los productos.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
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
	
	float a,b,c;
	
	cout << "Ingrese el dato 1: ";
	cin >> a;
	cout << "Ingrese el dato 2: ";
	cin >> b;
	cout << "Ingrese el dato 3: ";
	cin >> c;
	
	a += a*.08;
	b += b*.08;
	c += c*.12;
	
	cout << "\nEl 8% del dato 1 es: " << a << "\n";
	cout << "El 8% del dato 2 es: " << b << "\n";
	cout << "El 12% del dato 3 es: " << c << "\n\n";
	
	system("pause");
	return 0;
}