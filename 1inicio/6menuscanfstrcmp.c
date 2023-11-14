/*
Enunciado: Vamos a hacer el esqueleto de un menú interactivo.
El usuario introduce una cadena de texto inferior a 100 carácteres que representa una de las siguientes opciones de menú: 

iniciar
llamada1
llamada2
fin

Tras leer, imprimimos un mensaje, elige el mensaje que quieras. Cuando se lee un fin, se termina el programa. Si se lee algo que no corresponde con una opción de menú, se avisa al usuario que no se conoce esa opción, y se le muestra lo que ha introducido.
*/

#include<stdio.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
int main(int argc, char const *argv[]){

printf("niciar para iniciar\nllamada1 para opcion de llamada1\nllamada2 para opcion de llamada2\nfin para fin\n");
char caracter[100];
scanf("%s", caracter);
while(strcmp(caracter, "fin") != 0){
        

        if(strcmp(caracter, "iniciar") == 0){
            printf("\nBuenos dias.\n\n");
        }
        else if(strcmp(caracter, "llamada1") == 0){
            printf("\nLlamas1.\n\n");

        }
        else if(strcmp(caracter, "llamada2") == 0){
            printf("\nLlamas2\n\n");

        }
        else{
            printf("\nError\n\n");

        }
        printf("niciar para iniciar\nllamada1 para opcion de llamada1\nllamada2 para opcion de llamada2\nfin para fin\n");
        scanf("%s", caracter);

        

    }


}