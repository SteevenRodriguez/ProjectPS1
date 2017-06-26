#include <stdio.h>
#include <stdlib.h>

#include "miLista.h"

ElementoLista *Lista_Ultimo(ListaEnlazada *lista);

ElementoLista *Lista_Ultimo(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/
  if (lista != NULL){
  	int numeroElementos = Lista_Conteo(lista);
  	if (numeroElementos > 0){
   /*Como la lista no esta vacia el ultimo es el anterior del ancla*/
      return lista->ancla.anterior;
    }
  }
/*Si esta vacia se retorna NULL*/
  return NULL;
}
