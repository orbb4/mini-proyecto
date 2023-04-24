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
		
		pNode *second = new pNode(nullptr, b);
		pNode *first = new pNode(second, b);
		first->insert(0, v);
		first->used++;
		nodoHead = first;
		nodoTail = second;
		count+=2;
		rNode top = new rNode(first, second);
		nodoTop = top;
	// si el arreglo de la izquierda está lleno, se crean 2 nuevos a la izquierda de la cola
	}else if(nodoHead->used == b){
		pNode *newNode2 = new pNode(nodoHead, b);
		pNode *newNode1 = new pNode(newNode2, b);
		newNode1->insert(0, v);
		newNode1->used++;
		nodoHead = newNode1;
		count+=2;
		// creamos nuevos nodos resumen:
		rNode newRes = new rNode(newNode1, newNode2);s
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
