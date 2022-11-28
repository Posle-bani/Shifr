#include <iostream>
#include <string>
#include <chrono>
#include "Vigenere.h"

using namespace std;
using namespace chrono;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// функция получения кода символа
//ищем сивмол в алфавите и возращаем его номер.
int keycode(char s) {
    for (int i = 0; i < alphabet.length(); i++) {
        if (s == alphabet[i]) return i;
    }
    return 0;
}

string Encode(string text, string key) {
    string code;
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key) {
    string code;
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];
    }
    return code;
}

int Vigenere_cipher() {
    setlocale(LC_ALL, "Russian");
    string txt, key;
    char x;
    cout << "Зашифровать(1) or Расшифровать(2)" << endl;
    cin >> x;

    if (x != '1' && x != '2') {
        cout << "Проверьте корректность введенного значения" << endl;//проверка на корректность
        exit(0);
    }

    cout << "Введите текст без пробелов: ";//вводить текст без пробела
    cin >> txt;
    cout << "Введите ключ: ";
    cin >> key;

    for (auto& c : txt) c = toupper(c);
    for (auto& c : key) c = toupper(c);

    // Получаем момент времени_1
    system_clock::time_point start = system_clock::now();
    if (x == '1') cout << Encode(txt, key);
    if (x == '2') cout << Decode(txt, key);
    // Получаем момент времени_2
    system_clock::time_point end = system_clock::now();
    // Определяем тип объекта интервала и вычисляем его значение
    duration<double> sec = end - start;
    cout
        << "\nВремя выполнения программы:"
        << "\n" << duration_cast<microseconds>(end - start).count() << " microseconds\n"
        << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
}