#ifndef NODES_H
#define NODES_H
#include <iostream>

class Node{
protected:
	Node* ptrder;
	Node* ptrizq;	
};
class pNode : Node{ //Nodo de lista
protected:
	pNode* ptrder;
private:
	int b;
	int *arr; 
	
public:
	// insera un elemento en arr en un index dado
	void insert(int index, int dato);
	int* getArr();
	pNode* getPtrDer();
	int getUsed();
	void setPtrder(pNode* ptrDer);
	int used;
	pNode(pNode* ptrder, int b);
};
class rNode : Node{ //Nodo resumen
protected:
	Node* ptrder;
	Node* ptrizq;
private:
	int used;
	int cap;
public:
	rNode(Node* ptrizq, Node* ptrder);
};

#endif