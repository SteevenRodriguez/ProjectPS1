#ifndef _MILISTA_H
#define _MILISTA_H

/**
* Autor: Eduardo Murillo.
*/


/*Algunas definiciones*/
#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif


/**
* Definci�n del elemento de la lista
*/

typedef struct ElementeListaTDA{
	void *objeto;
	struct ElementeListaTDA *siguiente;
	struct ElementeListaTDA *anterior;
} ElementoLista;

/**
*Definci�n de la estructura de lista
*/

typedef struct ListaEnlazadaTDA{
	int numeroElementos;
	ElementoLista ancla;
}ListaEnlazada;

/*Definici�n de funciones sobre la lista*/
extern int Lista_Inicializar(ListaEnlazada *lista);

extern int Lista_Vacia(ListaEnlazada *lista);
extern int Lista_Conteo(ListaEnlazada *lista);

extern ElementoLista *Lista_Buscar(ListaEnlazada *lista, void *objeto);

/*Funciones de modificacion de la lista*/
extern int Lista_InsertarFin(ListaEnlazada *lista, void *objeto);
extern int Lista_InsertarInicio(ListaEnlazada *lista, void *objeto);
extern void Lista_Sacar(ListaEnlazada *lista, ElementoLista *elemento);
extern void Lista_SacarTodos(ListaEnlazada *lista);
extern int Lista_InsertarDespues(ListaEnlazada *lista, void *objeto, ElementoLista *elemento);
extern int Lista_InsertarAntes(ListaEnlazada *lista, void *objeto, ElementoLista *elemento);


/*Funciones que devuelven un elemento particular de la lista*/
extern ElementoLista *Lista_Primero(ListaEnlazada *lista);
extern ElementoLista *Lista_Ultimo(ListaEnlazada *lista);
extern ElementoLista *Lista_Siguiente(ListaEnlazada *lista, ElementoLista *elemento);
extern ElementoLista *Lista_Anterior(ListaEnlazada *lista, ElementoLista *elemento);


#endif
