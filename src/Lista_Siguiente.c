#include "miLista.h"

ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento);

ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
  if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
    
ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
help=Lista_Buscar(lista,elemento->objeto);
if(help!=NULL){
return help->siguiente;
}

}

return NULL;
}
