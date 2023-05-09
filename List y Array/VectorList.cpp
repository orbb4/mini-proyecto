#include "VectorList.h"
#include <iostream>

VectorList::VectorList(){
	this->T = nullptr;
	count = 0;
}
VectorList::~VectorList(){
	Node* current = T;
	while(current != nullptr){
		Node* next = current->next;
		delete current;
		current = next;
	}
	T = nullptr;
	count = 0;
}

bool VectorList::find(int n){
	Node *node = T;
	while(node!=nullptr){
		if(node->data == n){
			return true;
		}
		node = node->next;
	}
	return false;
}


int VectorList::at(int p){
	if(count==0){
		std::cout<<"El vector está vacío!"<<std::endl;
		return -2147483647;
	}
	else if(p<count){
		Node* aux = T;
		for (int i = 1; i < p; i++)
		{
			aux = aux->next;
		}
		return aux->data;
	}
	else if(p>=count){
		std::cout<<"La posición solicitada no existe!"<<std::endl;
		return -2147483647;
	}
	return -2147483647;
}

int VectorList::size(){
	return count;
}

void VectorList::insertAt(int p, int data){
	if(count == 0 && p == 0){
		T = new Node(data);
		count++;
	}
	else if(p<=count && count != 0){
		Node* aux = T;
		Node* nodo = new Node(data);
		for (int i = 0; i < p; i++)
		{
			aux = aux->next;
		}
		if(aux->next != nullptr){
			aux->next = nodo;
		}
		else{
			nodo->next = aux->next;
		}
		aux->next = nodo;
		count++;
	}
	else if(p>count){
		std::cout<<"La posición requerida no existe!"<<std::endl;
	}
	
}

void VectorList::insert_right(int data){
	if(count==0){
		T = new Node(data);
		count++;
	}
	else{
		Node* aux = T;
		Node* nodo = new Node(data, nullptr);
		for (int i = 1; i < count; i++)
		{
			aux = aux->next;
		}
		aux->next = nodo;
		count++;
	}
}

void VectorList::insert_left(int data){
	if(count==0){
		T = new Node(data);
		count++;
	}
	else{
		Node* nodo = new Node(data, T);
		T = nodo;
		count++;
	}
}

bool VectorList::empty(){
	if(count == 0){
		return true;
	}
	else{return false;}
}