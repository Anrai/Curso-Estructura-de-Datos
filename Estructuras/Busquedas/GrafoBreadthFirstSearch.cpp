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
#include <queue>
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
    list <int> nodos; // Nodos adyacentes (Con los que conecta)
    list <int> pesos;
};

//--------------------------------------------------------------------------------------- 
// Funcion que imprime un vector de enteros - FUNCIÓN TEMPORAL PARA PROBAR ALGORITMO BFS
//---------------------------------------------------------------------------------------
void print_vector(vector <int> color, vector <int> distancia, vector <int> padre)
{
    int i, x;

    cout << "\n\t--[IMPRESION DE VECTORES DE BFS]--" << endl << endl;

    // Se recorre el vector
    for(i=1; i<padre.size(); i++)
    {
        cout << "Nodo " << i << ": Color[" << color[i] << "], Distancia[" << distancia[i] << "], Padre[" << padre[i] << "]" << endl;
    }
}

//--------------------------------------------------------------------------------------- 
// Función que recorre un nodo y lo imprime
//---------------------------------------------------------------------------------------
void print_nodo(struct nodo p)
{
    cout << "[NODO " << p.nombre << "]" << endl;
    cout << "Nodos adyacentes: ";

    // Se recorre la lista
    for(it=p.nodos.begin(); it != p.nodos.end(); it++)
    {
        cout << *it << ", ";
    }
    cout << endl;
}

//--------------------------------------------------------------------------------------- 
// Función que recorre un grafo (vector) y manda a imprimir todos sus nodos
//---------------------------------------------------------------------------------------
void print_grafo(vector <struct nodo> G)
{
    int i;

    cout << "\n\t--[IMPRESION DE GRAFO]--" << endl << endl;

    // Se recorre cada cajon del vector y se imprime la lista contenida
    for(i=0; i<G.size(); i++)
    {
        print_nodo(G[i]);
    }
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
    bool nodoPeso = true; // true indica que es nodo y false indica que es peso

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

    return p;
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en el vector
//---------------------------------------------------------------------------------------
vector <struct nodo> cargar_grafo()
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

    return (G);
}

//--------------------------------------------------------------------------------------- 
// Algoritmo BFS - Función que pide un grafo y uno de sus vertices (será la raíz). Regresa un vector de padres de cada nodo.
//---------------------------------------------------------------------------------------
//vector <int> 
void bfs(vector <struct nodo> G, int s) // s=raíz
{
    // Muestra primero el grafo en pantalla
    print_grafo(G);

    //--------------------------------------------------------------------------------------- 
    // Primera parte de la función
    //---------------------------------------------------------------------------------------

    // Se declaran las estructuras que se utilizarán
    vector <int> color; // Es el estado de cada nodo. Indica si ya se recorrió el nodo (0=Blanco, 1=Gris, 2=Negro)
    vector <int> distancia; // Distancia de un nodo con respecto a la raíz
    vector <int> padre; // Vector que se regresa. Indica quién es el padre de cada nodo según la raíz
    queue <int> Q; // Cola que se rellena con los nodos a revisar y se vacía según se vayan revisando.
    int u; // Nombre del nodo que se estará revisando en el while
    list <int>::iterator it; // Iterador de lista de adyacencias de un nodo

    // El primer elemento de cada vector no existe
    color.push_back(-1);
    distancia.push_back(-1);
    padre.push_back(-1);

    // Armando las estructuras que se utilizarán
    for(int i=0; i<G.size(); ++i)
    {
        color.push_back(0);
        distancia.push_back(999);
        padre.push_back(-1);
    }
    // Se especifican los valores de la raíz
    color[s] = 1;
    distancia[s] = 0;
    Q.push(s);

    //--------------------------------------------------------------------------------------- 
    // Segunda parte de la función (Algoritmo)
    //---------------------------------------------------------------------------------------
    while(!Q.empty())
    {
        u = Q.front(); Q.pop(); // Se extrae y borra el elemento del frente de la cola (El nodo que se está revisando)

        // Se checan todas las adyacencias del nodo que se está revisando (*it=v según algoritmo)
        for(it=G[u-1].nodos.begin(); it!=G[u-1].nodos.end(); it++) // u-1 porque el nodo 1 se guarda en G[0] y así sucesivamente
        {
            if(color[*it] == 0)
            {
                color[*it] = 1;
                distancia[*it] = distancia[u]+1;
                padre[*it] = u;
                Q.push(*it);
            }
        }
        color[u] = 2;
    }

    print_vector(color, distancia, padre); // Se imprime un vector para ver que onda

}

/*
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
    vector <struct nodo> G;
    int raiz;

    while (1)
    {
        G = cargar_grafo();
        cout << "\nQue numero de nodo desea tomar como raiz para la busqueda? ";
        cin >> raiz;
        bfs(G, raiz);
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