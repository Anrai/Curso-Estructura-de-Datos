// Nombre del programa: StructGrafo.cpp
// Descripción: Programa que carga un grafo desde una archivo y genera un grafo
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 30-Abril-2014

//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Nuevo vector (grafo) de listas (la lista tiene un nodo y su valor (distancia) y luego otro nodo)
//---------------------------------------------------------------------------------------
list <int>::iterator it; // it es un iterador especial para listas

//--------------------------------------------------------------------------------------- 
// Funcion que convierte un renglón de numeros y regresa una lista
//---------------------------------------------------------------------------------------
list <int> generar_lista(string renglon)
{
    list <int> l; // Nueva lista donde se cargarán los nodos y sus valores respecto a otros nodos
    char *token;

    token = strtok( &renglon[0], " " );
    while( token != NULL )
    {
        l.push_back(atoi(token)); // Se mete el nuevo dato convertido de char a int en la lista de nodos
        token = strtok( NULL, " " );
    }

    return l;
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en el vector
//---------------------------------------------------------------------------------------
//vector <list <int> > 
void cargar_grafo()
{
    vector <list <int> > G; // G es el identificador de este vector (grafo)
    
    int nodo; // Para cada nodo se ocupa esta variable temporal
    char archivo[100];
    string renglon;

    cout << endl << "Ingrese el nombre de grafo a cargar: ";
    cin >> archivo;

    // Carga de archivo en infile;
    ifstream infile; 
    infile.open(archivo);

    if(!infile.is_open())
    {
        cout << "*No se pudo leer el archivo!" << endl;
    }
    else
    {
        getline(infile, renglon); // Se omite el primer renglon porque fstream no lo necesita

        // Se recorre cada renglón del archivo
        while(!infile.eof()) // Hasta que se terminen los renglones
        {
            getline(infile, renglon); // Se obtiene un renglon y se guarda en un string
            G.push_back(generar_lista(renglon)); // Se genera una lista a partir del string y se agrega la nueva lista a un cajón del grafo (vector)
        }

        infile.close(); // Cierra el archivo trabajado

        cout << "*Hecho, se agregaron " << G.size() << " listas de nodos en vector." << endl;
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que recorre una lista y la imprime
//---------------------------------------------------------------------------------------
/*
void print_lista(list <struct alumno> l)
{
    // Se recorre la lista
    for(it=l.begin(); it != l.end(); it++)
    {
        cout << "[ALUMNO]:" << endl;
        cout << "Nombre: " << it->nombre << endl;
        cout << "Saldo: " << it->saldo << endl;
        cout << "Licenciatura: " << it->licenciatura << endl;
        cout << "Matricula: " << it->matricula << endl << endl; 
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que recorre un vector y manda a imprimir la lista dentro del cajon
//---------------------------------------------------------------------------------------
void print_vector()
{
    int i;

    // Se recorre cada cajon del vector y se imprime la lista contenida
    for(i=0; i<G.size(); i++)
    {
        cout << "\n\t--[IMPRESION DE LISTA DE ALUMNOS] [CAJON " << i << "]--" << endl << endl;
        print_lista(G[i]);
    }
}

//--------------------------------------------------------------------------------------- 
// Función que imprime en consola un menú con las opciones que puede hacer el programa, pregunta la opción y la regresa
//---------------------------------------------------------------------------------------
int menu()
{
    int opcion;

    cout << "\n\n---------------------------------------------";
    cout << "\n\t--[MENU DE ALUMNOS DENTRO DE LISTAS EN CAJONES DE UN VECTOR]--";
    cout << "\n---------------------------------------------\n\n";

    cout << "1.-Cargar un archivo de alumnos" << endl;
    cout << "2.-Imprimir todos los cajones del vector" << endl;
    cout << "3.-Salir" << endl << endl;

    cout << "Introduzca una opcion: ";
    cin >> opcion;

    return opcion;
}*/

//--------------------------------------------------------------------------------------- 
// Programa Principal
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    while (1)
    {
        cargar_grafo(); 
    }

    /*
    int opcion;

    do{
        opcion = menu();

        switch(opcion)
        {
            case 1: // Generar una lista de alumnos cargada de un archivo de texto y meterla en un cajon del vector
            {
                cargar_alumnos();
                break;
            }
            case 2: // Imprimir todas las listas de alumnos del vector
            {
                print_vector();
                break;
            }
            default:
            {
                cout << "*La opcion ingresada es invalida.";
            }
        }

    } while (opcion != 3);
    */

    // Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}