#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct alumno{
char nombre[100], licenciatura[100];
int saldo, matricula;
struct alumno *sig;
};

vector<struct alumno> G;

void print_alumno()
{
int i,x;
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

/*void print()
{
   int i,x;
   for(i=0; i<G.size(); i++)
   {
     print_alumno();
   }
}*/

void inserta()
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

                            G.push_back(*p);
                            cout<<"\nSe Inserto con exito"<<endl;
}




void leer_de_archivo()
{

      struct alumno *p;
      FILE *fp;
      int  i, numero;

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
                            struct alumno *p=new(struct alumno);
                            fscanf(fp,"%s", p->nombre);
                            fscanf(fp,"%d", &p->saldo);
                            fscanf(fp,"%s", p->licenciatura);
                            fscanf(fp,"%d", &p->matricula);

                            G.push_back(*p);



                            cout<<"\n Dentro de la funcion"<<endl;
                        }


                        fclose(fp);

                        }

}

void writefopen(vector <alumno> G)
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

   void elimina_orden(){


       int matricula, x=-1, i;

       printf("\nMatricula a eliminar: ");
       scanf("%d",&matricula);
     /*  if(G.empty()==TRUE){
                  printf("\n Vacia");
                  }
       else{*/
           for(i=0; i<G.size(); i++)
           {


           if (G[i].matricula==matricula){
                             x=i;

                             }

                }

            if(x!=-1)
                {
                  G.erase (G.begin()+x);
                }
                else
                    cout<<"\nNo se encontro la matricula"<<endl;



       }



void menu_vector()
{
    cout<<"\n1.-Leer de archivo"<<endl;
    cout<<"\n2.-Imprimir"<<endl;
    cout<<"\n3.-Escribir a archivo"<<endl;
    cout<<"\n4.-Elimina con matricula"<<endl;
    cout<<"\n5.-Inserta manual"<<endl;
    cout<<"\n6.-Sobreescribir"<<endl;
    cout<<"\n7.-Salir"<<endl;
}


void sobreescribir()
{


       int matricula, op, x=-1, i=0;



       printf("\nMatricula a cambiar: ");
       scanf("%d",&matricula);

           for(i=0; i<G.size(); i++)
           {


           if (G[i].matricula==matricula){
                             x=i;

                             }

                }

            if(x!=-1)
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

int main()
{

    int opc;
    do{
        menu_vector();
        cout<<"\nIntroduzca una opcion"<<endl;
        cin>>opc;
        switch(opc)
        {
        case 1:
            {
                leer_de_archivo();
                break;
            }

        case 2:
            {
                print_alumno();
                break;
            }
        case 3:
            {
                writefopen(G);
                break;
            }

        case 4:
            {
                elimina_orden();
                break;
            }

        case 5:
            {
                inserta();
                break;
            }

        case 6:
            {
                sobreescribir();
                break;
            }

        }

    }while(opc!=7);

    return 0;
}
