// Nombre del programa: Ejercicio While #12
// Descripción: Un entrenador le ha propuesto a un atleta recorrer una ruta de cinco kilómetros durante 10 días,
//				para determinar si es apto para la prueba de 5 kílómetros o debe buscar otra especialidad.
//				Para considerarlo apto debe cumplir por lo menos una de las condiciones del documento de word.
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

	int i=0;
	float tiempo, sumaTiempo=0;
	bool noMasde16=true, almenos16=false, promedioMenor15=true;

	while(i<10)
	{
		cout << "\nIngrese el tiempo en minutos que tardo en recorrer los 5 kilometros en el dia " << i << "\n";
		cin >> tiempo;

		if(tiempo>16)
		{
			noMasde16=false;
			almenos16=true;
		}
		sumaTiempo+=tiempo;
		i+=1;
	}

	if (noMasde16 && almenos16 && promedioMenor15)
	{
		cout << "\nEl atleta es apto para la prueba de 5Km";
	}
	else
	{
		cout << "\nEl atleta no es apto para la prueba de 5Km";
	}

	system("pause");
	return 0;
}