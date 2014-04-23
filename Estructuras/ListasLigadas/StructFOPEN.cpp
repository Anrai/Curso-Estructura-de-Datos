// Nombre del programa: StructFOPEN.cpp
// Descripción: Programa que tiene una estructura de alumnos y puede leer y escribir en un archivo.txt
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
// Función que pide los datos de un alumno y llena una estructura tipo alumno
//---------------------------------------------------------------------------------------
struct alumno llena_alumno()
{
    struct alumno a;

    cout<<"\nIngrese Nombre: ";
    cin>>a.nombre;
    cout<<"Ingrese Saldo: ";
    cin>>a.saldo;
    cout<<"Ingrese Licenciatura: ";
    cin>>a.licenciatura;
    cout<<"Ingrese Matricula: ";
    cin>>a.matricula;

    return a;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime en consola la información de una estructura tipo alumno
//---------------------------------------------------------------------------------------
void print_alumno(struct alumno a){
    cout << "\n\t--[IMPRESION DE ALUMNO]--"<< endl;
    cout << "Nombre: "<< a.nombre << endl;
    cout << "Saldo: "<< a.saldo << endl;
    cout << "Licenciatura: "<< a.licenciatura << endl;
    cout << "Matricula: "<< a.matricula << endl; 
}

//--------------------------------------------------------------------------------------- 
// Función que busca por matricula un alumno en el arreglo de estructuras de alumnos y lo elimina
//---------------------------------------------------------------------------------------
int elimina_alumno(struct alumno g[20], int na) // g=arreglo con alumnos, na=numero de alumnos
{
    int indice=-1, i, j, x; // x=matricula del alumno que se quiere borrar, indice=indice del alumno en el arreglo, i y j son contadores

    cout << "\nIntroduzca la matricula del alumno a eliminar: ";
    cin >> x;

    // Se busca el indice del alumno que se quiere eliminar en el arreglo
    for(i=0; i<na; i++)
    {
        if(x==g[i].matricula)
            indice=i;
    }

    // Si se encontró el alumno, éste se elimina (recorriendo los demás alumnos)
    if(indice!=-1)
    {
        for(j=indice; j<na; j++)
        {
            g[j] = g[j+1];
        }
    }

    return indice;
}

//--------------------------------------------------------------------------------------- 
// Función que lee un archivo.txt y guarda los datos en un arreglo tipo struct alumno
//---------------------------------------------------------------------------------------
int leer_fopen(struct alumno a[20])
{
    int numero, i;
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
            fscanf(fp, "%s", a[i].nombre);
            fscanf(fp, "%d", &a[i].saldo);
            fscanf(fp, "%s", a[i].licenciatura);
            fscanf(fp, "%d", &a[i].matricula);
        }

        fclose(fp); // Cierra el archivo trabajado
        return numero; // Regresa el numero de registros indexados
    }
}

//--------------------------------------------------------------------------------------- 
// Función que escribe en un archivo.txt desde un arreglo tipo struct alumno
//---------------------------------------------------------------------------------------
void escribe_fopen(struct alumno a[20], int na) // na=número de alumnos
{
    int num=0, i;

    FILE *fp; // Nueva estructura tipo FILE
    fp = fopen("archivo.txt", "w"); // Se abre el archivo en modo escritura

    if(fp != NULL)
    {
        fprintf(fp, "%d\n", na); // Primero se escribe el numero de alumnos a indexar

        // Se llena el archivo.txt con los datos de los alumnos que están en el arreglo (con saltos de línea)
        for(i=0; i<na; i++)
        {
            fprintf(fp, "%s\n", a[i].nombre);
            fprintf(fp, "%d\n", a[i].saldo);
            fprintf(fp, "%s\n", a[i].licenciatura);
            fprintf(fp, "%d\n", a[i].matricula);
        }
    }

    fclose(fp); // Se cierra el archivo
}

//--------------------------------------------------------------------------------------- 
// Función que imprime en consola un menú con las opciones que puede hacer el programa, pregunta la opción y la regresa
//---------------------------------------------------------------------------------------
int menu()
{
    int opcion;

    cout<<"\n\n---------------------------------------------";
    cout<<"\n\t--[MENU DE ESTRUCTURAS DINAMICAS]--";
    cout<<"\n---------------------------------------------\n\n";

    cout<<"1.-Inserta nuevo alumno"<<endl;
    cout<<"2.-Imprime todos los alumnos"<<endl;
    cout<<"3.-Elimina un alumno"<<endl;
    cout<<"4.-Cargar alumnos desde archivo.txt"<<endl;
    cout<<"5.-Guardar alumnos en archivo.txt"<<endl;
    cout<<"6.-Salir"<<endl<<endl;

    cout << "Introduzca una opcion: ";
    cin >> opcion;

    return opcion;
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    int na=0, opcion, i, m;
    float prueba;
    struct alumno g[20];

    FILE *fp;

    // Se muestra el menú y se procede con la opción elegida
    do
    {
        opcion = menu();

        switch(opcion)
        {
            case 1:
            {
                // Nuevo alumno en el arreglo de estructura de alumnos
                g[na]=llena_alumno();
                na++;
                break;
            }

            case 2:
            {
                // Se recorre el arreglo de estructura de alumnos y se imprime cada uno de los registos
                for(i=0; i<na; i++)
                {
                    print_alumno(g[i]);
                }
                break;
            }

            case 3:
            {
                // Se elimina un alumno, se pasa el arreglo y la cantidad de alumnos del arreglo
                m = elimina_alumno(g, na);
                if(m==-1)
                    cout<<"\nNo se elimino"<<endl;
                else
                {
                    na--;
                    cout<<"\nSi se elimino"<<endl;
                }
                break;
            }

            case 4:
            {
                // Lee el archivo.txt y guarda la información en el arreglo de estructura de alumnos
                na = leer_fopen(g);
                cout << "\nSe guardaron "<< na << " nuevos alumnos exitosamente." << endl;
                break;
            }

            case 5:
            {
                // Se guardan los datos del arreglo de estructura de alumnos en el archivo.txt
                escribe_fopen(g, na);
            }
        }

    }while(opcion != 6);

    // Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}