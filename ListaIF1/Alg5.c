// Nombre del programa: Algoritmo #5
// Descripción: Diseñar un algoritmo que calcule la suma, el producto y el promedio de 5 números cualesquiera.
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
	
	float a,b,c,d,e,x,y,z;
	
	cout << "Ingrese el dato 1: ";
	cin >> a;
	cout << "Ingrese el dato 2: ";
	cin >> b;
	cout << "Ingrese el dato 3: ";
	cin >> c;
	cout << "Ingrese el dato 4: ";
	cin >> d;
	cout << "Ingrese el dato 5: ";
	cin >> e;
	
	/* Suma */
	x=a+b+c+d+e;
	
	/* Producto */
	y=a*b*c*d*e;
	
	/* Promedio */
	z=(a+b+c+d+e)/5;
	
	cout << "\nLa suma es: " << x << "\n";
	cout << "El producto es: " << y << "\n";
	cout << "El promedio es: " << z << "\n\n";
	
	system("pause");
	return 0;
}