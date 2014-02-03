// Nombre del programa: Ejercicio While #9
// Descripción: Una persona debe realizar un muestreo con 50 personas par adetermian el promedio de peso de los niños, jóvenes, adultos y viejos que existen en su zona habitacional.
//              se determinan las categorias con base en la tabla mostrada en el archivo de word.
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

	int i=0, edad, ninos=0, jovenes=0, adultos=0, viejos=0;
	float pninos=0, pjovenes=0, padultos=0, pviejos=0, peso;

	while(i<50)
	{
		cout << "\nIngrese la edad de la persona: ";
		cin >> edad;
		cout << "\nIngrese el peso de la persona en Kg: ";
		cin >> peso;
		if (edad<=12)
		{
			pninos+=peso;
			ninos+=1;
		}
		else if (edad<=29)
		{
			pjovenes+=peso;
			jovenes+=1;
		}
		else if (edad<=59)
		{
			padultos+=peso;
			adultos+=1;
		}
		else
		{
			pviejos+=peso;
			viejos+=1;
		}
		i+=1;
	}

	cout << "\n\nEl promedio de peso de los ninos es de:" << pninos/ninos;
	cout << "\nEl promedio de peso de los jovenes es de:" << pjovenes/jovenes;
	cout << "\nEl promedio de peso de los adultos es de:" << padultos/adultos;
	cout << "\nEl promedio de peso de los viejos es de:" << pviejos/viejos << "\n";

	system("pause");
	return 0;
}