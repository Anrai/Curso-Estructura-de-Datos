// Nombre del programa: Ejercicio While #3
// Descripción: Leer 10 números e imprimir solamente los números positivos
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
	float c;
	
	while(i<10)
	{
		printf("\nIngrese un numero:");
		cin >> c;
		
		if (c>0)
			cout << "El numero ingresado (" << c << ") es positivo\n";
		i+=1;
	}
	
	system("pause");
	return 0;
}