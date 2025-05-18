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
    /*
    digitMap.at("0").printDigit();
    digitMap.at("1").printDigit();
    digitMap.at("2").printDigit();
    digitMap.at("3").printDigit();
    digitMap.at("4").printDigit();
    digitMap.at("5").printDigit();
    digitMap.at("6").printDigit();
    digitMap.at("7").printDigit();
    digitMap.at("8").printDigit();
    digitMap.at("9").printDigit();

    std::cout << digitMap.at("0").getTopLine() <<
                 digitMap.at("1").getTopLine() <<
                 digitMap.at("2").getTopLine() <<
                 digitMap.at("3").getTopLine() <<
                 digitMap.at("4").getTopLine() <<
                 digitMap.at("5").getTopLine() <<
                 digitMap.at("6").getTopLine() <<
                 digitMap.at("7").getTopLine() <<
                 digitMap.at("8").getTopLine() <<
                 digitMap.at("9").getTopLine() << std::endl;
    std::cout << digitMap.at("0").getMiddleLine() <<
                 digitMap.at("1").getMiddleLine() <<
                 digitMap.at("2").getMiddleLine() <<
                 digitMap.at("3").getMiddleLine() <<
                 digitMap.at("4").getMiddleLine() <<
                 digitMap.at("5").getMiddleLine() <<
                 digitMap.at("6").getMiddleLine() <<
                 digitMap.at("7").getMiddleLine() <<
                 digitMap.at("8").getMiddleLine() <<
                 digitMap.at("9").getMiddleLine() << std::endl;
    std::cout << digitMap.at("0").getBottomLine() <<
                 digitMap.at("1").getBottomLine() <<
                 digitMap.at("2").getBottomLine() <<
                 digitMap.at("3").getBottomLine() <<
                 digitMap.at("4").getBottomLine() <<
                 digitMap.at("5").getBottomLine() <<
                 digitMap.at("6").getBottomLine() <<
                 digitMap.at("7").getBottomLine() <<
                 digitMap.at("8").getBottomLine() <<
                 digitMap.at("9").getBottomLine() << std::endl;
    */

    return 0;
}
