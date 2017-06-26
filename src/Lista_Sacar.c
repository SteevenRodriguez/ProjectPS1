#include <stdio.h>

#include "miLista.h"

void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento){
	/*Revision de las condiciones necesarias*/
	if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
/*Se crea una variable con el numero de elementos*/
		int numero = Lista_Conteo(lista);
/*Se crean dos punteros en los extremos de la lista para resolver con mayor rapidez*/
		ElementoLista *ancla = &(lista->ancla);
		ElementoLista *primero = Lista_Primero(lista);
		ElementoLista *ultimo = Lista_Ultimo(lista);
		if(numero==1){
			/*Revision de las condiciones necesarias*/
			if ( primero == elemento ){  
				ancla->siguiente = ancla;
				ancla->anterior = ancla;

				lista->numeroElementos = 0;
				return;
			}
		}
/*Si no se encuentra en los extremos entonces necesitamos a los extremos del elemento para hacer las referencias*/
		ElementoLista *next = Lista_Siguiente(lista,elemento);
		ElementoLista *before = Lista_Anterior(lista,elemento);

/*Se revisa si es el primero*/
		if (primero == elemento){
/*Se asignan las referencias con el ancla*/
			next->anterior = ancla;
			lista->ancla.siguiente = next;
			lista->numeroElementos -= 1;
			return;
		}
/*Se revisa si es el ultimo en que hay que sacar*/
		else if (ultimo == elemento){
/*Se asignan las referencias con el ancla*/
			lista->ancla.anterior = before;
			before->siguiente = ancla;
			lista->numeroElementos -= 1;
			return;
		}

		else{
/*Se asignan referencias con los punteros extremos del elemento*/
			next->anterior = before;
			before->siguiente = next;
			lista->numeroElementos -= 1;
			return;
		}
	}
}
