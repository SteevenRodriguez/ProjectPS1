#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

int Lista_Inicializar(ListaEnlazada *lista){
	ElementoLista *ancla = (ElementoLista*)malloc(sizeof(ElementoLista));
	if(ancla == NULL){
		return -1;
	}
	ancla->objeto = NULL;
	ancla->siguiente = ancla;
	ancla->anterior = ancla;
	lista->ancla = *ancla;
	lista->numeroElementos = 0;
	return 0;
}
