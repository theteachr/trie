#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "trie_helpers.h"
#include "trie.h"

bool is_leaf(struct Node* node) {
	for (int i = 0; i < NUM_PATHS; i++)
		if (node->paths[i] != NULL)
			return false;

	return true;
}

struct Node* get_next_node(struct Node* node) {
	for (int i = 0; i < NUM_PATHS; i++)
		if (node->paths[i] != NULL)
			return node->paths[i];
	return NULL;
}

void print_node(struct Node* node) {
	for (int i = 0; i < NUM_PATHS; i++)
		printf("%c ", (node->paths[i] == NULL) ? i + '0' : 'x');
	printf("\n");
}

void print_trie(struct Trie* trie) {
	struct Node* temp = trie->head;

	while (!is_leaf(temp)) {
		print_node(temp);
		temp = get_next_node(temp);
	}
}

struct Node* get_new_node() {
	struct Node* new_node = malloc(sizeof(struct Node*));
	struct Node** paths = malloc(NUM_PATHS * sizeof(struct Node*));

	for (int i = 0; i < NUM_PATHS; i++)
		paths[i] = NULL;

	new_node->paths = paths;

	return new_node;
}
