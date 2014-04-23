#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <list>
using namespace std;

 struct alumno{
char nombre[100], licenciatura[100];
int saldo, matricula;
};
list<struct alumno> l;
list<struct alumno>::iterator i;


void print_alumno()
{

int x;
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


void inserta_fin()
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

                            l.push_back(*p);
                            cout<<"\nSe Inserto con exito"<<endl;
}


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

void elimina_ini()
{
   l.pop_front();
}

void elimina_fin()
{
    l.pop_back();
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

                            l.push_back(*p);



                            cout<<"\n Dentro de la funcion"<<endl;
                        }


                        fclose(fp);

                        }

}


void writefopen()
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

void inserta_orden(){


       int matricula1, x=-1,y;

       printf("\nMatricula a insertar: ");
       scanf("%d",&matricula1);
     /*  if(G.empty()==TRUE){
                  printf("\n Vacia");
                  }
       else{*/
        //   for(i=l.begin(); i!=l.end(); i++)
           //for(y=0; y<l.size(); y++)
            {



           if (i->matricula<matricula1){
                i++;
                             x=y;

                             }

                //}

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
}


  /* void elimina_orden()
   {


       int matricula, x=-1, y;

       printf("\nMatricula a eliminar: ");
       scanf("%d",&matricula);
     /*  if(G.empty()==TRUE){
                  printf("\n Vacia");
                  }
       else{
           for(i=l.begin(); i!=l.end(); i++)
        {


           if (i->matricula==matricula){
                             x=y;

                             }

                }

            if(x!=-1)
                {
                   l.erase (l.begin()+ x);
                }
              /*  else
                    cout<<"\nNo se encontro la matricula"<<endl;*/



       //}






void menu()
{
    printf("\n1. Inserta Inicio.");

    printf("\n2. Inserta Final.");
    printf("\n3. Imprime.");
    printf("\n4. Elimina Inicio.");
    printf("\n5. Elimina final.");
    printf("\n6. Inserta desde archivo.");
    printf("\n7. Guarda en archivo");
    printf("\n8. Inserta en Orden");
    printf("\n9. Elimina en Orden.");
    printf("\n10. Salir.\n\n");

    printf("\nOpcion: ");

}


int main()
{



        int opc;
    do{
        menu();
        cout<<"\nIntroduzca una opcion"<<endl;
        cin>>opc;
        switch(opc)
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
                print_alumno();
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
                leer_de_archivo();
                break;
            }

        case 7:
            {
                writefopen();
                break;
            }

        case 8:
            {
                inserta_orden();
                break;
            }

   /*     case 9:
            {
            elimina_orden();
                break;
            }*/



        }

    }while(opc!=10);
    return 0;
}
