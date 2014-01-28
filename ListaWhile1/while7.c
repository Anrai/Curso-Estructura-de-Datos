// Nombre del programa: Ejercicio While #7
// Descripción: Calcular e imprimir la tabla de multiplicar de un numero cualquiera. Imprimir el multiplicando, el multiplicador y el producto.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 28-Enero-2014                                       
  
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

	int i = 0;
	float calificacionBaja=100, sumaCalificaciones=0, calificacion;

	while (i<40)
	{
		cout << "\n\nIngrese la cantidad del alumno no. " << i+1 << ":";
		cin >> calificacion;

		sumaCalificaciones+=calificacion;

		if (calificacion < calificacionBaja)
			calificacionBaja=calificacion;

		i+=1;
	}

	cout << "\n\nEl promedio de calificaciones es de: " << sumaCalificaciones/40;
	cout << "\nLa calificacion mas baja es de: " << calificacionBaja;

	system("pause");
	return 0;
}