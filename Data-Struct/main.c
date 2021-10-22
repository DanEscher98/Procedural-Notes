#include <stdio.h>
#include "libraries/safe_io.h"
#include "data_structures.h"

int main(void) {
	list ls_a = initList();
	printf("OK-0\n");
	ls_a = pushData(ls_a, 1);
	ls_a = pushData(ls_a, 2);
	ls_a = pushData(ls_a, 3);
	printList(ls_a);
	printf("First value: %d\n", headList(ls_a));
	printf("List length: %d\n", ls_a.length);
	return 0;
}
