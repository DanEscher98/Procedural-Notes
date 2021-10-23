//#####################################
//## Vector Functions #################

typedef struct Vector {
	int *values;
	int length;
} vector;

vector initVector(int);

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

// Dynamic memory allocation

list initList(void);

node *getNextNode(node*);

node *deleteThisNode(node*);

node *newNode(node*, int);

node *newNodeAfter(node*, int);

// Basic operations

int headList(list);

void freeList(list);

list deleteNodeInPosition(list, int);

list insertNodeInPosition(list, int, int);

list appendData(list, int);

list prependData(list, int);


//#####################################
//## Binary Tree Functions ############

typedef struct BinaryTree {
	struct BinaryTree *right;
	struct BinaryTree *left;
} tree;

//#####################################
//## Convert and Validation Functions #

// Printing
void printVector(vector);

void printList(list);

//void printTree(tree);

// Conversion
vector listToVector(list);

list vectorToList(vector);

// list listToSet(list);

//tree listToOrdTree(list);
//
//list treeToList(tree);

// Validation
void validVector(vector);

void validList(list);

//void validSet(list);
//
//void validTree(tree);
