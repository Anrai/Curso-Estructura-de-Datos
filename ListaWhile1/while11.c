// Nombre del programa: Ejercicio While #11
// Descripción: En un centro de verificación de automóviles se desea saber el promedio de puntos contaminantes de los primeros 25 automóviles que lleguen.
//				Asimismo se desea saber los puntos contaminantes del carro que menos contamino y del que más contaminó.
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
	float cont, mascont=0, menoscont=999999, sumacont=0;

	while(i<25)
	{
		cout << "\nIngrese los puntos de contaminacion del automovil:";
		cin >> cont;

		if (cont>mascont)
		{	
			mascont=cont;
		}
		if (cont<menoscont)
		{	
			menoscont=cont;
		}
		sumacont+=cont;
		i+=1;
	}

	cout << "\n\nEl promedio de los puntos de contaminacion es: " << sumacont/25;
	cout << "\nEl auto con mayor puntos de contaminacion tiene " << mascont << "puntos";
	cout << "\nEl auto con menor puntos de contaminacion tiene " << menoscont << "puntos\n";

	system("pause");
	return 0;
}