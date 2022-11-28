#include <fstream>
#include <algorithm>
#include <chrono>

int main_menu();
void code();

std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);

void decode();

std::string vigenereCode(std::string message, std::string key);
std::string vigenereDecode(std::string message, std::string key);