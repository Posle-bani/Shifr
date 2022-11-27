
#include <iostream>

template <typename temp> temp GetCorrectNumber(temp min, temp max) {
    temp x{};
    while ((cin >> x).fail() || x < min || x > max) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Enter a valid number!" << endl;
    }
    return x;
}

int search(char a, std::string alphabet) {
    int j = 0;
    while (alphabet.at(j) != a) {
        if (j + 1 < (alphabet.size()))
            j++;
        else
            return -1;
    }
    return j;
}

int Evklid(int a, int b, int c) {
    int otvet[4];
    int bb = b, x_2 = 1, x_1 = 0, y_2 = 0, y_1 = 1, x = 0, y = 0, q = 0, r = 0;
    while (b > 0) {
        q = a / b;
        r = a % b;
        x = x_2 - q * x_1;
        y = y_2 - q * y_1;

        a = b;
        b = r;
        x_2 = x_1;
        x_1 = x;
        y_2 = y_1;
        y_1 = y;
    }

    otvet[0] = (x % bb); //остаток от деления
    otvet[1] = x_2;
    otvet[2] = y_2;
    otvet[3] = b;
    if (c == 0) return otvet[0];
    else {
        if (c == 1) return otvet[1];
        else {
            if (c == 2) return otvet[2];
            else return otvet[3];
        }
    }
}

std::string Zashifr(int alfa, int beta,std::string alphabet) {
    int j;
    std::string word_to_shifr;
    std::string shifr_result;
    std::cout << "Введите слово за шифрования:" << std::endl;
    std::cin >> word_to_shifr;
    for (int i = 0; i < word_to_shifr.size(); i++) {
        j = search(word_to_shifr.at(i), alphabet);                                        //ищем положение i-го символа в нашем алфавите
        if (j == -1)
            shifr_result += word_to_shifr.at(i);
        else {
            shifr_result += alphabet.at(((alfa * j) + beta) % (alphabet.size()));  //дописываем в переменную out символ с расчитанным положением в алфавите
        }
    }
    return shifr_result;
}

int main()
{
    int alfa = 0, beta = 0;
    std::string alphabet = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    std::cout << "Введите ключ(два значения)"<<std::endl;
    alfa = GetCorrectNumber(1, 67);
    beta = GetCorrectNumber(1, 67);
    std::cout <<"Полученн" Zashifr(alfa, beta, alphabet) << std::endl;
}

