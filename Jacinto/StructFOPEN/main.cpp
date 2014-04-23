#include <iostream>
#include <stdio.h>
///STRUCT CON FOPEN
using namespace std;

struct alumno{
char nombre[100], licenciatura[100];
int saldo, matricula;

};

struct alumno llena_alumno()
{
struct alumno a;

cout<<"\n Nombre: ";
cin>>a.nombre;
cout<<"\n Saldo: ";
cin>>a.saldo;
cout<<"\n Licenciatura: ";
cin>>a.licenciatura;
cout<<"\n Matricula: ";
cin>>a.matricula;
return a;
}

int leer_fopen(struct alumno a[20])
  {
      FILE *fp;
      int numero, i;

    fp=fopen("archivo.txt","r");

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
                            fscanf(fp,"%s", a[i].nombre);
                            fscanf(fp,"%d", &a[i].saldo);
                            fscanf(fp,"%s", a[i].licenciatura);
                            fscanf(fp,"%d", &a[i].matricula);
                        }


                        fclose(fp);
                        return numero;
}
  }

void escribe_fopen(struct alumno a[20], int na)
{
    FILE *fp;
    int num=0, i;

    fp=fopen("archivo.txt","w");



    if(fp != NULL)
    {

        fprintf(fp,"%d\n",na);

        for(i=0; i<na; i++)
        {


            fprintf(fp,"%s\n", a[i].nombre);


            fprintf(fp,"%d\n", a[i].saldo);


            fprintf(fp,"%s\n", a[i].licenciatura);

            fprintf(fp,"%d\n", a[i].matricula);
        }
    }
    fclose(fp);
}

void print_alumno(struct alumno a){
    cout<<"\nImpresion"<<endl;
cout<<"\nNombre: "<<a.nombre<<endl;

cout<<"\nSaldo: "<<a.saldo<<endl;

cout<<"\nLicenciatura: "<<a.licenciatura<<endl;

cout<<"\nMatricula: "<<a.matricula<<endl;
    cout<<"\nTermina la impresion"<<endl;
}

int elimina_alumno(struct alumno g[20], int na)
{
    int cont=-1, i, x, y;
    cout<<"\n Introduzca el indice a eliminar: ";
    cin>>x;
    for(i=0;i<na; i++)
    {

        if(x==g[i].matricula)
            cont=i;

    }

if(cont!=-1)
    {


    for(y=cont; y<na; y++)
          {
              g[y]=g[y+1];
          }
    }


          return cont;

}

int menu()
{

    int opcion;
    cout<<"\nMenu Estructuras Dinamicas"<<endl;
    cout<<"\n1.-Inserta"<<endl;
    cout<<"\n2.-Muestra"<<endl;
    cout<<"\n3.-Elimina"<<endl;
    cout<<"\n4.-Leer con FOPEN"<<endl;
    cout<<"\n5.-Escribir con FOPEN"<<endl;
    cout<<"\n6.-Salir"<<endl;
    cout<<"\nIntroduzca una opcion: ";
    cin>>opcion;
    return opcion;
}

int main()
{
    FILE *fp;
    int na=0, opcion, i,m;
    float prueba;
    struct alumno g[20];





   do
    {

        opcion=menu();

        switch(opcion)
        {
            case 1:
            {
                g[na]=llena_alumno();
                na++;
                break;
            }

            case 2:
            {

                for(i=0; i<na; i++)
                    {
                        print_alumno(g[i]);

                    }
                break;
            }

            case 3:
            {
              m=elimina_alumno(g,na);
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
                    na=leer_fopen(g);
                    cout<<"\n"<<na<<endl;
                    break;
                }
            case 5:
                {
                    escribe_fopen(g, na);

                }


                }



        }while(opcion!=6);
        return 0;
    }


