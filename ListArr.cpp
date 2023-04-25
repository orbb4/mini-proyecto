#include "ListArr.h"
#include <stdio.h>
#include <vector>

void destroyTree(rNode* top){
	std::cout << "destroyed: " <<top<< std::endl;
	if(top == NULL) return;

	destroyTree(top->ptrizqR);

	destroyTree(top->ptrderR);
	delete(top);
}

void ListArr::redoTree(){
	rNodo newtop = new rNode(nullptr, nullptr);
	std::vector<rNode> resnodes;
	resnodes.push_back(newtop);
	int numRes = 1;
	destroyTree(nodoTop);
	int i = 1;
	while(numRes*2 < pCount){
		for(int j = 0; j < i; j++){
			rNode *actual = resnodes.pop_back();
			actual->ptrderR = 
		}
	}
}

ListArr::ListArr(int capacity){
	this->count = 0;
	rCount = 0;
	pCount = 0;
	this->b = capacity;
}

int ListArr::size(){
	return count;
}

void ListArr::insert_left(int v){
	if(count == 0){	
		pNode *first = new pNode(nullptr, b);
		first->insert(0, v);
		first->used++;
		nodoHead = first;
		nodoTail = first;
		count+=1;
		pCount+=1;
		rNode* top = new rNode(first, nullptr);
		nodoTop = top;
		std::cout<<"count==0"<<std::endl;
	// si el arreglo de la izquierda está lleno, se crean 1 nuevos a la izquierda de la cola
	}else if(nodoHead->getUsed() == b){
		pNode *newNode = new pNode(nodoHead, b);
		newNode->insert(0, v);
		newNode->used++;
		nodoHead=newNode;
		count++;
		pCount++;
	}else{
		nodoHead->insert(nodoHead->getUsed(), v);
		nodoHead->used++;
	}
}

//ToDo: añadir nodos resumen por cada dos nodos ListArr
void ListArr::insert_right(int v){
	// si no hay ningun array creado
	if(count == 0){
		pNode *first = new pNode(nullptr, b);
		first->insert(0, v);
		first->used++;
		nodoHead = first;
		nodoTail = first;
		count++;
	// si el arreglo de la derecha está lleno, se crea uno nuevo a la derecha de la cola
	}else if(nodoTail->used == b){
		pNode *newNode = new pNode(nullptr, b);
		newNode->insert(0, v);
		newNode->used++;
		nodoTail->setPtrder(newNode);
		nodoTail = newNode;
		count++;
	// si queda espacio en la cola	
	}else{
		std::cout << "Used: " << nodoTail->used << std::endl;
		int posicion = (nodoTail->used);
		nodoTail->insert(posicion, v);
		nodoTail->used++;
	}
}

void ListArr::insert(int v, int i){
}

void ListArr::print(){
	pNode* current = nodoHead;
	for(int i = 0; i<count;i++){
		for(int u = 0; u<current->getUsed(); u++){
			std::cout << current->getArr()[u] << std::endl;
		}
		current = current->getPtrDer();
	}
}

bool ListArr::find(int v){
	return false;
}
