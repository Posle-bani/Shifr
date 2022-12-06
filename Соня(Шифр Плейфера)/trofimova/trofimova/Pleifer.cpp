#include "Pleifer.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>


using namespace std;
using namespace std::chrono;

//void Enmessage(vector<int> index, char matrix[5][5]) {
//    int a = 0, b = 0;
//    /*cout << "encrypted sequence: " << endl;*/
//    for (int i = 0; i <= index.size() - 3; i += 4) {
//        a = index[i + 3] + 1;
//        // åñëè íà îäíîé ñòðîêå
//        if (index[i] == index[i + 2] && a < 5) {
//            /*cout.width(5);
//            cout <<*/ matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
//        }
//        // åñëè íà îäíîé ñòðîêå è ó êðàÿ
//        if (index[i] == index[i + 2] && a >= 5) {
//            a = 0;
//            /*cout.width(5);
//            cout <<*/ matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
//        }
//        b = index[i + 2] + 1;
//        // åñëè â îäíîì ñòîëáöå
//        if (index[i + 1] == index[i + 3] && b < 5) {
//            /*cout.width(5);
//            cout << */matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
//        }
//        // åñëè â îäíîì ñòîëáöå è ó êðàÿ
//        if (index[i + 1] == index[i + 3] && b >= 5) {
//            b = 0;
//            /*cout.width(5);
//            cout << */matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
//        }
//
//        if (index[i] != index[i + 2] && index[i + 1] != index[i + 3]) {
//            /*cout.width(5);
//            cout << */matrix[index[i + 2]][index[i + 1]] << matrix[index[i]][index[i + 3]];
//        }
//    }
//}
////void CinKeyCheck(Encryption &p) {
////    int q = 0;
////    while (q == 0) {
////        /*cout << "enter a keyword: ";
////        getline(cin, keyword);*/
////        p.keyword.erase(remove_if(p.keyword.begin(), p.keyword.end(), isspace),p.keyword.end());
////
////        for (int i = 0; i < p.keyword.length(); i++) {
////            if (isupper(p.keyword[i])) p.keyword[i] = tolower(p.keyword[i]);
////        }
////
////        /*for (int i = 0; i < keyword.length(); i++) {
////            if (isalpha(keyword[i])) q = 1;
////            else {
////                cout << "symbol " << keyword[i] << " is not appropriate!! " << endl;
////                q = 0;
////                break;
////            }
////        }*/
////    }
////}
//void DeleteDouble(Encryption&p) {
//    for (int i = 1; i < p.keyword.length(); i++) {
//        if (p.keyword[i - 1] == p.keyword[i]) {
//            p.keyword.erase(i, 1);
//            i--;
//        }
//    }
//}
//void DeleteKeyLetters(Encryption&p, string& alphabet) {
//    for (int i = 0; i < p.keyword.length(); i++) {
//        for (int j = 0; j < alphabet.length(); j++) {
//            if (p.keyword[i] == alphabet[j]) alphabet.erase(j, 1);
//        }
//    }
//}
//void CinMessageCheck(Encryption&p) {
//    int q = 0;
//    while (q == 0) {
//        /*cout << "enter massage: ";
//        getline(cin, word);*/
//        p.word.erase(remove_if(p.word.begin(),p.word.end(), isspace),p. word.end());
//
//
//        for (int i = 0; i < p.word.length(); i++) {
//            if (isupper(p.word[i])) p.word[i] = tolower(p.word[i]);
//        }
//
//
//        /*for (int i = 0; i < word.length(); i++) {
//            if (isalpha(word[i])) p = 1;
//            else {
//                cout << "symbol " << word[i] << " is not appropriate!! " << endl;
//                p = 0;
//                break;
//            }
//        }*/
//    }
//}
//void DoubleMessageCheck(Encryption&p) {
//    for (int i = 0; i < p.word.length(); i++) {
//        if (p.word[i] == p.word[i + 1]) p.word.insert(i + 1, 1, 'x');
//    }
//}
//void AddSymbol(Encryption&p) {
//    if (p.word.length() % 2 != 0) p.word.push_back('x');
//}
//void BygramsFormation(Encryption&p) {
//    for (int i = 0; i < p.word.length(); i += 2) {
//        /*cout.width(5);
//        cout <<*/ p.word[i] << p.word[i + 1];
//    }
//    /*cout << endl;*/
//}
//void MatrixCreation(char(&matrix)[5][5], Encryption&p, string& alphabet) {
//    /*cout << "key matrix: " << endl;*/
//    int k = 0, m = 0;
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 5; j++) {
//            if (k < p.keyword.length()) {
//                matrix[i][j] = p.keyword[k];
//            }
//            if (k >= p.keyword.length()) {
//                matrix[i][j] = alphabet[m];
//                m++;
//            }
//            k++;
//        }
//    }
//
//}
////void PrintMatrix(char(&matrix)[5][5]) {
////    for (int i = 0; i < 5; i++) {
////        for (int j = 0; j < 5; j++) {
////            cout << matrix[i][j] << " ";
////        }
////        cout << endl;
////    }
////}
//void FindId(char(&matrix)[5][5], vector <int>& index, Encryption&p) {
//    for (int i = 0; i < p.word.length(); i++) {
//        for (int j = 0; j < 5; j++) {
//            for (int k = 0; k < 5; k++) {
//                if (p.word[i] == matrix[j][k]) {
//                    index.push_back(j);
//                    index.push_back(k);
//                }
//            }
//        }
//    }
//}

int main ()
//string Encryption_pleifer(Encryption p) 
{
    Encryption p;
    vector<int> index;
    string alphabet = "abcdefghijklmnoprstuvwxyz";
    char matrix[5][5];
    auto start = steady_clock::now();
    //key check
    int q = 0;
    while (q == 0) {
        p.keyword.erase(remove_if(p.keyword.begin(), p.keyword.end(), isspace), p.keyword.end());
        p.keyword.erase(remove_if(p.keyword.begin(), p.keyword.end(), ispunct), p.keyword.end());
        p.keyword.erase(remove_if(p.keyword.begin(), p.keyword.end(), isdigit), p.keyword.end());

        for (int i = 0; i < p.keyword.length(); i++) {
            if (isupper(p.keyword[i])) p.keyword[i] = tolower(p.keyword[i]);
        }
    };
    // delete double
    for (int i = 1; i < p.keyword.length(); i++) {
        if (p.keyword[i - 1] == p.keyword[i]) {
            p.keyword.erase(i, 1);
            i--;
        }
    };
    //delete key letters
    for (int i = 0; i < p.keyword.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (p.keyword[i] == alphabet[j]) alphabet.erase(j, 1);
        }
    };
    //word check
    int l = 0;
    while (l == 0) {
        p.word.erase(remove_if(p.word.begin(), p.word.end(), isspace), p.word.end());
        p.word.erase(remove_if(p.word.begin(), p.word.end(), ispunct), p.word.end());
        p.word.erase(remove_if(p.word.begin(), p.word.end(), isdigit), p.word.end());
        for (int i = 0; i < p.word.length(); i++) {
            if (isupper(p.word[i])) p.word[i] = tolower(p.word[i]);
        }
    };
    //double message check
    for (int i = 0; i < p.word.length(); i++) {
        if (p.word[i] == p.word[i + 1]) p.word.insert(i + 1, 1, 'x');
    };
    //add symbol
    if (p.word.length() % 2 != 0) p.word.push_back('x');
    //bygrams formation
    for (int i = 0; i < p.word.length(); i += 2) {
        p.word[i] << p.word[i + 1];
    };
    //matrix creation
    int k = 0, m = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < p.keyword.length()) {
                matrix[i][j] = p.keyword[k];
            }
            if (k >= p.keyword.length()) {
                matrix[i][j] = alphabet[m];
                m++;
            }
            k++;
        }
    };
    //find id
    for (int i = 0; i < p.word.length(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (p.word[i] == matrix[j][k]) {
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
    //enmessage
   
    string outputword = "";
    int a = 0, b = 0;
    /*cout << "encrypted sequence: " << endl;*/
    for (int i = 0; i <= index.size() - 3; i += 4) {
        a = index[i + 3] + 1;
        // åñëè íà îäíîé ñòðîêå
        if (index[i] == index[i + 2] && a < 5) {
            /*cout.width(5);
            cout <<*/ outputword+=matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        // åñëè íà îäíîé ñòðîêå è ó êðàÿ
        if (index[i] == index[i + 2] && a >= 5) {
            a = 0;
            /*cout.width(5);
            cout <<*/ outputword += matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        b = index[i + 2] + 1;
        // åñëè â îäíîì ñòîëáöå
        if (index[i + 1] == index[i + 3] && b < 5) {
            /*cout.width(5);
            cout << */outputword += matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }
        // åñëè â îäíîì ñòîëáöå è ó êðàÿ
        if (index[i + 1] == index[i + 3] && b >= 5) {
            b = 0;
            /*cout.width(5);
            cout << */outputword += matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }

        if (index[i] != index[i + 2] && index[i + 1] != index[i + 3]) {
            /*cout.width(5);
            cout << */outputword += matrix[index[i + 2]][index[i + 1]] << matrix[index[i]][index[i + 3]];
        }
    }
    //CinKeyCheck(p);
    //DeleteDouble(p);
    //DeleteKeyLetters(p, alphabet);
    //MatrixCreation(matrix, p, alphabet);
    ///* PrintMatrix(matrix);*/
    //CinMessageCheck(p);
    //DoubleMessageCheck(p);
    //AddSymbol(p);
    //BygramsFormation(p);
    //FindId(matrix, index, p);

    //for (int i = 0; i < index.size(); i += 2) cout << index[i] << " " << index[i + 1] << "   ";
    //cout << endl;

    //auto start = steady_clock::now();
    //Enmessage(index, matrix);
    auto end = steady_clock::now();
    auto elapsed_ms = duration_cast<microseconds>(end - start);
    cout << elapsed_ms.count() << endl;

    //return outputword;
}
