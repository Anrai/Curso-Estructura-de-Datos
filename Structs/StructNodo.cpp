// Nombre del programa: Structs de nodos
// Descripción: Programa que genera, imprime, elimina y pide structs de nodo
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 5-Marzo-2014
  
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
// Funcion que elimina una estructura de nodo dentro del arreglo de nodos
//---------------------------------------------------------------------------------------
bool elimina_nodo(struct nodo arregloNodos[], int eliminar)
{
	bool recorrer = false;

	for(int i=0; i<20; ++i) // 20 Es el tamaño del arreglo de nodos
	{
		if (arregloNodos[i].num == eliminar) // Indica se se recorrerán todos los nodos a partir de ahora
			recorrer = true;
		if (recorrer) // Se recorre el nodo superior al actual en el arreglo de nodos
			arregloNodos[i] = arregloNodos[i+1];
		if (recorrer && !arregloNodos[i].s) // Si se recorrieron los nodos, el ultimo se borra (con un 0)
			arregloNodos[i].num = 0;
	}

	if (recorrer)
		return true;
	else
		return false;
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	struct nodo n1, n2, g[20]; // 20 es el tamaño del arreglo de nodos
	int opcion, na=0, i, eliminar;

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
					if (g[i].num != 0)
						print_nodo(g[i]);
				}
				break;
			case 3:
				cout << endl << "-Indique que numero de nodo quiere eliminar: ";
				cin >> eliminar;
				if (elimina_nodo(g, eliminar))
					cout << "Se ha eliminado correctamente el nodo " << eliminar << endl << endl;
				else
					cout << "No se pudo eliminar el nodo " << eliminar << endl << endl;
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


// TAREA:
//		Terminar cola para caracteres
//		
//		Struct de alumno
//		Struct alumno cargado desde archivo de texto con fopen
//		Hacer apuntador p para generar nuevas estructuras (estructura dinnámica con apuntador al siguiente) usando malloc
//		Hacer funcion de generar, llenar la estructura generada o insertar al inicio de la lista de structs