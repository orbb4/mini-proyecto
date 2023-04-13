#include "ListArr.h"
#include <stdio.h>

ListArr::ListArr(int capacity){
	this->count = 0;
	this->b = capacity;
}

int ListArr::size(){
	return 0;
}

void ListArr::insert_left(int v){
	if(count == 0){
		pNode *first = new pNode(nullptr, b);
		first->insert(0, v);
		first->used++;
		nodoHead = first;
		nodoTail = first;
		count++;
	// si el arreglo de la derecha está lleno, se crea uno nuevo a la derecha de la cola
	}else if(nodoHead->used == b){
		pNode *newNode = new pNode(nodoHead, b);
		newNode->insert(0, v);
		newNode->used++;
		nodoHead = newNode;
		count++;
	// si queda espacio en la cola	
	}else{
		std::cout << "Used(head): " << nodoHead->used << std::endl;
		int posicion = (nodoHead->used);
		nodoHead->insert(posicion, v);
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
