#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "componentes.h"

Lista Lista_Crear() {
    Lista *lista = NULL;
    return lista;
}

void Adquirir_Componente(long *codigo, char *texto) {
   printf("Introduzca un código y su descripción: ");
    scanf("%i", codigo);
    fgets(texto, MAX_CADENA, stdin);
    printf("\n");
}


void Lista_Agregar(Lista *lista, long codigo, char* textoFabricante){
    Lista Nodo = malloc(sizeof(struct elemLista));
    Nodo->codigoComponente = codigo;
    strcpy(Nodo->textoFabricante, textoFabricante);
    if(*lista == NULL){
        Nodo->sig = NULL;
        *lista = Nodo;
    }else{
        Lista it = *lista;
        while(it->sig != NULL){
            it = it->sig;
        }
        Nodo->sig = NULL;
        it->sig = Nodo;
    }
}


void Lista_Imprimir( Lista lista){
    if(lista!=NULL) {
        while(lista!=NULL) {
            printf("Codigo: %i\n Texto: %s \n\n", lista->codigoComponente, lista->textoFabricante);
            lista=lista->sig;
        }
    } else {
        printf("La lista está vacía\n");
    }
}

int Lista_Vacia(Lista lista){
    int vacia = 0;
    if(lista==NULL) {
        vacia=1;
    }
    return vacia;
}

int Num_Elementos(Lista lista) {
    int cont = 0;
    while(lista!=NULL) {
        cont++;
        lista=lista->sig;
    }
    return cont;
}

void Lista_Extraer(Lista *lista){
    if(*lista!=NULL){
        Lista it = *lista;            // Lista aux = *lista;
            // Lista Ejec;
            
        if(it->sig == NULL){
            *lista = (*lista)->sig;
            free(it);
        }else{
        Lista ant;
        while(it->sig != NULL){
            ant = it;
            it = it->sig;
        }

        ant->sig = it->sig;
        free(it);
        }   
    }
}
    

    //     while(aux->sig->sig!=NULL) {
    //         aux=aux->sig;
    //     }
    //     Ejec=aux->sig;
    //     aux->sig=NULL;
    //     free(Ejec);
    // }


void Lista_Vaciar(Lista *lista){
    if(*lista!=NULL){
        Lista Ejec;
        while((*lista)!=NULL){
            Ejec=*lista;
            *lista=(*lista)->sig;
            Ejec->sig=NULL;
            free(Ejec);
        }
    }
}


void Lista_Salvar(Lista  lista){
    FILE *archivo = fopen("examen.dat", "wb");
    int *numc = Num_Elementos(lista);
    fwrite(&numc, sizeof(int),1,archivo);
    while(lista!=NULL){
        //  fwrite(lista->codigoComponente, sizeof(int),1,archivo);
        //  fwrite(lista->textoFabricante, strlen(lista->textoFabricante)+1,1,archivo);
        fwrite(&lista, sizeof(Componente),1, archivo);
        lista=lista->sig;
    }
    fclose(archivo);

    FILE * fi = fopen("examen.dat", "rb");
    if(fi == NULL){
        perror("No se pudo abrir el fichero.");
        exit(-1);
    }
    int *numcr;
    fread(&numcr, sizeof(int), 1, archivo);
    printf("Num procesos: %i\n",numcr);

    Lista n;
    fread(&n, sizeof(Componente),numcr, archivo);
    Lista_Imprimir(n);
}
