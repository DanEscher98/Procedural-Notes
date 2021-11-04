#define SIZE_NAME 256
#define TABLE_SIZE 100

typedef struct Person {
	char name[SIZE_NAME];
	int age;
} person;

typedef struct Node {
	char *key;
	char *value;
	struct Node *next;
} node;

typedef struct HashTable {
	node **entries;
} hashtable;

unsigned int hash(char*);

node *ht_pair(char*, char*);

hashtable *ht_init(void);

void ht_set(hashtable*, char*, char*);

char *ht_get(hashtable*, char*);

void ht_del(hashtable*, char*);

void ht_print(hashtable*);
