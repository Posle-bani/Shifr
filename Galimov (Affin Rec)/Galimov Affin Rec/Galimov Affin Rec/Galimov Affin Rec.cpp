//#include <iostream>
//#include <locale>
//#include <vector>
//#include <numeric>
//#include <string>
//#include <algorithm>
//#include <chrono>
//#include "Galimov_rec_aff.h"
//
//using namespace std;
//
////Рекуррентный аффинный шифр
//
//struct keys
//{
//    int affreca1 = 1, affrecb1 = 1, affreca2 = 1, affrecb2 = 1;
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
//    vector <char> alphavit(256);
//    vector <int> shifr, alpha, beta;
//    char el;
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
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //позиция зашифрованной буквы
//                shifr.push_back(alphavit[sh_poz]); //заношу в вектор зашифрованную букву
//                //cout << alphavit[sh_poz];//вывожу зашифрованную букву          
//            }
//            else //тут после второй итерации ключи сами создаются по формуле
//            {
//                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //считаю новую альфу
//                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //считаю новую бетту
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
//                shifr.push_back(alphavit[sh_poz]);  //заношу в вектор зашифрованную букву               
//                //cout << alphavit[sh_poz]; //вывожу зашифрованную букву               
//            }
//        }
//    }
//    //cout << endl << "Recurent Affin Shifr" << endl;
//}
//
//void deshifr_Galimov(keys& key)
//{
//    string sh_slovo;
//    int kolvo_sh_bukv,sh_poz,poz;
//    vector <char> alphavit(256);
//    vector <int> alpha, beta;
//    char sh_el;
//    zapoln_alphavit(alphavit);//алфавит заполняю
//    zapoln_keys(key, alpha, beta);//ключи забираются из структуры
//    cout << "Введите шифрованный текст" << endl;
//    getline(cin >> ws, sh_slovo);
//    kolvo_sh_bukv = sh_slovo.length();
//    if (kolvo_sh_bukv > 2)
//    {
//
//    }
//    else//до 2 элементов
//    {
//        for (int i = 0; i < 2; i++)
//        {
//            sh_el = sh_slovo[i];
//            vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), sh_el);
//            sh_poz= distance(alphavit.begin(), it);//позиция зашифрованной буквы в алфавите
//            poz = (sh_poz - beta[i]) / alpha[i];
//            cout << alphavit[poz];
//        }
//    }
//}
//
//int main()
//{
//    setlocale(LC_ALL, "Russian");
//    keys key;
//    string slovo="ABCD";//тут ввести чему оно равно  
//    Galimov(slovo,key);
//
//    deshifr_Galimov(key);
//}
//
