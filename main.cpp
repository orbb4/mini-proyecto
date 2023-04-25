#include "ListArr.h"
#include "Nodes.h"
#include <iostream>

using namespace std;

int main(){

	ListArr* li = new ListArr(4);
	for(int i = 0; i < 20; i++){
		li->insert_left(i);
	}
	li->print();
	li->redoTree();
	return 0;
}