#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
//#include "data_structures.h"
#include "basic_algorithms.h"

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

list initList(void) {
	list new_list = (list){
		.length = 0,
		.head = node_size
	};
	new_list.head = NULL;
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

void freeList(list ls) {
	node *aux, *head = ls.head;
	while (head) {
		aux = head->next;
		free(head);
		head = aux;
	}
}

node *newNode(node *link, int value) {
	node *new_node = node_size;
	if (!new_node) return NULL;
	new_node->value = value;
	new_node->next = link;
	return new_node;
}

// Basic operations

int headList(list ls) {
	if (ls.head == NULL) {
		perror("Empty list doesn't have head");
		exit (1);
	} else {
		return ls.head->value;
	}
}

list insertNodeInPosition(list ls, int position, int value) {
	node *head = ls.head;
	while (position > 0) {
		position--;
		head = getNextNode(head);
	}
	head = newNode(head, value);
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
	printf("Error: %d => %s\n",
			errno, strerror(errno));
	exit (1);
}

list prependData(list ls, int value) {
	ls.head = newNode(ls.head, value);
	ls.length++;
	return ls;
}

node *newNodeAfter(node *link, int value) {
	node *new_node = newNode(NULL, value);
	if (!new_node) return NULL;
	if (!link) return new_node;
	node *last = link;
	while (last->next != NULL) {
		last = getNextNode(last);
	}
	last->next = new_node;
	return link;
}

list appendData(list ls, int value) {
	node *new_node = newNode(NULL, value);
	if (!ls.head) return (list){ 
		.length = 1, 
		.head = new_node
	}; else {
		node *head = ls.head;
		while (head->next) {
			head = getNextNode(head);
		}
		head->next = new_node;
		ls.length++;
		return ls;
	}
}

//list appendData(list ls, int value) {
//	node *head = ls.head;
//	//for (int i=0; i < ls.length-1; i++) {
//	//	head = getNextNode(head);
//	//}
//	printList(ls);
//	while(head != NULL) {
//		printf("Address of head: %p\n", &head);
//		head = getNextNode(head);
//	}
//	head = newNode(head, value);
//	printf("Last value: %d\n", head->value);
//	if (valueInList(ls, value)) {
//		printf("Append Success!\n");
//	} else {
//		printf("Append Fail :/\n");
//	}
//	ls.length++;
//	return ls;
//}

// Miscellaneous

list deleteValue(list ls, int value) {
	node *head = ls.head;
	while (head != NULL) {
		if (head->value == value) {
			head = deleteThisNode(head);
			ls.length--;
		} else {
			head = getNextNode(head);
		}
	}
	return ls;
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
		//printf("\tValue: %d\t", head->value);
		//printf("\tAddress: %p\n", head);
		printf("%d", head->value);
		head = getNextNode(head);
		if (head != NULL) printf(" → ");
	}
	printf(")\n");
}

// Conversion

vector listToVector(list ls) {
	node *head = ls.head;
	vector new_vector = initVector(ls.length);
	for (int i=0; i<ls.length; i++) {
		if (head == NULL) exit(1);
		new_vector.values[i] = head->value;
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
