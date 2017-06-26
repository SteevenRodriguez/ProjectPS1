#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"



int Lista_InsertarFin(ListaEnlazada *lista, void *objeto){
/*Revision de las condiciones necesarias*/
	if (lista != NULL){
/*Crea una variable con el numero de elementos en la lista*/
		int numeroElementos = Lista_Conteo(lista);
		ElementoLista *nuevo = (ElementoLista *)malloc(sizeof(ElementoLista));

/*Revision de la habilitacion del puntero*/
		if (nuevo==NULL)
			return -1;
/*Se asigna el objeto al puntero*/
		nuevo->objeto = objeto;
/*Revision de las condiciones necesarias*/
		if (numeroElementos == 0){
/*Nuevo se asigna con el ancla*/
			nuevo->siguiente = &(lista->ancla);
			nuevo->anterior = &(lista->ancla);

			lista->ancla.siguiente = nuevo;
			lista->ancla.anterior = nuevo;

		}else{
/*Se obtiene el ultimo elemento de la lista*/
			ElementoLista *ultimo = Lista_Ultimo(lista);

/*Se realizan las referencias*/
			nuevo->siguiente = &(lista->ancla);
			nuevo->anterior = ultimo;

			ultimo->siguiente = nuevo;
			lista->ancla.anterior = nuevo;
		}
/*Aumenta el numero de elementos en la lista*/
		lista->numeroElementos += 1;
		return 0;

	}
	return -1;
}
