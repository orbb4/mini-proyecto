#include <iostream>

class Node{
protected:
	Node* ptrder;
	Node* ptrizq;	
}
class pNode : Node{ //Nodo de lista
protected:
	pNode* ptrder;
private:
	int b; 
	int *arr; 
	int numDeDatos;
public:
	setPtrder(pNode* ptrDer);
	pNode(pNode* ptrder, int b);
}
class rNode : Node{ //Nodo resumen
protected:
	Node* ptrder;
	Node* ptrizq;
private:
	int used;
	int cap;
}
