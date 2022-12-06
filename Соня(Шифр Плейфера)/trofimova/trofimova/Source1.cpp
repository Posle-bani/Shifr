#include <iostream>
#include <math.h>
#include "Pleifer.h"
#include "Header1.h"
#include <string>
#include <vector>
#include <chrono>


using namespace std;
using namespace chrono;
//string word = " ";

int main() {
	Encryption p;
	string e;
	auto start = steady_clock::now();
	Encryption_pleifer(p);
	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<microseconds>(end - start);
	cout << elapsed_ms.count()<< "mc" << endl;

	return 0;


}