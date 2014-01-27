// Nombre del programa: Ejercicio While #1
// Descripción: Calcular el promedio de un alumno que tiene 7 calificaciones en la materia de Diseño Estructurado de Algoritmos
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
	float s=0;
	float c;
	
	while(i<7)
	{
		printf("\nIngrese calificacion:");
		cin >> c;
		s=s+c;
		i+=1;
	}
	s=s/7;
	printf("El promedio es %f\n\n",s);
	
	system("pause");
	return 0;
}