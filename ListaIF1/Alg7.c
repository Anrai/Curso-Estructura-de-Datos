// Nombre del programa: Algoritmo #7
// Descripción: Hacer un algoritmo que mande a escribir el mayor de dos números dados.
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
	
	float a,b,x;
	
	cout << "Ingrese un numero: ";
	cin >> a;
	cout << "Ingrese otro numero: ";
	cin >> b;
	
	if(a>b){
		cout << "\nEl numero mayor es: ";
		cout << a << "\n\n";
	}
	else if(a<b){
		cout << "\nEl numero mayor es: ";
		cout << b << "\n\n";
	}
	else
		cout << "Los numeros son iguales\n\n";
	
	system("pause");
	return 0;
}