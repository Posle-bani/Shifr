#include <iostream>
#include <math.h>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

unsigned int lenght(const char s[])
{
	int i = 0;
	while (s[i++]);
	return (i - 1);
}

//при шифровании по Хиллу мы используем mod26 для замены символов

vector<int> key = { 1, 2, 3, 7, 5, 4, 8, 2, 7 };

int main()
{
	string word;
	time_t start, end;
	cout << "\nInput word";
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	getline(cin, word);

	time(&start);

	if ((word.length() != 0) and (word.length() % 3 != 0))
	{
		int amount = 3 - word.length() % 3;
		for (int i(0); i < amount; ++i)
			word += '#';
	}
	//cout << endl << word.length() <<" "<< word;

	int i(0);
	string outputword = "";
	while (i < word.length() - 1) {
		for (int j(0); j < 3; ++j) {
			int letter = (word[i] * key[j * 3 + 0] + word[i + 1] * key[j * 3 + 1] + word[i + 2] * key[j * 3 + 2]) % 26;
			outputword += (char)letter;
		}
		i += 3;
	}

	time(&end);
	double seconds;
	seconds = difftime(end, start);

	cout << endl << " " << outputword << endl;
	cout << seconds << endl;

	return 0;
}
