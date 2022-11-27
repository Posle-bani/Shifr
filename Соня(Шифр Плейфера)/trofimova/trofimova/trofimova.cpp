#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <chrono>

using namespace std;
using namespace std::chrono;

void Enmessage(vector<int> index, char matrix[5][5]) {
    int a = 0, b = 0;
    cout << "encrypted sequence: " << endl;
    for (int i = 0; i <= index.size() - 3; i += 4) {
        a = index[i + 3] + 1;
        // если на одной строке
        if (index[i] == index[i + 2] && a < 5) {
            cout.width(5);
            cout << matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        // если на одной строке и у края
        if (index[i] == index[i + 2] && a >= 5) {
            a = 0;
            cout.width(5);
            cout << matrix[index[i]][index[i + 1] + 1] << matrix[index[i + 2]][a];
        }
        b = index[i + 2] + 1;
        // если в одном столбце
        if (index[i + 1] == index[i + 3] && b < 5) {
            cout.width(5);
            cout << matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }
        // если в одном столбце и у края
        if (index[i + 1] == index[i + 3] && b >= 5) {
            b = 0;
            cout.width(5);
            cout << matrix[index[i] + 1][index[i + 1]] << matrix[b][index[i + 3]];
        }

        if (index[i] != index[i + 2] && index[i + 1] != index[i + 3]) {
            cout.width(5);
            cout << matrix[index[i + 2]][index[i + 1]] << matrix[index[i]][index[i + 3]];
        }
    }
}
void CinKeyCheck(string& keyword){
    int q = 0;
    while (q == 0) {
        cout << "enter a keyword: ";
        getline(cin, keyword);
        keyword.erase(remove_if(keyword.begin(), keyword.end(), isspace), keyword.end());

        for (int i = 0; i < keyword.length(); i++) {
            if (isupper(keyword[i])) keyword[i] = tolower(keyword[i]);
        }

        for (int i = 0; i < keyword.length(); i++) {
            if (isalpha(keyword[i])) q = 1;
            else {
                cout << "symbol " << keyword[i] << " is not appropriate!! " << endl;
                q = 0;
                break;
            }
        }
    }
}
void DeleteDouble(string& keyword){
    for (int i = 1; i < keyword.length(); i++) {
        if (keyword[i - 1] == keyword[i]) {
            keyword.erase(i, 1);
            i--;
        }
    }
}
void DeleteKeyLetters(string& keyword,string &alphabet) {
    for (int i = 0; i < keyword.length(); i++) {
        for (int j = 0; j < alphabet.length(); j++) {
            if (keyword[i] == alphabet[j]) alphabet.erase(j, 1);
        }
    }
}
void CinMessageCheck(string& message) {
    int p = 0;
    while (p == 0) {
        cout << "enter massage: ";
        getline(cin, message);
        message.erase(remove_if(message.begin(), message.end(), isspace), message.end());

        
        for (int i = 0; i < message.length(); i++) {
            if (isupper(message[i])) message[i] = tolower(message[i]);
        }

        
        for (int i = 0; i < message.length(); i++) {
            if (isalpha(message[i])) p = 1;
            else {
                cout << "symbol " << message[i] << " is not appropriate!! " << endl;
                p = 0;
                break;
            }
        }
    }
}
void DoubleMessageCheck(string& message) {
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == message[i + 1]) message.insert(i + 1, 1, 'x');
    }
}
void AddSymbol(string& message) {
    if (message.length() % 2 != 0) message.push_back('x');
}
void BygramsFormation(string& message) {
    for (int i = 0; i < message.length(); i += 2) {
        cout.width(5);
        cout << message[i] << message[i + 1];
    }
    cout << endl;
}
void MatrixCreation(char (&matrix)[5][5], string& keyword, string& alphabet) {
    cout << "key matrix: " << endl;
    int k = 0, m = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < keyword.length()) {
                matrix[i][j] = keyword[k];
            }
            if (k >= keyword.length()) {
                matrix[i][j] = alphabet[m];
                m++;
            }
            k++;
        }
    }

}
void PrintMatrix(char(&matrix)[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void FindId(char(&matrix)[5][5], vector <int>& index, string&message) {
    for (int i = 0; i < message.length(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                if (message[i] == matrix[j][k]) {
                    index.push_back(j);
                    index.push_back(k);
                }
            }
        }
    }
}
int main() {
    vector<int> index;
    string keyword = "", message = "";
    string alphabet = "abcdefghijklmnoprstuvwxyz";
    char matrix[5][5];

    CinKeyCheck(keyword);
    DeleteDouble(keyword);
    DeleteKeyLetters(keyword, alphabet);
    MatrixCreation(matrix, keyword, alphabet);
    PrintMatrix(matrix);
    CinMessageCheck(message);
    DoubleMessageCheck(message);
    AddSymbol(message);
    BygramsFormation(message);
    FindId(matrix, index, message);

    for (int i = 0; i < index.size(); i += 2) cout << index[i] << " " << index[i + 1] << "   ";
    cout << endl;

    auto start = system_clock::now();
    Enmessage(index, matrix);
    auto finish = system_clock::now();
    auto duration = duration_cast<nanoseconds>(finish - start).count();
    cout << "\nduration: " << duration << endl;

}
