// Nombre del programa: StructFOpen.cpp
// Descripción: Struct de alumnos que los carga desde un archivo de texto con fopen
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
// Se declara una estructura de alumno
//---------------------------------------------------------------------------------------
struct alumno{
	char nombre [100], licenciatura[100];
	int matricula, saldo;
};

//--------------------------------------------------------------------------------------- 
// Funcion que llena una estructura de alumno
//---------------------------------------------------------------------------------------
struct alumno llena_alumno()
{
	struct alumno n;

	cout << "Ingrese el nombre del alumno: ";
	cin >> n.nombre;
	cout << "Ingrese la licenciatura del alumno: ";
	cin >> n.licenciatura;
	cout << "Ingrese la matricula del alumno: ";
	cin >> n.matricula;
	cout << "Ingrese el saldo del alumno: ";
	cin >> n.saldo;

	return n;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime una estructura alumno
//---------------------------------------------------------------------------------------
void print_alumno(struct alumno n)
{
	cout << n.nombre << endl;
	cout << n.licenciatura << endl;
	cout << n.matricula << endl;
	cout << n.saldo << endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que elimina una estructura de alumno dentro del arreglo de alumnos
//---------------------------------------------------------------------------------------
bool elimina_alumno(struct alumno arregloAlumnos[], int eliminar)
{
	bool recorrer = false;

	for(int i=0; i<20; ++i) // 20 Es el tamaño del arreglo de alumno
	{
		if (arregloAlumnos[i].matricula == eliminar) // Indica se se recorrerán todos los alumno a partir de ahora
			recorrer = true;
		if (recorrer) // Se recorre el nodo superior al actual en el arreglo de alumnos
			arregloAlumnos[i] = arregloAlumnos[i+1];
		if (recorrer && !arregloAlumnos[i].matricula) // Si se recorrieron los alumnos, el ultimo se borra (con un 0)
			arregloAlumnos[i].matricula = 0;
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

	struct alumno n1, n2, g[20]; // 20 es el tamaño del arreglo de alumnos
	int opcion, na=0, i, eliminar;

	// Menú de opciones que siempre se muestran
	while(1){
		cout << "Que operacion quiere realizar en el arreglo de alumnos? " << endl << "1 para insertar, 2 para mostrar, 3 para eliminar ";
		cin >> opcion;

		switch(opcion)
		{
			case 1:
				cout << endl << "-Se le pediran los valores del nuevo alumno: " << endl;
				g[na]=llena_alumno();
				na+=1;
				break;
			case 2:
				cout << endl << "-Se mostraran todos los alumnos:" << endl;
				for(i=0; i<na; ++i)
				{
					if (g[i].matricula != 0)
					{
						cout << endl << "Alumno: " << endl;
						print_alumno(g[i]);
					}
				}
				break;
			case 3:
				cout << endl << "-Indique la matricula del alumno que quiere eliminar: ";
				cin >> eliminar;
				if (elimina_alumno(g, eliminar))
					cout << "Se ha eliminado correctamente el alumno " << eliminar << endl << endl;
				else
					cout << "No se pudo eliminar el alumno " << eliminar << endl << endl;
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