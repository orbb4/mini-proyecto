#include "ListArr.h"
#include "Nodes.h"
#include <iostream>

using namespace std;

int main(){

	ListArr* li = new ListArr(4);
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		li->insert_right(i);
	}
	li->updateTree(li->nodoTop);
	li->print();
	li->printOrder(li->nodoTop);
	cout<<li->find(1)<<endl;
	cout<<li->find(4)<<endl;
	cout<<li->find(-200)<<endl;
	return 0;
}