// Nombre del programa: Ejercicio While #4
// Descripción: Leer 20 números e imprimir cuantos son  positivos, cuantos negativos y cuantos neutros.
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
	
	int i=0,p=0,n=0,neutros=0;
	float c;
	
	while(i<20)
	{
		printf("Ingrese un numero: ");
		cin >> c;
		
		if (c>0)
			p+=1;
		else if (c<0)
			n+=1;
		else
			neutros+=1;
			
		i+=1;
	}
	
	cout << "\n\nDe los numeros ingresados:\n";
	cout << p <<" son positivos\n";
	cout << n <<" son negativos\ny ";
	cout << neutros <<" son neutros\n\n";
	
	system("pause");
	return 0;
}