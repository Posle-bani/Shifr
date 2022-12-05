#include <iostream>
#include <string>
#include <chrono>
#include "VigenerR.h"

using namespace std;
using namespace chrono;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// ������� ��������� ���� �������
//���� ������ � �������� � ��������� ��� �����.
int keycode(char s) {
    for (size_t i = 0; i < alphabet.length(); i++) {
        if (s == alphabet[i]) return i;
    }
    return 0;
}

string Encode(string text, string key) {
    string code;
    for (size_t i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key) {
    string code;
    for (size_t i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];
    }
    return code;
}

void Vigenere_cipher(std::string word) {
    setlocale(LC_ALL, "Russian");
    string key;
    //char x;
    //cout << "�����������(1) or ������������(2)" << endl;
    //cin >> x;

 //   if (x != '1' && x != '2') {
   //     cout << "��������� ������������ ���������� ��������" << endl;//�������� �� ������������
     //   exit(0);
    //}

    //cout << "������� ����� ��� ��������: ";//������� ����� ��� �������
    //cin >> txt;
    cout << "������� ����: ";
    cin >> key;

    for (auto& c : word) c = toupper(c);
    for (auto& c : key) c = toupper(c);

    // �������� ������ �������_1
    system_clock::time_point start = system_clock::now();
    Encode(word, key);
    //if (x == '2') cout << Decode(txt, key);
    // �������� ������ �������_2
    system_clock::time_point end = system_clock::now();
    // ���������� ��� ������� ��������� � ��������� ��� ��������
    duration<double> sec = end - start;
    cout
        << "\n����� ���������� ���������:"
        << "\n" << duration_cast<microseconds>(end - start).count() << " microseconds\n";
       // << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
}