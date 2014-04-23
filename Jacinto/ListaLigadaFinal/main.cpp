#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

struct alumno{
char nombre[100], licenciatura[100];
int saldo, matricula;
struct alumno *sig;
};

struct alumno *llena_alumno()
{
struct alumno *l;

l=(struct alumno *)(malloc(sizeof(alumno)));

    if(l==NULL)
        cout<<"\n No existe nada en la lista para llenar"<<endl;
    else
    {


    cout<<"\n Nombre: ";
    cin>>l->nombre;
    cout<<"\n Saldo: ";
    cin>>l->saldo;
    cout<<"\n Licenciatura: ";
    cin>>l->licenciatura;
    cout<<"\n Matricula: ";
    cin>>l->matricula;
    l->sig=NULL;
    }

        return l;
}

struct alumno *inserta_inicio(struct alumno *l, struct alumno *p)
{


	if(l==NULL)///la lista está vacía
	{
		l=p;///P pasa a ser el primer elemento de la lista
	}
	else///La listas NO está vacía
	{
		p->sig=l;///sig del nuevo nodo a insertar pasa a apuntar a l
		l=p;///l pasa a p para que sea el nuevo
	}
	return l;
}

struct alumno *inserta_en_orden(struct alumno *l, struct alumno *p)
{
    struct alumno *q, *r;

	if(l==NULL)///la lista está vacía
	{
		l=p;///P pasa a ser el primer elemento de la lista
	}
	else
        {
            if(p->matricula <= l->matricula)
            {
                    p->sig=l;
                    l=p;
            }
            else
            {
               q=l;
               while(q!=NULL && q->matricula < p->matricula)
               {


                r=q;
               q=q->sig;

            }
            r->sig=p;
            p->sig=q;
        }
        }

	return l;
}

struct alumno *elimina_en_orden()
{

}

void print_alumno(struct alumno *l){


    cout<<"\nImpresion"<<endl;
cout<<"\nNombre: "<<l->nombre<<endl;

cout<<"\nSaldo: "<<l->saldo<<endl;

cout<<"\nLicenciatura: "<<l->licenciatura<<endl;

cout<<"\nMatricula: "<<l->matricula<<endl;
    cout<<"\nTermina la impresion"<<endl;
}

void print_lista(struct alumno *l)
{
    struct alumno *p;
    p=l;
                while(p!=NULL)
                    {
                        print_alumno(p);
                        p=p->sig;///L pasa a ser L SIG y L SIG  apunta al siguiente nodo
                    }
}


struct alumno *leer_fopen(int *numero)
  {
      struct alumno *l,*p;
      l=NULL;
      FILE *fp;
      int  i;

    fp=fopen("archivo.txt","r");

                    if(fp==NULL)
                    {
                        cout<<"\nNo se pudo leer el archivo"<<endl;

                    }
                    else
                    {

                        fscanf(fp,"%d", numero);
                        cout<<"\nLectura con exito"<<endl;
                        cout<<*numero;
                        for(i=0; i<*numero; i++)
                        {
                            p=(struct alumno *)(malloc(sizeof(struct alumno)));
                            fscanf(fp,"%s", p->nombre);
                            fscanf(fp,"%d", &p->saldo);
                            fscanf(fp,"%s", p->licenciatura);
                            fscanf(fp,"%d", &p->matricula);
                            p->sig=NULL;


                            l=inserta_inicio(l,p);

                            cout<<"\n Dentro de la funcion"<<endl;
                        }


                        fclose(fp);
                        return l;
                        }
  }

void writefopen(struct alumno *l, int na)
{

    FILE *fp;
    fp=fopen("archivowrite.txt","w");
    if (fp!=NULL)
    {

            fprintf(fp,"%d\n",na);
        while(l!=NULL)
        {
            fprintf(fp,"%s\n",l->nombre);
            fprintf(fp,"%d\n",l->saldo);
            fprintf(fp,"%s\n",l->licenciatura);
            fprintf(fp,"%d\n",l->matricula);
            l=l->sig;
        }
        fclose(fp);
    }

}

struct alumno *elimina_inicio(struct alumno *l)
{
    struct alumno *p;
    if(l!=NULL)
    {
        p=l;
        l=l->sig;
        free(p);
    }
    return l;
}

struct alumno *elimina_final(struct alumno *l)
{

        struct alumno *q, *m;
        m=q=l;
        while(m->sig!=NULL)
        {


                q=m;
                m=m->sig;
        }
        q->sig=NULL;
        free(m);

        return l;

}

struct alumno *inserta_final(struct alumno *l)
{
    struct alumno *q, *p;
    p=llena_alumno();

    if(l==NULL)
        l=p;
    else
    {
    q=l;
    while(q->sig!=NULL)
    {
     q=q->sig;///Se recorre por los nodos
    }
    q->sig=p;///Asignas p a q->sig porqu eya se recorrío
    }
    return l;
}




int menu()
{

    int opcion;
    cout<<"\nMenu Lista ligada con lectura de txt"<<endl;
    cout<<"\n1.-Leer de archivo"<<endl;

    cout<<"\n2.-Muestra"<<endl;

    cout<<"\n3.-Escribir a archivo"<<endl;

    cout<<"\n4.-Inserta inicio"<<endl;

    cout<<"\n5.-elimina inicio"<<endl;

    cout<<"\n6.-inserta final"<<endl;

    cout<<"\n7.-elimina final"<<endl;

    cout<<"\n8.-inserta en orden"<<endl;

    cout<<"\n9.-elimina en orden"<<endl;

    cout<<"\n10.-Salir"<<endl;
    cout<<"\nIntroduzca una opcion: ";
    cin>>opcion;
    return opcion;
}

int main()
{
    struct alumno *l=NULL,*p;
    int na=0, opcion, i,m;
    float prueba;

   do
    {

        opcion=menu();

        switch(opcion)
        {
            case 1:
            {

                l=leer_fopen(&na);

                cout<<na;


                break;
            }

            case 2:
                {
                    print_lista(l);
                    break;
                }

            case 3:
                {
                    writefopen(l,na);
                    break;
                }

            case 4:
                {
                    p=llena_alumno();
                    l=inserta_inicio(l,p);
                    break;
                }

            case 5:
                {
                    l=elimina_inicio(l);
                    break;

                }

            case 6:
                {
                    l=inserta_final(l);
                    break;
                }

            case 7:
                {
                    l=elimina_final(l);
                    break;
                }
            case 8:
                {
                    p=llena_alumno();
                    l=inserta_en_orden(l,p);
                    break;
                }

        }
    }while(opcion!=10);
        return 0;
    }
