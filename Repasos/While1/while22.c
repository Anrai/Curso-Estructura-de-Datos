// Nombre del programa: Ejercicio while #22
// Descripción: Encontrar el mayor valor de un conjunto de n números dados.
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
	float mayor=-999999, valor;

	cout << "Cuantos valores quiere ingresar: ";
	cin >> n;

	while(i<n)
	{
		cout << "\nIngrese un valor: ";
		cin >> valor;
		if(valor>mayor)
		{	
			mayor=valor;
		}
		i+=1;
	}

	cout << "\n\nEl mayor valor anotado es: " << mayor << "\n\n";

	system("pause");
	return 0;
}