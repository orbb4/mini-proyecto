#include "ListArr.h"
#include <stdio.h>
#include <vector>

// funcion que borra todos los nodos resumen existentes
void destroyTree(rNode* top){
	std::cout << "destroyed: " <<top<< std::endl;
	if(top == NULL) return;

	destroyTree(top->ptrizqR);

	destroyTree(top->ptrderR);
	delete(top);
}

// funcion para actualilzar los nodos resumen en base a los arreglos existentes
void ListArr::redoTree(){
	// la raiz del arbol
	rNode *newtop = new rNode(nullptr, nullptr);
	std::cout<<"se crea newtop"<<std::endl; 
	// un vector con los nodos resumen a ser creados
	std::vector<rNode*> nodes;
	nodes.push_back(newtop);
	std::cout<<"se crea vector con newtop"<<std::endl; 
	// num de nodos resumen
	int numRes = 1; 
	/* destroytree() da segmentation fault por ahora
	// borramos los nodos resumen antiguos
	destroyTree(nodoTop);
	std::cout<<"arbol destruido!"<<std::endl;
	*/
	// seguiremos creando nodos resumen hasta que alcanzen para todos los arreglos
	// consideramos que un nodo resumen puede apuntar hasta 2 arreglos
	int i = 1; // num de nodos en la ultima capa de nodos 
	while(numRes*2 < pCount){
		std::cout<<"entrando al while, con numRes="<<numRes<<std::endl; 
		// creamos dos nodos resumen hijos para cada nodo en la ultima capa
		// repetimos hasta tener los nodos resumen suficientes
		for(int j = 0; j < i; j++){
			rNode *n1 = new rNode(nullptr, nullptr);
			rNode *n2 = new rNode(nullptr, nullptr);
			// conectamos el ultimo elemento del vector, en la siguiente iteracion conectamos el penultimo
			// en la tercera el antepenultimo... con el par de nodos creado atras
			// hasta recorrer toda la ultima capa de nodos
			rNode *temp = nodes.at(nodes.size()-1-j);
			temp->ptrizqR = n1;
			temp->ptrderR = n2;
			numRes+=2;
			std::cout<<"en: numRes*2 < pCount. j= "<<j<<std::endl; 
			nodes.push_back(n1);
			nodes.push_back(n2);
		}
		i++;
	}
	// ahora que tenemos nodos resumen suficientes, conectamos la ultima capa de nodos a los arreglos! :)
	std::cout<<"conetando ultima capa a los arreglos :)"<<std::endl; 
	pNode *actualArr = nodoHead;
	for(int j = 0; j < i; j++){		
		rNode *temp = nodes.at(nodes.size()-1-j);
		std::cout<<"j="<<j<<std::endl;
		// actualizamos ptr izquierdo
		temp->ptrizqP = actualArr;
		// actualizamos ptr derecho	
		actualArr=actualArr->getPtrDer(); // le asignamos al ptr derecho el nodo siguiente al previo(?)
		temp->ptrderP = actualArr;
	}
}



ListArr::ListArr(int capacity){
	this->count = 0;
	rCount = 0;
	pCount = 0;
	this->b = capacity;
	std::cout<<"Recordatorio de que hay que borrar las banderas :>"<<std::endl;
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
