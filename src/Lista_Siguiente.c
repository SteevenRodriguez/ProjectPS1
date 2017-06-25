#include <stdio.h>

#include "miLista.h"



ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
		ElementoLista *ancla = &(lista -> ancla);
		ElementoLista *help = Lista_Buscar(lista,elemento->objeto);
		if(help!=NULL && (help->siguiente != ancla)){
			return help->siguiente;
		}

	}

return NULL;
}
