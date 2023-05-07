#include "ListArr.h"
#include "Nodes.h"
#include <iostream>
#include <chrono>
using namespace std;

int main(){

	int n = 300000;
	std::chrono::duration<double> avg_secs;
	avg_secs = std::chrono::seconds::zero();
	for(int j = 0; j < 20; j++){
		ListArr* li = new ListArr(250);
		auto start = std::chrono::steady_clock::now();
		for(int i = 0; i < n; i++){
			li->insert_right(i);
		}
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_in_secs = end-start;
		std::cout <<"Experimento "<< j <<": "<< time_in_secs.count() << "segundos" << std::endl;
		avg_secs+=time_in_secs;
	}
	avg_secs/=20;
	std::cout<<"Tiempo promedio: "<< avg_secs.count() << "s" << std::endl;
	return 0;


}