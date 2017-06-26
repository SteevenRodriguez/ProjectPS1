#include <stdio.h>

#include "miLista.h"

int Lista_Conteo(ListaEnlazada *lista){
/*Revision de las condiciones necesarias*/	
if(lista == NULL){
		return -1;
	}
	else{
		return lista->numeroElementos;
	}
}
