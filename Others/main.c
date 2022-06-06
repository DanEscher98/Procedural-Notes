#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int *p = malloc(sizeof(int) * 5);
	for (int i=0; i < 5; i++) {
		p[i] = 3;
	}
	if ((p+5) == NULL) {
		printf("NULL");
	}
	free(p);
	return EXIT_SUCCESS;
}
