#include <stdio.h>
#include "miLista.h"
ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){
/*Revision de las condiciones necesarias*/
	if (  (lista!=NULL) && (lista->numeroElementos!=0) ){
		ElementoLista *elemento = Lista_Primero(lista);/*Se tiene referencia al primer elemento*/
		ElementoLista ancla = lista -> ancla;/*Se tiene referencia al ancla de la lista*/
		
/*Forma de recorrer la lista*/
		while(elemento != &ancla){
			/*Se validad si el objeto es igual al dado en la funcion*/
			if(elemento -> objeto == objeto){
				return elemento;/*De ser valido se retorna el elemento*/
			}
			elemento = elemento -> siguiente;/*Se asigna al siguiente para movernos dentro de la lista*/
		}
		
	}
	
	return NULL;/*Se retorna NULL si no encuentra el elemento*/
}
