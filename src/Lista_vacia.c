#include <stdio.h>
#include "miLista.h"

int Lista_Vacia(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/
	if (lista == NULL){
		return -1;
	}
/*Si no existe elementos esta vacia*/
	else if(lista->numeroElementos == 0){
		return 1;
	}
	else{
		return 0;
	}
}
