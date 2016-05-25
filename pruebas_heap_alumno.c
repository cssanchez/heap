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
	int a = 4, b = 2, c = 5,d = 1, e = 9, f = 23;

	void* vec_prueba[] = {&a,&b,&c,&d,&e,&f};
	size_t cantidad = 6;
	heapify(vec_prueba, func_comp, cantidad);
	for (int i = 0; i < cantidad; ++i){
		//printf("ERROR \n");
		printf("%i /", *(int*)vec_prueba[i]);
	}
	printf("\n");
}


void pruebas_heap_alumno(){

	/*heap_t* heap = heap_crear(func_comp);	

	print_test("El heap esta vacio", heap_esta_vacio(heap));
	print_test("Ver max del heap es NULL", heap_ver_max(heap) == NULL);

	int a = 5, b = 6, c = 8, d = 7, e = 10;

	print_test("Encolo el primer elemento (a)",heap_encolar(heap, &a));
	print_test("El maximo del heap es: ",heap_ver_max(heap) == &a);

	print_test("Encolo el segundo elemento (b)", heap_encolar(heap,&b));
	print_test("El maximo del heap es el segundo elemento: ", heap_ver_max(heap) == &b);
	
	print_test("La cantidad del heap es 2", heap_cantidad(heap) == 2);
	print_test("Encolo el tercer elemento (c): ", heap_encolar(heap,&c));
	
	print_test("El maximo del heap es el tercer elemento", heap_ver_max(heap) == &c);
	print_test("Encolo el cuarto elemento (d) ", heap_encolar(heap,&d));
	
	print_test("El maximo del heap sigue siendo el tercer elemento", heap_ver_max(heap) == &c);
	print_test("La cantidad del heap es 4", heap_cantidad(heap) == 4);

	print_test("Encolo el quinto elemento (e) ", heap_encolar(heap, &e));
	print_test("El maximo del heap es el quinto elemento", heap_ver_max(heap) == &e);

	print_test("Desencolo", heap_desencolar(heap) == &e);
	print_test("Desencolo", heap_desencolar(heap) == &c);
	print_test("Desencolo", heap_desencolar(heap) == &d);
	print_test("Desencolo", heap_desencolar(heap) == &b);
	print_test("Desencolo", heap_desencolar(heap) == &a);
	print_test("El heap esta vacio", heap_esta_vacio(heap));*/

	pruebas_heapify();
}