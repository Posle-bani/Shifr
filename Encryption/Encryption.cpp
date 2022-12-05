#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>
#include "Hill.h"
#include "AffG.h"
#include "Pleifer.h"
#include "Affin.h"
#include "Vigenere.h"
#include "VigenerR.h"

using namespace std;

template <typename T>
T correctNumber(T min, T max) 
{
	int x;
	while ((cin >> x).fail() || (x < min) || (x > max)) 
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Type number (" << min << "-" << max << "):";
	}
	return x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Enter the word you want to encrypt: ";
	string word;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, word);
	int action = -1;
	while (action)
	{
		cout << "\n\nChoose algorithm: \n1. Hill (Karpova) \n2. Pleifer (Trofimova) \n3. Affin (Kosov)  \n4. Affin Rec (Galimov) \n5. Vigenere (Rozhnov) \n6. Vigenere (Syromyatnikov)  \n0. Exit \n";
		action = correctNumber(0, 9);
		switch (action)
		{
		case 1:
		{
			Hill_encryption(word);
			break;
		}
		case 2:
		{
			Encryption_pleifer(word);
			break;
		}
		case 3:
		{
			Affin_method(word);
			break;
		}
		case 4:
		{
			Galimov(word);
			break;
		}
		case 5:
		{
			Vigenere_cipher(word);
			break;
		}
		case 6:
		{
			code(word);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Wrong number. Please, enter right action";
		}
		}
	}
}