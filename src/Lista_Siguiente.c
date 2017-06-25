#include <stdio.h>

#include "miLista.h"



ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
		ElementoLista *ancla = &(lista -> ancla);
		if(elemento->siguiente != ancla){
			return elemento->siguiente;
		}

	}

return NULL;
}
