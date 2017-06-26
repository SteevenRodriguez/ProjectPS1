#include <stdio.h>

#include <stdlib.h>

#include "miLista.h"

void Lista_SacarTodos(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/
  if ( (lista!=NULL) && (lista->numeroElementos!=0) ){
    int numeroElementos = Lista_Conteo(lista);
/*Se crea dos punteros uno al ancla y otro al primer elemento de la lista*/
    ElementoLista *ancla = &(lista->ancla);
    ElementoLista *head = Lista_Primero(lista);
	/*Si solo existe un elemento*/
    if(numeroElementos==1){
/*El ancla apunte a si mismo*/
         ancla->siguiente = ancla;
         ancla->anterior = ancla;
    }
/*Si existen mas de un elemento*/
    if(numeroElementos>1){
/*Se crea un puntero*/
      ElementoLista *before = (ElementoLista *)malloc(sizeof(ElementoLista));
      
      /*Se recorre la lista*/
      while (head!= ancla){
        /*Puntero before se colocara antes de la cabecera*/
        before = head->anterior;
        if(before != ancla)  {
/*Nos brinda facilidad mientras no sea el ancla se referencia todos los atributos a null*/
          before->siguiente = NULL;
          before->anterior = NULL;
          before->objeto = NULL;
            

        }
        
        head = head->siguiente;
      }

    }
    /*Se actualiza el numero de elementos en la lista*/
    lista->numeroElementos = 0;
  }
  
  return;

}
