#include <stdbool.h>

//#####################################
//## Vector Functions #################

typedef struct Vector {
	int *values;
	int length;
} vector;

vector initVector(int, bool, bool);

//#####################################
//## List Functions ###################

typedef struct Node {
	int value;
	struct Node *next;
} node;

typedef struct List {
	int length;
	node *head;
} list;

typedef struct StateList {
	node *link;
	bool change;
} statelist;

// Dynamic memory allocation

list initList(void);

void freeList(list);

list initRandomList(int, bool);

node *getNextNode(node*);

node *deleteThisNode(node*);

node *newNode(node*, int);

// Basic operations

int headList(list);

list prependData(list, int);

list appendData(list, int);

int numberOfOccurrences(list, int);


//#####################################
//## Functions to solve the challeges #
list deleteClones(list);

list intersection(vector, list);

//#####################################
//## Convert and Validation Functions #

// Printing
void printVector(vector);

void printList(list);

void horizontalLine(void);

// Validation
void validVector(vector);

void validList(list);

int parseInt(char *value);
