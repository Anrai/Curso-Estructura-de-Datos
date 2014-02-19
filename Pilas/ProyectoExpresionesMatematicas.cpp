// Nombre del programa: Proyecto de Expresiones Matemáticas con Pilas
// Descripción: 
// Responsables: 
//          Profesor: Dr. Antonio Benitez Ruiz
//          Alumno: Sergio Enrique Vargas García 
// Fecha: 19-Febrero-2014                                       
  
//--------------------------------------------------------------------------------------- 
// INCLUDES 
//--------------------------------------------------------------------------------------- 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>

using namespace std;

#define MAX 50

//--------------------------------------------------------------------------------------- 
// Función que indica si la pila está vacía
//---------------------------------------------------------------------------------------
bool pila_vacia(int sp)
{
	bool st = false;

	if(sp==MAX)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que indica si la pila está llena
//---------------------------------------------------------------------------------------
bool pila_llena(int sp)
{
	bool st = false;

	if(sp==0)
		st = true;

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace push de integer en la pila
//---------------------------------------------------------------------------------------
bool push_int(int stack[MAX], int *sp, int dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición
{
	int st=false;

	if(!pila_llena(*sp))
	{
		*sp=*sp-1;
		stack[*sp]=dato;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace pop de integer en la pila
//---------------------------------------------------------------------------------------
bool pop_int(int stack[MAX], int *sp, int *dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición, el dato se pasa por referencia
{
	int st=false;

	if(!pila_vacia(*sp))
	{
		*dato=stack[*sp];
		*sp=*sp+1;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace push de char en la pila
//---------------------------------------------------------------------------------------
bool push_char(char stack[MAX], int *sp, char dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición
{
	bool st=false;

	if(!pila_llena(*sp))
	{
		*sp=*sp-1;
		stack[*sp]=dato;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que hace pop de char en la pila
//---------------------------------------------------------------------------------------
bool pop_char(char stack[MAX], int *sp, char *dato) // Push y Pop siempre se pasa con referencia porque se pasa la posición, el dato se pasa por referencia
{
	bool st=false;

	if(!pila_vacia(*sp))
	{
		*dato=stack[*sp];
		*sp=*sp+1;
		st=true;
	}

	return st;
}

//--------------------------------------------------------------------------------------- 
// Función que imprime todos los valores de una pila int
//---------------------------------------------------------------------------------------
void pp_int(int stack[MAX], int sp)
{
	// Inicialización de una pila temporal de almacenamiento para los valores de la pila original
	int p1[MAX], sp1=MAX, d;
	bool k;

	cout << "Inicia impresion de pila" << endl;

	// Vacía la pila original, imiprime sus valores, y los mete en una nueva pila
	while(pop_int(stack, &sp, &d))
	{
		cout << d << endl;
		k = push_int(p1, &sp1, d);
	}

	cout << "Termina impresion de pila" << endl;

	// Regresa los valores a la pila original
	while(pop_int(p1, &sp1, &d))
	{
		k = push_int(stack, &sp, d);
	}

}

//--------------------------------------------------------------------------------------- 
// Función que imprime todos los valores de una pila char
//---------------------------------------------------------------------------------------
void pp_char(char stack[MAX], int sp)
{
	// Inicialización de una pila temporal de almacenamiento para los valores de la pila original
	char p1[MAX], d;
	int sp1=MAX;
	bool k;
	// Vacía la pila original, imprime sus valores, y los mete en una nueva pila
	while(pop_char(stack, &sp, &d))
	{
		cout << "\n" << d;
		k = push_char(p1, &sp1, d);
	}
	// Regresa los valores a la pila original
	while(pop_char(p1, &sp1, &d))
	{
		k = push_char(stack, &sp, d);
	}
}

//--------------------------------------------------------------------------------------- 
// Función que pide una expresión matemática (y su tamaño en caracteres) y detecta si los paréntesis están bien escritos
//---------------------------------------------------------------------------------------
bool comprobacion(char operacion[], int largo)
{
	// Inicialización de una pila temporal
	char stack[MAX]; // Pila y dato a almacenar en la pila
	char dato;
	int sp=MAX; // Stack Pointer

	for (int i=0; i<largo; ++i)
	{
		dato=operacion[i]; // Se mete el caracter en la variable dato para utilizarla
		if (dato=='(')
			push_char(stack, &sp, dato); // Se pushea cada párentesis de apertura en la pila
		else if (dato==')')
		{
			// Se borra cada párentesis de cierre en la pila
			if (!pop_char(stack, &sp, &dato)) // Si el primer paréntesis es de cierre la expresión es incorrecta
			{
				return false;
				break;
			}
		}
	}
	if (!pila_vacia(sp)) // Checa si quedaron paréntesis sin cerrar
		return false;
	else
		return true;
}

//--------------------------------------------------------------------------------------- 
// Función que busca cual es el top de una pila de caracteres y la deja intacta
//---------------------------------------------------------------------------------------
char find_top_char(char stack[MAX], int sp)
{
	char top;
	if(pop_char(stack, &sp, &top)) // Aquí se guarda el valor en la variable top
	{
		if(push_char(stack, &sp, top)) // Aquí se regresa el valor a la pila
			return top;
		else
			return false;// La pila estaba llena
	}
	else
		return false;// La pila estaba vacía
}

//--------------------------------------------------------------------------------------- 
// Función que busca los dos últimos números de una pila de enteros y los regresa en un arreglo
//---------------------------------------------------------------------------------------
bool find_tops_int(int stack[MAX], int sp, int tops[2])
{
	if(pop_int(stack, &sp, &tops[0]) && pop_int(stack, &sp, &tops[1])) // Aquí se guardan los valores de los tops
	{
		if(push_int(stack, &sp, tops[1]) && push_int(stack, &sp, tops[0])) // Aquí se regresan los valores a la pila
			return true;
		else
			return false;// La pila estaba llena
	}
	else
		return false;// La pila estaba vacía
}

//--------------------------------------------------------------------------------------- 
// Función que realiza una operación con dos números dependiendo del signo indicado
//---------------------------------------------------------------------------------------
int realizar_operacion(char signo, int valor1, int valor2)
{
	if (signo == '+')
	{
		return valor1+valor2;
	}
	else if (signo == '-')
	{
		return valor1-valor2;
	}
	else if (signo == '/')
	{
		return valor1/valor2;
	}
	else if (signo == '*')
	{
		return valor1*valor2;
	}
	else
	{
		return 0;
	}
}

//--------------------------------------------------------------------------------------- 
// Función que hace una operación según los dos dígitos de una pila y su operación (tipo: 23+) (se tiene que hacer return 2+3)
//---------------------------------------------------------------------------------------
void evaluarExpresion(char expresion[], int largo)
{
	// Se hace una pila temporal de int para los números a evaluar
	int pila_numeros[MAX];
	int sp_numeros=MAX;

	char temp; // Aquí se van guardando los valores temporales recuperados de la pila original
	char tops_char[10]; // Arreglo de numero char donde se guardará temporalmente el dígito char a convertir a int
	int tops[2]; // Arreglo en el cual voy a meter los dos digitos recuperados como enteros
	char signo; // Variable que almacenará la operación a realizar
	int i=0, operacion, d;

	// Se recorre el arreglo y se van metiendo los valores numericos en la pila int o realizando las operaciones
	while(i<largo)
	{
		temp=expresion[i];

		if((temp == '+') || (temp == '-') || (temp == '*') || (temp == '/'))
		{
			find_tops_int(pila_numeros, sp_numeros, tops);
			operacion=realizar_operacion(temp, tops[1], tops[0]);
			pop_int(pila_numeros, &sp_numeros, &d);
			pop_int(pila_numeros, &sp_numeros, &d);
			push_int(pila_numeros, &sp_numeros, operacion);
		}
		else if((temp == ';'))
		{
			break;
		}
		else
		{
			tops_char[0]=temp;
			push_int(pila_numeros, &sp_numeros, atoi(tops_char));
		}
		i+=1;

		// pp_int(pila_numeros, sp_numeros); // Por si se quiere saber qué hay en la pila en este momento
	}

	// Se imprime el resultado final
	cout << "Evaluacion final: " << operacion << endl;
}

//--------------------------------------------------------------------------------------- 
// Función que asigna un valor de prioridad a un operador
//---------------------------------------------------------------------------------------
int prioridad(char operador)
{
	int prioridad;
	switch (operador) {
		case '+':
			prioridad=0; // Menor prioridad
		break;
		case '-':
			prioridad=0;
		break;
		case '/':
			prioridad=1;
		break;
		case '*':
			prioridad=1;
		break;
		case '(':
			prioridad=2;
		break;
		default:
			prioridad=2;// Mayor prioridad
		break;
	}
	return prioridad;
}

//--------------------------------------------------------------------------------------- 
// Función que genera una expresión posfija para ser evaludada
//---------------------------------------------------------------------------------------
void generarPosfijo(char expresion[], char posfijo[], int largo) // Se envía una expresión[] y se regresa por posfijo[]
{
	// Se hace una pila de signos
	char pila_signos[MAX];
	int sp_signos=MAX;
	char temp, temp2;
	int contadorPosfijo=0;

	for(int i=0; i<largo; ++i) // Se recorre toda la expresión
	{
		temp = expresion[i];

		if((temp == '+') || (temp == '-') || (temp == '*') || (temp == '/') || (temp == '('))
		{
			if(pila_vacia(sp_signos)) // La pila está vacía, entonces se introduce el signo en ella
			{
				push_char(pila_signos, &sp_signos, temp);
			}
			else if (prioridad(temp)>prioridad(find_top_char(pila_signos, sp_signos))) // La prioridad es mayor, entonces se mete en la pila
			{
				push_char(pila_signos, &sp_signos, temp);
			}
			else // La prioridad del signo es menor o igal, por lo tanto se saca el valor almacenado, se mete en Posfijo y se introduce el nuevo signo a la pila
			{
				pop_char(pila_signos, &sp_signos, &temp2);
				push_char(pila_signos, &sp_signos, temp);
				if(temp2 != '(') // Los paréntesis de apertura se ignoran en Posfijo
				{
					posfijo[contadorPosfijo]=temp2; 
					contadorPosfijo+=1;
				}
			}
		}
		else if((temp == ')')) // El cierre de paréntesis indica que se debe recuperar el último valor de la pila y colocarlo en Posfijo
		{
			pop_char(pila_signos, &sp_signos, &temp2);
			if(temp2 != '(') // Los paréntesis de apertura se ignoran en Posfijo
			{
				posfijo[contadorPosfijo]=temp2; 
				contadorPosfijo+=1;
			}
		}
		else if((temp == ';')) // El cierre de operación indica que se debe recuperar el último valor (¿o todos?) de la pila (si no está vacía) y colocarlo en Posfijo
		{
			while(pop_char(pila_signos, &sp_signos, &temp2))
			{
				if(temp2 != '(')
				{
					posfijo[contadorPosfijo]=temp2;
					contadorPosfijo+=1;
				}
			}
			posfijo[contadorPosfijo]=';';
			contadorPosfijo+=1;
		}
		else
		{
			posfijo[contadorPosfijo]=temp; // Se mete un numero a Posfijo
			contadorPosfijo+=1;
		}
	}
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	// Inicialización de una pila para almacenar los paréntesis de la expresión matemática
	char pila[MAX];
	int sp=MAX, d;
	bool k;

	push_char(pila, &sp, '3');
	push_char(pila, &sp, '5');
	push_char(pila, &sp, '+');

	char expresion[100], posfijo[100];
	cout << "Ingrese una expresion matematica: ";
	cin >> expresion;

	generarPosfijo(expresion, posfijo, 100);
	cout << "Conversion a posfijo: " << posfijo << endl;
	evaluarExpresion(posfijo, 100);

	cout << endl;
	// cout << posfijo;

/*
	char operacion[100];

	cout << "Ingrese una expresion matematica: ";
	cin >> operacion;

	if(comprobacion(operacion, 100))
	{
		cout << "Esta bien escrito";
	}
*/

/*
	int tops[2];

	push_int(pila, &sp, 1);
	push_int(pila, &sp, 2);
	push_int(pila, &sp, 3);
	push_int(pila, &sp, 4);
	push_int(pila, &sp, 5);

	find_tops_int(pila, sp, tops);

	cout << "Los ultimos tops son: " << tops[0] << " y " << tops[1] << endl;

	find_tops_int(pila, sp, tops);
	cout << "Los ultimos tops son: " << tops[0] << " y " << tops[1] << endl;
*/
/*
	push_char(pila, &sp, 'a');
	push_char(pila, &sp, 'b');
	push_char(pila, &sp, 'c');
	push_char(pila, &sp, 'd');
	push_char(pila, &sp, 'e');

	if (find_top_char(pila, sp))
	{
		cout << "El valor de top es: " << find_top_char(pila, sp) << endl;
	}
	else
		cout << "error";
*/

	cout << "\n\n";
	system("pause");
	return 0;
}

/*
	push(pila, &sp, 'a');
	push(pila, &sp, 'b');
	push(pila, &sp, 'c');
	push(pila, &sp, 'd');
	push(pila, &sp, 'e');
	*/
	//pop(pila, &sp, &d);
	//pop(pila, &sp, &d);

	// pp(pila, sp); // Imprime todos los valores de una pila

	// Declaro un string "operacion" que almacenará la expresión matemática


	/*
	//Saca todo lo que está en la pila y lo mete en posfijo (caso;)
	while(pop_char(pila_signos, &sp_signos, &temp2))
			{
				if(temp2 != '(')
				{
					posfijo[contadorPosfijo]=temp2;
					contadorPosfijo+=1;
				}
			}
			posfijo[contadorPosfijo]=';';
			contadorPosfijo+=1;
	*/