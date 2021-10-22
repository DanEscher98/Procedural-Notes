#include <stdio.h>
#include <stdlib.h>
#include "data_structures.h"

//#####################################
//## Vector Functions #################

vector initVector(int length) {
	vector new_vector = (vector){ .length = length };
	new_vector.values = malloc(sizeof(int)*length);
	for (int i=0; i<length; i++) {
		new_vector.values[i] = 0;
	}
	return new_vector;
}

//#####################################
//## List Functions ###################

// Dynamic memory allocation

#define node_size (node*)malloc(sizeof(node))

node initNode(void) {
	node new_node = (node){
		.data = 0,
		.next = node_size };
	new_node.next = NULL;
	return new_node;
}

list initList(void) {
	list new_list = (list){
		.length = 0,
		.head = NULL
	};
	return new_list;
}

node *getNextNode(node *a) {
	if (a == NULL) {
		return NULL;
	} else {
		return a->next;
	}
}

node *deleteThisNode(node *a) {
	if (a == NULL) {
		return NULL;
	} else {
		node *aux = getNextNode(a);
		free(a);
		a = aux;
		return a;
	}
	exit (1);
}

node *insertNode(node *head, int value) {
	node new_node = initNode();
	new_node.data = value;
	if (head != NULL) {
		new_node.next = head->next;
	}
	head = &new_node;
	printf("Inserted value: %d - ", head->data);
	return head;
}

// Basic operations

int headList(list ls) {
	if (ls.head == NULL) {
		printf("Empty list doesn't have head.\n");
		exit (1);
	} else {
		return ls.head->data;
	}
}

list insertNodeInPosition(list ls, int position, int value) {
	node *head = ls.head;
	while (position > 0) {
		position--;
		head = getNextNode(head);
	}
	head = insertNode(head, value);
	ls.length++;
	return ls;
}

list deleteNodeInPosition(list ls, int position) {
	node *head = ls.head;
	if (head == NULL && ls.length == 0) {
		return ls;
	} else {
		while (position != 0) {
			position--;
			head = head->next;
		}
		head = deleteThisNode(head);
		ls.length--;
		return ls;
	}
	exit (1);
}

list appendData(list ls, int value) {
	node *head = ls.head;
	for (int i=0; i < ls.length; i++) {
		head = getNextNode(head);
	}
	head = insertNode(head, value);
	if (ls.length == 0) {
		printf("First value for a empty list.");
		ls.head = head;
	}
	printf("Append value: %d\n", ls.head->data);
	ls.length++;
	return ls;
}

list pushData(list ls, int value) {
	node **init = &ls.head;
	insertNode(ls.head, value);
	ls.head = *init;
	ls.length++;
	return ls;
}

// Miscellaneous

list deleteValue(list ls, int value) {
	node *head = ls.head;
	while (head != NULL) {
		if (head->data == value) {
			head = deleteThisNode(head);
			ls.length--;
		} else {
			head = getNextNode(head);
		}
	}
	return ls;
}

int valueInList(list ls, int value) {
	node *head = ls.head;
	while (head != NULL) {
		if (head->data == value) {
			return 1;
		} else {
			head = getNextNode(head);
		}
	}
	return 0;
}

//#####################################
//## Convert and Validation Functions #

void printVector(vector vec) {
	printf("[");
	for (int i=0; i < vec.length; i++) {
		printf("%d", vec.values[i]);
		if (i + 1 < vec.length) printf(", ");
	}
	printf("]\n");

}

void printList(list ls) {
	node *head = ls.head;
	printf("(");
	while (head != NULL) {
		printf("%d", head->data);
		head = head->next;
		if (head != NULL) printf(" → ");
	}
	printf(")\n");
}

// Conversion

vector listToVector(list ls) {
	node *head = ls.head;
	vector new_vector = initVector(ls.length);
	for (int i=0; i<ls.length; i++) {
		new_vector.values[i] = head->data;
		head = getNextNode(head);
	}
	return new_vector;
}

list vectorToList(vector vec) {
	list new_list = initList();
	for (int i=0; i<vec.length; i++) {
		new_list = appendData(new_list, vec.values[i]);
	}
	return new_list;
}
