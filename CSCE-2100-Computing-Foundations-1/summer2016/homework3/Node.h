#pragma once

class Node {
private:
	Node* left;
	Node* right;
	int value;
public:
	Node();
	Node(int val, Node* left);
	~Node();
	Node* getNext();
	void setNext(Node* newNext);

};