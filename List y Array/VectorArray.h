#include"VectorADT.h"

class VectorArray : VectorADT{
private:
	int *arr;
	int s;
	int capacity;
public:
	VectorArray(int c);
	~VectorArray();
	int at(int p);
	int size();
	void insertAt(int p, int data);
	void insert_right(int data);
	void insert_left(int data);
	bool empty();
	bool find(int data);
};