#include <stdio.h>
#include <stdlib.h>
#include "colaprio.h"

void insertar(TColaPrio *lista, int id, int prio) {
    TColaPrio aux = malloc(sizeof(struct Nodo));
    aux->idProceso = id;
    aux->prioProceso = prio;
    if (*lista == NULL) {
        aux->sig = NULL;
        *lista = aux;
    } else {
        if(aux->prioProceso< (*lista)->prioProceso) {
            aux->sig= *lista;
            *lista = aux;
        } else {
            TColaPrio it = *lista;
            while(it->sig != NULL && it->sig->prioProceso <= aux->prioProceso){
                it = it->sig;
            }
            aux->sig=it->sig;
            it->sig=aux;
        }
    }
}

void Crear_Cola(char *nombre, TColaPrio *cp){
    FILE *archivo = fopen( nombre, "rb");
    if(archivo==NULL) {
        printf("No se ha podido leer el fichero");
        exit(-1);
    } else {
        *cp=NULL;
        int num, id, prio;
        fread(&num, sizeof(int), 1, archivo); //lee el primer dato
        for(int i=0; i<num;++i){
            fread(&id, sizeof(int), 1, archivo);
            fread(&prio, sizeof(int), 1, archivo);
            insertar(cp,id,prio); //va sin & porque es puntero a un puntero
        }
        fclose(archivo);
    }
}

void Mostrar(TColaPrio cp){
    if(cp!=NULL){
        int i = 0;
        while(cp!=NULL) {
            printf("Puesto: %i, Id de proceso: %i, Prio de proceso: %i \n",i,cp->idProceso, cp->prioProceso);
            ++i;
            cp=cp->sig;
        }
    }
}
void Destruir(TColaPrio *cp){
    TColaPrio aux;
    if (*cp != NULL){
        while((*cp)->sig!=NULL) {
            aux = *cp;
            *cp=(*cp)->sig;
            free(aux);
        }
        *cp = NULL;
    }
}

void Ejecutar_Max_Prio(TColaPrio *cp){
    TColaPrio aux = *cp;
    while(aux->sig!=NULL) {
        aux=aux->sig;
    }
    Ejecutar(cp, aux->prioProceso);
}

void Ejecutar(TColaPrio *cp, int prio){
    TColaPrio aux = *cp;
    TColaPrio Ejec;
    TColaPrio ant;
    if(aux->prioProceso == prio){
        while(aux != NULL && aux->prioProceso == prio) {
            Ejec = aux;
            aux= aux->sig;
            free(Ejec);
            *cp=aux;
        }
    } else {
        ant=*cp;
        while(aux!=NULL) {
            if(aux->prioProceso==prio) {
                Ejec = aux;
                ant->sig = aux->sig;
                aux=ant->sig;
                free(Ejec);
            } else {
                ant=aux;
                aux=aux->sig;
            }
        }
    }
}