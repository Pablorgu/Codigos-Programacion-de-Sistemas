/*Punteros
&n = La direccion de n
*n = La variable cuya direccion esta almacenada en n*/

#include<stdio.h>
int main()
{
    double numeros_array[]= (2.3,3.3,4.4,5.5);
    double *d;
    d=numeros_array
    printf("%lf %lf",d,*(d+2));
    return 0;
}
/*
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int xx = 10;
    int *ptr;
    ptr = &xx;
    //ej
    printf ("El valor de ptr es:")
    return 0;
}
*/