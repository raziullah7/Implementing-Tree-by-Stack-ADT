#include "Node.h"
#include "myStack.cpp"


Node* constructTree(int input[], int size) {
	// making the last element as root
	Node* root = new Node(input[size - 1]);
	myStack<Node*> st(size);
	Node* x;
	st.Push(root);

	// traversing from second last node
	for (int i = size - 2; i >= 0; i++) {
		Node* newNode = new Node(input[i]);
		// Keep popping nodes while top()
		// of stack is greater.
		Node* temp = NULL;
		while (!st.IsEmpty() && st.TopElement()->data < input[i]) {
			temp = st.TopElement();
			st.Pop(x);
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



void main() {
	int input[] = { 1, 7, 5, 50, 40, 10 };
	Node* myNode = constructTree(input, sizeof(input) / sizeof(int));
	printInorder(myNode);
}