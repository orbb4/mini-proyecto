#include "ListArr.h"
#include "Nodes.h"
#include <iostream>

using namespace std;

int main(){

	ListArr* li = new ListArr(4);
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		li->insert_left(i);
	}
	li->print(li->nodoTop);
	return 0;
}