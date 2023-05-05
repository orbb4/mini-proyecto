#include "ListArr.h"
#include <stdio.h>
#include <vector>

// funcion que borra todos los nodos resumen existentes
void destroyTree(rNode* top){
	std::cout<<"entering destroy tree"<<std::endl;
	if(top == NULL){
		std::cout<<"destroy tree finaliza correctamente"<<std::endl;
		return;
	}else{
		
		if(top->ptrizqR != nullptr){
			destroyTree(top->ptrizqR);
		}
		if(top->ptrderR != nullptr){
			destroyTree(top->ptrderR);
		}
		
	}

	delete(top);
}

int ListArr::updateTree(rNode* top){
	if (top == NULL) return -1;
 
    // first recur on left subtree
    	int uno = updateTree(top->ptrizqR);
 
    	if(uno == -1 && top->ptrizqP){
    		uno = top->ptrizqP->used;
    	}else if(top->ptrizqP == NULL){
	    	uno = 0;
	    }
    // then recur on right subtree
	    int dos = updateTree(top->ptrderR);

	    if (dos == -1 && top->ptrderP != NULL)
	    {
	    	dos = top->ptrderP->used;

	    }else if(top->ptrderP == NULL){
	    	dos = 0;
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
			temp->ptrizqR = n1;
			temp->ptrderR = n2;
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
		actualArr=actualArr->getPtrDer();
		temp->ptrderP = actualArr;
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

void ListArr::print(rNode* node){
	/*
	pNode* current = nodoHead;
	for(int i = 0; i<count;i++){
		for(int u = 0; u<current->getUsed(); u++){
			std::cout << current->getArr()[u] << std::endl;
		}
		current = current->getPtrDer();
	}*/

	if (node == NULL)
        return;
 
    /* first recur on left child */
    print(node->ptrizqR);
 
    /* then print the data of node */
    std::cout << "node->used (print)"<<node->used << std::endl;
 
    /* now recur on right child */
    print(node->ptrderR);

}

bool ListArr::find(int v){
	return false;
}
