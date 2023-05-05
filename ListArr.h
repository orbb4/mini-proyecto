#ifndef LISTARR_H
#define LISTARR_H
#include <iostream>
#include "Nodes.h"

class ListArr{
private:
	int b;
	int count;
	int rCount;
	int pCount;
	pNode* nodoHead;
	pNode* nodoTail;
public:
	rNode* nodoTop;
	ListArr(int b);
	int size();
	void insert_left(int v);
	void insert_right(int v);
	void insert(int v, int i);
	void print();
	void printOrder(rNode* node);
	bool find(int v);
	void redoTree();
	int updateTree(rNode* top);
};

#endif