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
		right = left = nullptr;
		// right = nullptr;
	}
};