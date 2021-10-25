#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "data_structures.h"
#include "basic_algorithms.h"
//#include "libraries/safe_io.h"
#define node_size (node*)malloc(sizeof(node))

int main(void) {
	srand(time(NULL));
	list ls_a = initList();
	list ls_b = initList();
	int size = 10+rand()%100;
	for (int i=0; i<size; i++) {
		ls_a = prependData(ls_a, rand()%(size/2));
	}
	ls_b = deleteValue(ls_a, 5);
	printList(ls_a);
	printList(ls_b);
	return 0;
}
