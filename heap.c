#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define TAM_INICIAL 15
#define FACTOR_REDIMENSION 2 // Numero por el que se multiplica o divide el tamanio al redimensionar
#define DIVISOR_ACHIQUE 4 // Si heap->cantidad se vuelve menor que heap->tam/DIVISOR_ACHIQUE, se redimensiona


// Estructura.

struct heap {
	void **vector;
	size_t cantidad;
	size_t tam;
	cmp_func_t cmp;
};


// Auxiliares.

void swap(void **vector, size_t posicion_a, size_t posicion_b) {
	void* aux_a = vector[posicion_a];
	vector[posicion_a] = vector[posicion_b];
	vector[posicion_b] = aux_a;
}


void upheap(heap_t *heap, size_t posicion) {
	//printf("ERROR\n");
	size_t posicion_padre = (posicion - 1) / 2;
	//printf("ERROR\n");
	printf ("POSICION: %ld\n", posicion);
	printf ("PISICION PADRE: %ld\n", posicion_padre);
	if (heap->cmp(heap->vector[posicion], heap->vector[posicion_padre]) < 0) {
		swap(heap->vector, posicion, posicion_padre);
		upheap(heap, posicion_padre);
	}
	return;
}


// Primitivas.

heap_t *heap_crear(cmp_func_t cmp) {
	heap_t *heap = malloc(sizeof(heap_t));
	if (!heap) return NULL;
	heap->vector = malloc(sizeof(void*) * TAM_INICIAL);
	if (!heap->vector) {
		free(heap);
		return NULL;
	}
	heap->cantidad = 0;
	heap->tam = TAM_INICIAL;
	return heap;
}

bool heap_encolar(heap_t *heap, void *elem) {
	if (heap_esta_vacio(heap)) {
		heap->vector[0] = elem;
		heap->cantidad++;
		return true;
	}
	heap->vector[heap->cantidad] = elem;
	//printf("ERROR\n");
	upheap(heap, heap->cantidad);
	printf("ERROR\n");
	return true;
}

void *heap_ver_max(const heap_t *heap){
	if (heap->cantidad == 0) return NULL;
	return heap->vector[0];
}

bool heap_esta_vacio(const heap_t *heap){
	if (heap->cantidad == 0) return true;
	return false;
}

size_t heap_cantidad(const heap_t *heap){
	return heap->cantidad;
}