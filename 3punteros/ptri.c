/*4. ¿Que valor tiene z tras ejecutar el siguiente código?  ¡Usa el debug!*/

#include<stdio.h>
int main(){
int x =10;
int y = 20;
int z[]={1,2,3};
int *ptri;

ptri = &x;
y = *ptri;

*ptri = 0;
ptri=&z[0]; // ptri=z;'''
´´´ 4. ¿Que valor tiene z tras ejecutar el siguiente código?  ¡Usa el debug!
int x =10;
int y = 20;
int z[]={1,2,3};
int *ptri;

ptri = &x;
y = *ptri;

*ptri = 0;
ptri=&z[0]; // ptri=z;´´´
return 0;
}