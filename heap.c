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
	if (posicion == 0) return;
	size_t posicion_padre = (posicion - 1) / 2;
	printf ("POSICION: %zu\n", posicion);
	printf ("PISICION PADRE: %zu\n", posicion_padre);
	if (heap->cmp(heap->vector[posicion], heap->vector[posicion_padre]) > 0) {
		swap(heap->vector, posicion, posicion_padre);
		upheap(heap, posicion_padre);
	}
}


size_t max(void** vector, cmp_func_t cmp, size_t posicion_a, size_t posicion_b) {
	if (!posicion_a) return posicion_b;
	if (!posicion_b) return posicion_a;
	return (cmp(vector[posicion_a], vector[posicion_b]) < 0) ? posicion_b : posicion_a;
}


void downheap(void **vector, size_t tam_vector, cmp_func_t cmp, size_t posicion) {
	size_t pos_hijo_izq = (2 * posicion) + 1;
	size_t pos_hijo_der = (2 * posicion) + 2;
	if (pos_hijo_izq >= tam_vector - 1) pos_hijo_izq = false;
	if (pos_hijo_der >= tam_vector - 1) pos_hijo_der = false;
	if (!pos_hijo_izq && !pos_hijo_der) return;
	size_t pos_hijo_mayor = max(vector, cmp, pos_hijo_izq, pos_hijo_der);
	if (cmp(vector[posicion], vector[pos_hijo_mayor]) < 0) {
		swap(vector, posicion, pos_hijo_mayor);
		downheap(vector, tam_vector, cmp, pos_hijo_mayor);
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
	heap->cmp = cmp;
	heap->cantidad = 0;
	heap->tam = TAM_INICIAL;
	return heap;
}


heap_t *heap_crear_arr(void *arreglo[], size_t n, cmp_func_t cmp) {
	heap_t *heap = malloc(sizeof(heap_t));
	if (!heap) return NULL;
	heap->vector = heapify(arreglo, n, cmp); // Modificar segpun como quede heapify
	heap->cmp = cmp;
	heap->cantidad = n;
	heap->tam = n * 2;
	return heap;
}


void heap_destruir(heap_t *heap, void destruir_elemento(void *e)){
	if (destruir_elemento) {
		for (int i = 0; i < heap->cantidad; ++i) {
			destruir_elemento(heap->vector[i]);
		}
	}
	free(heap->vector);
	free(heap);
}


bool heap_encolar(heap_t *heap, void *elem) {
	if (heap_esta_vacio(heap)) {
		heap->vector[0] = elem;
		heap->cantidad++;
		return true;
	}
	heap->vector[heap->cantidad] = elem;
	upheap(heap, heap->cantidad);
	heap->cantidad++;
	for (int i = 0; i < heap->cantidad; ++i)
	{
		printf("%i /", *(int*)heap->vector[i]);
	}
	printf("\n");
	return true;
}


void *heap_desencolar(heap_t *heap) {
	if (heap_esta_vacio(heap)) return NULL;
	void *elem_a_devolver = heap->vector[0];
	heap->vector[0] = heap->vector[heap->cantidad - 1];
	downheap(heap->vector, heap->cantidad, heap->cmp, 0);
	heap->cantidad--;
	for (int i = 0; i < heap->cantidad; ++i)
	{
		printf("%i /", *(int*)heap->vector[i]);
	}
	printf("\n");
	return elem_a_devolver;
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