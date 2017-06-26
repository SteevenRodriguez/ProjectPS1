#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

int Lista_Inicializar(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/
	ElementoLista *ancla = (ElementoLista*)malloc(sizeof(ElementoLista));
	if(ancla == NULL){
		return -1;
	}
/*Se asigna los valores correspondientes a los atributos de la estructura definida*/
	ancla->objeto = NULL;
	ancla->siguiente = ancla;
	ancla->anterior = ancla;
	lista->ancla = *ancla;
	lista->numeroElementos = 0;
	return 0;
}
