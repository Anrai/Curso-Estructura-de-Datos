// Nombre del programa: Ejercicio arreglos 1-22
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
// Detecta si el numero es primo o no
bool primo(int p)
{
    int i;

    if(p<2)
        return false; 

    for(i=2; i<=sqrt(p); i++)
    {
        if(p%i == 0)
            return false; 
    }
    return true;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 1
// Leer un arreglo desde el teclado
void llena_arreglo(int a[10], int k)
{
    int i=0;
    while(i<k)
    {
      printf("\n teclee el numero: ");
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
int * mostrar_elemento_central(int a[10], int k)
{
    int *b[2];
    int x,y;

    if(k%2 > 0) // Solo hay un elemento central
    {
        x=k/2;
        cout << "\nEl elemento central es x["<<x<<"]:"<<a[x];
        b[0]=x-1;
        b[1]=x;

    }
    else // Hay dos elementos centrales
    {
        x=k/2;
        y=x-1;
        cout << "\nLos elementos centrales son x["<<y<<"]:"<<a[y]<<" y x["<<x<<"]:"<<a[x]<<"\n\n\n";
        b[0]=y;
        b[1]=x;
    }

    return b;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 5
// Recorrer el arreglo de los extremos hacia el centro.
void recorrer_arreglo_centro(int a[10], int k)
{
    int i=0;

    while(k>i)
    {
        k-=1;
            cout << "\n x[" << i << "]:" << a[i];
            cout << "\n x[" << k << "]:" << a[k];
        i+=1;

        if (k==i)
            k-=1;
    }
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 6
// Recorrer el arreglo del centro a los extremos
void recorrer_arreglo_extremos(int a[10], int k)
{
    int *centro[2];
    centro = mostrar_elemento_central(a,k);

    while(centro[0]>=0)
    {
            cout << "\n x[" << centro[0] << "]:" << a[centro[0]];
            cout << "\n x[" << centro[1] << "]:" << a[centro[1]];

            centro[0]-=1;
            centro[1]+=1;
    }
    if(centro[1]<k)
        cout << "\n x[" << centro[1] << "]:" << a[centro[1]];
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
    return calcular_suma_elementos(a,k)/k;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 9
// Calcular el numero de ocurrencias del numero num dentro del arreglo
int calcular_ocurrencias(int a[10], int k)
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
// Ejercicio 10
// Diseñar un algoritmo que inserte de manera ordenada los elementos en un vector (considere que debe buscar
// la posición de inserción y abrir el hueco para insertar el elemento).
int * ordenar_arreglo(int *a[10], int k)
{
    int i=1, memoria;

    while(i<k)
    {
        if(a[i-1] > a[i])
        {
            memoria = a[i];
            a[i] = a[i-1];
            a[i-1] = memoria;
        }
        i+=1;
    }

    return a;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 11
// Realizar una búsqueda secuencial de un elemento dentro del arreglo y regresar la posición en donde se encuentra
// o bien un -1 en caso de que no se encuentre.
int busqueda_elemento(int a[10], int k, int elemento)
{
    int i=0;
    int posicion = -1;

    while(i<k)
    {
        if(a[i] == elemento)
            posicion = i;
    }

    return posicion;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 12
// Hacer la suma de dos vectores (elemento a elemento) y almacenar el resultado en un tercer vector.
int * multiplicacion_arreglos(int a[], int b[], int x, int y)
{
    int tamano = y, i=0;
    if (x>tamano)
        tamano=x;

    int *multiplicacion[tamano];

    while(i<tamano)
    {
        if (i<x && i<y)
            multiplicacion[i] = a[i]*b[i];
        else
            multiplicacion[i]=0;
        i+=1;
    }

    return multiplicacion;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 13
// Sumar los elementos de dos vectores de manera cruzada (el primer elemento del primer vector con el ultimo
// elemento del segundo, … y almacenar el resultado en un tercer vector de arriba hacia abajo).
int * suma_cruzada_arreglos(int a[], int b[], int x, int y)
{
    int tamano = y, i=0;
    if (x>tamano)
        tamano=x;
    int j=tamano;

    int *suma[tamano];

    while(i<tamano)
    {
        j-=1;

        if (x>y)
        {
            if (i<y)
                suma[j] = b[i]+a[j];
            else
                suma[j]=a[j];
        }
        else
        {
            if (i<x)
                suma[j] = a[i]+b[j];
            else
                suma[j]=b[j];
        }

        i+=1;
    }

    return suma;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 14
// Buscar el elemento mayor dentro del vector.
int elemento_mayor(int a[10], int k)
{
    int i=0, mayor=0;

    while(i<k)
    {
        if(a[i]>mayor)
            mayor=a[i];
        i+=1;
    }

    return mayor;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 15
// Buscar el elemento menor dentro del vector.
int (int a[10], int k)
{

}

//--------------------------------------------------------------------------------------- 
// Ejercicio 16
// Calcular la desviación estandar de los elementos del arreglo, con el valor de la media calculado en el problema 8.
int (int a[10], int k)
{
    int i=0, menor=99999999999999999;

    while(i<k)
    {
        if(a[i]<menor)
            menor=a[i];
        i+=1;
    }

    return menor;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 17
// Determinar si cada elemento en el vector es un número primo o no, si todos los elementos son primos contestar
// que el arreglo es primo, en caso contrario indicar que no lo es.
bool (int a[10], int k)
{
    int i=0;

    while(i<k)
    {
        if (!primo(a[i])
            return false;
        i+=1;
    }
    return true;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 18
// Determinar si dos vectores son iguales ( para serlo, los elementos en posiciones iguales deberá ser iguales.)
int arreglo_primo(int a[10], int b[10], int k)
{
    int i;

    for (i=0; i<k; i++)
    {
        if (a[i] != b[i]);
            return false;
    }

    return true;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 19
// Intercambiar dos elementos cualesquiera dentro del vector, dando como parámetros de entrada los elementos a intercambiar
// (verifique primero si los elementos están contenidos en el vector para poder intercambiarlos).
int *intercambiar_elemenots(int *a[10], int x, int y, int, k)
{
    int memoria;

    if (x<k && y<k)
    {
        memoria = a[y];
        a[y]=a[x];
        a[x]=memoria;
    }
    return a;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 20
// Eliminar un elemento del arreglo, reduciendo el número de elementos almacenados y cerrando el hueco en el vector.
int *eliminar_elemento(int a[10], int x, int k)
{
    while(x<k-1)
    {
        a[x]=a[x+1];
        x+=1;
    }
    a[k-1]=null;

    return a;
}

//--------------------------------------------------------------------------------------- 
// Ejercicio 21
// Recorrer todos los elementos del vector hacia arriba una  posición. Y el ultimo a la primera posición
int * recorrer_elementos_arriba(int *a[10], int k)
{
    int memoria;

    memoria = a[k-1];

    for (k-=1; k>0; k--)
    {
        a[k] = a[k-1];
    }

    a[0]=memoria;

    return a;

}

//--------------------------------------------------------------------------------------- 
// Ejercicio 22
// Recorrer todos los elementos del vector hacia abajo un posición, Y el primero en la última posición
int * recorrer_elementos_abajo(int *a[10], int k)
{
    int i, memoria;

    memoria = a[0];

    for (i=0; i<k-1; i++)
    {
        a[i] = a[i+1];
    }

    a[k-1]=memoria;

    return a;

}


//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int k=10;


    calcular_suma_elementos(a, k);

    system("pause");
    return 0;
}