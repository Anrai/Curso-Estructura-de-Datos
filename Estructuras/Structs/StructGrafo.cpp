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

using namespace std;

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
vector <list <struct alumno> > G; // G es el identificador de este vector
list <struct alumno>::iterator it; // it es un iterador especial para listas (se ocupa en el print_lista)

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en una lista en el siguiente cajón dentro del vector
//---------------------------------------------------------------------------------------
void cargar_alumnos()
{
    list <struct alumno> l; // Nueva lista donde se cargarán los alumnos
    struct alumno *p; // Puntero de struct alumno temporal para guardar cada nuevo alumno detectado y después poder pasarlo a la lista
    int  i, numero;
    char archivo[100];

    cout << endl << "Ingrese el nombre de la lista a cargar en un nuevo cajon del vector: ";
    cin >> archivo;

    FILE *fp; // Se genera una nueva estructura de archivo que cargará la información del archivo
    fp = fopen(archivo, "r"); // Se abre el archivo en modo lectura    

    if(fp == NULL)
    {
        cout << "*No se pudo leer el archivo!" << endl;
    }
    else
    {
        fscanf(fp,"%d", &numero); // Lee el numero de datos guardados, lo formatea como int y guarda en variable

        // Se recorre cada renglón del archivo según cuantos alumnos haya detectado
        for(i=0; i<numero; i++)
        {
            struct alumno *p = new(struct alumno); // Nuevo struct alumno que se guardará en la lista
            fscanf(fp,"%s", p->nombre);
            fscanf(fp,"%d", &p->saldo);
            fscanf(fp,"%s", p->licenciatura);
            fscanf(fp,"%d", &p->matricula);

            // Se agrega el nuevo nodo a la lista de alumnos de este archivo
            l.push_back(*p);
        }

        fclose(fp); // Cierra el archivo trabajado

        // Se guarda la lista en un nuevo cajón del vector
        G.push_back(l);
        cout << "*Hecho, " << numero << " registros en nueva lista del vector en el cajon " << G.size()-1 << "." << endl;
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que recorre una lista y la imprime
//---------------------------------------------------------------------------------------
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
}

//--------------------------------------------------------------------------------------- 
// Programa Principal
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
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

    // Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}