// Nombre del programa: Algoritmo #8
// Descripción: Diseñar un algoritmo que calcule y mande a escribir la suma, resta, multiplicación y división entre dos números cuialesquiera.
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
	
	float a,b,w,x,y,z;
	
	cout << "Ingrese un numero: ";
	cin >> a;
	cout << "Ingrese otro numero: ";
	cin >> b;
	
	/* Suma */
	w=a+b;
	/* Resta */
	x=a-b;
	
	/* Multiplicación */
	y=a*b;
	
	/* Imprimir resultados */
	cout << "\nLa suma es: " << w << "\n";
	cout << "La resta es: " << x << "\n";
	cout << "El producto es: " << y << "\n";

	/* División */
	/* Division entre 0 */
	if (b>0)
		z=a/b;
	else {
		cout << "La division nopuede realizarse\n\n";
	}
	
	system("pause");
	return 0;
}