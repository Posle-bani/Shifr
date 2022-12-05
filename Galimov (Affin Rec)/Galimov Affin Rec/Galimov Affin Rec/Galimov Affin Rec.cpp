#include <iostream>
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <chrono>
#include "Galimov_rec_aff.h"

using namespace std;

//Рекуррентный аффинный шифр

//struct keys        //структура общая для ключей  
//{
//    int affreca1 = 26, affrecb1 = 6, affreca2 = 6, affrecb2 = 2;
//};
//
//void zapoln_alphavit(vector <char>& alphavit) //заполнение алфавита всей кодировкой ACII
//{
//    iota(alphavit.begin(), alphavit.end(), 'A');
//}
//
//void zapoln_keys(keys& key, vector <int>& alpha, vector <int>& beta)  //переприсваивание нужных мне ключей из структуры
//{
//    alpha.resize(2);
//    beta.resize(2);
//    alpha[0] = key.affreca1;
//    alpha[1] = key.affreca2;
//    beta[0] = key.affrecb1;
//    beta[1] = key.affrecb2;
//}
//
//void Galimov(string& slovo, keys& key)  //сама функция
//{
//    int kolvo = 0, poz = 0, sh_poz = 0;
//    string shslovo;
//    vector <char> alphavit(256);
//    vector <int> shifr, alpha, beta;
//    char el, sh_el;
//    zapoln_keys(key, alpha, beta);//ключи забираются из структуры
//    zapoln_alphavit(alphavit);//алфавит заполняю
//    kolvo = slovo.length();//смотрю количество букв в слове
//    for (int i = 0; i < kolvo; i++)//на каждую букву шаг
//    {
//        el = slovo[i];//беру нужную букву
//        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //нахожу эту букву в алфавите и беру итератор
//        if (it == alphavit.end())//проверка на нахождение буквы
//        {
//            cout << "Element " << el << " not found" << endl;//ну не найдено понятно же
//        }
//        else //а если найдена
//        {
//            poz = distance(alphavit.begin(), it);   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ нахожу позицию в алфавите
//            if (i == 0 || i == 1) //первые два раза коэф по вводу
//            {
//                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size()); //заношу в вектор позицию зашифрованной буквы
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //позиция зашифрованной буквы
//                cout << alphavit[sh_poz];//вывожу зашифрованную букву          
//            }
//            else //тут после второй итерации ключи сами создаются по формуле
//            {
//                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //считаю новую альфу
//                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //считаю новую бетту
//                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size());  //заношу в вектор позицию зашифрованной буквы
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
//                cout << alphavit[sh_poz]; //вывожу зашифрованную букву               
//            }
//        }
//    }
//    cout << endl << "Recurent Affin Shifr" << endl;
//}


int main()
{
    setlocale(LC_ALL, "Russian");
    keys key;
    string slovo="abcd";//тут ввести чему оно равно  
    Galimov(slovo,key);
}

