// Nombre del programa: StructListaLigadaAlumnos.cpp
// Descripción: Mismo programa que StructArrayAlumnos.cpp pero que los alumnos los guarda en una Lista Ligada
// Importante: El archivo.txt de esta versión es un poco diferente
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 23-Abril-2014
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

//--------------------------------------------------------------------------------------- 
// Estructura de alumno
//---------------------------------------------------------------------------------------
struct alumno
{
    char nombre[20];
    int edad, matricula;
    float saldo;
    struct alumno *sig;
};

//--------------------------------------------------------------------------------------- 
// Función que pide los datos de un alumno y llena una estructura tipo alumno
//---------------------------------------------------------------------------------------
struct alumno *llena_alumno()
{
    // Se hace un nuevo alumno de estructura alumno y revisa el tamaño de la lista ligada
    struct alumno *a;
    a=(struct alumno*)(malloc(sizeof(alumno)));

    if(a == NULL)
        cout << endl << "No se puede crear el nuevo alumno.";
    else
    {
        cout<<"\nIngrese Nombre: ";
        cin>>a->nombre;
        cout<<"Ingrese Saldo: ";
        cin>>a->saldo;
        cout<<"Ingrese Edad: ";
        cin>>a->edad;
        cout<<"Ingrese Matricula: ";
        cin>>a->matricula;
        a->sig=NULL;
    }

    return a;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime en consola la información de una estructura tipo alumno
//---------------------------------------------------------------------------------------
void print_alumno(struct alumno *a){
    cout << "\n\t--[IMPRESION DE ALUMNO]--"<< endl;
    cout << "Nombre: "<< a->nombre << endl;
    cout << "Saldo: "<< a->saldo << endl;
    cout << "Edad: "<< a->edad << endl;
    cout << "Matricula: "<< a->matricula << endl; 
}

//--------------------------------------------------------------------------------------- 
// Función que Imprime cada uno de los nodos de la lista ligada
//---------------------------------------------------------------------------------------
void print_lista(struct alumno *r) // Puntero del primer nodo de la lista ligada
{
    while(r != NULL)
    {
        print_alumno(r);
        r = r->sig;
    }
}

//--------------------------------------------------------------------------------------- 
// Función que Inserta un nuevo Alumno al principio de la lista ligada
//---------------------------------------------------------------------------------------
struct alumno *ins_ini(struct alumno *a, struct alumno *p) // a es el viejo primer nodo, p es el neuvo primer nodo
{
    // Si no hay alumnos todavía, el segundo argumento (*p) será el primer nodo de la lista 
    if(a == NULL)
        a = p; // Son punteros
    else
    {
        // El apuntador siguiente del alumno p será el antiguo primer nodo de la lista
        // El alumno p será el nuevo primer nodo de la lista ligada
        p->sig = a;
        a = p; // Siguen siendo punteros
    }
    return a; // Regresa el puntero del nuevo primer nodo de la lista
}

//--------------------------------------------------------------------------------------- 
// Función que Inserta un nuevo Alumno al final de la lista ligada
//---------------------------------------------------------------------------------------
struct alumno *ins_final(struct alumno *l) // *l es el puntero inicial de la lista ligada
{
    struct alumno *q, *p;
    p = llena_alumno();

    // Si no hay nodos en la lista, p va a ser el primero
    if(l == NULL)
    {
        l = p;
    }
    else
    {
        q = l;
        while(q->sig != NULL)
        {
            q = q->sig; // Se recorre la lista para encontrar el nodo final
        }
        q->sig = p; // El nodo final ahora apunta al nuevo nodo creado
    }
    return l; // Se regresa el puntero del nuevo nodo final
}

//--------------------------------------------------------------------------------------- 
// Función que inserta un nuevo alumno, ordenado en la lista según su matrícula
//---------------------------------------------------------------------------------------
struct alumno * ins_orden(struct alumno *lista, struct alumno *nuevoNodo)
{
    struct alumno *nodoRecorrido, *nodoAnterior;
    nodoRecorrido = lista;

    if(lista == NULL)
    {
        // El nuevo alumno es el único
        lista = nuevoNodo;
    }
    else
    {
        // Se recorre la lista
        while(nodoRecorrido->sig != NULL && nodoRecorrido->matricula < nuevoNodo->matricula)
        {
            nodoAnterior = nodoRecorrido;
            nodoRecorrido = nodoRecorrido->sig;
        }

        // Nuevo nodo al inicio
        if(lista->matricula >= nuevoNodo->matricula)
        {
            nuevoNodo->sig = lista;
            lista = nuevoNodo;
        }
        // Nuevo nodo al final
        else if(nodoRecorrido->sig == NULL)
        {
            nodoRecorrido->sig = nuevoNodo;
        }
        // Nuevo nodo en medio
        else
        {
            nuevoNodo->sig = nodoRecorrido;
            nodoAnterior->sig = nuevoNodo;
        }
    }

    return lista;
}

//--------------------------------------------------------------------------------------- 
// Función que elimina el nodo final de la lista ligada de alumnos
//---------------------------------------------------------------------------------------
struct alumno *eli_inicio(struct alumno *l)
{
    struct alumno *p; // Puntero temporal para borrar el nodo
    if(l != NULL) // Si existe el nodo, entonces se elimina
    {
        p = l; // Se guarda el primer nodo en el temporal
        l = l->sig; // El nodo siguiente ahora es el primero
        free(p); // Se libero memoria que contenía el primer nodo antiguo
    }
    return l; // Se regresa el puntero del nuevo primer nodo
}

//--------------------------------------------------------------------------------------- 
// Función que elimina el último nodo de la lista ligada de alumnos
//---------------------------------------------------------------------------------------
void eli_final(struct alumno *l)
{
    struct alumno *m;
    struct alumno *q;

    m = l; // m es para ir recorriendo la lista hasta encontrar el final
    q = l;

    while(m != NULL)
    {
        if(m->sig == NULL) // Si se llega al final de la lista...
        {
            q->sig = NULL; // Cuando se llega al final de la lista, el penultimo nodo apuntará a NULL para indicar que es el nuevo último nodo de la lista ligada
            free(m); // Se libera el nodo final de la memoria
        }
        else
        {
            q = m; // q almacena el puntero del nodo actual
        }
        m = m->sig; // Se va al siguiente nodo
    }
}

//--------------------------------------------------------------------------------------- 
// Función que elimina el alumno segun la matricula ingresada
//---------------------------------------------------------------------------------------
struct alumno *eli_orden(struct alumno *l){

    struct alumno *q, *r;
    int matricula;

    printf("\nMatricula a eliminar: ");
    scanf("%d",&matricula);
    if(l==NULL){
        printf("\n Vacia");
    }
    else{
        q=l;
        if (q->matricula==matricula){
            l=q->sig;
        }
        else{
            while(q!=NULL && q->matricula!=matricula){
                r=q; q=q->sig;
            }
            if(q==NULL){
                printf("\n No existe la matricula en la lista");
            }
            else{
                r->sig=q->sig;
            }
        }
    }
    return l;
}

//--------------------------------------------------------------------------------------- 
// Función que lee un archivo.txt y guarda los datos en una lista ligada de tipo struct alumno
//---------------------------------------------------------------------------------------
struct alumno * leer_archivo()
{
    int numero, i;
    struct alumno *l = NULL, *p;

    FILE *fp; // Nueva estructura tipo FILE
    fp = fopen("archivo.txt","r"); // Se carga el archivo en fp con la función fopen en modo lectura

    if(fp == NULL)
    {
        cout << "\nNo se pudo leer el archivo" << endl;
    }
    else
    {
        fscanf(fp, "%d", &numero); // Lee el numero de datos guardados, lo formatea como int y guarda en variable
        cout << "\nLectura con exito, " << numero << " registros encontrados.";

        // Almacena toda la información del archivo.txt en el arreglo con estructuras de alumnos
        for(i=0; i<numero; i++)
        {
            // Se crea una nueva estructura alumno en la lista ligada
            p = (struct alumno*)(malloc(sizeof(alumno))); 
            fscanf(fp,"%s", p->nombre);
            fscanf(fp,"%d", &p->edad);
            fscanf(fp,"%f", &p->saldo);
            fscanf(fp,"%d", &p->matricula);
            p->sig = NULL;
            l = ins_ini(l, p); // Se van insertando al inicio, l es el puntero del principio, p es el nuevo nodo
        }

        fclose(fp); // Cierra el archivo trabajado
        return l; // Regresa el puntero al nodo
    }
}

//--------------------------------------------------------------------------------------- 
// Función que escribe en un archivo.txt desde un arreglo tipo struct alumno
//---------------------------------------------------------------------------------------
void guardar_archivo(struct alumno *l)
{
    struct alumno *r;
    int i=0; // Contador de alumnos

    FILE *fp; // Nueva estructura tipo FILE
    fp = fopen("archivo.txt", "w"); // Se abre el archivo en modo escritura

    r=l; // r es cada uno de los nuevos nodos
    if(fp != NULL)
    {
        // Se cuentan cuantos nodos hay en la lista
        while (r != NULL)
        {
            i++;
            r = r->sig;
        }
        fprintf(fp, "%d\n", i); // Primero se escribe el numero de alumnos a indexar

        // Se llena el archivo.txt con los datos de los alumnos que están en la lista (con saltos de línea)
        while(l != NULL)
        {
            fprintf(fp,"%s\n", l->nombre);
            fprintf(fp,"%d\n", l->edad);
            fprintf(fp,"%d\n", l->matricula);
            fprintf(fp,"%f\n", l->saldo);
            l = l->sig;
        }
    }
    else
        printf("No se pudo crear el archivo!!!");

    fclose(fp); // Se cierra el archivo
}

//--------------------------------------------------------------------------------------- 
// Función que imprime en consola un menú con las opciones que puede hacer el programa, pregunta la opción y la regresa
//---------------------------------------------------------------------------------------
int menu()
{
    int opcion;

    cout<<"\n\n---------------------------------------------";
    cout<<"\n\t--[MENU DE LISTA LIGADA]--";
    cout<<"\n---------------------------------------------\n\n";

    cout<<"1.-Inserta nuevo alumno al inicio"<<endl;
    cout<<"2.-Inserta nuevo alumno al final"<<endl;
    cout<<"3.-Imprime todos los alumnos"<<endl;
    cout<<"4.-Elimina el primer alumno"<<endl;
    cout<<"5.-Elimina el ultimo alumno"<<endl;
    cout<<"6.-Inserta un alumno en orden segun su matricula"<<endl;
    cout<<"7.-Elimina un alumno segun su matricula"<<endl;
    cout<<"8.-Cargar alumnos desde archivo.txt"<<endl;
    cout<<"9.-Guardar alumnos en archivo.txt"<<endl;
    cout<<"10.-Salir"<<endl<<endl;

    cout << "Introduzca una opcion: ";
    cin >> opcion;

    return opcion;
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    struct alumno *lista, *p; // Alumno es nuevo nodo, lista es el puntero del primer nodo de una lista, p es un puntero temporal para nuevos nodos
    int i, opcion;
    lista = NULL; // La lista comienza vacía

    // Se muestra el menú y se procede con la opción elegida
    do
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
            {
                // Insertar nuevo alumno al inicio
                p = llena_alumno();
                lista = ins_ini(lista, p); // p lo mete al principio de lista
                break;
            }

            case 2:
            {
                // Insertar nuevo alumno al final
                lista = ins_final(lista); // Ahí mismo se llama a llena_alumno
                break;
            }

            case 3:
            {
                // Imprime todos los alumnos
                print_lista(lista);
                break;
            }

            case 4:
            {
                // Elimina el primer alumno
                lista = eli_inicio(lista);
                break;
            }

            case 5:
            {
                // Elimina el último alumno
                eli_final(lista);
                break;
            }

            case 6:
            {
                // Inserta un nuevo alumno, ordenándolo según su matrícula
                p = llena_alumno();
                lista = ins_orden(lista, p);
                break;
            }

            case 7:
            {
                // Elimina un alumno según su matrícula
                lista = eli_orden(lista);
                break;
            }

            case 8:
            {
                // Carga alumnos de un archivo.txt y hace una lista nueva
                lista = leer_archivo();
                break;
            }

            case 9:
            {
                // Guarda los alumnos de la lista en un archivo.txt
                guardar_archivo(lista);
                break;
            }

        }

    }while(opcion != 10);

    // Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}