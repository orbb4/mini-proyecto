#include "Nodes.h"
#include <stdio.h>

pNode::pNode(pNode* ptrder, int b){
	this->b = b;
	this->ptrder = ptrder;
	this->used = 0;
	arr = new int[b];
}
void pNode::insert(int index, int dato){
	arr[index] = dato;
}

int* pNode::getArr(){
	return this->arr;
}

pNode* pNode::getPtrDer(){
	return ptrder;
}

int pNode::getUsed(){
	return this->used;
}

void pNode::setPtrder(pNode* ptrder){
	this->ptrder = ptrder;
}

//COSAS DE RESUMEN

rNode::rNode(pNode* ptrizq, pNode* ptrder){
	ptrderP = ptrizq;
	ptrizqP = ptrder;
	ptrderR = nullptr;
	ptrizqR = nullptr;
}