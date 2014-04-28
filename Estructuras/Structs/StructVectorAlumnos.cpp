// Nombre del programa: StructVectorAlumnos.cpp
// Descripción: Mismo programa que StructArrayAlumnos.cpp pero que los alumnos los guarda en un Vector
// Importante: El archivo.txt de esta versión es un poco diferente
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 28-Abril-2014
  
//---------------------------------------------------------------------------------------
// INCLUDES 
//---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
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
// Nuevo vector de estructura de alumno
//---------------------------------------------------------------------------------------
vector <struct alumno> G; // G es el identificador de este vector

//--------------------------------------------------------------------------------------- 
// Funcion que imprime un alumno
//---------------------------------------------------------------------------------------
void print_vector()
{
	int i, x;

	// Se recorre el vector
	for(i=0; i<G.size(); i++)
	{
		cout<<"\nImpresion"<<endl;
		cout<<"\nNombre: "<<G[i].nombre<<endl;
		cout<<"\nSaldo: "<<G[i].saldo<<endl;
		cout<<"\nLicenciatura: "<<G[i].licenciatura<<endl;
		cout<<"\nMatricula: "<<G[i].matricula<<endl;
		cout<<"\nTermina la impresion"<<endl;
	}
}

//--------------------------------------------------------------------------------------- 
// Funcion que inserta un nuevo alumno
//---------------------------------------------------------------------------------------
void llena_alumno()
{
	struct alumno *p = new(struct alumno); // Más bonito que malloc

	cout<<"\nNombre: ";
	scanf("%s", p->nombre);
	cout<<"\nSaldo: ";
	scanf("%d", &p->saldo);
	cout<<"\nLicenciatura: ";
	scanf("%s", p->licenciatura);
	cout<<"\nMatricula: ";
	scanf("%d", &p->matricula);

	G.push_back(*p); // Función de vector que inserta al final
	cout<<"\nSe Inserto con exito"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que carga la información de un archivo y la guarda en el vector
//---------------------------------------------------------------------------------------
void cargar_alumnos()
{
	struct alumno *p;
	FILE *fp;
	int  i, numero;

	fp = fopen("archivo.txt", "r"); // Se abre en modo lectura

	if(fp == NULL)
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

			G.push_back(*p); // Se inserta al final

			cout<<"\n Dentro de la funcion"<<endl;
		}
		fclose(fp); // Se cierra el archivo
	}
}

//--------------------------------------------------------------------------------------- 
// Funcion que guarda el vector en un archivo de texto
//---------------------------------------------------------------------------------------
void guardar_alumnos(vector <alumno> G) // Así se pide un vector de tipo alumno, pero creo que funciona como una variable global
{
	int i=0,j=0;
	struct alumno *r;
	FILE *fp;
	fp=fopen("archivowrite.txt","w");

	if (fp!=NULL)
	{
		i=G.size();
		fprintf(fp,"%d\n",i);
		while(j<G.size())
		{
			fprintf(fp,"%s\n",G[j].nombre);
			fprintf(fp,"%d\n",G[j].saldo);
			fprintf(fp,"%s\n",G[j].licenciatura);
			fprintf(fp,"%d\n",G[j].matricula);
			j++;
		}
		fclose(fp);
	}
	else
		cout<<"\nNo se pudo crear el archivo"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion elimina un alumno según la matrícula que se le haya pasado
//---------------------------------------------------------------------------------------
void eli_orden()
{
	int matricula, x=-1, i;

	printf("\nMatricula a eliminar: ");
	scanf("%d",&matricula);

	for(i=0; i<G.size(); i++)
	{
		if (G[i].matricula==matricula){
			x=i;
		}
	}

	if(x!=-1)
	{
		// begin() regresa el primer iterador del vector
		// erase() borra los elementos
		G.erase (G.begin()+x);
	}
	else
		cout<<"\nNo se encontro la matricula"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Funcion que cambia algun valor indicado de un elemento dentro del vector. (Se carga con matrícula)
//---------------------------------------------------------------------------------------
void sobreescribir()
{
	int matricula, op, x=-1, i=0;

	printf("\nMatricula a cambiar: ");
	scanf("%d",&matricula);

	for(i=0; i<G.size(); i++)
	{
		if (G[i].matricula==matricula)
		{
			x=i;
		}
	}

	if(x != -1)
	{
		cout<<"\nIntroduzca elemento a cambiar"<<endl;
		cout<<"\n1.-Nombre";
		cout<<"\n2.-Saldo";
		cout<<"\n3.-Licenciatura";
		cout<<"\n4.-Matricula"<<endl;
		cin>>op;
		switch(op){
			case 1:
			{
				cout<<"\nIntroduzca el nuevo nombre"<<endl;
				cin>>G[x].nombre;
				break;
			}

			case 2:
			{
				cout<<"\nIntroduzca nuevo saldo"<<endl;
				cin>>G[x].saldo;
				break;
			}

			case 3:
			{
				cout<<"\nIntroduzca nueva licenciatura"<<endl;
				cin>>G[x].licenciatura;
				break;
			}

			case 4:
			{
				cout<<"\nIntroduzca nueva matricula"<<endl;
				cin>>G[x].matricula;
				break;
			}
		}
	}
	else
		cout<<"\nNo se encontro la matricula"<<endl;
}

//--------------------------------------------------------------------------------------- 
// Menú con las opciones para realizar trabajos en el vector
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
				cargar_alumnos();
				break;
			}

			case 2:
			{
				print_vector();
				break;
			}
			case 3:
			{
				guardar_alumnos(G);
				break;
			}

			case 4:
			{
				eli_orden();
				break;
			}

			case 5:
			{
				llena_alumno();
				break;
			}

			case 6:
			{
				sobreescribir();
				break;
			}
		}
	}while(opc!=7);

	// Fin del programa
    cout << "\n\n";
    system("pause");
    return 0;
}
