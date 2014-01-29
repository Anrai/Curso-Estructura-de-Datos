// Nombre del programa: Ejercicio While #5
// Descripción: Leer 15 números negativos y convertirlos a positivos e imprimir dichos números
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

using namespace std;

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	int i=0;
	float a;

	while(i<15)
	{
		cout << "\n\nIngrese un numero negativo: ";
		cin >> a;
		while (a>=0)
		{
			cout << "\nEl numero que ingreso no es negativo, intente nuevamente: ";
			cin >> a;
		}

		cout << "\nEl valor positivo del numero ingresado es: " << -a;
		i+=1;
	}

	system("pause");
	return 0;
}