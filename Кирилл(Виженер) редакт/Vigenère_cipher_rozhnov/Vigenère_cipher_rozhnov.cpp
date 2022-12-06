#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include "Header.h"
#include "Vigenere.h"

using namespace std;
string D;


//struct Encryption
//{
//    string word = "pipec";
//    string keyword = "aklmn";
//};
/*void ops(string word, string keyword) //растягиваем ключ, если его длина меньше длины слова.
{
    if (word.length() >= keyword.length())
    {
        for (int i = 0; i < (word.length() / keyword.length()); i++)
        {
            D = D + keyword;
        }
    }
    else {
        for (int j = 0; j < (word.length() % keyword.length()); j++)
        {
            D = D + keyword[j];
        }
    }

}
*/
void Encode(vector <char> alphabet, string word, string keyword)
{
    string code;
    int poz = 0;//индекс буквы
    char el;
    int sh_key, sh_poz;
    char sh_el;
    for (size_t i = 0; i < word.length(); i++)
    {
        if (word.length() >= keyword.length())
        {
            for (int i = 0; i < (word.length() / keyword.length()); i++)
            {
                D = D + keyword;
            }
        }
        else {
            for (int j = 0; j < (word.length() % keyword.length()); j++)
            {
                D = D + keyword[j];
            }
        }

        //keyword = keyword + keyword + keyword;
        el = word[i];
        vector<char>::iterator it = find(alphabet.begin(), alphabet.end(), el);
        poz = distance(alphabet.begin(), it); //номер буквы в алфавите из слова   

        sh_el = D[i];//считываю по буквам пароль
        vector<char>::iterator it2 = find(alphabet.begin(), alphabet.end(), sh_el);//нахожу итератор его позиции в алфавите
        sh_key = distance(alphabet.begin(), it2); //нахожу его позицию в алфавите(пароля)
        //sh_key2 = sh_key

        sh_poz = (poz + sh_key) % alphabet.size(); //складываем номер буквы из слова на номер буквы из пароля

        cout << alphabet[sh_poz];
        //cout << "\n" << sh_key << endl;
        //cout << "\n" << keyword.length() << endl;
        //cout << "\n" << D << endl;
    }
}
int main()
//void Vigenere_cipher(Encryption p)
{
    //setlocale(LC_ALL, "Russian");

    Encryption p;

    vector <char> alphabet(256);
    iota(alphabet.begin(), alphabet.end(), 'A');
    string keyword = p.keyword;
    string word = p.word;
    Encode(alphabet, word, keyword);
}