int main(int argc, char const *argv[])
{
     char cadena[11]="Hola mundo";
    int tamano = strlen(cadena);
    printf("El tamaño de la cadena es: %i",tamano);
    if(strcmp(cadena, "Hola mundo") == 0)
    {
          printf("La cadena es igual\n");
    }else{
        printf("La cadena NO es igual\n");
    }
    return 0;
}
