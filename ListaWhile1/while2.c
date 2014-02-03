// Nombre del programa: Ejercicio While #2
// Descripción: Leer 10 números y obtener su cubo y su cuarta.
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
#include <math.h>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//--------------------------------------------------------------------------------------- 
int main(int argc, char** argv) {
	
	int i=0;
	float c,x,y;
	
	while(i<10)
	{
		printf("\nIngrese un numero:");
		cin >> c;
		x=pow(c,3);
		y=pow(c,4);
		
		cout << "El cubo del numero ingresado es: " << x << "\n";
		cout << "La cuarta del numero ingresado es: " << y << "\n\n";
		i+=1;
	}
	
	system("pause");
	return 0;
}