#pragma once
#ifndef BPTree
#define BPTree
#include <iostream>

class Node {
private:
	static int max;
	static int min;
public:
	bool isLeaf;
	int size;
	int* key;
	Node** pointer;
	Node* parent;

	Node() {
		key = new int[Node::max - 1];
		pointer = new Node * [Node::max];
		this->isLeaf = false;
	}

	void split();
	friend class BPlusTree;
};
int Node::max;
int Node::min;

class BPlusTree {

public:	
	int degree;
	BPlusTree(int m) {
		this->degree = m;
		this->root = nullptr;

		Node::max = m;
		Node::min = m / 2 - 1;
	}

	void insert_key(int k);
	void delete_key(int);
	int* search_key(int);	
	void print(Node*);

private:
	Node* search_leaf(int k);
	Node* root = nullptr;
};



#endif