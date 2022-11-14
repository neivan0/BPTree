#include <iostream>
#include "BPTree.h"
int main()
{
	BPlusTree bpt(3);
	bpt.insert_key(10);
	bpt.insert_key(11);
	bpt.insert_key(2);
	//bpt.insert_key(2);
	std::cout << bpt.root->key[0] << " " << bpt.root->key[1] << std::endl;
	//std::cout << bpt.root->children[0]->key[2] << std::endl;
	//std::cout << bpt.root->key[0] << " " << bpt.root->key[1] << " " << bpt.root->key[2]<< " " << bpt.root->key[3] << " " << bpt.root->key[4]<<" " << bpt.root->key[5]<< " " << bpt.root->key[6] << " " << bpt.root->key[7] << std::endl;
	//std::cout<<bpt.find_leaf(1)->key[0]<<std::endl;
	//std::cout << bpt.find_index(bpt.root->key, 20, bpt.root->size);
	//std::cout << bpt.degree << std::endl;
}
