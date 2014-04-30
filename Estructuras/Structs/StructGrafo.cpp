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
// Iterador para listas de enteros para print_nodo()
//---------------------------------------------------------------------------------------
 list <int>::iterator it; // it es un iterador especial para listas

//--------------------------------------------------------------------------------------- 
// Estructura de nodo
//---------------------------------------------------------------------------------------
struct nodo
{
    int nombre;
    list <int> nodos;
    list <int> pesos;
};

//--------------------------------------------------------------------------------------- 
// Funcion que recorre una nodo y lo imprime
//---------------------------------------------------------------------------------------
void print_nodo(struct nodo p)
{
    cout << "[NODO " << p.nombre << "]" << endl;

    // Se recorre la lista
    for(it=p.nodos.begin(); it != p.nodos.end(); it++)
    {
        cout << *it;
    }
    cout << endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que convierte un renglón de numeros y regresa un struct de nodo
//---------------------------------------------------------------------------------------
struct nodo *generar_lista(int nombre, string renglon)
{
    struct nodo *p = new(struct nodo); // Nueva estructura de nodo

    list <int> nodos; // Nueva lista donde se cargarán los nodos
    list <int> pesos; // Nueva lista donde se cargarán los pesos de los nodos
    char *token;
    bool nodoPeso = true; // true indica que es nodo y false indica que es false

    token = strtok( &renglon[0], " " );
    while( token != NULL )
    {
        if(nodoPeso)
            nodos.push_back(atoi(token)); // Se mete el nuevo dato convertido de char a int en la lista de nodos
        else
            pesos.push_back(atoi(token)); // Se mete el nuevo dato convertido de char a int en la lista de pesos de los nodos
        
        token = strtok( NULL, " " );
        nodoPeso = !nodoPeso;
    }

    p->nombre = nombre;
    p->nodos = nodos;
    p->pesos = pesos;

    print_nodo(*p);

    return p;
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en el vector
//---------------------------------------------------------------------------------------
//vector <list <int> > 
void cargar_grafo()
{
    vector <struct nodo> G; // G es el identificador de este vector (grafo)
    
    int nombreNodo = 1; // Para cada nodo se ocupa esta variable temporal
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
            G.push_back(*generar_lista(nombreNodo, renglon)); // Se genera una lista a partir del string y se agrega la nueva lista a un cajón del grafo (vector)
            nombreNodo++;
        }

        infile.close(); // Cierra el archivo trabajado

        cout << "*Hecho, se agregaron " << G.size() << " listas de nodos en vector." << endl;
    }
}

/*
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