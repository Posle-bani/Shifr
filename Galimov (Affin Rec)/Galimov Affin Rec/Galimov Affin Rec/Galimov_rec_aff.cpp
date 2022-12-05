#include "galimov_rec_aff.h"
#include <iostream>
#include <locale>
#include <vector>
#include <numeric>
#include <string>
#include <algorithm>
#include <chrono>

using namespace std;


void zapoln_alphavit(vector <char>& alphavit) //���������� �������� ���� ���������� ACII
{
    iota(alphavit.begin(), alphavit.end(), 'A');
}

void zapoln_keys(keys& key, vector <int>& alpha, vector <int>& beta)  //���������������� ������ ��� ������ �� ���������
{
    alpha.resize(2);
    beta.resize(2);
    alpha[0] = key.affreca1;
    alpha[1] = key.affreca2;
    beta[0] = key.affrecb1;
    beta[1] = key.affrecb2;
}

void Galimov(string& slovo, keys& key)  //���� �������
{
    int kolvo = 0, poz = 0, sh_poz = 0;
    vector <char> alphavit(256);
    vector <int> shifr, alpha, beta;
    char el;
    zapoln_keys(key, alpha, beta);//����� ���������� �� ���������
    zapoln_alphavit(alphavit);//������� ��������
    kolvo = slovo.length();//������ ���������� ���� � �����
    for (int i = 0; i < kolvo; i++)//�� ������ ����� ���
    {
        el = slovo[i];//���� ������ �����
        vector<char>::iterator it = find(alphavit.begin(), alphavit.end(), el); //������ ��� ����� � �������� � ���� ��������
        if (it == alphavit.end())//�������� �� ���������� �����
        {
            cout << "Element " << el << " not found" << endl;//�� �� ������� ������� ��
        }
        else //� ���� �������
        {
            poz = distance(alphavit.begin(), it);   //https://www.techiedelight.com/ru/find-index-element-vector-cpp/ ������ ������� � ��������
            if (i == 0 || i == 1) //������ ��� ���� ���� �� �����
            {
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size(); //������� ������������� �����
                shifr.push_back(alphavit[sh_poz]); //������ � ������ ������������� �����
                //cout << alphavit[sh_poz];//������ ������������� �����          
            }
            else //��� ����� ������ �������� ����� ���� ��������� �� �������
            {
                alpha.push_back((alpha[i - 2] * alpha[i - 1]) % alphavit.size()); //������ ����� �����
                beta.push_back((beta[i - 2] + beta[i - 1]) % alphavit.size());  //������ ����� �����
                sh_poz = (poz * alpha[i] + beta[i]) % alphavit.size();
                shifr.push_back(alphavit[sh_poz]);  //������ � ������ ������������� �����               
                //cout << alphavit[sh_poz]; //������ ������������� �����               
            }
        }
    }
    //cout << endl << "Recurent Affin Shifr" << endl;
}
