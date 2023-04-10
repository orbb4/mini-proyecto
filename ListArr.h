#import <iostream>
class ListArr{
private:
	Node* nodoHead;
	Node* nodoTail;
	Node* nodoTop;
public:
	virtual int size()=0;
	virtual void insert_left(int v)=0;
	virtual void insert_right(int v)=0;
	virtual void insert(int v, int i)=0;
	virtual void print()=0;
	virtual bool find(int v)=0;
};
