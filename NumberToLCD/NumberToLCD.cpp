#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

// _ 
//|_|
//|_|

class SevenSegments
{
public:
    SevenSegments(int segmentFlags)
    {
        m_segmentA = static_cast<bool>( segmentFlags & 0b00000001);
        m_segmentB = static_cast<bool>((segmentFlags & 0b00000010) >> 1);
        m_segmentC = static_cast<bool>((segmentFlags & 0b00000100) >> 2);
        m_segmentD = static_cast<bool>((segmentFlags & 0b00001000) >> 3);
        m_segmentE = static_cast<bool>((segmentFlags & 0b00010000) >> 4);
        m_segmentF = static_cast<bool>((segmentFlags & 0b00100000) >> 5);
        m_segmentG = static_cast<bool>((segmentFlags & 0b01000000) >> 6);
    }

    void printDigit()
    {
        std::cout << " " << getSegmentAChar() << " " << std::endl;
        std::cout << getSegmentFChar() << getSegmentGChar() << getSegmentBChar() << std::endl;
        std::cout << getSegmentEChar() << getSegmentDChar() << getSegmentCChar() << std::endl;
    }

    std::string getTopLine()
    {
        std::stringstream topLineString;
        topLineString << " " << getSegmentAChar() << " ";
        return topLineString.str();
    }

    std::string getMiddleLine()
    {
        std::stringstream middleLineString;
        middleLineString << getSegmentFChar() << getSegmentGChar() << getSegmentBChar();
        return middleLineString.str();
    }

    std::string getBottomLine()
    {
        std::stringstream bottomLineString;
        bottomLineString << getSegmentEChar() << getSegmentDChar() << getSegmentCChar();
        return bottomLineString.str();
    }

private:
    char getSegmentAChar()
    {
        if (m_segmentA)
        {
            return '_';
        } else
        {
            return ' ';
        }
    }

    char getSegmentBChar()
    {
        if (m_segmentB)
        {
            return '|';
        } else
        {
            return ' ';
        }
    }

    char getSegmentCChar()
    {
        if (m_segmentC)
        {
            return '|';
        } else
        {
            return ' ';
        }
    }

    char getSegmentDChar()
    {
        if (m_segmentD)
        {
            return '_';
        } else
        {
            return ' ';
        }
    }

    char getSegmentEChar()
    {
        if (m_segmentE)
        {
            return '|';
        } else
        {
            return ' ';
        }
    }

    char getSegmentFChar()
    {
        if (m_segmentF)
        {
            return '|';
        } else
        {
            return ' ';
        }
    }

    char getSegmentGChar()
    {
        if (m_segmentG)
        {
            return '_';
        } else
        {
            return ' ';
        }
    }

    bool m_segmentA;
    bool m_segmentB;
    bool m_segmentC;
    bool m_segmentD;
    bool m_segmentE;
    bool m_segmentF;
    bool m_segmentG;
};

int main(int argc, char *argv[])
{
    std::unordered_map<std::string, SevenSegments> digitMap;
    digitMap.insert({"0", SevenSegments(0b00111111)});
    digitMap.insert({"1", SevenSegments(0b00000110)});
    digitMap.insert({"2", SevenSegments(0b01011011)});
    digitMap.insert({"3", SevenSegments(0b01001111)});
    digitMap.insert({"4", SevenSegments(0b01100110)});
    digitMap.insert({"5", SevenSegments(0b01101101)});
    digitMap.insert({"6", SevenSegments(0b01111101)});
    digitMap.insert({"7", SevenSegments(0b00000111)});
    digitMap.insert({"8", SevenSegments(0b01111111)});
    digitMap.insert({"9", SevenSegments(0b01101111)});

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
    return 0;
}
