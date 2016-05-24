#include "heap.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_comp (const void* a, const void* b){

	if(a > b) return 1;
	else if (a < b) return -1;
	else return 0;
}

void pruebas_heap_alumno(){

	heap_t* heap = heap_crear(func_comp);	

	int a = 5, b = 6; //c = 7;

	print_test("askaskba", func_comp(&a,&b) == -1);
	print_test("Encolo el primer elemento (a)",heap_encolar(heap, &a));
	print_test("El maximo del heap es: ",heap_ver_max(heap) == &a);
	print_test("Encolo el segundo elemento (b)", heap_encolar(heap,&b));
}