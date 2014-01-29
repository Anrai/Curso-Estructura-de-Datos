// Nombre del programa: Ejercicio While #8
// Descripción: Al cerrar un expendio de naranjas, 15 clientes que aun no han pagado recibirán un 15% de descuento si compan más de 10 kilos.
//              Determinar cuánto pagará cada cliente y cuánto percibirá la tienda por esas compras.
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
	float compra, peso;

	while(i<15)
	{
		cout << "\n\nIngrese el costo de la compra del cliente:";
		cin >> compra;
		cout << "Ingrese el peso de la compra del cliente en kilogramos:";
		cin >> peso;

		if(peso>10)
		{
			cout << "Al cliente se le hara un descuento y tendra que pagar $" << compra*.85;
		}
		else
		{
			cout << "El cliente tiene que pagar el total que es de $" << compra;
		}
	}

	system("pause");
	return 0;
}