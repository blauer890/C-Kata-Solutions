#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#include "SevenSegments.h"

int main(int argc, char *argv[])
{
    SevenSegments segments;

    std::string number;
    int width;
    int height;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    std::cout << "Enter a character width: ";
    std::cin >> width;

    std::cout << "Enter a character height: ";
    std::cin >> height;

    std::cout << segments.getLCDRows(number, width, height);

    return 0;
}

