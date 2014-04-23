#include <iostream>

using namespace std;

// function to generate and retrun random numbers.
int * mostrar_elemento_central(int a[], int k)
{

  static int  b[2];
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

// main function to call above defined function.
int main ()
{
   // a pointer to an int.
   int *p[2];

   int arreglito[2]={1,2};

   p = mostrar_elemento_central(arreglito, 2);

   return 0;
}