// Nombre del programa: conversionSistemas.c
// Descripción: Convertir de decimal a base 8, 2, y 16
// Alumno: Sergio Enrique Vargas García 
// Fecha: 4-Febrero-2014                                       
  
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
// Funcion que conseguí en internet que converte de int a char, que de hecho también convierte de decimal a los otros sistemas numéricos :S
//---------------------------------------------------------------------------------------
char* itoa(int val, int base)
{        
    static char buf[32] = {0};
    int i = 30;
    bool sign = val < 0;
    if (val == 0) {
        buf[30] = '0';
        return &buf[30];
    } 
    if (sign) val = -val;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789ABCDEF"[val % base];
    if (sign) buf[i--] = '-';
    return &buf[i+1];
}

//--------------------------------------------------------------------------------------- 
// Funcion que converte de decimal a binario, octal o hexadecimal (El programa que yo hice)
//---------------------------------------------------------------------------------------
void conversor(int decimal, int base)
{
	int posicion=1, multiplicador;

	//Este while indica la posicion máxima
	while (posicion<=decimal)
	{
		if(posicion*base<=decimal)
		{
			posicion*=base;
		}
		else
			break;
	}

	cout << "\n\nEl resultado es: ";

	//Este while hace la conversion del valor de cada posición del sistema en cada ciclo
	while(posicion>=1)
	{
		cout << itoa(decimal/posicion, 16);

		decimal%=posicion;
		posicion/=base;
	}

	cout << "\n\n";
}

//--------------------------------------------------------------------------------------- 
// Programa Principal 
//---------------------------------------------------------------------------------------
int main(int argc, char** argv) {

	int base, decimal;

	cout << "Escribe 2, 8 o 16 a continuación para convertir desde decimal al otro sistema: ";
	cin >> base;
	cout << "\nIngresa el numero a convertir: ";
	cin >> decimal;

	conversor(decimal, base);

	//system("pause");
	return 0;
}