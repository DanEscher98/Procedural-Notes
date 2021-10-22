#include <cstdio>

struct Node {
	Node* next{};
	void insert_after(Node* new_node) {
		new_node->next = this->next;
		this->next = new_node;
	}
	short id;
};

int main() {
	Node n1, n2, n3;
	n1.id = 1;
	n2.id = 2;
	n3.id = 3;
	n1.insert_after(&n2);
	n2.insert_after(&n3);
	
	for (Node *cursor = &n1; cursor; cursor = cursor->next) {
		printf("Node-%d\n", cursor->id);
	}
}
