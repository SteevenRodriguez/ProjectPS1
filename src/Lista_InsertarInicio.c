#include <stdio.h>
#include <stdlib.h>

#include "miLista.h"

int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto);

int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto){
/*Revision de las condiciones necesarias*/
  if (lista != NULL){
/*Crea una variable con el numero de elementos en la lista*/
	int numeroElementos = Lista_Conteo(lista);
	ElementoLista *nuevo = (ElementoLista *)malloc(sizeof(ElementoLista));

	if( nuevo == NULL )
		return -1;
/*Se asigna el objeto al puntero*/
	nuevo->objeto = objeto;

/*Revision de las condiciones necesarias*/
	if (numeroElementos == 0) {
/*Nuevo se asigna con el ancla*/
      nuevo->siguiente = &(lista->ancla);
      nuevo->anterior = &(lista->ancla);
      
      lista->ancla.siguiente = nuevo;
      lista->ancla.anterior = nuevo;

    }else{
/*Se realizan las referencias*/
      ElementoLista *primero = Lista_Primero(lista);

      nuevo->siguiente = primero;
      nuevo->anterior = &(lista->ancla);
      
       
      lista->ancla.siguiente = nuevo;
      primero->anterior = nuevo;
      
    }

    lista->numeroElementos += 1;
    return 0;

  }
  else
    return -1;
}
