#include "miLista.h"

int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento);

int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento)
{
  
  if (  (lista!=NULL) && (elemento!=NULL) && (objeto!=NULL) && (lista->numeroElementos!=0) )
  {
    
    ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
    ElementoLista *nuevo = (ElementoLista*)malloc(sizeof(ElementoLista));

    
    help = elemento;
    ElementoLista *ant = (ElementoLista *)malloc(sizeof(ElementoLista));


   
    nuevo->objeto = objeto;

    ant = help->anterior;

    help->anterior = nuevo;
    nuevo->siguiente = eItr;

    ant->siguiente = nuevo;
    nuevo->anterior = oldAnterior;

 
    lista->numeroElementos += 1;
    
    return 0;
  }
  return -1;
}
