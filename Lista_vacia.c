#include <stdio.h>
#include "miLista.h"

int Lista_Vacia(ListaEnlazada *lista){
	if (lista == NULL){
		return -1;
	}
	else if(lista->numeroElementos == 0){
		return 1;
	}
	else{
		return 0;
	}
}
