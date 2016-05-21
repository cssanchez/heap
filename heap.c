#include "heap.h"
#include <stdlib.h>
#include <stdio.h>


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
	size_t posicion_padre = (posicion - 1) / 2;
	if (heap->cmp(heap->vector[posicion], heap->vector[posicion_padre]) > 0) {
		swap(heap->vector, posicion, posicion_padre);
		upheap(heap, posicion_padre);
	}
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


//usa upheap
/*bool heap_encolar(heap_t *heap, void *elem) {
	if (heap_esta_vacio(heap)) {
		heap->vector[0] = elem;
		return true;
	}
	heap->vector[heap->cantidad] = elem;
	upheap(heap, heap->cantidad);
}*/

int main(int argc, char const *argv[])
{	char *a = "1a", *b = "2b";
	void *vector[] = {a, b};
	printf("[%s, %s]\n", (char*)vector[0],  (char*)vector[1]);

	swap(vector, 0, 1);
	printf("[%s, %s]\n", (char*)vector[0],  (char*)vector[1]);
	return 0;
}