#include "ListArr.h"
#include <stdio.h>

ListArr::ListArr(int capacity){
	this->b = capacity;
}

int ListArr::size(){
}

void ListArr::insert_left(int v){
	if(count = 0){
		pNode first = new Node(b);
		first.arr[0] = v;
		head = first;
		tail = first;
	}
}
//ToDo: añadir nodos resumen por cada dos nodos ListArr
void ListArr::insert_right(int v){
	// si no hay ningun array creado
	if(count = 0){
		pNode *first = new pNode(nullptr, b);
		first->arr[0] = v;
		first->numDeDatos++;
		nodoHead = first;
		nodoTail = first;
	// si el arreglo de la derecha está lleno, se crea uno nuevo a la derecha de la cola
	}else if(nodoTail->numDeDatos == b){
		pNode *newNode = new pNode(nullptr, b);
		newNode[0] = v;
		newNode->numDeDatos++;
		nodoTail->setPtrder(newNode);
	// si queda espacio en la cola	
	}else{
		int posicion = (nodoTail->numDeDatos)-1
		nodoTail->arr[pos]=v;
		nodoTail->numDeDatos++;
	}
}

void ListArr::insert(int v, int i){

}

void ListArr::print(){

}

bool ListArr::find(){

}
