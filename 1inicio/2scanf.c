int main(int argc, char const *argv[])
{
    printf("Introduce dos floats que se multiplicaran");
    float a, b;
   if(scanf("%f %f", &a, &b) ==2) {
    float mul = a * b;
    printf("La multiplicacion resultante es %.2f",mul);
   }else {
       perror("Se esperaban dos floats separados por un espacio y no se han encontrado");
   }
   return 0;
}
