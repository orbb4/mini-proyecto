#ifndef NODES_H
#define NODES_H
#include <iostream>

class Node{
protected:
	Node* ptrder;
	Node* ptrizq;	
};


class pNode : public Node{ //Nodo de lista
protected:
	pNode* ptrder;
private:
	int b;
	int *arr; 
public:
	bool isR;
	// insera un elemento en arr en un index dado
	void insert(int index, int dato);
	int* getArr();
	pNode* getPtrDer();
	int getUsed();
	void setPtrder(pNode* ptrDer);
	int used;
	pNode(pNode* ptrder, int b);
};


class rNode : public Node{ //Nodo resumen
private:

public:
	int used;
	int cap;
	// ptr nodos resumen
	rNode* ptrderR;
	rNode* ptrizqR;
	// ptr nodos principales (hojas del arbol¿)
	pNode* ptrderP;
	pNode* ptrizqP;

	rNode(pNode* ptrizq, pNode* ptrder);
};

#endif