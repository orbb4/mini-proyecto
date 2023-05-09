#ifndef VECTORADT_H
#define VECTORADT_H

class VectorADT{
	virtual int at(int) = 0;
	virtual int size() = 0;
	virtual void insertAt(int,int) = 0;
	virtual void insert_right(int) = 0;
	virtual void insert_left(int) = 0;
	virtual bool empty() = 0;
};

#endif