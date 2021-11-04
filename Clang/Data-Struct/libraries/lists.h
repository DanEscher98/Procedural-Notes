#define node_size (node*)malloc(sizeof(node))

typedef struct vector vector;
struct vector {
	int length;
	float *values;
};

typedef struct node node;
struct node {
	int data;
	node *next;
};

typedef int (*intFunc)(int);
typedef double (*biFunc)(double, int);

// Basic Functions over vectors
vector get_vector();

// Basic Functions over Lists
node *initList();

void push(node**, int);

void append(node**, int);

void deleteNode(node**, int);

void printList(node*);

int length(node*);

// Higer order functions over Lists
void map(intFunc, node*);

double foldl(biFunc, double, node*);
