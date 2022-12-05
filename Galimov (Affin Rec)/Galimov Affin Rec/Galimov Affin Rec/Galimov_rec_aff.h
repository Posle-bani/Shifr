#pragma once
#include <iostream>
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

struct keys
{
    int affreca1 = 26, affrecb1 = 6, affreca2 = 6, affrecb2 = 2;
};

void zapoln_alphavit(vector <char>& alphavit);

void zapoln_keys(keys& key, vector <int>& alpha, vector <int>& beta);

void Galimov(string& slovo,keys&keys);

