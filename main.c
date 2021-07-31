#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_PATHS 10

struct Node {
	struct Node** paths;
};

struct Trie {
	struct Node* head;
};

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

int main(void) {
	char *zip_code_data[] = {
		"580030",
		"560782",
		"789663"
	};

	struct Trie zip_codes;

	init_trie(&zip_codes);

	for (int i = 0; i < 3; i++)
		insert(&zip_codes, zip_code_data[i]);

	print_trie(&zip_codes);

	char* key = "580031";

	printf("%s was%sfound.\n", key, search(&zip_codes, key) ? " " : " not ");

	return 0;
}
