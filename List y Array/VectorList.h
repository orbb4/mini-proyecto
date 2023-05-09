#include "VectorADT.h"

class VectorList : VectorADT{
private:
	struct Node{
		int data;
		Node* next;
		Node(int data, Node* next = nullptr){
			this->data = data;
			this->next = next;
		}
	};
	Node* T;
	int count;
public:
	VectorList();
	~VectorList();
	int at(int);
	int size();
	void insertAt(int,int);
	void insert_right(int);
	void insert_left(int);
	bool empty();
	bool find(int n);
};