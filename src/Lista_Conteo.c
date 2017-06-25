#include <stdio.h>

#include "miLista.h"

int Lista_Conteo(ListaEnlazada *lista){
	if(lista == NULL){
		return -1;
	}
	else{
		return lista->numeroElementos;
	}
}
