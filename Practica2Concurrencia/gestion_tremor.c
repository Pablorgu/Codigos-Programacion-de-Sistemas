#include <stdlib.h>
#include <stdio.h>
#include "gestion_tremor.h"

/* Muestra los episodios de tremor que ha tenido el usuario por orden cronológico, primero los más nuevos, se le pasa la cabeza de la lista  */
	void mostrar_nuevos2antiguos (T_Lista lista){
        if (lista!=NULL){
            mostrar_nuevos2antiguos(lista->sig);
            printf("Evento en %s con duracion %i\n",ctime(&(lista->fecha)),lista->duracion);
        }
    }



/* 
Registra un episodio de tremor, con su fecha y duración, OK es igual a 1 si se puede, 0 si no es posible pedir memoria
 */
	void registrar(T_Lista * ptr_lista_head, const time_t * fecha, unsigned duracion,unsigned* ok){
       T_Lista newNode = (T_Lista)malloc(sizeof(struct T_Nodo));
       T_Lista aux = *ptr_lista_head;

       while(aux-sig !=NULL){
           aux=aux->sig
       }

    }

/* 
Libera todos los episodios que son anteriores a la fecha dada. Devuelve el número que se ha eliminado.
 */
	int liberar(T_Lista * ptr_lista_head, const time_t *  fecha){
        int cont = 0;
        T_Lista aux;
        while(((*ptr_lista_head)!=  NULL))
        return 0;
    }

/* Destruye la estructura utilizada (libera todos los nodos de la lista. El parámetro manejador debe terminar apuntando a NULL */

	void destruir(T_Lista* ptr_lista_head){
       T_Lista aux ;
       while ((*ptr_lista_head)!=NULL) {
          aux =(* ptr_lista_head);
          ptr_lista_head = (*ptr_lista_head)->sig;
          free(aux);
       }
    }