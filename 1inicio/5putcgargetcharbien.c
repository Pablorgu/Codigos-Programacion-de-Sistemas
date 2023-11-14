/*
Enunciado: Vamos a hacer el esqueleto de un menú interactivo.
El usuario introduce un carácter que representa una de las siguientes opciones de menú: 

i para iniciar
1 para opción de llamada1
2 para opción de llamada1
f para fin

Tras leer, imprimimos un mensaje, elige el mensaje que quieras. Cuando se lee un f de fin, se termina el programa. Si se lee algo que no corresponde con una opción de menú, se avisa
al usuario que no se conoce esa opción, y se le muestra lo que ha introducido.

//Usa para hacerlo:
int getchar(void)
int putchar (int character);
switch
*/
#include<stdio.h>
#include<string.h>
int main(int argc, char const *argv[]){

    printf("i para iniciar\n1 para opcion de llamada1\n2 para opcion de llamada2\nf para fin\n");

    char caracter;
    int c;

    scanf("%s", caracter);
    while((c = getchar()) != 'f'){
        putchar(c);

        switch(c){
            
            case 'i':
            printf("Iniciar.\n\n");
            break;
            
            case '1':
            printf("Llamada1.\n\n");
            break;

            case '2':
            printf("Llamada2.\n\n");
            break;
            
            case 'f':
            printf("Terminar.\n\n");
            break;

            default:
            printf("Error.\n\n");
            break;

        }

        printf("i para iniciar\n1 para opción de llamada1\n2 para opción de llamada2\nf para fin\n");
        scanf("%s", caracter);

    }
    return 0;
}