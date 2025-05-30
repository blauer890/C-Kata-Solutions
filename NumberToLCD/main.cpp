#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#include "SevenSegments.h"

std::string getLCDInteger(std::string numStr, int width, int height)
{
    std::stringstream LCDStream;
    for (char c: numStr)
    {
        switch (c)
        {
            case '0':
            case '2':
            case '3':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << ' ';
                break;
            case '1':
            case '4':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << ' ';
                }
                LCDStream << ' ';
                break;
            default:
                break;
        }
    }
    LCDStream << std::endl;
    for (int i = 0; i < height - 1; i++)
    {
        for (char c: numStr)
        {
            switch (c)
            {
                case '0':
                case '4':
                case '8':
                case '9':
                    LCDStream << '|';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << '|';
                    break;
                case '5':
                case '6':
                    LCDStream << '|';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << ' ';
                    break;
                case '1':
                case '2':
                case '3':
                case '7':
                    LCDStream << ' ';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << '|';
                    break;
                default:
                    break;
            }
        }
        LCDStream << std::endl;
    }
    for (char c: numStr)
    {
        switch (c)
        {
            case '0':
                LCDStream << '|';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << ' ';
                }
                LCDStream << '|';
                break;
            case '4':
            case '8':
            case '9':
                LCDStream << '|';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << '|';
                break;
            case '5':
            case '6':
                LCDStream << '|';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << ' ';
                break;
            case '1':
            case '7':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << ' ';
                }
                LCDStream << '|';
                break;
            case '2':
            case '3':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << '|';
                break;
            default:
                break;
        }
    }
    LCDStream << std::endl;
    for (int i = 0; i < height - 1; i++)
    {
        for (char c: numStr)
        {
            switch (c)
            {
                case '0':
                case '6':
                case '8':
                    LCDStream << '|';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << '|';
                    break;
                case '2':
                    LCDStream << '|';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << ' ';
                    break;
                case '1':
                case '3':
                case '4':
                case '5':
                case '7':
                case '9':
                    LCDStream << ' ';
                    for (int i = 0; i < width; i++)
                    {
                        LCDStream << ' ';
                    }
                    LCDStream << '|';
                    break;
                default:
                    break;
            }
        }
        LCDStream << std::endl;
    }
    for (char c: numStr)
    {
        switch (c)
        {
            case '0':
            case '6':
            case '8':
                LCDStream << '|';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << '|';
                break;
            case '2':
                LCDStream << '|';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << ' ';
                break;
            case '1':
            case '4':
            case '7':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << ' ';
                }
                LCDStream << '|';
                break;
            case '3':
            case '5':
            case '9':
                LCDStream << ' ';
                for (int i = 0; i < width; i++)
                {
                    LCDStream << '_';
                }
                LCDStream << '|';
                break;
            default:
                break;
        }
    }
    LCDStream << std::endl;
    return LCDStream.str();
}

int main(int argc, char *argv[])
{
//    std::unordered_map<char, SevenSegments> digitMap;
//    digitMap.insert({'0', SevenSegments(0b00111111)});
//    digitMap.insert({'1', SevenSegments(0b00000110)});
//    digitMap.insert({'2', SevenSegments(0b01011011)});
//    digitMap.insert({'3', SevenSegments(0b01001111)});
//    digitMap.insert({'4', SevenSegments(0b01100110)});
//    digitMap.insert({'5', SevenSegments(0b01101101)});
//    digitMap.insert({'6', SevenSegments(0b01111101)});
//    digitMap.insert({'7', SevenSegments(0b00000111)});
//    digitMap.insert({'8', SevenSegments(0b01111111)});
//    digitMap.insert({'9', SevenSegments(0b01101111)});

    std::string number;
    int width;
    int height;

    std::cout << "Enter an integer: ";
    std::cin >> number;

    std::cout << "Enter a character width: ";
    std::cin >> width;

    std::cout << "Enter a character height: ";
    std::cin >> height;

    std::cout << getLCDInteger(number,width,height);

//    std::stringstream LCDStream;
//    for (char c : number)
//    {
//        LCDStream << digitMap.at(c).getTopSection(4);
//    }
//    LCDStream << std::endl;
//    for (char c : number)
//    {
//        LCDStream << digitMap.at(c).getMiddleSection(4, 3);
//    }
//    LCDStream << std::endl;
//    for (char c : number)
//    {
//        LCDStream << digitMap.at(c).getBottomSection(4, 3);
//    }
//    LCDStream << std::endl;

//    std::cout << LCDStream.str();

    return 0;
}

