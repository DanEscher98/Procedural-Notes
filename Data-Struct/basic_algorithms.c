#include "data_structures.h"
#include <stdlib.h>

int valueInList(list ls, int value) {
	node *head = ls.head;
	while (head != NULL) {
		if (head->value == value) {
			return 1;
		} else {
			head = getNextNode(head);
		}
	}
	return 0;
}

