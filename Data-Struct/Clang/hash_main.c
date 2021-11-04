#include <time.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_structures.h"
#include "libraries/safe_io.h"

int main(void) {
	srand(time(NULL));
	hashtable *A_ht = ht_init();
	char *names[] = {
		"John", "Mary", "Giselle",
		"Clark", "Bob", "Susan",
		"Ricky", "Eve", "Max",
		"Grace", "Patrick", "Jim",
		"Irving", "Gretel", "Kim",
		"Jacob", "Maria", "Jonas",
		"Jaspers", "Carlos", "Elias",
		"Maggie", "Rosa", "Javier"};
	int num_names = sizeof(names)/sizeof(char*);
	for (int i=0; i < num_names; i++) {
		ht_set(A_ht, names[i], toString(10+rand()%90));
	}
	ht_print(A_ht);
	return EXIT_SUCCESS;
}
