/*Un puntero en C no es más que una variable que tiene el valor en memoria en la que se almacena otra variable. Se definen variables de tipo puntero con el operador unario indirección *

Por ejemplo:
int a; /// en dónde uses a, estás usando un valor númerico entero.

int * b; 
int* b;
int *b;
/// b es de tipo puntero a un entero. Dónde uses b estás usando una dirección de memoria. Si vas a esa dirección de memoria, puedes encontrar un entero o no, dependiendo de lo que contenga esa memoria.

El operador unario dirección & se usa para conocer dónde está en memoria almacenada una variable.

1.- En el siguiente código, 

int xx = 10;
int *ptr;
ptr = &xx;

¿Qué valor tiene ptr? Usa el debug.
¿Qué valor tiene ptr? Usa el printf con el specifier p*/
//************************************
/*Los punteros son como struct pero se pisan ya que une las variables, recordar 
lo de nombre e inicial: https://www.youtube.com/watch?v=6b7HbxzZGVY */
//************************************

#include<stdio.h>

typedef union Persona Persona;

union Persona
{   
    char nombre[50];
    char inicial;
};

int main(int argc, char const *argv[])
{
        Persona juan = { "Juan", "J"};
 //   Persona Juan = { "Juan", "R"};
    printf("Nombre: %s\n" , juan.nombre);
    printf("Inicial: %c\n", juan.inicial);
    return 0;
}


