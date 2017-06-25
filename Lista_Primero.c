#include "miLista.h"

ElementoLista *Lista_Primero(ListaEnlazada *lista);

ElementoLista *Lista_Primero(ListaEnlazada *lista){
  if (lista != NULL)
  {
  	int numeroElementos = Lista_Conteo(lista);
  	if (numeroElementos > 0)
    {
    //ElementoLista ultimo = (lista->ancla).anterior; 
      return lista->ancla.siguiente;
    }
  }
  return NULL;
}
