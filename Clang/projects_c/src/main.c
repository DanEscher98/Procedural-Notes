#include "lib.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	int a = 5;
	int* ptr_a = &a;
	printf("%p ~> %p\n", (void*)ptr_a, (void*)&a);
	// 4.1 pointers
	printf("Void pointer: %lu\n", sizeof(void*));
	printf("Int pointer: %lu\n", sizeof(int*));
	char* vec_c = "hola\0";
	for (char* v = vec_c; *v; v++) {
		printf("%p: %c\n", (void*)v, *v);
	}

	int vec_i[5] = { 1, 2, 3, 4, 5 };

	for (int* v = vec_i; *v; v++) {
		printf("%p: %d\n", (void*)v, *v);
	}
	// int a = 5;
	return EXIT_SUCCESS;
}
