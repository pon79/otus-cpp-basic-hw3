#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


int getRandomValue();
std::string getUserName();

int main() {

    std::cout << getUserName() << std::endl;

    std::cout << getRandomValue() << std::endl;


    return 0;
}

int getRandomValue() {

    std::srand(std::time(nullptr));

    return std::rand() % 100;
}

std::string getUserName() {

    std::cout << "Hi! Enter your name, please \n";

    std::string userName;

    std::cin >> userName;

    return userName;
}