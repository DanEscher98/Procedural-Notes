#include <stdio.h>
#include <stdlib.h>
#define node_size (node*)malloc(sizeof(node))

typedef struct node node;
struct node {
	int value;
	node *next;
};

typedef struct list list;
struct list {
	int length;
	node head;
};

// Basic List Functions
list initList();
node createNode();
void deleteNode(list, int);
int  pop(list);
void push(list, int);
void append(list, int);


// Other List Functions
void printList(list);
list orderedlist_to_set(list);

int main(void) {
	int values[10] = {1,2,3,4,5,6,7,8,9,10};
	list lista_a = initList();
	for (int i=0; i < 10; i++) {
		push(lista_a, values[i]);
	}
	lista_a = orderedlist_to_set(lista_a);
	printList(lista_a);
	return 0;
}

//###############################################
//## Basic List Functions #######################

list initList() {
	list new_list;
	new_list.length = 0;
	new_list.head = (node){.next=NULL};
	return new_list;
}

node createNode(int data) {
	node new_node = *node_size;
	new_node.value = data;
	new_node.next = NULL;
	return new_node;
}

void deleteNode(list list_in, int position) {
	node current = list_in.head;
	if (position == 1) {
		pop(list_in);
	} else if (position < list_in.length) {
		for (int i=1; i < position; i++) {
			current = *current.next;
		}
		// Falta implementar free()
		current.next = current.next->next;
	}
}

void append(list list_in, int data) {
	node current = list_in.head;
	node new_node = createNode(data);
	printf("Val: %d - Len: %d\n", new_node.value, list_in.length);
	if (list_in.length == 0) {
		list_in.head = new_node;
	} else {
		while(current.next != NULL) {
			printf("%d - ", current.value);
			current = *current.next;
		}
		//current.next = node_size;
	}
	current.next = &new_node;
	printf("Len1: %d \n", list_in.length);
	list_in.length = list_in.length + 1;
	printf("Len2: %d \n", list_in.length);
}

void push(list list_in, int data) {
	node new_node = createNode(data);
	new_node.value = data;
	new_node.next = &list_in.head;
	list_in.head = new_node;
	list_in.length += 1;
}

int pop(list list_in) {
	int data = list_in.head.value;
	node aux = *list_in.head.next;
	// Implement function free
	list_in.head = aux;
	return data;
}


//###############################################
//## Extra Function for Lists ###################

void printList(list list_in) {
	node current = list_in.head;
	printf("(");
	for (int i=0; i < list_in.length; i++) {
		printf("%d", current.value);
		if (i + 1 < list_in.length) printf(" ~> ");
		current = *current.next;
	}
	printf(")\n");
}

list orderedlist_to_set(list list_in) {
	node current = list_in.head;
	list list_out = list_in;
	int i=0;
	while (current.next) {
		if (current.value == current.next->value) {
			deleteNode(list_out, i+1);
		} else {
			current = *current.next; i++;
		}
	}
	return list_in;
}
