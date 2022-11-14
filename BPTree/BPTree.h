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
	Node** children;
	Node* parents;

	Node() {
		key = new int[Node::max - 1];
		children = new Node * [Node::max];
		this->isLeaf = false;
		parents = nullptr;
	}
	friend class BPlusTree;
};
int Node::max;
int Node::min;

class BPlusTree {

public:
	Node* root = nullptr;
	int degree;
	BPlusTree(int m) {
		this->degree = m;
		this->root = nullptr;

		Node::max = m-1;
		Node::min = m / 2 - 1;
	}

	void insert_key(int k) {
		Node* current;
		if (root == nullptr) {
			root = new Node();
			root->key[0] = k;
			root->isLeaf = true;
			root->size = 1;
			current = root;
		}

		else {
			current = find_leaf(k);

			//если лист не переполнен
			if (current->size < Node::max) {
				int place = find_index(current->key, k, current->size);
				
				for (int i = (current->size); i > place; i--) {
					current->key[i] = current->key[i - 1];
				}
				current->key[place] = k;
				current->size++;
			}

			//если лист переполнен
			else {
				split(current, k, Node::max / 2 + 1);
			}
		}
	}
	void delete_key(int);

	bool find_key(int k) {
		Node* current = find_leaf(k);
		int i = find_index(current->key, k, current->size);
		if (current->key[i] == k) return true;
		else return false;
	};
	int find_index(int arr[], int k, int size) {
		if (k >= arr[size-1]) return size;
		else {
			for (int i = 0; i < size; i++) {
				if (k < arr[i]) {
					return i;
				}
			}
		}

	}
	//
	Node* find_leaf(int k) {
		Node* current = root;
		
		while (!current->isLeaf) {
			current = current->children[find_index(current->key, k, current->size)];
		}
			return current;
		
	}

	void split(Node * current, int k, int point) {
		
	}
	void print(Node*);
};



#endif