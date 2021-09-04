#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include "trie_helpers.h"

void init_trie(struct Trie* trie) {
	trie->head = get_new_node();
}

void insert(struct Trie* trie, char* data) {
	struct Node* temp = trie->head;
	struct Node* path = NULL;
	int idx;

	for (int i = 0; data[i] != 0; i++) {
		idx = data[i] - '0';
		path = temp->paths[idx];

		if (path == NULL)
			temp->paths[idx] = get_new_node();

		temp = temp->paths[idx];
	}
}

bool search(struct Trie* trie, char* key) {
	struct Node* temp = trie->head;

	for (int i = 0; key[i] != 0; i++) {
		if (temp->paths[key[i] - '0'] == NULL)
			return false;
		temp = temp->paths[key[i] - '0'];
	}

	return true;
}
