// Nombre del programa: Algoritmo #10
// Descripción: Diseñar un algoritmo que resuelva la ec. De segundo grado.
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
	
	float a,b,c,y,x1,x2;
	
	cout << "Ingrese los valores de una ecuacion de segundo grado de la forma ax2+bx+c=0\n";
	cout << "Ingrese el valor de la variable a: ";
	cin >> a;
	cout << "Ingrese el valor de la variable b: ";
	cin >> b;
	cout << "Ingrese el valor de la variable c: ";
	cin >> c;
	
	/* Interior de la raiz */
	y=pow(b,2)-(4*a*c);

	/* Proceder si se le puede sacar raiz */
	if(y>=0 && a>0)
	{
		x1=(-b+sqrt(y))/2*a;
		x2=(-b-sqrt(y))/2*a;
		
		/* Si solo hay un valor de x, se anota una vez, si tiene dos, se escriben los dos resultados */
		if (x1==x2)
			cout << "\nx vale: " << x1 << "\n\n";
		else{
			cout << "\nx1 vale: " << x1 << "\n";
			cout << "\nx2 vale: " << x2 << "\n\n";
		}
	}
	else
		cout << "\nEl sistema de ecuaciones no puede resolverse\n\n";
	
	system("pause");
	return 0;
}