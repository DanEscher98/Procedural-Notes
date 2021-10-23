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
	//ls_a = appendData(ls_a, 10);
	//printf("New length: %d\n", ls_a.length);
	//vector vec = initVector(ls_a.length);
	//vec = listToVector(ls_a);
	//printVector(vec);
	//node *a_head = ls_a.head;
	//ls_a.head = deleteThisNode(ls_a.head);
	//printf("Deleted value %d\n", a_head->value);
	//printf("The next value: %d\n",
	//		getNextNode(ls_a.head)->value);
	return 0;
}
