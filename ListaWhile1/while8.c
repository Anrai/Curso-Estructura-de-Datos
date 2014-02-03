// Nombre del programa: Ejercicio While #8
// Descripción: Simular el comportamiento de un reloj digital, imprimiendo la hora, minutos y segundos de un día desde las 0:00:00 horas hasta las 23:59:59 horas
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

	int hora = 0, minuto = 0, segundo = 0;
	
	while(hora<24){
		
		while(minuto<60)
		{
			while(segundo<60)
			{
				if (hora<10)
				{
					cout << 0;
				}
				cout << hora << ":";
			
				if (minuto<10)
				{
					cout << 0;
				}
				cout << minuto << ":";
				
				if (segundo<10)
				{
					cout << 0;
				}
				cout << segundo << "\n";
				segundo+=1;
			}
			segundo=0;
			minuto+=1;
		}
		minuto=0;
		hora+=1;
	}

	system("pause");
	return 0;
}