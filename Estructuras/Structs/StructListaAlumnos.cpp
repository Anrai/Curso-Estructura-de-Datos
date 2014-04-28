// Nombre del programa: StructListaAlumnos.cpp
// Descripción: Programa que tiene una estructura de alumnos en list SLT y puede leer y escribir en un archivo.txt
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 28-Abril-2014
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list>

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
// Nueva lista de estructura de alumno
//---------------------------------------------------------------------------------------
list <struct alumno> l;
list <struct alumno>::iterator i;

//--------------------------------------------------------------------------------------- 
// Funcion que imprime un alumno
//---------------------------------------------------------------------------------------
void print_lista()
{
    int x;

    // Se recorre la lista
    for(i=l.begin(); i!=l.end(); i++)
    {
        cout<<"\nImpresion"<<endl;
        cout<<"\nNombre:"<<i->nombre<<endl;
        cout<<"\nSaldo: "<<i->saldo<<endl;
        cout<<"\nLicenciatura: "<<i->licenciatura<<endl;
        cout<<"\nMatricula: "<<i->matricula<<endl;
        cout<<"\nTermina la impresion"<<endl;
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que inserta un nuevo alumno al final de la lista
//---------------------------------------------------------------------------------------
void inserta_fin()
{
    struct alumno *p=new(struct alumno); // Nuevo nodo
    cout<<"\nNombre: ";
    scanf("%s", p->nombre);
    cout<<"\nSaldo: ";
    scanf("%d", &p->saldo);
    cout<<"\nLicenciatura: ";
    scanf("%s", p->licenciatura);
    cout<<"\nMatricula: ";
    scanf("%d", &p->matricula);

    l.push_back(*p); // Inserta al final
    cout<<"\nSe Inserto con exito"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que inserta un nuevo alumno al inicio de la lista
//---------------------------------------------------------------------------------------
void inserta_ini()
{
    struct alumno *p=new(struct alumno);
    cout<<"\nNombre: ";
    scanf("%s", p->nombre);
    cout<<"\nSaldo: ";
    scanf("%d", &p->saldo);
    cout<<"\nLicenciatura: ";
    scanf("%s", p->licenciatura);
    cout<<"\nMatricula: ";
    scanf("%d", &p->matricula);

    l.push_front(*p);
    cout<<"\nSe Inserto con exito"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion borra el primer elemento de la lista
//---------------------------------------------------------------------------------------
void elimina_ini()
{
    l.pop_front();
}

//--------------------------------------------------------------------------------------- 
// Funcion borra el último elemento de la lista
//---------------------------------------------------------------------------------------
void elimina_fin()
{
    l.pop_back();
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en la lista
//---------------------------------------------------------------------------------------
void cargar_alumnos()
{
    struct alumno *p;
    FILE *fp;
    int  i, numero;

    fp=fopen("archivo.txt", "r"); // Se abre en modo lectura

    if(fp==NULL)
    {
        cout<<"\nNo se pudo leer el archivo"<<endl;
    }
    else
    {

        fscanf(fp,"%d", &numero);
        cout<<"\nLectura con exito"<<endl;
        cout<<numero;

        for(i=0; i<numero; i++)
        {
            struct alumno *p=new(struct alumno);
            fscanf(fp,"%s", p->nombre);
            fscanf(fp,"%d", &p->saldo);
            fscanf(fp,"%s", p->licenciatura);
            fscanf(fp,"%d", &p->matricula);

            l.push_back(*p);

            cout<<"\n Dentro de la funcion"<<endl;
        }
        fclose(fp);
    }
}

//--------------------------------------------------------------------------------------- 
// Funcion que guarda la lista en un archivo de texto
//---------------------------------------------------------------------------------------
void guardar_alumnos()
{
    int y=0,j=0;
    struct alumno *r;
    FILE *fp;
    fp=fopen("archivowrite.txt","w");

    if (fp!=NULL)
    {
        y=l.size();
        fprintf(fp,"%d\n",y);
        for(i=l.begin(); i!=l.end(); i++)
        {
            fprintf(fp,"%s\n",i->nombre);
            fprintf(fp,"%d\n",i->saldo);
            fprintf(fp,"%s\n",i->licenciatura);
            fprintf(fp,"%d\n",i->matricula);
        }
        fclose(fp);
    }
    else
        cout<<"\nNo se pudo crear el archivo"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que inserta un nuevo registro según la matricula ingresada
//---------------------------------------------------------------------------------------
void inserta_orden()
{
    int matricula1, x=-1,y;

    printf("\nMatricula a insertar: ");
    scanf("%d",&matricula1);

    for(i=l.begin(); i!=l.end(); i++)
    {
        if (i->matricula<matricula1){
            i++;
            x=y;
        }
    }

    if(x!=-1)
    {
        struct alumno *p=new(struct alumno);
        cout<<"\nNombre: ";
        scanf("%s", p->nombre);
        cout<<"\nSaldo: ";
        scanf("%d", &p->saldo);
        cout<<"\nLicenciatura: ";
        scanf("%s", p->licenciatura);
        cout<<"\nMatricula: ";
        scanf("%d", &p->matricula);

        l.insert(i,*p);
    }
}

//--------------------------------------------------------------------------------------- 
// Menú con las opciones para realizar trabajos en la lista
//---------------------------------------------------------------------------------------
void menu()
{
    cout<<"\n1.-Leer de archivo"<<endl;
    cout<<"\n2.-Imprimir"<<endl;
    cout<<"\n3.-Escribir a archivo"<<endl;
    cout<<"\n4.-Elimina con matricula"<<endl;
    cout<<"\n5.-Inserta manual"<<endl;
    cout<<"\n6.-Sobreescribir"<<endl;
    cout<<"\n7.-Salir"<<endl;
    printf("\nOpcion: ");
}

//--------------------------------------------------------------------------------------- 
// Programa Principal
//---------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
    int opcion;

    do{
        menu();
        cout<<"\nIntroduzca una opcion"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
            {
                inserta_ini();
                break;
            }

            case 2:
            {
                inserta_fin();
                break;
            }
            case 3:
            {
                print_lista();
                break;
            }

            case 4:
            {
                elimina_ini();
                break;
            }

            case 5:
            {
                elimina_fin();
                break;
            }

            case 6:
            {
                cargar_alumnos();
                break;
            }

            case 7:
            {
                guardar_alumnos();
                break;
            }

            case 8:
            {
                inserta_orden();
                break;
            }
        }

    }while(opcion!=7);

    // Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}