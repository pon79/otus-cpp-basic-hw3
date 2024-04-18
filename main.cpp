#include <iostream>
#include <cstdlib>
#include <ctime>


int getRandomValue();

int main() {
    std::cout << getRandomValue() << std::endl;


    return 0;
}

int getRandomValue() {

    std::srand(std::time(nullptr));

    return std::rand() % 100;
}