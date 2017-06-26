#include <stdio.h>

#include "miLista.h"



ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento){
	if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
/*Revision de las condiciones necesarias*/
		ElementoLista *ancla = &(lista -> ancla);
/*Se verifica que siguiente no sea el ancla */
		if(elemento->siguiente != ancla){
			return elemento->siguiente;
		}

	}

return NULL;
}
