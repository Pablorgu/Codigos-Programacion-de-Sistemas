#include<stdio.h>
#include<stdlib.h>
#include "circular.h"
void Crear (LProc *lista) {
    *lista=NULL;
}


void AnyadirProceso (LProc *lista, int idproc){
    LProc aux = (LProc)malloc(sizeof(struct circular));
    aux->pid=idproc;
    if (*lista==NULL){
        *lista = aux;
        aux->sig = aux;
    }else{
        LProc aux_ptr = (*lista);
        aux->sig=(*lista);
        while(aux_ptr->sig!=*lista) aux_ptr=aux_ptr->sig;
        aux_ptr->sig = aux;
    }
}


void MostrarLista(LProc lista){
    LProc aux = lista;
    if(lista!=NULL){
        do
        {
            printf("Pid: %i \n",aux->pid);
            aux=aux->sig;
        } while (aux!=lista);
    }
}

void EjecutarProceso(LProc *lista){
    if(*lista!=NULL){
        
        if((*lista)->sig == (*lista)){
            LProc aux = *lista;
            free(aux);
            (*lista) = NULL;
        } else {
            LProc aux = *lista;
            LProc ptr = (*lista)->sig;
            while(ptr->sig!=*lista) ptr=ptr->sig;
            ptr->sig=aux->sig;
            free(aux);
            *lista=ptr->sig;
        }
    }
}
