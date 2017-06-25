#include <stdio.h>
#include "miLista.h"
ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto);

ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto){

 
  if (  (lista!=NULL) && (lista->numeroElementos!=0) )
  {


  	int n = lista->numeroElementos;
  	ElementoLista *primero = Lista_Primero(lista);
  	ElementoLista *ultimo = Lista_Ultimo(lista);   
  	if(n>0)
  	{
      
      if(primero->objeto == objeto)
      {
        ultimo = NULL;
        free(ultimo);
  	    return primero;
      }
  	}
  	if(n>1)
  	{ 
      if(ultimo->objeto == objeto)
      {
        
        primero = NULL;
        free(primero);
  	    return ultimo;	
      }
    }
    while (primero != ultimo)
    {
      
      if (primero->objeto == objeto)
      {
        return primero;
      }
      primero = primero->siguiente;
    }
  }

  return NULL;
}
