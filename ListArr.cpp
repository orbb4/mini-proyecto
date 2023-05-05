#include "ListArr.h"
#include <stdio.h>
#include <vector>

// funcion que borra todos los nodos resumen existentes
void destroyTree(rNode* top){
	std::cout<<"entering destroy tree"<<std::endl;
	if(top == nullptr){
		std::cout<<"destroy tree finaliza correctamente"<<std::endl;
		return;
	}else{
		if(top->ptrizqR != nullptr){
			std::cout<<"entering izq"<<std::endl;
			destroyTree(top->ptrizqR);
		}
		if(top->ptrderR != nullptr){
			std::cout<<"entering dder"<<std::endl;
			destroyTree(top->ptrderR);
		}
		
	}
	std::cout<<"destroy tree finaliza correctamente"<<std::endl;
	delete(top);
}

int ListArr::updateTree(rNode* top){
	if (top == nullptr) return -1;
 
    // first recur on left subtree
    int uno = updateTree(top->ptrizqR);
 
    if(uno == -1 && top->ptrizqP != nullptr){
    	uno = top->ptrizqP->used;
    }else if(top->ptrizqP == nullptr && top->ptrizqR == nullptr){
	   	uno = 0;
	}
	else{
	    uno = top->ptrizqR->used;
	}
    // then recur on right subtree
	int dos = updateTree(top->ptrderR);

	if (dos == -1 && top->ptrderP != nullptr)
	{
		dos = top->ptrderP->used;

	}else if(top->ptrderP == nullptr && top->ptrderR == nullptr){
		dos = 0;
	}
	else{
		dos = top->ptrderR->used;
	}
    // now deal with the node
	top->used = uno + dos;
    std::cout <<"sum "<< top->used << std::endl;

    return top->used;
}

void ListArr::redoTree(){
	destroyTree(nodoTop);
	rNode *newtop = new rNode(nullptr, nullptr);
	std::vector<rNode*> nodes;
	nodes.push_back(newtop);
	int numRes = 1; 
	nodoTop = newtop;
	std::cout<<"arbol"<<std::endl;
	int i = 1;
	while(i*2 < pCount){
		for(int j = 0; j < i; j++){
			rNode *n1 = new rNode(nullptr, nullptr);
			rNode *n2 = new rNode(nullptr, nullptr);
			rNode *temp = nodes.at(nodes.size()-1-j);
			temp->ptrizqR = n2;
			temp->ptrderR = n1;
			numRes+=2;
			nodes.push_back(n1);
			nodes.push_back(n2);
		}
		i++;
	}
	pNode *actualArr = nodoHead;
	for(int j = 0; j < i; j++){		
		rNode *temp = nodes.at(nodes.size()-1-j);
		temp->ptrizqP = actualArr;
		if(actualArr->getPtrDer() != nullptr){
			actualArr = actualArr->getPtrDer();
		}
		else{break;}
		temp->ptrderP = actualArr;
		if(actualArr->getPtrDer() != nullptr){
			actualArr = actualArr->getPtrDer();
		}
		else{break;}
	}
	updateTree(nodoTop);
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
		std::cout<<"insert left con count==0 "<<std::endl;
	// si el arreglo de la izquierda está lleno, se crean 1 nuevos a la izquierda de la cola
	}else if(nodoHead->getUsed() == b){
		pNode *newNode = new pNode(nodoHead, b);
		newNode->insert(0, v);
		newNode->used++;
		nodoHead=newNode;
		count++;
		pCount++;
		redoTree();
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
		count+=1;
		pCount+=1;
		rNode* top = new rNode(first, nullptr);
		nodoTop = top;
		std::cout<<"insert right con count==0 "<<std::endl;

	// si el arreglo de la derecha está lleno, se crea uno nuevo a la derecha de la cola
	}else if(nodoTail->used == b){
		pNode *newNode = new pNode(nullptr, b);
		newNode->insert(0, v);
		newNode->used++;
		nodoTail->setPtrder(newNode);
		nodoTail = newNode;
		count++;
		pCount++;
		redoTree();
	// si queda espacio en la cola	
	}else{
		nodoTail->insert(nodoTail->used, v);
		nodoTail->used++;
	}
}

void ListArr::insert(int v, int i){
	pNode* current = nodoHead;
	for (int j = 1; j <= i; ++j)
	{
		if (i == j)
		{
			int res = j%capacity();
			if (current->used < capacity())
			{
				int* arr = current->getArr();
				for (int u = current->getUsed()-1; u > j-1; i--)
				{
					arr[u] = arr[u+1];
				}
			}
		}
		if (j/nodoHead->getUsed() == 0 && nodoHead->getPtrDer() != nullptr)
		{
			current = nodoHead->getPtrDer();
		}
		if (j/nodoHead->getUsed() == 0 && nodoHead->getPtrDer() == nullptr)
		{
			std::cout<<"La posición solicitada no existe"<<std::endl;
		}
	}
}

void ListArr::print(){
	
	pNode* current = nodoHead;
	for(int i = 0; i<count;i++){
		for(int u = 0; u<current->getUsed(); u++){
			std::cout << current->getArr()[u] << ", ";
		}
		current = current->getPtrDer();
	}
	std::cout << "" << std::endl;
}

void ListArr::printOrder(rNode* node){
	if (node == NULL)
        return;
 
    /* first recur on left child */
    printOrder(node->ptrizqR);
 
    /* then print the data of node */
    std::cout << "Usados preOrder: "<<node->used << std::endl;
 
    /* now recur on right child */
    printOrder(node->ptrderR);
    std::cout << "Usados postOrder: "<<node->used << std::endl;
}

bool ListArr::find(int v){
	pNode* node = nodoHead;
	while(node != nullptr){
		for(int i = 0; i < node->used; i++){
			if(node->getArr()[i]==v){
				return true;
			}
		}
		node = node->getPtrDer();
	}
	return false;
}

int ListArr::capacity(){
	return b;
}