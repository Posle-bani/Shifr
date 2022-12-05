#include <iostream>
#include <math.h>
#include "Shifr_Hilla.h"
#include <string>
#include <vector>
#include "Header.h"

using namespace std;

//Ключ матрица, заданная изначально

string symbols;
vector<int> key = {};

vector<int> KEY(string keyword)
{
	for (int s = 0; s < keyword.length(); s++) {
		for (int c = 0; c < symbols.length();c++ )
		{
			if (keyword[s] == symbols[c])
			{
				key.push_back(c);
				//cout << c << endl;
			}
		}
	}
	return key;
}

//алфавит

string alphabet() {
	string alpabet = "";
	for (int i = 'A'; i <= 'Z'; i++)
		alpabet += (char)i;
	for (int i = 'a'; i <= 'z'; i++)
		alpabet += (char)i;
	return alpabet;
}

void output(int n) {

	cout << n << endl;
}

string Hill_encryption(Shifr p)
{	
	symbols = alphabet();

	key = KEY(p.keyword);

	if ((p.word.length() != 0) and (p.word.length() % 3 != 0))
	{
		int amount = 3 - p.word.length() % 3;
		for (int i(0); i < amount; ++i)
			p.word += 'A';
	}

	for (int s = 0; s < p.word.length();s++) {
		for (int c = 0; c < symbols.length(); )
		{
			if (p.word[s] == symbols[c])
			{
				p.word[s] = c;
				c++;
				//cout << c << endl;
			}
			else
				c++;
		}
	}
	//cout << word << endl;


	int i(0);
	string outputword = "";
	while (i < p.word.length() - 1) {
		for (int j(0); j < 3; ++j) {
			//при шифровании по Хиллу мы используем mod26 для замены символов(так как в вводятся заглавные и строчные буквы английского алфавита)
			int letter = (p.word[i] * key[j * 3 + 0] + p.word[i + 1] * key[j * 3 + 1] + p.word[i + 2] * key[j * 3 + 2]) % 26;
			outputword += symbols[letter+1];
		}
		i += 3;
	}


	//cout << endl << outputword <<endl;
	//cout << endl << elapsed_ms.count() <<endl;

	return outputword;
}

