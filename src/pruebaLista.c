#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>     /* assert */
#include "miLista.h"

//#define IMPRIMIR_LISTA



void ImprimirLista(ListaEnlazada *lista, int numeroElementos){

	if (Lista_Conteo(lista) != numeroElementos){
		printf("ImprimirLista: Error. Numero de elementos en lista incorrecto\n");
		exit(-1);
	}

	ElementoLista *elem = NULL;

	for (elem = Lista_Primero(lista); elem != NULL; elem = Lista_Siguiente(lista, elem)) {

		printf("%lu\n", (long)elem->objeto);
	}
}




/*Llena la lista*/
void LlenarLista(ListaEnlazada *lista, int numeroElementos){

	long i = 0;

	for (i = 0; i < numeroElementos; i++){
		Lista_InsertarFin(lista, (void *)i);
	}
}

/*Devuelve numero aleatorio de entre 0 y numeroElementos - 1*/
long IndiceAleatorio(int numeroElementos)
{
	srand(time(NULL));
	long r = (rand() % numeroElementos);

	return r;
}


/*Baraja los elementos de la lista*/
int BarajarLista(ListaEnlazada *lista, int numeroElementos)
{

	int i = 0;

	ElementoLista *elem = NULL;
	ListaEnlazada lista_tmp;

	memset(&lista_tmp, 0, sizeof(ListaEnlazada));
	Lista_Inicializar(&lista_tmp);

	//Buscar elemento, sacarlo de lista, ponerla en lista_tmp
	int elementos_en_lista;

	printf("BarajarLista: Barajando la lista...\n");

	for (i = 0; i < numeroElementos; i++){
		int j = 0;
		long indiceAleatorio = 0;

		elementos_en_lista = numeroElementos - i;

		/*Obtenemos indice aleatorio*/
		indiceAleatorio = IndiceAleatorio(elementos_en_lista);

		elem = Lista_Primero(lista);

		assert(elem != NULL);

		/*Buscamos un elemento a sacar de la lista*/
		for (elem = Lista_Primero(lista); elem != NULL; elem = Lista_Siguiente(lista, elem)) {

			if (j == indiceAleatorio) {
#ifdef IMPRIMIR_LISTA
				printf("%lu\n", (long)elem->objeto);
#endif
				break;
			}

			j++;
		}

		if (elem == NULL){
			/*No encontramos el valor (o Buscar esta mal implementada)*/
			fprintf(stderr, "BarajarLista: Error critico en BarajarLista (linea %d)\n", __LINE__);
			exit(-1);
		}

		//Sacamos el elemeno de la lista
		void *objeto = NULL;
		objeto = elem->objeto;


		Lista_Sacar(lista, elem);
		free(elem);
		Lista_InsertarFin(&lista_tmp, objeto);
	}

	/*Aqui lista debe estar vacia...*/
	if (!Lista_Vacia(lista)){
		/*No encontramos el valor (o Buscar esta mal implementada)*/
		fprintf(stderr, "BarajarLista: Error critico, lista no esta vacia (linea %d)\n", __LINE__);
		exit(-1);
	}

	/*lista_tmp contiene elementos insertados de manera aleatoria, reinsertamos en lista*/
	for (elem = Lista_Primero(&lista_tmp); elem != NULL; elem = Lista_Siguiente(&lista_tmp, elem)) {
		Lista_InsertarFin(lista, elem->objeto);
	}

	Lista_SacarTodos(&lista_tmp);

	/**/
	if (!Lista_Vacia(&lista_tmp)){
		/*No encontramos el valor (o Buscar esta mal implementada)*/
		fprintf(stderr, "BarajarLista: Error critico, lista_tmp no esta vacia (linea %d)\n", __LINE__);
		exit(-1);
	}

	printf("BarajarLista: lista barajada exitosamente\n");
	return 0;
}


/**/
void BuscarTodosEnLista(ListaEnlazada *lista, int numeroItems){

	long conteo = (long)numeroItems;
	long i = 0;

	printf("BuscarTodosEnLista: buscando todos los elementos en la lista...\n");
	for (i = 0; i < conteo; i++){
		ElementoLista *elem = NULL;
		elem = Lista_Buscar(lista, (void *)i);
#ifdef IMPRIMIR_LISTA
		printf("BuscarTodosEnLista: Se encontro el elemento %lu\n", (long)elem->objeto);
#endif

		if (elem == NULL){
			fprintf(stderr, "BuscarTodosEnLista. No se encontro el elemento %lu en la lista (linea %d)\n", i, __LINE__);
			exit(-1);
		}
	}

	fprintf(stderr, "BuscarTodosEnLista: prueba finalizo exitosamente.\n");

	return;
}

void CopiarListaHaciaAdelante(ListaEnlazada *fuente, ListaEnlazada *destino){

	ElementoLista *elem;

	for (elem = Lista_Primero(fuente); elem != NULL; elem = Lista_Siguiente(fuente, elem)) {

		Lista_InsertarFin(destino, elem->objeto);
	}


	if (Lista_Conteo(fuente) != Lista_Conteo(destino)){
		fprintf(stderr, "CopiarListaHaciaAdelante: El numero de elementos en lista fuente y destino no son iguales (linea %d).\n", __LINE__);
		exit(-1);
	}

	/*Comparemos...*/
	ElementoLista *elem_fuente = NULL;
	ElementoLista *elem_destino = NULL;

	for (elem_fuente = Lista_Primero(fuente), elem_destino = Lista_Primero(destino); elem_fuente != NULL;
		elem_fuente = Lista_Siguiente(fuente, elem_fuente), elem_destino = Lista_Siguiente(destino, elem_destino)) {	//fuente, elem_destino

		//printf("elemento fuente: %lu, elemento destino: %lu\n", (long)elem_fuente->objeto, (long)elem_destino->objeto);

		if ((long)elem_fuente->objeto != (long)elem_destino->objeto){
			fprintf(stderr, "CopiarListaHaciaAdelante: Objetos fuente y destino no son iguales (linea %d)\n", __LINE__);
			exit(-1);
		}
	}

	fprintf(stderr, "CopiarListaHaciaAdelante: prueba finalizo exitosamente.\n");
	return;
}

void CopiarListaHaciaAtras(ListaEnlazada *fuente, ListaEnlazada *destino){

	ElementoLista *elem;

	for (elem = Lista_Primero(fuente); elem != NULL; elem = Lista_Siguiente(fuente, elem)){
		Lista_InsertarInicio(destino, elem->objeto);
	}

	if (Lista_Conteo(fuente) != Lista_Conteo(destino)){
		fprintf(stderr, "CopiarListaHaciaAtras: El numero de elementos en lista fuente y destino no son iguales.\n");
		exit(-1);
	}

	/*Comparemos...*/
	ElementoLista *elem_fuente = NULL;
	ElementoLista *elem_destino = NULL;

	for (elem_fuente = Lista_Primero(fuente), elem_destino = Lista_Ultimo(destino); elem_fuente != NULL;
		elem_fuente = Lista_Siguiente(fuente, elem_fuente), elem_destino = Lista_Anterior(destino, elem_destino)) {	//fuente, elem_destino

		if (elem_fuente->objeto != elem_destino->objeto){
			fprintf(stderr, "CopiarListaHaciaAtras: Objetos fuente y destino no son iguales (linea %d.\n", __LINE__);
			exit(-1);
		}
	}

	fprintf(stderr, "CopiarListaHaciaAtras: prueba finalizo exitosamente.\n");
	return;
}


void CopiarListaPares(ListaEnlazada *lista, ListaEnlazada *listaPar){

	ElementoLista *elem;

	/*Copiamos toda la lista*/
	for (elem = Lista_Primero(lista); elem != NULL; elem = Lista_Siguiente(lista, elem)){
		Lista_InsertarFin(listaPar, elem->objeto);
	}

	ElementoLista *aEliminar = NULL;
	int eliminar = FALSE;

	/*Sacamos los eelementos impares*/
	for (elem = Lista_Primero(listaPar); elem != NULL; elem = Lista_Siguiente(listaPar, elem)){

		if (eliminar){
			free(aEliminar);
			eliminar = FALSE;
		}


		if (elem == NULL){
			fprintf(stderr, "CopiarListaPares: Error al acceder al elemento\n");
			exit(-1);
		}

		long valor = (long)elem->objeto;


		if (valor % 2 != 0){
			Lista_Sacar(listaPar, elem);
			//Copiamos el puntero para eliminarlo en la siguiente corrida (despues que hayamos encontrado el siguiente.
			aEliminar = elem;
			eliminar = TRUE;
		}
	}

	//Eliminamos el ultimo elemento.	
	if (eliminar){
		free(aEliminar);
		eliminar = FALSE;
	}


	/*Verificar que solo tengamos pares*/
#ifdef IMPRIMIR_LISTA
	ImprimirLista(listaPar, Lista_Conteo(listaPar));
#endif

	for (elem = Lista_Primero(listaPar); elem != NULL; elem = Lista_Siguiente(listaPar, elem)){
		long valor = (long)elem->objeto;
		if (valor % 2 != 0){
			fprintf(stderr, "CopiarListaPares: Error, se encontro un elemento impar (%lu) en la lista par (linea %d)\n", valor, __LINE__);
			exit(-1);
		}
	}

	printf("CopiarListaPares: Prueba finalizo exitosamente.\n");

}


void IntercambiarElementos(ListaEnlazada *lista, ElementoLista **elemento1, ElementoLista **elemento2){

	ElementoLista *anteriorElem1 = Lista_Anterior(lista, *elemento1);
	ElementoLista *anteriorElem2 = Lista_Anterior(lista, *elemento2);
	ElementoLista *siguienteElem2 = Lista_Siguiente(lista, *elemento2);


	long valor_anterior_elem2 = (long)(anteriorElem2)->objeto;
	//long valor_siguiente_elem2 = (long)(siguienteElem2)->objeto;

	//printf(" elem1 %lu\n", (long)(*elemento1)->objeto);
	//printf(" elem2 %lu\n", (long)(*elemento2)->objeto);	

	long valor_elem1 = (long)(*elemento1)->objeto;
	long valor_elem2 = (long)(*elemento2)->objeto;

	//Sacamos (y se libera memoria)
	Lista_Sacar(lista, *elemento1);
	Lista_Sacar(lista, *elemento2);

	free(*elemento1);
	free(*elemento2);

	//printf("antes del swap\n");
	//ImprimirLista(lista, Lista_Conteo(lista));

	/*elemento 2*/
	if (anteriorElem1 == NULL){
		/*elem1 es el primer elemento de la lista*/
		Lista_InsertarInicio(lista, (void *)valor_elem2);
		*elemento2 = Lista_Primero(lista);
		//ImprimirLista(lista, Lista_Conteo(lista));
	}
	else{


		Lista_InsertarDespues(lista, (void *)valor_elem2, anteriorElem1);
		*elemento2 = Lista_Siguiente(lista, anteriorElem1);
		//ImprimirLista(lista, Lista_Conteo(lista));

	}


	/*elemento 1*/
	if (anteriorElem2 == NULL){
		/*elem2 es el primer elemento de la lista*/
		Lista_InsertarInicio(lista, (void *)valor_elem1);
		*elemento1 = Lista_Primero(lista);
		//ImprimirLista(lista, Lista_Conteo(lista));
	}
	else{
		/*El elemento2 siempre es cambiado correctamente
		*Sin embargo, puede darse el caso que el elemento1
		*tenga como elemento anterior al elemento2 (si no es cabeza de la lista),
		*pero a este punto elemento1 ya cambio de posicion, y no tendra como padre/hijo
		*al elemento2*/
		if (valor_anterior_elem2 == valor_elem1){

			if (siguienteElem2 == NULL){	/*elemento2 era ultimo de la lista*/
				Lista_InsertarFin(lista, (void *)valor_elem1);
				*elemento1 = Lista_Ultimo(lista);
			}
			else{
				Lista_InsertarAntes(lista, (void *)valor_elem1, siguienteElem2);
				*elemento1 = Lista_Anterior(lista, anteriorElem2);
			}

			//ImprimirLista(lista, Lista_Conteo(lista));
		}
		else{

			Lista_InsertarDespues(lista, (void *)valor_elem1, anteriorElem2);
			*elemento1 = Lista_Siguiente(lista, anteriorElem2);

		}
	}
	//printf("despues del swap\n");
	//ImprimirLista(lista, Lista_Conteo(lista));

	return;
}


void OrdenarListaAscendente(ListaEnlazada *lista){
	long numeroElementos = Lista_Conteo(lista);

	int i = 0;

#ifdef IMPRIMIR_LISTA
	printf("Lista antes de ordenar:\n");
	ImprimirLista(lista, Lista_Conteo(lista));
#endif

	ElementoLista *actual, *siguiente, *minimoActual, *elem;
	for (i = 0; i < numeroElementos; i++){

		//printf(" i %d\n", i);

		//Sacar el siguiente elemento a comparar
		if (i == 0){
			actual = Lista_Primero(lista);
			minimoActual = actual;
		}
		else{
			int j = 0;
			for (j = 0; j < i; j++){

				//printf("j = %d\n",j);
				if (j == 0){
					siguiente = Lista_Primero(lista);
					siguiente = Lista_Siguiente(lista, siguiente);
				}
				else{
					siguiente = Lista_Siguiente(lista, siguiente);
				}
			}
			actual = siguiente;
			minimoActual = actual;
			//printf("Siguiente %lu\n", (long)siguiente->objeto);	
		}

		//siguiente = Lista_Siguiente(lista, actual);
		//printf("Siguiente %lu\n", (long)siguiente->objeto);

		int minimo_cambio = FALSE;
		for (elem = actual; elem != NULL; elem = Lista_Siguiente(lista, elem)){

			long valor_elem = (long)elem->objeto;
			long valor_min = (long)minimoActual->objeto;

			if (valor_elem < valor_min){
				minimoActual = elem;
				//printf("Min: %lu, elem: %lu, actual %lu\n", valor_min, valor_elem, (long)actual->objeto);
				minimo_cambio = TRUE;
			}
			else{
				//printf("Min: %lu, elem: %lu, actual %lu\n", valor_min, valor_elem, (long)actual->objeto);
			}
		}

		//Aqui encontramos el minimo, 
		//printf("Minimo Actual %lu\n", (long)minimoActual->objeto);
		//printf("Actual %lu\n", (long)actual->objeto);

		//Si valor_elem == valor_min Quiere decir que el minimo lo encontramos de inmediato
		if (minimo_cambio){

			//TODO: Intercambiamos el minimo y el actual
			IntercambiarElementos(lista, &actual, &minimoActual);

			//ImprimirLista(lista, numeroElementos);


		}
		else{
			//ImprimirLista(lista, numeroElementos);
		}


		//Aqui actual y minimoActual son punteros liberados (IntercambiarElementos los libero)

	}
#ifdef IMPRIMIR_LISTA
	printf("OrdenarLista: despues de ordenar:\n");
	ImprimirLista(lista, Lista_Conteo(lista));
#endif

	for (elem = Lista_Primero(lista); elem != NULL; elem = Lista_Siguiente(lista, elem)){
		siguiente = Lista_Siguiente(lista, elem);

		if (siguiente != NULL){
			if (siguiente->objeto < elem->objeto){
				printf("OrdenarLista: los elementos %lu y %lu no estan en orden ascendente\n", (long)siguiente->objeto, (long)elem->objeto);
			}
		}

	}

	printf("OrdenarLista: Prueba de ordernar lista exitosa\n");
}





void RealizarPruebas(int numeroElementos)
{
	/*Creamos una lista*/
	ListaEnlazada lista, lista2, lista3, listaPares;



	/*Inicializamos la lista*/
	memset(&lista, 0, sizeof(ListaEnlazada));
	Lista_Inicializar(&lista);

	memset(&lista2, 0, sizeof(ListaEnlazada));
	Lista_Inicializar(&lista2);

	memset(&lista3, 0, sizeof(ListaEnlazada));
	Lista_Inicializar(&lista3);

	memset(&listaPares, 0, sizeof(ListaEnlazada));
	Lista_Inicializar(&listaPares);

	/*gLista_InsertarFin(&lista, (void*)2);
	Lista_InsertarFin(&lista, (void*)9);
	Lista_InsertarFin(&lista, (void*)5);
	Lista_InsertarFin(&lista, (void*)4);
	Lista_InsertarFin(&lista, (void*)3);
	Lista_InsertarFin(&lista, (void*)6);
	Lista_InsertarFin(&lista, (void*)0);

	Lista_InsertarFin(&lista, (void*)8);
	Lista_InsertarFin(&lista, (void*)1);
	Lista_InsertarFin(&lista, (void*)7);
	OrdenarLista(&lista);
	exit(0);*/

	/*Llenamos la lista*/
	LlenarLista(&lista, numeroElementos);

	/*Barajar los elementos dentro de la lista*/
	BarajarLista(&lista, numeroElementos);

	/*Buscar todos en lista*/
	BuscarTodosEnLista(&lista, numeroElementos);

	/*Copiar lista prueba*/
	CopiarListaHaciaAdelante(&lista, &lista2);
	CopiarListaHaciaAtras(&lista, &lista3);
	CopiarListaPares(&lista, &listaPares);


	/*Finalemente ordenamos la lista*/
	OrdenarListaAscendente(&lista);


	return;

}



int main(int argc, char *argv[])
{

	if (argc < 2){
		fprintf(stderr, "Por favor ingrese el numero de elementos como argumento ej.: ./prueba 1234");
		exit(-1);
	}

	int elementos = atoi(argv[1]);
	RealizarPruebas(elementos);
	return 0;
}
