#import <iostream>

class Node{
protected:
	Node* ptrder;
	Node* ptrizq;	
}
class realNode : Node{
protected:
	Node* ptrder;
private:
	int b; // num de elementos del arreglo
	int arr[b]; 
	int numDeDatos;
}
class sumaNode : Node{
protected:
	Node* ptrder;
	Node* ptrizq;
private:
	int arr[2];
}
