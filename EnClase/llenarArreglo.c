// Nombre del programa: llenarArreglo
// Descripción: Checar paso de valores!
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 27-Enero-2014                                       
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

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
// Programa Principal 
//--------------------------------------------------------------------------------------- 
int main(int argc, const char** argv)
{
    int a[10],b[10],c[10];
    int i,j,k;
    
    printf("Numero de elementos: ");
    scanf("%i",&k);
    
    llena_arreglo(a,k);// Cuando se quiere que se pase y se modifique en la funcion se pasa con & y se utiliza el valor con un *
    escribe_arreglo(a,k);
    
    llena_arreglo(b,k);// Cuando se quiere que se pase y se modifique en la funcion se pasa con & y se utiliza el valor con un *
    escribe_arreglo(b,k);
    
    llena_arreglo(c,k);// Cuando se quiere que se pase y se modifique en la funcion se pasa con & y se utiliza el valor con un *
    escribe_arreglo(c,k);

    system("pause");
    return 0;
}