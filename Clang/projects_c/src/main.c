#include "lib.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	char saludo[5] = { 104, 111, 108, 32, 97 };
	for (int i = 0; i < 5; i++) {
		printf("%c", saludo[i]);
	}
	// int a = 5;
	return EXIT_SUCCESS;
}
