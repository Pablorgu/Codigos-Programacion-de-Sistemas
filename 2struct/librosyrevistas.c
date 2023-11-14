/*Vamos a crear una tienda con 100 artículos máximo, vamos a tener libros y revistas.

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
1.- Genera una nueva estructura str_item que contenga un struct str_Libro, un str_Revisa_Mensual y un char que almacene 'r' si es revista, 'l' si es libro y 'v' si no hay nada.
2.-usa sizeof(struct str_item) para conocer cuantos bytes necesitamos.*/

int main(int argc, char const *argv[])
{
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
    return 0;
}
