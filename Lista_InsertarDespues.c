#include "miLista.h"

int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento);

int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento)
{
  
  if (  (lista!=NULL) && (elemento!=NULL) && (objeto!=NULL) && (lista->numeroElementos!=0)  )
  {
   
    ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));

    ElementoLista *nuevo = (ElementoLista*)malloc(sizeof(ElementoLista));

   help = elemento;
    ElementoLista *next = (ElementoLista *)malloc(sizeof(ElementoLista));
    	
   
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
