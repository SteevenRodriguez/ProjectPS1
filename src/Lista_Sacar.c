#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"

void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento);
void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento)
{
  //Condiciones para entrar al algoritmo
  if ( (lista!=NULL) && (elemento!=NULL) && (lista->numeroElementos!=0) )
  {
    //Se obtiene el tamaño de la lista
    int numeroElementos = Lista_Conteo(lista);
    //Se crean dos punteros hacia ancla y primero para facilitar la busqueda
    ElementoLista *ancla = &(lista->ancla);
    ElementoLista *primero = Lista_Primero(lista);
    if(numeroElementos==1)
    {
      //if ( (long)primero->objeto == (long)elemento->objeto )
      if ( primero == elemento )
      {  
         ancla->siguiente = ancla;
         ancla->anterior = ancla;

         lista->numeroElementos = 0;
      }
}
		ElementoLista *next = Lista_Siguiente(lista,elemento);
		ElementoLista *before = Lista_Anterior(lista,elemento);
		next->anterior = anterior;
		before->siguiente = siguiente;
		lista->numeroElementos -= 1;
	}
}
