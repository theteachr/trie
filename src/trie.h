#include <stdbool.h>

struct Trie {
	struct Node* head;
};

#define NUM_PATHS 10

void insert(struct Trie*, char*);
bool delete(struct Trie*, char*);
void init_trie(struct Trie*);
bool search(struct Trie*, char*);
void print_trie(struct Trie*);
