#import <iostream>

class Node{
protected:
	Node* ptrder;
	Node* ptrizq;	
}
class pNode : Node{ //Nodo de lista
protected:
	Node* ptrder;
private:
	int b; 
	int arr[b]; 
	int numDeDatos;
}
class rNode : Node{ //Nodo resumen
protected:
	Node* ptrder;
	Node* ptrizq;
private:
	int used;
	int cap;
}
