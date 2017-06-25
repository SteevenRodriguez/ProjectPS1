#include "miLista.h"

ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento);

ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
  if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
    
    ElementoLista *primer = (ElementoLista*)malloc(sizeof(ElementoLista));
    primer = Lista_Primero(lista);
    if(primer == elemento)
      return NULL;
ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
help=Lista_Buscar(lista,elemento->objeto);

if(help!=NULL){
    return help->anterior;

}
  }
  return NULL;
}
