#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"
//#include "libraries/safe_io.h"
#define node_size (node*)malloc(sizeof(node))

int main(void) {
	list ls_a = initList();
	for (int i=0; i<10; i++) {
		ls_a = prependData(ls_a, i);
	}
	printf("List length: %d\n", ls_a.length);
	printf("The first value: %d\n", headList(ls_a));
	printList(ls_a);
	ls_a = appendData(ls_a, 10);
	printList(ls_a);
	ls_a = insertNodeInPosition(ls_a, 5, 100);
	printf("New Length: %d\n", ls_a.length);
	printList(ls_a);
	ls_a = deleteNodeInPosition(ls_a, 8);
	printList(ls_a);
	ls_a = appendData(ls_a, 10);
	printf("New length: %d\n", ls_a.length);
	vector vec = initVector(ls_a.length);
	vec = listToVector(ls_a);
	printVector(vec);
	vec.values[2] = 115;
	printList(vectorToList(vec));
	freeList(ls_a);
	return 0;
}
