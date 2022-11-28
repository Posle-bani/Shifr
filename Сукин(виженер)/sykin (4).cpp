#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <chrono>

void code(std::string message);
void decode(std::string message);
std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);
bool alphabetOnly = true;

using namespace std::chrono;

void code(std::string message) {
    unsigned int choice = 0;    

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

void decode(std::string message) {
    
    std::string key;

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

