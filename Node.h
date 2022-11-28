#pragma once

class Node {
public:
	// data members
	int data;
	Node* left;
	Node* right;

	// member functions
	Node(int data) {
		this->data = data;
		//right = left = NULL; (include iostream for this)
		right = left = nullptr;
	}
};