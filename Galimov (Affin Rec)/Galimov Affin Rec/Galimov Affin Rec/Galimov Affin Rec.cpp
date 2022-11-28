#include <iostream>
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;

//Рекуррентный аффинный шифр

int proverka(int &x, int min, int max)
{
    cin >> x;
  while (cin.fail() || x<min || x>max)
    {
      cout << "Введено некорректное значение" << endl << "Диапазон: " << min << "-" << max << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin >> x;
    } 
        return x;
}

void input_a_b(vector <int> &alpha, vector <int>& beta)
{
    int x = 0;
    cout << "Введите альфа" << endl;
    alpha.push_back(proverka(x, 0, 10000));
    cout << "Введите бетта" << endl;
    beta.push_back(proverka(x, 0, 10000));
    cout << "Введите альфа2" << endl;   //ввод переменных
    alpha.push_back(proverka(x, 0, 10000));
    cout << "Введите бетта2" << endl;
    beta.push_back(proverka(x, 0, 10000));
}

void zapoln_alphavit(vector <char> &alphavit)
{
    iota(alphavit.begin(), alphavit.begin() + 26, 'A');
    iota(alphavit.begin() + 26, alphavit.end(), 'a'); //заполнение алфавита
}

void slovo_kolvo(string& slovo, int& kolvo)
{
    //cout << "Введите слово" << endl;
    //getline(cin >> ws, slovo);                  //пробелы тоже считает!!!!!!!!!!!
    kolvo = slovo.length();
    cout << "Кол-во элементов в слове: " << kolvo << endl;
}

void Galimov(string &slovo)
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    string shslovo;
    vector <char> alphavit(52);
    vector <int> shifr, alpha, beta;
    char el, sh_el;
    input_a_b(alpha, beta);
    zapoln_alphavit(alphavit);
    slovo_kolvo(slovo, kolvo);
    auto start = chrono::high_resolution_clock::now();//засекаю время
    for (int i = 0; i < kolvo; i++)
    {
        el = slovo[i];//беру нужную букву
        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //нахожу эту букву в алфавите и беру итератор
        if (it == alphavit.end())//проверка на нахождение буквы
        {
            cout << "Элемент "<<el<< " не найден" << endl;
        }
        else
        {
            poz = distance(alphavit.begin(), it);   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ нахожу позицию в алфавите
            if (i == 0 || i == 1) //первые два раза коэф по вводу
            {
                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size()); //заношу в вектор позицию зашифрованной буквы
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
                cout << alphavit[sh_poz];//вывожу зашифрованную букву        или cout << alphavit[sh_poz-1];     
            }
            else
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //считаю новую альфу
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //считаю новую бетту
                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size());  //заношу в вектор позицию зашифрованной буквы
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
                cout << alphavit[sh_poz]; //вывожу зашифрованную букву           или cout << alphavit[sh_poz-1];     
            }
        }
    }
    auto elapsed = chrono::high_resolution_clock::now() - start;//засек конец
    long long microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();//вывод в мкрс
    cout << endl << "Рекуррентный аффинный шифр" << "  Затраченное на шифрование время: " << microseconds << " мкрс" << endl;
}

int main()
{
    string slovo="sdgkjshdgjkhsdgsdhfkkskKHGJHEJHJHDKUSHUKHGhsfhgkjshdfhskdgksjf";//тут ввести чему оно равно
    setlocale(LC_ALL, "Russian");
    Galimov(slovo);
}

