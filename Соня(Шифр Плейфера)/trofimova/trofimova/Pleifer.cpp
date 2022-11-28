#include "Pleifer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>


using namespace std;
using namespace std::chrono;

void Enmessage(vector<int> index, char matrix[5][5]) {
    int a = 0, b = 0;
    /*cout << "encrypted sequence: " << endl;*/
    for (int i = 0; i <= index.size() - 3; i += 4) {
        a = index[i + 3] + 1;
        // ���� �� ����� ������
        if (index[i] == index[i + 2] && a < 5) {
            /*cout.width(5);
            cout <<*/ matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        // ���� �� ����� ������ � � ����
        if (index[i] == index[i + 2] && a >= 5) {
            a = 0;
            /*cout.width(5);
            cout <<*/ matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        b = index[i + 2] + 1;
        // ���� � ����� �������
        if (index[i + 1] == index[i + 3] && b < 5) {
            /*cout.width(5);
            cout << */matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }
        // ���� � ����� ������� � � ����
        if (index[i + 1] == index[i + 3] && b >= 5) {
            b = 0;
            /*cout.width(5);
            cout << */matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }

        if (index[i] != index[i + 2] && index[i + 1] != index[i + 3]) {
            /*cout.width(5);
            cout << */matrix[index[i + 2]][index[i + 1]] << matrix[index[i]][index[i + 3]];
        }
    }
}
void CinKeyCheck(string& keyword) {
    int q = 0;
    while (q == 0) {
        cout << "enter a keyword: ";
        getline(cin, keyword);
        keyword.erase(remove_if(keyword.begin(), keyword.end(), isspace), keyword.end());

        for (int i = 0; i < keyword.length(); i++) {
            if (isupper(keyword[i])) keyword[i] = tolower(keyword[i]);
        }

        for (int i = 0; i < keyword.length(); i++) {
            if (isalpha(keyword[i])) q = 1;
            else {
                cout << "symbol " << keyword[i] << " is not appropriate!! " << endl;
                q = 0;
                break;
            }
        }
    }
}
void DeleteDouble(string& keyword) {
    for (int i = 1; i < keyword.length(); i++) {
        if (keyword[i - 1] == keyword[i]) {
            keyword.erase(i, 1);
            i--;
        }
    }
}
void DeleteKeyLetters(string& keyword, string& alphabet) {
    for (int i = 0; i < keyword.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (keyword[i] == alphabet[j]) alphabet.erase(j, 1);
        }
    }
}
void CinMessageCheck(string& word) {
    int p = 0;
    while (p == 0) {
        cout << "enter massage: ";
        getline(cin, word);
        word.erase(remove_if(word.begin(), word.end(), isspace), word.end());


        for (int i = 0; i < word.length(); i++) {
            if (isupper(word[i])) word[i] = tolower(word[i]);
        }


        for (int i = 0; i < word.length(); i++) {
            if (isalpha(word[i])) p = 1;
            else {
                cout << "symbol " << word[i] << " is not appropriate!! " << endl;
                p = 0;
                break;
            }
        }
    }
}
void DoubleMessageCheck(string& word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == word[i + 1]) word.insert(i + 1, 1, 'x');
    }
}
void AddSymbol(string& word) {
    if (word.length() % 2 != 0) word.push_back('x');
}
void BygramsFormation(string& word) {
    for (int i = 0; i < word.length(); i += 2) {
        /*cout.width(5);
        cout <<*/ word[i] << word[i + 1];
    }
    /*cout << endl;*/
}
void MatrixCreation(char(&matrix)[5][5], string& keyword, string& alphabet) {
    /*cout << "key matrix: " << endl;*/
    int k = 0, m = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < keyword.length()) {
                matrix[i][j] = keyword[k];
            }
            if (k >= keyword.length()) {
                matrix[i][j] = alphabet[m];
                m++;
            }
            k++;
        }
    }

}
//void PrintMatrix(char(&matrix)[5][5]) {
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
void FindId(char(&matrix)[5][5], vector <int>& index, string& word) {
    for (int i = 0; i < word.length(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (word[i] == matrix[j][k]) {
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
}

int Encryption_pleifer(string word) {
    vector<int> index;
    string keyword = "", word = "";
    string alphabet = "abcdefghijklmnoprstuvwxyz";
    char matrix[5][5];

    CinKeyCheck(keyword);
    DeleteDouble(keyword);
    DeleteKeyLetters(keyword, alphabet);
    MatrixCreation(matrix, keyword, alphabet);
   /* PrintMatrix(matrix);*/
    CinMessageCheck(word);
    DoubleMessageCheck(word);
    AddSymbol(word);
    BygramsFormation(word);
    FindId(matrix, index, word);

    for (int i = 0; i < index.size(); i += 2) cout << index[i] << " " << index[i + 1] << "   ";
    cout << endl;

    auto start = steady_clock::now();
    Enmessage(index, matrix);
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<microseconds>(end - start);

    return elapsed_ms.count();
}
