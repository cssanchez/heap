#include "heap.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_comp(const void* a, const void* b){
	if(*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;
}


void pruebas_heapify(){
	printf("PRUEBAS HEAPIFY \n");
	int a = 4, b = 2, c = 5,d = 1, e = 9, f = 23,g = 8, h = 50, i = 16;

	void* vec_prueba[] = {&a,&b,&c,&d,&e,&f,&g,&h,&i};
	size_t cantidad = 9;
	printf("Vector antes del heapify: ");
	for (int i = 0; i < cantidad; ++i){
		//printf("ERROR \n");
		printf("%i /", *(int*)vec_prueba[i]);
	}	
	printf("\n");
	heapify(vec_prueba, func_comp, cantidad);
	printf("Despues: ");
	for (int i = 0; i < cantidad; ++i){
		//printf("ERROR \n");
		printf("%i /", *(int*)vec_prueba[i]);
	}
	printf("\n");
}

void pruebas_heapsort(){
	printf("PRUEBAS HEAPSORT \n");
	int a = 4, b = 2, c = 5,d = 1, e = 9, f = 23,g = 8, h = 50, i = 16;

	void* vec_prueba[] = {&a,&b,&c,&d,&e,&f,&g,&h,&i};
	size_t cantidad = 9;
	printf("Vector antes del heapsort: ");
	for (int i = 0; i < cantidad; ++i){
		//printf("ERROR \n");
		printf("%i /", *(int*)vec_prueba[i]);
	}
	printf("\n");
	heap_sort(vec_prueba, cantidad, func_comp);
	printf("Despues: ");
	for (int i = 0; i < cantidad; ++i){
		//printf("ERROR \n");
		printf("%i /", *(int*)vec_prueba[i]);
	}
	printf("\n");
}

void pruebas_heap_crear_arr(){
	
	printf("PRUEBAS CREAR HEAP CON ARREGLO\n");
	int a = 4, b = 2, c = 5,d = 1, e = 9, f = 23;
	size_t cantidad = 6;
	void** vec_prueba = malloc(cantidad * sizeof(void*));
	vec_prueba[0] = &a;
	vec_prueba[1] = &b;
	vec_prueba[2] = &c;
	vec_prueba[3] = &d;
	vec_prueba[4] = &e;
	vec_prueba[5] = &f;

	heap_t* heap = heap_crear_arr(vec_prueba,cantidad,func_comp);

	print_test("La cantidad del heap es 6 ", heap_cantidad(heap) == 6);
	print_test("El maximo del heap es 23",heap_ver_max(heap) ==&f);
	print_test("Desencolo el 23",heap_desencolar(heap) == &f);
	print_test("El maximo del heap es 9",heap_ver_max(heap) == &e);
	print_test("La cantidad del heap es 5", heap_cantidad(heap) == 5);
	print_test("Desencolo el 9",heap_desencolar(heap) == &e);
	print_test("Desencolo el 5",heap_desencolar(heap) == &c);
	print_test("Desencolo el 4",heap_desencolar(heap) == &a);
	print_test("Desencolo el 2",heap_desencolar(heap) == &b);
	print_test("Desencolo el 1",heap_desencolar(heap) == &d);
	print_test("El heap esta vacio", heap_esta_vacio(heap));
	print_test("Ver max del heap es NULL", heap_ver_max(heap) == NULL);

	heap_destruir(heap,NULL);
}


void pruebas_heap_alumno(){

	heap_t* heap = heap_crear(func_comp);	
	print_test("El heap esta vacio", heap_esta_vacio(heap));
	print_test("Ver max del heap es NULL", heap_ver_max(heap) == NULL);
	int a = 5, b = 6, c = 8, d = 7, e = 10;
	print_test("Encolo el primer elemento (a)",heap_encolar(heap, &a));
	print_test("El maximo del heap es a ",heap_ver_max(heap) == &a);
	print_test("Encolo el segundo elemento (b)", heap_encolar(heap,&b));
	print_test("El maximo del heap es el segundo elemento (b): ", heap_ver_max(heap) == &b);
	
	print_test("La cantidad del heap es 2", heap_cantidad(heap) == 2);
	print_test("Encolo el tercer elemento (c): ", heap_encolar(heap,&c));
	
	print_test("El maximo del heap es el tercer elemento (c)", heap_ver_max(heap) == &c);
	print_test("Encolo el cuarto elemento (d) ", heap_encolar(heap,&d));
	
	print_test("El maximo del heap sigue siendo el tercer elemento (c)", heap_ver_max(heap) == &c);
	print_test("La cantidad del heap es 4", heap_cantidad(heap) == 4);
	print_test("Encolo el quinto elemento (e) ", heap_encolar(heap, &e));
	print_test("El maximo del heap es el quinto elemento", heap_ver_max(heap) == &e);
	print_test("Desencolo", heap_desencolar(heap) == &e);
	print_test("Desencolo", heap_desencolar(heap) == &c);
	print_test("Desencolo", heap_desencolar(heap) == &d);
	print_test("Desencolo", heap_desencolar(heap) == &b);
	print_test("Desencolo", heap_desencolar(heap) == &a);
	print_test("El heap esta vacio", heap_esta_vacio(heap));

	pruebas_heapify();
	pruebas_heapsort();
	pruebas_heap_crear_arr();
	heap_destruir(heap,NULL);
}
