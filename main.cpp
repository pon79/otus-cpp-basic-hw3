#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>


int getRandomValue( const int maxRandomValue );

std::string getUserName();

int playGame( const int randomValue ); // return attempts

void parseArgumets( const int argc, char** argv, int& maxRandomValue, bool& isOnlyPrintTable );

void saveResult( const char* highScoresFileName, const std::string userName, const int attempts );

void printResult( const char* highScoresFileName );


int main( int argc, char** argv ) {

    const char* highScoresFileName{ "high_scores.txt" };

    int maxRandomValue{ 100 };
    bool isOnlyPrintTable{ false };
    parseArgumets( argc, argv, maxRandomValue, isOnlyPrintTable );

    if( isOnlyPrintTable ) {
        printResult( highScoresFileName );
    }
    else {
        const std::string userName{ getUserName() };
        const int attempts{ playGame( getRandomValue( maxRandomValue ) ) };

        if( attempts > 0 ) {
            saveResult( highScoresFileName, userName, attempts );
            printResult( highScoresFileName );
        }
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

    std::cout << "attempts = " << attempts << std::endl << std::endl;

    return attempts;
}

void parseArgumets( const int argc, char** argv,  int& maxRandomValue, bool& isOnlyPrintTable ) {

    for( int index{} ; index < argc ; ++index ) {

        const std::string arg{ argv[index] };

        if( arg == "-table" ) {
            isOnlyPrintTable = true;
            return;
        }

        if(arg == "-max") {

            if( argv[index + 1] ) { // is there any next argument? (argv[argc], is guaranteed to be a null pointer)
                ++index;
                maxRandomValue = std::stoi( std::string{ argv[index] } ); // TD DO check result stoi
            } else {
                std::cout << "Error arguments" << std::endl;
            }
        }
    }
}

void saveResult( const char* highScoresFileName, const std::string userName, const int attempts ) {

    std::ofstream outFile{ highScoresFileName, std::ios_base::app };

    if ( !outFile.is_open() ) {
        std::cout << "Failed to open file for write: " << highScoresFileName << "!" << std::endl;
        return;
    }

    // Append new results to the table:
    outFile << userName << ' ' << attempts << std::endl;
}

void printResult( const char* highScoresFileName ) {

    std::ifstream inFile{ highScoresFileName };

    if ( !inFile.is_open() ) {
        std::cout << "Failed to open file for read: " << highScoresFileName << "!" << std::endl;
        return;
    }

    std::cout << "High scores table: " << std::endl;

    std::string username;
    int high_score{};

    while ( inFile.good() ) {

        if( inFile >> username >> high_score ) {

            inFile.ignore(); // Ignore the end of line symbol

            // Print the information to the screen
            std::cout << username << '\t' << high_score << std::endl;
        }
    }
}