#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#include "SevenSegments.h"

int main(int argc, char *argv[])
{
    std::unordered_map<char, SevenSegments> digitMap;
    digitMap.insert({'0', SevenSegments(0b00111111)});
    digitMap.insert({'1', SevenSegments(0b00000110)});
    digitMap.insert({'2', SevenSegments(0b01011011)});
    digitMap.insert({'3', SevenSegments(0b01001111)});
    digitMap.insert({'4', SevenSegments(0b01100110)});
    digitMap.insert({'5', SevenSegments(0b01101101)});
    digitMap.insert({'6', SevenSegments(0b01111101)});
    digitMap.insert({'7', SevenSegments(0b00000111)});
    digitMap.insert({'8', SevenSegments(0b01111111)});
    digitMap.insert({'9', SevenSegments(0b01101111)});

    std::string number;
    std::cout << "Enter an integer: ";
    std::cin >> number;

    std::stringstream LCDStream;
    for (char c : number)
    {
        LCDStream << digitMap.at(c).getTopLine();
    }
    LCDStream << std::endl;
    for (char c : number)
    {
        LCDStream << digitMap.at(c).getMiddleLine();
    }
    LCDStream << std::endl;
    for (char c : number)
    {
        LCDStream << digitMap.at(c).getBottomLine();
    }
    LCDStream << std::endl;

    std::cout << LCDStream.str();

    return 0;
}

