#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"



int Lista_InsertarFin(ListaEnlazada *lista, void *objeto)
{
  if (lista != NULL)
  {

    int numeroElementos = Lista_Conteo(lista);
    ElementoLista *nuevo = (ElementoLista *)malloc(sizeof(ElementoLista));
    
    
    if (nuevo==NULL)
      return -1;

    nuevo->objeto = objeto;

    if (numeroElementos == 0)
    {
      nuevo->siguiente = &(lista->ancla);
      nuevo->anterior = &(lista->ancla);
      
      lista->ancla.siguiente = nuevo;
      lista->ancla.anterior = nuevo;

    }else
    {
      ElementoLista *ultimo = Lista_Ultimo(lista);

      
      nuevo->siguiente = &(lista->ancla);
      nuevo->anterior = ultimo;
       
      ultimo->siguiente = nuevo;
      lista->ancla.anterior = nuevo;
    }

    lista->numeroElementos += 1;
    return 0;

  }
  else
    return -1;
}
