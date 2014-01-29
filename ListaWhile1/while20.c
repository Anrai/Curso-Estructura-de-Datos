// Nombre del programa: Ejercicio While #20
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

	int i=0, alumnos, genero, mujeres=0, hombres=0;
	float edad, edadH=0, edadM=0;
	cout << "Ingrese el total de alumnos: ";
	cin >> alumnos;

	while(i<alumnos)
	{
		cout << "\nIngrese 0 para hombre o cualquier otro numero para mujer: ";
		cin >> genero;
		cout << "\nIngrese la edad del alumno: ";
		cin >> edad;

		if (genero==0)
		{
			edadH+=edad;
			hombres+=1;
		}
		else
		{
			edadM+=edad;
			mujeres+=1;
		}

		i+=1;
	}

	cout << "\n\nEl promedio de edad de hombres es de: " << edadH/hombres;
	cout << "\nEl promedio de edad de mujeres es de: " << edadM/mujeres;
	cout << "\nEl promedio de edad es de: " << (edadH+edadM)/alumnos << "\n\n";

	system("pause");
	return 0;
}