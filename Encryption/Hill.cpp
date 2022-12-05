#include <iostream>
#include <math.h>
#include "Hill.h"
#include <string>
#include <chrono>
#include <vector>

using namespace std::chrono;

//Ключ матрица, заданная изначально
std::vector<int> key = { 1, 2, 3, 7, 5, 4, 8, 2, 7 };

//алфавит
std::string alphabet() {
	std::string alpabet = " ";
	for (int i = 'A'; i <= 'Z'; i++)
		alpabet += (char)i;
	for (int i = 'a'; i <= 'z'; i++)
		alpabet += (char)i;
	return alpabet;
}


void output(int n) {

	std::cout << n <<" microseconds" << std::endl;
}

int Hill_encryption(std::string word)
{
	auto start = steady_clock::now();

	if ((word.length() != 0) and (word.length() % 3 != 0))
	{
		int amount = 3 - word.length() % 3;
		for (int i(0); i < amount; ++i)
			word += ' ';
	}
	std::string symbols;
	symbols = alphabet();

	for (int s = 0; s < word.length(); s++) {
		for (int c = 0; c < symbols.length(); c++)
		{
			if (word[s] == symbols[c])
			{
				word[s] = c;
				//std::cout << c << std::endl;
			}
		}
	}
	//std::cout << word << std::endl;


	int i(0);
	std::string outputword = "";
	while (i < word.length() - 1) {
		for (int j(0); j < 3; ++j) {
			//при шифровании по Хиллу мы используем mod26 для замены символов(так как в вводятся заглавные и строчные буквы английского алфавита)
			int letter = (word[i] * key[j * 3 + 0] + word[i + 1] * key[j * 3 + 1] + word[i + 2] * key[j * 3 + 2]) % 26;
			outputword += symbols[letter + 1];
		}
		i += 3;
	}



	auto end = steady_clock::now();
	auto elapsed_ms = duration_cast<microseconds>(end - start);

	//std::cout << std::endl << outputword << std::endl;
	//std::cout << std::endl << elapsed_ms.count() << std::endl;

	output(elapsed_ms.count());
	return elapsed_ms.count();
}
