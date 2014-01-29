// Nombre del programa: Ejercicio while #21
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

	int i=0, n;
	float menor=9999999, valor;

	cout << "Cuantos valores quiere ingresar: ";
	cin >> n;

	while(i<n)
	{
		cout << "\nIngrese un valor: ";
		cin >> valor;
		if(valor<menor)
		{	
			menor=valor;
		}
		i+=1;
	}

	cout << "\n\nEl menor valor anotado es: " << menor << "\n\n";

	system("pause");
	return 0;
}