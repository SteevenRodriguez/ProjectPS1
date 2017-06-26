#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

ElementoLista *Lista_Primero(ListaEnlazada *lista);

ElementoLista *Lista_Primero(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/	
if (lista != NULL){
	int numeroElementos = Lista_Conteo(lista);
/*Si la lista no esta vacia se obtiene el primero que es siguiente al ancla*/
	if (numeroElementos > 0){
		return lista -> ancla.siguiente;
			}
	}
	return NULL;
}
