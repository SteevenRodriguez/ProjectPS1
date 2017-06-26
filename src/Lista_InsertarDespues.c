#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento);

int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento){
 /*Revision de las condiciones necesarias*/ 
  if (  (lista!=NULL) && (elemento!=NULL) && (objeto!=NULL) && (lista->numeroElementos!=0)  )
  {
   /*Se crean dos punteros para facilitar el algortimo*/
    ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
    ElementoLista *nuevo = (ElementoLista*)malloc(sizeof(ElementoLista));
/*Se asgina un puntero a elemento*/
    help = elemento;
    ElementoLista *next = (ElementoLista *)malloc(sizeof(ElementoLista));
    	
   /*Se Conectan las referencias entre los punteros*/
    nuevo->objeto = objeto;
    next = help->siguiente;
    help->siguiente = nuevo;
    nuevo->anterior = help;
    next->anterior = nuevo;
    nuevo->siguiente = next;

 
    lista->numeroElementos += 1;

    return 0;
  }
  return -1;

}
