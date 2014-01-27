// Nombre del programa: Algoritmo #9
// Descripción: Construir un algoritmo que calcule el área de un triangulo.
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
	
	float a,b,h;
	
	cout << "Ingrese el tamano de la base de un triangulo en cm: ";
	cin >> b;
	cout << "Ingrese el tamano de la altura de un triangulo en cm: ";
	cin >> h;
	
	/* Operación */
	a=b*h/2;
	
	/* Imprimir resultados */
	cout << "\nEl area del triangulo es de : " << a << " cm2\n\n";
	
	system("pause");
	return 0;
}