#include "vec_list.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//#####################################
//## Vector Functions #################

vector initVector(int length, bool zeros, bool sorted)
{
	srand((unsigned int)time(NULL));
	vector new_vector = (vector) { .length = length };
	new_vector.values = malloc(sizeof(int) * (unsigned int)length);
	if (zeros) {
		for (int i = 0; i < length; i++) {
			new_vector.values[i] = 0;
		}
	} else if (sorted) {
		int value = 0;
		for (int i = 0; i < length; i++) {
			value += rand() % 6;
			new_vector.values[i] = value;
		}
	} else {
		int max = length / 2;
		for (int i = 0; i < length; i++) {
			new_vector.values[i] = rand() % max;
		}
	}
	return new_vector;
}

//#####################################
//## List Functions ###################

// Dynamic memory allocation

#define node_size (node*)malloc(sizeof(node))

list initList(void)
{
	list new_list = (list) { .length = 0, .head = node_size };
	new_list.head = NULL;
	return new_list;
}

void freeList(list ls)
{
	node* head = ls.head;
	while (head) {
		head = deleteThisNode(head);
	}
	// free(ls.head);
	// ls.head = NULL;
	ls.length = 0;
}

list initRandomList(int length, bool sorted)
{
	srand((unsigned int)time(NULL));
	list new_ls = initList();
	if (sorted) {
		// The sorted list is in reverse order
		int value = 0;
		for (int i = 0; i < length; i++) {
			value += rand() % 6;
			new_ls = prependData(new_ls, value);
		}
	} else {
		int value, max = length / 2;
		for (int i = 0; i < length; i++) {
			value = rand() % max;
			new_ls = prependData(new_ls, value);
		}
	}
	return new_ls;
}

node* getNextNode(node* a)
{
	if (a == NULL) {
		return NULL;
	} else {
		return a->next;
	}
}

node* deleteThisNode(node* a)
{
	if (a == NULL) {
		return NULL;
	} else {
		node* aux = getNextNode(a);
		free(a);
		return aux;
	}
}

node* newNode(node* link, int value)
{
	node* new_node = node_size;
	if (!new_node)
		return NULL;
	new_node->value = value;
	new_node->next = link;
	return new_node;
}

// Basic operations

int headList(list ls)
{
	if (ls.head == NULL) {
		perror("Empty list doesn't have head");
		exit(1);
	} else {
		return ls.head->value;
	}
}

list prependData(list ls, int value)
{
	ls.head = newNode(ls.head, value);
	ls.length++;
	return ls;
}

list appendData(list ls, int value)
{
	node* new_node = newNode(NULL, value);
	// A initialized structure is returned
	if (!ls.head)
		return (list) { .length = 1, .head = new_node };
	else {
		node* head = ls.head;
		while (head->next) {
			head = getNextNode(head);
		}
		head->next = new_node;
		ls.length++;
		return ls;
	}
}

int numberOfOccurrences(list ls, int value)
{
	node* head = ls.head;
	int count = 0;
	while (head != NULL) {
		if (value == head->value) {
			count++;
		}
		head = getNextNode(head);
	}
	return count;
}

list deleteClones(list ls)
{
	node* head = ls.head;
	int value;
	list new_ls = initList();
	while (head != NULL) {
		value = head->value;
		if (numberOfOccurrences(ls, value) == 1) {
			new_ls = prependData(new_ls, value);
		}
		head = getNextNode(head);
	}
	return new_ls;
}

list intersection(vector vec_x, list ly)
{
	list new_ls = initList();
	node *head, *initial = ly.head;
	int vec_val, ls_val;
	bool mainHead;
	for (int i = 0; i < vec_x.length; i++) {
		head = initial;
		mainHead = true;
		vec_val = vec_x.values[i];
		while (head != NULL) {
			ls_val = head->value;
			if (vec_val == ls_val) {
				// printf("Vector: %d List: %d\n", vec_val, ls_val);
				new_ls = prependData(new_ls, vec_val);
				head = deleteThisNode(head);
				if (mainHead) {
					initial = head;
					mainHead = false;
				}
				break;
			}
			head = getNextNode(head);
		}
	}
	return new_ls;
}

//#####################################
//## Convert and Validation Functions #

void printVector(vector vec)
{
	printf("[ ");
	for (int i = 0, count = 1; i < vec.length; i++, count++) {
		printf("%3d", vec.values[i]);
		if (count > 10) {
			count = 0;
			printf("\n");
		}
		if (i + 1 < vec.length)
			printf(", ");
	}
	printf("]\n");
}

void printList(list ls)
{
	node* head = ls.head;
	printf(" ( ");
	for (int count = 1; head != NULL; count++) {
		printf("%4d", head->value);
		head = getNextNode(head);
		if (count > 10) {
			count = 0;
			printf("\n");
		}
		if (head != NULL)
			printf(" → ");
	}
	printf(" )\n");
}

void horizontalLine()
{
	printf("\n#");
	for (int i = 0; i < 75; i++) {
		putc('-', stdout);
	}
	printf("#\n");
}

int parseInt(char* value)
{
	int num;
	char* endptr; // reset error number
	errno = 0;
	// The problems set maxium size at 1000, so the max
	// length of a number is set to 4 digits
	num = (int)strtol(value, &endptr, 10);
	if (errno == ERANGE) {
		fputs("ERR => Number too big\n", stdout);
		exit(1);
	} else if (endptr == value) {
		fputs("ERR => The arg must be an int\n", stdout);
		exit(1); // no character readed
	} else if (*endptr && *endptr != '\n') {
		fputs("ERR => Incorrect char\n", stdout);
		exit(1);
	} else
		return num;
}
