// Nombre del programa: Ejercicio arreglos 1-4, 7-9
// Descripción: Varios ejercicios con arreglos, cada ejercicio se encuentra dentro de una función.
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 29-Enero-2014                                       
  
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
// Ejercicio 1
// Leer un arreglo desde el teclado
void llena_arreglo(int a[10], int k)
{
    int i=0;
      while(i<k)
    {
      printf("\n teclee el numero: ",i);
      scanf("%d",&a[i]);
      i++;  
    } 
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 2
// Escribir un arreglo del primer elemento al último
void escribe_arreglo(int a[10], int k)
{
    int i=0;
    while(i<k)
    {
      printf("\n x[%d]:%d\n",k,a[i]);
      i++;        
    }
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 3
// Mostrar el arreglo al revés
void mostrar_arreglo_alreves(int a[10], int k)
{
    while(k>0)
    {
    	k-=1;
		cout << "\n x["<<k<<"]:"<<a[k];
    }
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 4
// Mostrar el/los elementos cetrales del arreglo
void mostrar_elemento_central(int a[10], int k)
{
    int x,y;

    if(k%2 > 0) // Solo hay un elemento central
    {
    	x=k/2;
    	cout << "\nEl elemento central es x["<<x<<"]:"<<a[x];
    }
    else // Hay dos elementos centrales
    {
    	x=k/2;
    	y=x-1;
    	cout << "\nLos elementos centrales son x["<<y<<"]:"<<a[y]<<" y x["<<x<<"]:"<<a[x];
    }
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 7
// Calcular la suma de los elementos del arreglo
int calcular_suma_elementos(int a[10], int k)
{
	int suma=0;
    while(k>0)
    {
    	k-=1;
		suma+=a[k];
    }
    return suma;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 8
// Calcular la media de los elementos en el vector
int calcular_media_elementos(int a[10], int k)
{
	int suma=0, m=k;
    while(k>0)
    {
    	k-=1;
		suma+=a[k];
    }
    return suma/m;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 9
// Calcular el numero de ocurrencias del numero num dentro del arreglo
int calcular_media_elementos(int a[10], int k)
{
	int num, ocurrencias=0;
	cout << "\nQue numero quiere revisar? ";
	cin >> num;

	while(k>0)
    {
    	k-=1;
		if(a[k]==num)
		{
			ocurrencias+=1;
		}
    }
    return ocurrencias;
}


//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {


	system("pause");
	return 0;
}