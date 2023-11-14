/*Define la siguiente extructura:
struct str_Libro
{
    char titulo[200];
    char autor[200];
    int paginas;
    float precio;
};
1.- Define:
 a) una variable de esta estructura llamada libro.
 b) un puntero a la estructura que apunte a esta variable llamada ptr_libro.
 ¿Puedes comprobar con el debugger que funciona esta asignación?

2.- ¿Puedes mostrar el autor y el precio con printf usando sólo el puntero?
*/
#include<stdio.h>

 struct str_Libro
    {
        char titulo[200];
        char autor[200];
        int paginas;
        float precio;
    };
    typedef str_Libro libro;
int main(int argc, char const *argv[])
{
   struct str_libro libro;
   struct str_libro * ptr_libro;
   strcpy(libro.autor, "ErJaki");
   strcpy(libro.titulo, "Tears")
   libro.pagina = 12;
   libro.precio = 10.5;

    ptr_libro = &libro;
    printf("Nombre %s, precio %f" , ptr_libro->autor,
    (*ptr_libro).precio);

    return 0;
}