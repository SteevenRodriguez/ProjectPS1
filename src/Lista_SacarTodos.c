#include <stdio.h>

#include <stdlib.h>

#include "miLista.h"

void Lista_SacarTodos(ListaEnlazada *lista)
{

  if ( (lista!=NULL) && (lista->numeroElementos!=0) )
  {
    int numeroElementos = Lista_Conteo(lista);
    ElementoLista *ancla = &(lista->ancla);
    ElementoLista *head = Lista_Primero(lista);

    if(numeroElementos==1)
    {
         ancla->siguiente = ancla;
         ancla->anterior = ancla;
    }

    if(numeroElementos>1)
    {
      ElementoLista *before = (ElementoLista *)malloc(sizeof(ElementoLista));
      
      
      while (head!= ancla)
      {
        
        before = head->anterior;
        if(before != ancla)  
        {
          before->siguiente = NULL;
          before->anterior = NULL;
          before->objeto = NULL;
            

        }
        
        head = head->siguiente;
      }

    }
    
    lista->numeroElementos = 0;
  }
  
  return;

}
