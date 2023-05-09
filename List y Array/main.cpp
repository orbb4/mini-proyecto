#include <iostream>
#include <chrono>
#include "VectorArray.h"
#include "VectorList.h"

using namespace std;
using namespace std::chrono;

int main() {
    
	int n = 10000000;
	std::chrono::duration<double> avg_secs;
	avg_secs = std::chrono::seconds::zero();
	for(int j = 0; j < 20; j++){
		VectorList* li = new VectorList();
		for(int i = 0; i < n; i++){
			li->insert_left(i);
		}
		auto start = std::chrono::steady_clock::now();
		li->find(n-1);
		auto end = std::chrono::steady_clock::now();
		std::chrono::duration<double> time_in_secs = end-start;
		std::cout <<"Experimento "<< j <<": "<< time_in_secs.count() << "segundos" << std::endl;
		avg_secs+=time_in_secs;
	}
	avg_secs/=20;
	std::cout<<"Tiempo promedio: "<< avg_secs.count() << "s" << std::endl;
    return 0;
}
