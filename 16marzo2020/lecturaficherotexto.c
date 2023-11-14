#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdlib.h>
struct str_Libro
{
    char titulo[200];
    char autor[200];
    int paginas;
    float precio;
};

enum Meses { ENE, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC };

struct str_Revisa_Mensual
{
    char titulo[200];
    enum Meses mes;
    float precio;
};

union u_Item{
    struct str_Libro libro;
    struct str_Revisa_Mensual revista;
};

typedef struct str_union_item * ptr_str_union_item;

struct str_union_item{
    union u_Item item;
    char tipo;
    ptr_str_union_item siguiente;  
};

/*
1.- Crea un fichero que se va a abrir (fopen) en modo texto y escritura con un parámetro de entrada de la línea de comandos argv[1]. El argv[0] es el nombre del propio programa.
https://www.cplusplus.com/reference/cstdio/fopen/

Ejecuta varias veces el programa y observa si cambia el fichero.

2.- Cambia el modo de acceso del fichero de escritura "w" a añadir "a", ¿qué resultado se espera?

Ejecuta varias veces el programa y observa si cambia el fichero.

3.- Ahora vamos a pasar los parámetros con args en el launch.json. 
https://code.visualstudio.com/docs/cpp/launch-json-reference#_environment

4.- COmo curiosidad, mira el puntero al fichero, tiene unos cuantos campos interesantes.
http://tigcc.ticalc.org/doc/stdio.html#FILE

¿Cuántos bytes podemos escribir como máximo? 
*/

int main(int argc, char const *argv[])
{

    if (argc!=2){
        printf("Se esperaban el nombre de fichero como parámetro de entrada");
        exit(-1);
    }

...