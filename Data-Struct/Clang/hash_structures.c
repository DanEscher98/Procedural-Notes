#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_structures.h"

unsigned int hash(char *key) {
	size_t key_len = strlen(key);//, SIZE_NAME);
	unsigned int value = 0;
	for (size_t i=0; i < key_len ; i++) {
		value += key[i] * (1 + value);
	}
	return value % TABLE_SIZE;
}

node *ht_pair(char *key, char *value) {
	node *entry = malloc(sizeof(node));
	entry->key	= malloc(sizeof(key) + 1);
	entry->value= malloc(sizeof(value) + 1);
	entry->next = NULL;
	strcpy(entry->key, key);
	strcpy(entry->value, value);
	return entry;
}


// ####################################
// ## Public functions ################

hashtable *ht_init(void) {
	hashtable *new_ht = malloc(sizeof(hashtable));
	new_ht->entries = malloc(sizeof(node*) * TABLE_SIZE);
	for (size_t i=0; i < TABLE_SIZE; i++) {
		new_ht->entries[i] = NULL;
	}
	return new_ht;
}


// Resolve collisions by chaining (open addressing)
void ht_set(hashtable *ht, char *key, char *value) {
	unsigned int slot = hash(key);
	node *entry = ht->entries[slot];
	node *new_link = ht_pair(key, value);

	if (entry == NULL) {
		ht->entries[slot] = new_link;
	} else {
		node *prev;
		while (entry != NULL) {
			if (strcmp(entry->key, key) == 0) {
				// A match found, replace value
				free(entry->value);
				entry->value = malloc(strlen(value) + 1);
				strcpy(entry->value, value);
			} else {
				prev = entry;
				entry = prev->next;
			}
		}
		// End reached without match, add new
		prev->next = new_link;
	}
}

char *ht_get(hashtable *ht, char *key) {
	unsigned int slot = hash(key);
	// try to find a valid slot
	node *entry = ht->entries[slot];
	
	if (entry == NULL) {
		return "";
	} else {
		while (entry != NULL) {
			if (strcmp(entry->key, key)==0) {
				return entry->value;
			} else {
				// Traverse the list
				entry = entry->next;
			}
		}
		return "";
	}
}

void ht_del(hashtable *ht, char *key) {
	unsigned int bucket = hash(key);
	// try to find a valid bucket
	node *entry = ht->entries[bucket];
	
	if (entry != NULL) {
		return;
	} else {
		node *prev = malloc(sizeof(node));
		int index = 0;
		while (entry != NULL) {
			if (strcmp(entry->key, key)==0) {
				if (index == 0) { // First element
					// Only one element
					if (entry->next == NULL) {
						ht->entries[bucket] = NULL;
					} else {
						ht->entries[bucket] = entry->next;
					}
				} else {
					// No more elements
					if (entry->next == NULL) {
						prev->next = NULL;
					} else {
						prev->next = entry->next;
					}
				}
				// Delete the entry
				free(entry->key);
				free(entry->value);
				free(entry);
				return;
			}
			// Walk to next element
			prev = entry;
			entry = entry->next;
			index++;
		}
	}
}

void ht_print(hashtable *ht) {
	node *entry;
	for (size_t i=0; i < TABLE_SIZE; i++) {
		entry = ht->entries[i];
		if (entry == NULL) {
			continue;
		} else {
			printf("slot[%4lu]: {\n", i);
			while (entry != NULL) {
				printf("\t%s is %s years old.\n", entry->key, entry->value);
				entry = entry->next;
			}
			printf("}\n\n");
		}
	}
}
