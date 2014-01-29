// Nombre del programa: Ejercicio While #13
// Descripci�n: Un zo�logo pretende determinar el porcentaje de animales que hay en las siguientes tres categor�as de edades:
//				de 0 a 1 a�o, de m�s de 1 a�o y menos de 3 y de 3 o m�s a�os.
//				El zool�gico todav�a no est� seguro del animal que va a estudiar.
//				Si decide por elefantes s�lo tomar� una muestra de 20 de ellos; si se decide por jirafas, tomar� 15 muestras, y si son chimpanc�s tomar� 40.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas Garc�a 
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

	int i=0, x, animal;
	float  edad, edad1=0, edad2=0, edad3=0;

	cout << "Que animal pretende determinar el porcentaje de edades? elefantes=1, jirafas=2, chimpances=3 \n";
	cin >> animal;

	if (animal==1)
		{x=20;}
	else if (animal==2)
		{x=15;}
	else if (animal==3)
		{x=40;}
	else
	{
		x=0;
		cout << "\nEl valor indicado es incorrecto\n";
	}

	while(i<x)
	{
		cout << "\nIngrese la edad del animal: ";
		cin >> edad;

		if(edad==1 || edad==0)
		{
			edad1+=edad;
		}
		else if(edad==2)
		{
			edad2+=edad;
		}
		else if (edad>0)
		{
			edad3+=edad;
		}
		i+=1;
	}

	cout << "\n\nEl porcentaje de animales de edades de 0 a 1 ano es:" << (edad1*100)/x << " porciento";
	cout << "\nEl porcentaje de animales de edades de 1 a 3 anos es:" << (edad2*100)/x << " porciento";
	cout << "\nEl porcentaje de animales de edades de mas de 3 anos es:" << (edad3*100)/x << " porciento\n";

	system("pause");
	return 0;
}
