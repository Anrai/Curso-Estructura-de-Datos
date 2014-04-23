// Nombre del programa: Ejercicio while #49
// Descripción: Diseñe un pseudo código que lea el valor de un ángulo expresado en radianes y calcule e imprima el valor del seno de dicho ángulo.
// 				Se leerá también el  número de términos de la serie.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 29-Enero-2014                                       
  
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
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	double angulo;

	cout << "Ingrese el angulo en radianes: ";
	cin >> angulo;

	cout << "\nEl seno del angulo es: " << sin(angulo);




	system("pause");
	return 0;
}