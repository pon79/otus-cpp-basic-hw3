#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


int getRandomValue( const int maxRandomValue );
std::string getUserName();
int playGame( const int randomValue ); // return attempts
void parseArgumets( const int argc, char** argv, int& maxRandomValue  );

int main( int argc, char** argv ) {

    int maxRandomValue{ 100 };

    parseArgumets( argc, argv, maxRandomValue );

    const int attempts{ playGame( getRandomValue( maxRandomValue ) ) };

    if( attempts > 0 ) {
        // TO DO save result
    }

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

    for (int currentValue{-1}; !isWin; ++attempts) {

        if (std::cin >> currentValue) {
            if (randomValue < currentValue) {
                std::cout << "less than " << currentValue << std::endl;
            } else if (randomValue > currentValue) {
                std::cout << "greater than " << currentValue << std::endl;
            } else {
                std::cout << "you win! ";
                isWin = true;
            }
        } else {
            if (std::cin.bad()) {
                std::cout << "I/O error while reading" << std::endl;
                return -1;
            } else if (std::cin.eof()) { // linux CTRL+D
                std::cout << "Game over" << std::endl;
                return -1;
            } else if (std::cin.fail()) {
                std::cout << "it's not a number, try again " << std::endl;
                std::cin.clear();
                std::cin.ignore();
            } else {
                std::cout << "Unknow error" << std::endl;
                return -1;
            }
        }
    }

    std::cout << "attempts = " << attempts << std::endl;

    return attempts;
}

void parseArgumets( const int argc, char** argv,  int& maxRandomValue ) {


    for( int index{} ; index < argc ; ++index ) {

        if( std::string{ argv[index] } == "-max") {

            if( argv[index + 1] ) { // is there any next argument? (argv[argc], is guaranteed to be a null pointer)
                ++index;
                maxRandomValue = std::stoi( std::string{ argv[index] } ); // TD DO check result stoi
            } else {
                std::cout << "Error arguments" << std::endl;
            }
        }
    }
}