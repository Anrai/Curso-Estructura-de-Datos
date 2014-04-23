#include <iostream>
#include <stdio.h>
///STRUCT CON FOPEN
using namespace std;

int main()
{
    FILE *fp;

    float prueba;



    fp=fopen("archivo.txt","r");

    if(fp==NULL)
    {
        cout<<"\nNo se pudo leer el archivo"<<endl;

    }
    else
    {

        fscanf(fp,"%f",prueba);
        cout<<"\nLectura con exito"<<endl;
        cout<<prueba;

    }
    return 0;
}
