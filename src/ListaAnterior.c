#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"



ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento){
/*Revision de las condiciones necesarias*/
	if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) ){
    /*Se crea un puntero para revisar la condicion de que exista solo un elemento*/
    		ElementoLista *primer = (ElementoLista*)malloc(sizeof(ElementoLista));
    		primer = Lista_Primero(lista);
	    	if(primer == elemento)

	      		return NULL;/*Se retorna NULL ya que no existe anterior*/
		ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
		help=Lista_Buscar(lista,elemento->objeto);/*Se revisa si el elemento dado pertenece a la lista*/

		if(help!=NULL){
	    		return help->anterior;/*Si existe el elemento se retorna el anterior*/

		}
  	}
  	return NULL;
}
