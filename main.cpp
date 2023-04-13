#include "ListArr.h"
#include "Nodes.h"
#include <iostream>

using namespace std;

int main(){

	ListArr* li = new ListArr(4);
	li->insert_right(4);
	li->insert_right(4);
	li->insert_right(1);
	li->insert_right(4);

	li->insert_left(3);
	li->insert_left(3);
	li->insert_left(3);
	li->insert_left(3);
	li->insert_left(3);
	li->print();
	return 0;
}