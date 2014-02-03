// Nombre del programa: Ejercicio while #29
// Descripción: Calcular el promedio de masa de aire de los neumáticos de n vehículos que están en compostura en un servicio de alineación y balanceo.
// 				Los vehículos pueden ser motocicletas o automóviles.
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
	float masaSuma=0, presion, volumen, temperatura;

	cout << "Cuantos neumaticos quiere calcular: ";
	cin >> n;

	while(i<n)
	{
		cout << "\nIngrese la presion del neumatico: ";
		cin >> presion;
		cout << "\nIngrese el volumen del neumatico: ";
		cin >> volumen;
		cout << "\nIngrese la temperatura del neumatico: ";
		cin >> temperatura;

		masaSuma+=(presion*volumen)/(0.37*(temperatura+460));
	}

	cout << "\n\nEl promedio de la masa del aire calculada de los neumaticos es de: " << masaSuma/n << "\n\n";

	system("pause");
	return 0;
}