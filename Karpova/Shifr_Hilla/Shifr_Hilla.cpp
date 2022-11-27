#include <iostream>
#include <math.h>
#include "Shifr_Hilla.h"
#include <string>
#include <chrono>
#include <vector>

using namespace std::chrono;

//Ключ матрица, заданная изначально
std:: vector<int> key = { 1, 2, 3, 7, 5, 4, 8, 2, 7 };

int Hill_encryption(std::string word)
{
	//std::string word;
	//std:: cout << "\nInput word";
	//std:: cin.clear();
	//std:: cin.ignore(INT_MAX, '\n');
	//getline(std:: cin, word);
 
	auto start = steady_clock::now();

	if ((word.length() != 0) and (word.length() % 3 != 0))
	{
		int amount = 3 - word.length() % 3;
		for (int i(0); i < amount; ++i)
			word += '#';
	}
	//cout << endl << word.length() <<" "<< word;

	int i(0);
	std:: string outputword = "";
	while (i < word.length() - 1) {
		for (int j(0); j < 3; ++j) {
			//при шифровании по Хиллу мы используем mod52 для замены символов(так как в вводятся заглавные и строчные буквы английского алфавита)
			int letter = (word[i] * key[j * 3 + 0] + word[i + 1] * key[j * 3 + 1] + word[i + 2] * key[j * 3 + 2]) % 52;
			outputword += (char)letter;
		}
		i += 3;
	}

	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<milliseconds>(end - start);

	//std::cout << std::endl << outputword << std::endl;
	//std::cout << std::endl << elapsed_ms.count() << std::endl;
	

	return elapsed_ms.count();
}
