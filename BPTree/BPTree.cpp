#include <iostream>
#include "BPTree.h"
int main()
{
	BPlusTree bpt(3);
	std::cout << bpt.degree;
}
