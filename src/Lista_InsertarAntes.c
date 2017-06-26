#include <stdio.h>
#include <stdlib.h>
#include "miLista.h"



int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento)
{
  /*Revision de las condiciones necesarias*/
  if (  (lista!=NULL) && (elemento!=NULL) && (objeto!=NULL) && (lista->numeroElementos!=0) )
  {
    /*Se crean dos punteros para facilitar el algortimo*/
    ElementoLista *help = (ElementoLista*)malloc(sizeof(ElementoLista));
    ElementoLista *nuevo = (ElementoLista*)malloc(sizeof(ElementoLista));

    /*Se asgina un puntero a elemento*/
    help = elemento;
    ElementoLista *ant = (ElementoLista *)malloc(sizeof(ElementoLista));


   /*Se Conectan las referencias entre los punteros*/
    nuevo->objeto = objeto;
    ant = help->anterior;
    help->anterior = nuevo;
/*Nuevo nodo apunta a siguiente, se encuentra en la mitad de ant y help*/
    nuevo->siguiente = help;

    ant->siguiente = nuevo;
    nuevo->anterior = ant;

 /*Se incremeneta el numero de la lista en 1*/
    lista->numeroElementos += 1;
    
    return 0;
  }
  return -1;
}
