#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

void code();
void decode();
std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);
bool alphabetOnly = true;

using namespace std::chrono;

int main()
{
    unsigned int choice = 1;
    std::string actualMode;

    while(choice > 0 && choice <= 3) {
        actualMode = (alphabetOnly) ? "Alphabet Only" : "ASCII";
        std::cout << "What do you want to do?" << std::endl
                  << "1) Encrypt a message" << std::endl
                  << "2) Decrypt a message" << std::endl
                  << "0) Quit"<< std::endl
                  << "> ";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice) {
            case 1: 
                code();
                break;
            case 2:
                decode();
                break;
            case 0:
                break;
        }

        std::cout << std::endl << std::endl;
    }

    return 0;
}

void code() {
    unsigned int choice = 0;
    std::cout << std::endl << "What do you want to do?" << std::endl
                           << "1) Write the message in standard input" << std::endl
                           << "2) Quit";

    while(choice < 1 || choice > 2) {
        std::cout << std::endl << "> ";
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string message;

    if(choice == 1) {
        std::cout << std::endl << "Your message > ";
        getline(std::cin, message);
    }
    else if(choice == 2) {
        main();
    }

    std::string key;

    std::cout << "Choose a key > ";
    getline(std::cin, key);

    if(key.size() == 0)     { std::cout << "Key's length is 0, quitting"; return; }
    auto start_1 = system_clock::now();
    
    std::string result = vigenereCode(message, key);

    std::cout << "Result : " << result;
    auto finish_1 = system_clock::now();
    auto duration_1 = duration_cast<microseconds>(finish_1-start_1).count();
    std::cout << "\nEncrypt time: "<< duration_1 << " microseconds"<< std::endl;
}

void decode() {
    std::string message;
    std::string key;

    std::cout << "Your message > ";
    getline(std::cin, message);

    std::cout << "Your key > ";
    getline(std::cin, key);

    if(key.size() == 0)     { std::cout << "Key's length is 0, quitting"; return; }

    auto start_2 = system_clock::now();
    std::string result = vigenereDecode(message, key);

    std::cout << "Result : " << result;
    auto finish_2 = system_clock::now();
    auto duration_2 = duration_cast<microseconds>(finish_2-start_2).count();
    std::cout << "\nDecrypt time: "<< duration_2 << " microseconds"<< std::endl;
}

std::string vigenereCode(std::string message, std::string key) {
    unsigned int counterKey = 0, sizeOfKey = key.size();
    char codedChar;
    std::string codedString;
    unsigned int placeOfChar;
    if(alphabetOnly) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        for(unsigned int i = 0; i < message.size(); i++) {
            if((placeOfChar = alphabet.find(message[i])) == std::string::npos)  { return "Error, characters are not part of the following string : " + alphabet; }
            codedChar = (placeOfChar + key[counterKey]%53)%53;
            codedString += alphabet[codedChar];
            ++counterKey%=sizeOfKey;
        }
    } else {
        for(unsigned int i = 0; i < message.size(); i++) {
            codedChar = (message[i] + key[counterKey])%256;
            codedString += codedChar;
            ++counterKey%=sizeOfKey;
        }
    }
    return codedString;
}

std::string vigenereDecode(std::string message, std::string key) {
    unsigned int counterKey = 0, sizeOfKey = key.size();
    char decodedChar;
    std::string decodedString;
    unsigned int placeOfChar;
    if(alphabetOnly) {
        std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ";
        for(unsigned int i = 0; i < message.size(); i++) {
            if((placeOfChar = alphabet.find(message[i])) == std::string::npos)  { return "Error, characters are not part of the following string : " + alphabet; }
            decodedChar = (placeOfChar - (key[counterKey]%53));
            std::cout<< "1: " << (int)decodedChar << std::endl;
            if(decodedChar < 0)   { decodedChar+=53; }
            std::cout<< "2: " << (int)decodedChar << std::endl;
            decodedString += alphabet[decodedChar];
            ++counterKey%=sizeOfKey;
        }
    } else {
        for(unsigned int i = 0; i < message.size(); i++) {
            decodedChar = (message[i] - key[counterKey]);
            if(decodedChar < 0)   { decodedChar+=256; }
            decodedString += decodedChar;
            ++counterKey%=sizeOfKey;
        }
    }
    return decodedString;
}

