#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


int getRandomValue( const int maxRandomValue );
std::string getUserName();
int playGame( const int randomValue ); // return attempts
void parseArgumets( const int argc, const char** argv  );

int main( int argc, char** argv ) {

    int maxRandomValue{ 100 };

    playGame( getRandomValue( maxRandomValue ) );

    return 0;
}

int getRandomValue( const int maxRandomValue ) {

    std::srand(std::time(nullptr));

    return std::rand() % maxRandomValue;
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

void parseArgumets( const int argc, const char** argv,  int &maRandomValue ) {


}