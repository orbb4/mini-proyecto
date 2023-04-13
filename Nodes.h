#import <iostream>

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
	int arr[b]; 
	int numDeDatos;
public:
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
