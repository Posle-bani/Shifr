//#include "galimov_rec_aff.h"
//#include <iostream>
//#include <locale>
//#include <vector>
//#include <numeric>
//#include <string>
//#include <algorithm>
//#include <chrono>
//
//using namespace std;
//
//int proverka(int& x, int min, int max)
//{
//    cin >> x;
//    while (cin.fail() || x<min || x>max)
//    {
//        cout << "������� ������������ ��������" << endl << "��������: " << min << "-" << max << endl;
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cin >> x;
//    }
//    return x;
//}
//
//void input_a_b(vector <int>& alpha, vector <int>& beta)
//{
//    int x = 0;
//    cout << "������� �����" << endl;
//    alpha.push_back(proverka(x, 0, 10000));
//    cout << "������� �����" << endl;
//    beta.push_back(proverka(x, 0, 10000));
//    cout << "������� �����2" << endl;   //���� ����������
//    alpha.push_back(proverka(x, 0, 10000));
//    cout << "������� �����2" << endl;
//    beta.push_back(proverka(x, 0, 10000));
//}
//
//void zapoln_alphavit(vector <char>& alphavit)
//{
//    iota(alphavit.begin(), alphavit.begin() + 26, 'a');
//    iota(alphavit.begin() + 26, alphavit.end(), 'a'); //���������� ��������
//}
//
//void slovo_kolvo(string& slovo, int& kolvo)
//{
//    cout << "������� �����" << endl;
//    getline(cin >> ws, slovo);//������� ���� �������
//    kolvo = slovo.length();
//    cout << "���-�� ��������� � �����: " << kolvo << endl;
//}
//
//void Galimov()
//{
//    int kolvo = 0, poz = 0, sh_poz = 0;
//    string slovo, shslovo;
//    vector <char> alphavit(52);
//    vector <int> shifr, alpha, beta;
//    char el, sh_el;
//    input_a_b(alpha, beta);
//    zapoln_alphavit(alphavit);
//    slovo_kolvo(slovo, kolvo);
//    auto start = std::chrono::high_resolution_clock::now();//������� �����
//    for (int i = 0; i < kolvo; i++)
//    {
//        el = slovo[i];//���� ������ �����
//        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //������ ��� ����� � �������� � ���� ��������
//        if (it == alphavit.end())//�������� �� ���������� �����
//        {
//            cout << "������� " << el << " �� ������" << endl;
//        }
//        else
//        {
//            poz = distance(alphavit.begin(), it);   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
//            if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
//            {
//                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size()); //������ � ������ ������� ������������� �����
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
//                cout << alphavit[sh_poz];//������ ������������� �����        ��� cout << alphavit[sh_poz-1];     
//            }
//            else
//            {
//                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //������ ����� �����
//                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //������ ����� �����
//                shifr.push_back((poz * alpha[i] + beta[i]) % alphavit.size());  //������ � ������ ������� ������������� �����
//                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
//                cout << alphavit[sh_poz]; //������ ������������� �����           ��� cout << alphavit[sh_poz-1];     
//            }
//        }
//
//
//    }
//    auto elapsed = chrono::high_resolution_clock::now() - start;//����� �����
//    long long microseconds = chrono::duration_cast<chrono::microseconds>(elapsed).count();//����� � ����
//    cout << endl << "������������ �������� ����" << "  ����������� �� ���������� �����: " << microseconds << " ����" << endl;
//}
