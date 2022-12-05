#include <iostream>
#include <string>
#include <chrono>
#include "Vigenere.h"

using namespace std;
using namespace chrono;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$%&'()*+,-./0123456789:;<=>?@ ";

// функция получения кода символа
//ищем сивмол в алфавите и возращаем его номер.
int keycode(char s) {
    for (int i = 0; i < alphabet.length(); i++) {//для i меньше длины алфавита увеличивается на одно значение. начинаем с нуля, так как для шифра индексы для букв начинаются с нуля.
        if (s == alphabet[i])
            return i;
    }
    return 0;//если после прохождения цикла не нашлась буква, то возвращаем ноль.
}

string Encode(string text, string key) {
    string code;//keycode(text[i]) число каждой буквы текста
    //keycode(key[i]) число каждой буквы ключа
    //keycode(key[i % key.length()]) делим по модулю длины ключа, чтобы ключ растянулся по вводимому тексту
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key) {
    string code;
    for (int i = 0; i < text.length(); i++) {
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];//прибалвяем длину алфавита, чтобы избежать отрицательные числа
    }
    return code;
}

void in()
{
    string txt, key;
    char x;
    cout << "Encode(1) or Decode(2)" << endl;
    cin >> x;

    if (x != '1' && x != '2') {
        cout << "Check if the entered value is correct" << endl;//проверка на корректность
        exit(0);
    }
    cout << "Enter text without spaces: ";
    cin >> txt;
    cout << "Enter key: ";
    cin >> key;

    //если пользователь текст или ключ в разных регистрах, нам нужно привести с верхнему регистру(ЗАГЛАВНЫЕ БУКВЫ):
    for (auto& c : txt) c = toupper(c);
    for (auto& c : key) c = toupper(c);

    if (x == '1') cout << Encode(txt, key);
    if (x == '2') cout << Decode(txt, key);
}

int main() {
    /*setlocale(LC_ALL, "Russian");
    string txt, key;
    char x;
    cout << "Encode(1) or Decode(2)" << endl;
    cin >> x;

    if (x != '1' && x != '2') {
        cout << "Check if the entered value is correct" << endl;//проверка на корректность
        exit(0);
    }

    //cout << "Enter text without spaces: ";
    //cin >> txt;
    //cout << "Enter key: ";
    //cin >> key;

    //for (auto& c : txt) c = toupper(c);
    //for (auto& c : key) c = toupper(c);
*/
// Получаем момент времени_1
    system_clock::time_point start = system_clock::now();
    //if (x == '1') cout << Encode(txt, key);
    in();
    //if (x == '2') cout << Decode(txt, key);
    // Получаем момент времени_2
    system_clock::time_point end = system_clock::now();
    // Определяем тип объекта интервала и вычисляем его значение
    duration<double> sec = end - start;
    cout
        << "\nProgram execution time:"
        << "\n" << duration_cast<microseconds>(end - start).count() << " microseconds\n"
        << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
}
/*
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ#$%&'()*+,-./0123456789:;<=>?@";
string znaki = "#$%&'()*+,-./0123456789:;<#$%&'()*+,-./0123456789:;<=>?@";

// функция получения кода символа
//ищем сивмол в алфавите и возращаем его номер.
int keycode(char s) {
    for (int i = 0; i < alphabet.length(); i++) {//для i меньше длины алфавита увеличивается на одно значение. начинаем с нуля, так как для шифра индексы для букв начинаются с нуля.
        for (int c = 0; c < znaki.length(); c++)
        {
            if (alphabet[i] == znaki[c]) {
                (s == znaki[c]);
                return c;
            }
            else
                (s == alphabet[i]);
            return i;
        }
    }
    return 0;//если после прохождения цикла не нашлась буква, то возвращаем ноль.
}*/
