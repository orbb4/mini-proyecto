#include<iostream>
#include "VectorArray.h"

VectorArray::VectorArray(int c){
	this->capacity = c;
	this->arr = new int[capacity];
	this->s = 0;
}
VectorArray::~VectorArray(){
	delete[] arr;
}

bool VectorArray::find(int data){
	for(int i = 0; i < s; i++){
		if(arr[i]==data){
			return true;
		}
	}
	return false;
}

int VectorArray::at(int p){
	if(s != 0 && p<=s){
		return arr[p];
	}
	else{
		std::cout << "La posición requerida no existe!" << std::endl;
		return -2147483647;
	}
	
}

void VectorArray::insert_right(int data){
	if (s==capacity)
	{
		int *aux = new int[capacity*2];
		for (int i = 0; i < capacity; i++)
		{
			aux[i] = arr[i];
		}
		aux[capacity] = data;
		arr = aux;
		//delete[] aux;
		capacity *= 2;
		s++;
	}
	else{
		arr[s] = data;
		s++;
	}
}
void VectorArray::insert_left(int data){
	if (s==capacity)
	{
		int *aux = new int[capacity*2];
		for (int i = capacity; 0 < i; i--)
		{
			aux[i] = arr[i-1];
		}
		aux[0] = data;
		arr = aux;
		//delete[] aux;
		capacity *= 2;
		s++;
	}
	else{
		for (int i = s; 0 < i; i--)
		{
			arr[i] = arr[i-1];
		}
		arr[0] = data;
		s++;
	}
}

void VectorArray::insertAt(int p, int data){
	if(p==0 && s==0){
		arr[0] = data;
		s++;
	}
	else if(s==capacity && p<=s){
		int *aux = new int[capacity*2];
		for (int i = 0; i < capacity + 1; i++)
		{
			if(i == p){
				aux[i] = data;
			}
			else{
				aux[i] = arr[i];
			}
		}
		arr = aux;
		//delete[] aux;
		capacity *= 2;
		s++;
	}
	else if(s!=capacity && p<=s){
		for (int i = p; i < capacity-1; i++)
		{
			arr[i+1] = arr[i]; 
		}
		arr[p] = data;
		s++;
	}
	else if(p>s){
		std::cout<<"La posición no existe!"<<std::endl;
	}
}

int VectorArray::size(){
	return s;
}

bool VectorArray::empty(){
	if(s==0){
		std::cout<<"El vector está vacío!"<<std::endl;
		return true;
	}
	else{
		std::cout<<"El vector no está vacío!"<<std::endl;
		return false;
	}
}