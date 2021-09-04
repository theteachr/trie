struct Node {
	int times_used;
	struct Node** paths;
};

bool is_leaf(struct Node* node);
struct Node* get_next_node(struct Node* node);
struct Node* get_new_node();
