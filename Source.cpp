#include "Node.h"
#include "myStack.cpp"
#include <stack>


Node* constructTree(int input[], int size) {
	// making the last element as root
	Node* root = new Node(input[size - 1]);
	myStack<Node*> st(100);
	st.Push(root);

	// traversing from second last node
	for (int i = size - 2; i >= 0; i--) {
		Node* newNode = new Node(input[i]);

		// Keep popping nodes while top()
		// of stack is greater.
		Node* temp = NULL;
		while (st.getSize() && (input[i] > st.TopElement()->data)) {
			temp = st.TopElement(), st.Pop();
		}
		// the stack became empty but (st.TopElement()->data < input[i])
		// still returned true 
		// (input element was greater than all previous elements)
		if (temp != NULL) {
			temp->left = newNode;
		}
		// (st.TopElement()->data < input[i]) returned false
		// before the stack became empty
		else {
			st.TopElement()->right = newNode;
		}
		// after resetting the stack element order,
		// simply push the newNode into the stack
		st.Push(newNode);
	}
	return root;
}


void printInorder(Node* node) {
	if (node == NULL)
		return;
	printInorder(node->left);
	std::cout << node->data << "-->";
	printInorder(node->right);
}

Node* search(Node* root, int key) {
	Node* node = root;
	while (node->data != key) {
		if (node != NULL) {
			// go to left
			if (node->data > key) {
				node = node->left;
			}
			// go right
			else {
				node = node->right;
			}
		}
		else {
			return NULL;
		}
	}
	return node;
}



int main() {
	int input[] = { 1, 7, 5, 50, 40, 10 };
	int size = sizeof(input) / sizeof(int);
	Node* myNode = constructTree(input, size);
	printInorder(myNode);

	return 0;
}