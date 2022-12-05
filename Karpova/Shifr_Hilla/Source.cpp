#include <iostream>
#include <math.h>
#include "Shifr_Hilla.h"
#include "Header.h"
#include <string>
#include <vector>
#include <chrono>


using namespace std;
using namespace chrono;
string word = " ";

int main() {
	Shifr p;
	string e;
	auto start = steady_clock::now();
	e = Hill_encryption(p);
	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<microseconds>(end - start);
	cout << elapsed_ms.count() << endl;

    return 0;


}