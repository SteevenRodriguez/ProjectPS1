#include <stdio.h>
#include "miLista.h"
ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
	if (  (lista!=NULL) && (lista->numeroElementos!=0) ){
		ElementoLista *elemento = Lista_Primero(lista);
		while(elemento -> objeto != NULL){
			if(elemento -> objeto == objeto){
				return elemento;
			}
			elemento = elemento -> siguiente;
		}
		
	}
	return NULL;
}
