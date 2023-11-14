#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearLista(TLista *lista) {
    *lista=NULL;
}
int buscarigual(TLista lista, TLista punto){
    int ok=1;
    if(lista!=NULL) {
        while(lista->sig!=NULL) {
            if(punto->punto.x==lista->punto.x) ok=0;
            lista=lista->sig;
        }
    }
    return ok;
}

void insertarPunto(TLista *lista, struct Punto punt, int *ok){
    TLista punto = (TLista)malloc(sizeof(struct Nodo));
    *ok=0;
    punto->punto= punt;
    TLista aux= *lista;
    int rep = buscarigual(*lista, punto);
    if(rep==1){
        if(*lista==NULL) { //cuando añades el primer punto
            *lista = punto;
            (*lista)->sig=NULL;
        } else if((*lista)->sig==NULL ){ //añade el segundo punto
            if (((aux->punto).x)>((punto)->punto).x) {
                punto->sig=aux;
                *lista = punto;
            } else {
                aux->sig=punto;
                punto->sig=NULL;
            }
        }else {    //añade cuando hay mas de dos puntos
            if((aux->punto.x)>(punto->punto.x)){ //en caso de que vaya en el primer puesto
                punto->sig=aux;
                *lista=punto;
            }else {

                while(aux->sig !=NULL && aux->sig->punto.x < punto->punto.x) { //para cuando tiene que buscar en que posicion va
                    aux=aux->sig;
                }
                punto->sig=aux->sig;
                aux->sig=punto;
            }
        }
        *ok=1;
    }
}

void eliminarPunto(TLista *lista, float x, int *ok) {
    TLista aux= *lista;
    TLista aux2= *lista;
    *ok=0;
    while(aux->punto.x != x){
        aux=aux->sig;
        if(aux->punto.x != x) *ok=1;
    } 
    if(aux==(*lista) && ok == 1) { 
        *lista = (*lista)->sig;
        free(aux);
    } else if (ok==1) {
        while(aux2->sig != aux) aux2++;
        aux2->sig=aux->sig;
        free(aux);
    }
}

void mostrarLista(TLista lista){
    int i=0;
    if(lista!=NULL){
        while(lista->sig !=NULL) {
            printf("Punto %i: (%f,%f) \n",i,lista->punto.x,lista->punto.y);
            i++;
            lista=lista->sig;
        }
    }else{
        printf("La lista esta vacia");
    }
}


void destruir(TLista *lista){
    TLista aux;
    if(lista!=NULL){
        while((*lista)->sig!=NULL){
            aux=*lista;
            *lista=(*lista)->sig;
            free(aux);
        }
        *lista=NULL;
    }
}

void leePuntos(TLista *lista, char *nFichero){
    int ok;
    crearLista(lista);
    FILE *archivo = fopen(nFichero, "rb");

    if(archivo == NULL) {
        perror("No se puede abrir el archivo");
    } else {
        struct Punto p;
        while (fread(&p, sizeof(struct Punto), 1, archivo) == 1) {
            insertarPunto(lista, p, &ok);
        }
        fclose(archivo);
    }
}