#include "miLista.h"

ElementoLista *Lista_Ultimo(ListaEnlazada *lista);

ElementoLista *Lista_Ultimo(ListaEnlazada *lista){
  if (lista != NULL)
  {
  	int numeroElementos = Lista_Conteo(lista);
  	if (numeroElementos > 0)
    {
   
      return lista->ancla.anterior;
    }
  }
  return NULL;
}
