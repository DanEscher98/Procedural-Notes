#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
#include "safe_io.h"

vector get_vector() {
	vector vec;
	char msg[50];
	vec.length = readInt("Size of vector: ");
	vec.values = malloc(vec.length*sizeof(float));
	for (int i=0; i < vec.length; i++) {
		sprintf(msg, "Value [%d]", i);
		vec.values[i] = readFloat(msg);
	}
	return vec;
}

node *initList() {
	node *head		= NULL;
	return head;
}

void push(node **head, int data) {
	// 1. Allocate node
	node *new_node = node_size;
	// 2. Put in the data
	new_node->data = data;
	// 3. Make next of new node as head
	new_node->next = (*head);
	// 4. Move the head to point to the new node
	(*head) = new_node;
}

void append(node **head, int data) {
	// Same 1. and 2. steps as push
	node *new_node = node_size;
	new_node->data = data;
	new_node->next = NULL;
	// Used to traverse the list
	node *last = (*head);
	if(last == NULL) {
		(*head) = new_node;
		return;
	} else {
		while(last->next != NULL) last = last->next;
		last->next = new_node;
		return;
	}
}

void deleteNode(node **head, int key) {
	node *temp = *head, *prev;
	if(temp != NULL && temp->data == key) {
		(*head) = temp->next;
		free(temp);
		return;
	} else {
		while(temp != NULL && temp->data != key) {
			prev = temp;
			temp = temp->next;
		}
		if(temp == NULL) return;
		else {
			prev->next = temp->next;
			free(temp);
		}
	}
}

void printList(node *node) {
	while(node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void map(intFunc f, node *node) {
	while(node != NULL) {
		node->data = f(node->data);
		node = node->next;
	}
}

double foldl(biFunc f, double e, node *node) {
	while(node != NULL) {
		e = f(e, node->data);
		node = node->next;
	}
	return e;
}

int length(node *node) {
	int count = 0;
	while(node != NULL) {
		count++;
		node = node->next;
	}
	return count;
}
