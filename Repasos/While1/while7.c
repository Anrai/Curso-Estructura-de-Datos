// Nombre del programa: Ejercicio While #7
// Descripción: Calcular e imprimir la tabla de multiplicar de un numero cualquiera. Imprimir el multiplicando, el multiplicador y el producto.
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

	int i = 1, num;
	
	cout << "Ingrese un numero entero del 1 al 9:";
	cin >> num;
	while(i<10)
	{
		cout << num << "x" << i << "=" << i*num << "\n";
		i+=1;
	}

	system("pause");
	return 0;
}