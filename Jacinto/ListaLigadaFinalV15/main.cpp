#include<iostream>

#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>

using namespace std;


struct alumno
{
	int matricula,edad;
	char nombre[20];
	float saldo;
	struct alumno *sig;
};
//Llena alumno
struct alumno *llena_nodo()
{
	struct alumno *l;
	l=(struct alumno*)(malloc(sizeof(alumno)));
	if(l==NULL)
	{
        printf("\nNo se pudo crear");
	}
	else
	{
		printf("\nNombre: \n");
        scanf("%s", l->nombre);
        printf("Edad: \n");
        scanf("%d", &l->edad);
        printf("Numero de alumno: \n");
        scanf("%d", &l->matricula);
        printf("Saldo: \n");
        scanf("%f", &l->saldo);
        l->sig=NULL;
	}
	return l;
}
//Escribe nodo de alumno
void escribe_nodo(struct alumno *l)
{
	printf("\n\nNombre %s",l->nombre );
	printf("\nEdad %d",l->edad );
	printf("\nNumero de alumno %d", l->matricula );
	printf("\nSaldo %f", l->saldo );
}

//Inserta al Inicio
struct alumno *ins_ini(struct alumno *l, struct alumno *p)
{
	if(l==NULL)
	{
		l=p;
	}
	else
	{
		p->sig=l;
		l=p;
	}
	return l;
}

void imprime(struct alumno *r)
{
	while(r!=NULL)
	{
		escribe_nodo(r);
		r=r->sig;
	}
}

struct alumno *eli_inicio(struct alumno *l)
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

struct alumno *ins_final(struct alumno *l)
{
	struct alumno *q, *p;
	p= llena_nodo();
	if(l==NULL)
	{
		l=p;
	}
	else
    {
        q=l;
		while(q->sig!=NULL)
        {
            q=q->sig;
		}
		q->sig=p;
	}
	return l;

    }



struct alumno * leer_fopen()
  {
      FILE *fp;
      struct alumno *l=NULL, *p;
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
                            p=(struct alumno*)(malloc(sizeof(alumno)));
                            fscanf(fp,"%s", p->nombre);
                            fscanf(fp,"%d", &p->edad);
                            fscanf(fp,"%f", &p->saldo);
                            fscanf(fp,"%d", &p->matricula);
                            p->sig=NULL;
                            l= ins_ini(l,p);
                        }


                        fclose(fp);
                        return l;
}
  }

  //Guarda en archivo
void guardar_ar(struct alumno *l)
{
    struct alumno *r;
    int i=0;
    FILE *fp;
    fp=fopen("prueba.txt","w");

    r=l;
    if (fp!=NULL)
    {
        while (r!= NULL){
            i++;
            r=r->sig;
        }
        fprintf(fp,"%d\n",i);

        while(l!=NULL)
        {

            fprintf(fp,"%s\n",l->nombre);
            fprintf(fp,"%d\n",l->edad);
            fprintf(fp,"%d\n",l->matricula);
            fprintf(fp,"%f\n",l->saldo);
            l=l->sig;
        }
        fclose(fp);
    }
    else
    {
        printf("No se pudo crear el archivo!!!");
    }
}



void eli_fin(struct alumno *l)
{
    struct alumno *m;
	struct alumno *q;

	m=l;
	q=l;

	while(m!=NULL)
	{
	    if(m->sig==NULL)
		{
			q->sig=NULL;
			free(m);
		}
		else
		{
			q=m;
		}
		m=m->sig;
	}

}

struct alumno *inserta_orden(struct alumno *l, struct alumno *p)
{
    struct alumno *r, *q;
    if(l==NULL)
        {
            l=p;
        }
    else{
        if(p->matricula <= l->matricula){
            p->sig=l;
            l=p;
        }
        else{
            q=l;
            while(q!=NULL && q->matricula < p->matricula){
                r=q;
                q=q->sig;
            }
            r->sig=p;
            p->sig=q;
        }
    }
    return l;
}

struct alumno *elimina_orden(struct alumno *l){

       struct alumno *q, *r;
       int matricula;

       printf("\nMatricula a eliminar: ");
       scanf("%d",&matricula);
       if(l==NULL){
                  printf("\n Vacia");
                  }
       else{
           q=l;
           if (q->matricula==matricula){
                             l=q->sig;
                             }
           else{
                while(q!=NULL && q->matricula!=matricula){
                              r=q; q=q->sig;
                              }
                              if(q==NULL){
                                         printf("\n No existe la matricula en la lista");
                                         }
                              else{
                                  r->sig=q->sig;
                                  }
                }
           }
                return l;
}

void menu()
{
    printf("\n1. Inserta Inicio.");
    printf("\n2. Imprime.");
    printf("\n3. Elimina Inicio.");
    printf("\n4. Inserta Final.");
    printf("\n5. Inserta desde archivo en inicio.");
    printf("\n6. Guardar en archivo.");
    printf("\n7. Elimina al Final.");
    printf("\n8. Inserta en Orden");
    printf("\n9. Elimina en Orden");
    printf("\n10. Salir.\n\n");

    printf("\nOpcion: ");

}

int main()
{
	struct alumno *lista, *p;
	int i,op;


    lista=NULL;

    do{
        menu();
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            {
                p=llena_nodo();
                lista=ins_ini(lista,p);
                break;
            }
            case 2:
            {
               imprime(lista);
                break;

            }
            case 3:
            {
                lista=eli_inicio(lista);
                break;
            }
            case 4:
            {
                lista=ins_final(lista);
                break;
            }
            case 5:
            {
                lista=leer_fopen();
                break;
            }
            case 6:
            {
                guardar_ar(lista);
                break;
            }
            case 7:
            {
               eli_fin(lista);
                break;
            }
            case 8:
            {
               p=llena_nodo();
                lista=inserta_orden(lista,p);
                break;
            }
            case 9:
            {
                lista=elimina_orden(lista);
                break;
            }
        }

    }while(op!=10);

	system("PAUSE");
    return EXIT_SUCCESS;
}
