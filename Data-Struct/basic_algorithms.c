#include <stdlib.h>
#include <stdio.h>
#include "data_structures.h"

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

list deleteValue(list ls, int target) {
	// Modify to work as mutable function
	node *head = ls.head;
	list new_ls = initList();
	int value;
	while (head != NULL) {
		value = head->value;
		if (value != target) {
			new_ls = appendData(new_ls, value);
		}
		head = getNextNode(head);
	}
	return new_ls;
}

//#####################################
//## Set Related Functions ############

list intersectionList(list ls_a, list ls_b) {
	// !!! The list b is modified
	list ls_new = initList();
	node *head_a = ls_a.head, *head_b = ls_b.head;
	//if (head_a != NULL && head_b != NULL) {
	while (head_a != NULL) {
		head_b = ls_b.head;
		while (head_b != NULL) {
			if (head_b->value == head_a->value) {
				ls_new = prependData(ls_new, head_a->value);
				head_b = deleteThisNode(head_b);
				printf("Prepended value: %d\n", head_b->value);
				break;
			} else {
				head_b = getNextNode(head_b);
			}
		}
		head_a = getNextNode(head_a);
	}
	//}
	freeList(ls_b);
	return ls_new;
}
