#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


int getRandomValue();
std::string getUserName();
int playGame( const int randomValue ); // return attempts

int main() {

    playGame( getRandomValue() );

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

int playGame( const int randomValue ) {

    std::cout << "Enter your guess:" << std::endl;

    bool isWin{false};
    int attempts{0};

    for( int currentValue{-1} ; isWin == false ; ++attempts) {

        std::cin >> currentValue;

        if (randomValue <  currentValue ) {
            std::cout << "less than " << currentValue << std::endl;
        } else if (randomValue > currentValue) {
            std::cout << "greater than " << currentValue << std::endl;
        } else {
            std::cout << "you win! ";
            isWin = true;
        }
    }

    std::cout << "attempts = " << attempts << std::endl;

    return attempts;
}