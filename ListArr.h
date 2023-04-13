#ifndef LISTARR_H
#define LISTARR_H
#include <iostream>
#include "Nodes.h"

class ListArr{
private:
	int b;
	int count;
	pNode* nodoHead;
	pNode* nodoTail;
	rNode* nodoTop;
public:
	ListArr(int b);
	int size();
	void insert_left(int v);
	void insert_right(int v);
	void insert(int v, int i);
	void print();
	bool find(int v);
};

#endif