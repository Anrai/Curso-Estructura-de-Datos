// Nombre del programa: Structs de nodos
// Descripción: Programa que genera, imprime y pide struct de nodo
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 24-Febrero-2014
  
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
// Se declara una estructura de nodo
//---------------------------------------------------------------------------------------
struct nodo{
	int num;
	float s;
	char nom[15];
};

//--------------------------------------------------------------------------------------- 
// Función que imprime una estructura nodo
//---------------------------------------------------------------------------------------
void print_nodo(struct nodo n)
{
	cout << n.num << endl;
	cout << n.s << endl;
	cout << n.nom << endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que llena una estructura de nodo
//---------------------------------------------------------------------------------------
struct nodo llena_nodo()
{
	struct nodo n;

	cout << "Ingrese un numero entero: ";
	cin >> n.num;
	cout << "Ingrese un flotante: ";
	cin >> n.s;
	cout << "Ingrese el nombre: ";
	cin >> n.nom;

	return n;
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	struct nodo n1, n2, g[20];
	int opcion, na=0, i;

	// Menú de opciones que siempre se muestran
	while(1){
		cout << "Que operacion quiere realizar en el arreglo de nodos? " << endl << "1 para insertar, 2 para mostrar, 3 para eliminar ";
		cin >> opcion;

		switch(opcion)
		{
			case 1:
				cout << endl << "-Se le pediran los valores del nuevo nodo: " << endl;
				g[na]=llena_nodo();
				na+=1;
				break;
			case 2:
				cout << endl << "-Se mostraran todos los nodos:" << endl;
				for(i=0; i<na; ++i)
				{
					cout << endl << "Nodo: " << endl;
					print_nodo(g[i]);
				}
				break;
			case 3:
				cout << endl << "-Indique que numero de nodo quiere eliminar: ";
				break;
			default:
				cout << "-La opcion especificada no existe, intente nuevamente." << endl;
		}

		cout << endl << "=====================================" << endl << endl;
	}

	// Fin del programa
	cout << "\n\n";
	system("pause");
	return 0;
}


// TAREA PARA EL 26 DE FEBRERO:
//		Terminar cola para caracteres
//		Hacer un menú con las opciones de: insertar, mostrar y eliminar struct nodo dentro de un arreglo de nodo según su num
//		muestra: muestra todo el arreglo
//		inserta: inserta un elemento al final del arreglo