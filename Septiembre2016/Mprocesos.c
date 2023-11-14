#include <stdio.h>
#include "MProcesos.h"

void Crear(LProc *lista){
    *lista=NULL;
}

void AnadirProceso(LProc *lista, int idproc){
    LProc aux = (LProc)malloc(sizeof(struct Nodo));
    aux->id=idproc;
    if((*lista) == NULL){
        aux->sig=aux;
        *lista=aux;
    } else {
        aux->sig= (*lista)->sig;
        (*lista)->sig=aux;
        *lista=aux;
    }
}

void EjecutarProcesos(LProc lista){
    if(lista!=NULL){
    LProc aux = lista->sig;
        do{
            printf("\nQuantum de proceso %i realizado", aux->id);
            aux=aux->sig;
        }while (aux!=lista->sig);
    } else {
        printf("La lista de procesos está vacia");
    }
}


void EliminarProceso(int id, LProc *lista){
    LProc aux = *lista;
    LProc Ejec;
    if(*lista!=NULL){
        do{
            aux=aux->sig;
        } while(aux->sig->id!=id);
        Ejec=aux->sig;
        aux->sig=Ejec->sig;
        if(Ejec==*lista) *lista=aux;
        free(Ejec);
    }
}

void EscribirFichero (char * nomf, LProc *lista){
    FILE *archivo = fopen(nomf, "wb");
    LProc aux = *lista;
    LProc Ejec;
    if(lista!=NULL){
        int cont=0;       
        do{
            ++cont;
            aux=aux->sig;
        }while (aux!=*lista);
        aux=aux->sig;
        fwrite(&cont, sizeof(int), 1, archivo);
        for(int i=cont; i>0; --i) {
            fwrite(&(aux->id), sizeof(int), 1, archivo);
            Ejec=aux;
            aux=aux->sig;
            Ejec->sig=NULL;
            free(Ejec);
        }
        *lista=NULL;
    } else {
        fwrite(0,sizeof(int),1, archivo);
    }
    fclose(archivo);
}