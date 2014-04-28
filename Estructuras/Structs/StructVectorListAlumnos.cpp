// Nombre del programa: StructVectorListAlumnos.cpp
// Descripción: Programa que tiene un vector con lista de alumnos por cajón
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 28-Abril-2014

//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <stdio.h>

//--------------------------------------------------------------------------------------- 
// Estructura de alumno
//---------------------------------------------------------------------------------------
struct alumno
{
    char nombre[100], licenciatura[100];
    int saldo, matricula;
};

//--------------------------------------------------------------------------------------- 
// Nuevo vector de listas de alumnos
//---------------------------------------------------------------------------------------
vector <list <struct alumno>> G; // G es el identificador de este vector
list <struct alumno>::iterator it; // it es un iterador especial para listas (se ocupa en el print_lista)

//--------------------------------------------------------------------------------------- 
// Funcion que recorre una lista y la imprime
//---------------------------------------------------------------------------------------
void print_lista(list <struct alumno> l)
{
    // Se recorre la lista
    for(it = l.begin(); it != l.end(); i++)
    {
        cout << "\n\t--[IMPRESION DE ALUMNO]--" << endl;
	    cout << "Nombre: " << it->nombre << endl;
	    cout << "Saldo: " << it->saldo << endl;
	    cout << "Licenciatura: " << it->licenciatura << endl;
	    cout << "Matricula: " << it->matricula << endl; 
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en una lista en el siguiente cajón dentro del vector
//---------------------------------------------------------------------------------------
void cargar_alumnos(vector <<list <struct alumno>> g)
{
	// Nueva lista donde se cargarán los alumnos
	list <struct alumno> l;

    struct alumno *p;
    FILE *fp;
    int  i, numero;
    char archivo[100];

    cout << endl << "Ingrese el nombre de la lista a cargar en un nuevo cajon del vector: ";
    cin >> archivo;

    fp = fopen(archivo, "r"); // Se abre el archivo en modo lectura

    if(fp==NULL)
    {
        cout<<"\nNo se pudo leer el archivo"<<endl;
    }
    else
    {
    	// Se lee el numero de alumnos que hay en el archivo
        fscanf(fp,"%d", &numero);

        // Se recorre cada renglón del archivo según cuantos alumnos haya detectado
        for(i=0; i<numero; i++)
        {
            struct alumno *p = new(struct alumno);
            fscanf(fp,"%s", p->nombre);
            fscanf(fp,"%d", &p->saldo);
            fscanf(fp,"%s", p->licenciatura);
            fscanf(fp,"%d", &p->matricula);

            // Se agrega el nuevo nodo a la lista de alumnos de este archivo
            l.push_back(*p);
        }
        fclose(fp);
    }

    // Se guarda la lista en un nuevo cajón del vector

}

// Tengo que checar como pasar list y vector a una funcion que se usan en linea 35 y 51 de este archivo
// Posiblemente con typedef antes ayude un poco