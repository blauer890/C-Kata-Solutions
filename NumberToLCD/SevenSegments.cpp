#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#include "SevenSegments.h"

// _ 
//|_|
//|_|

void SevenSegments::printDigit()
{
    std::cout << " " << getSegmentAChar() << " " << std::endl;
    std::cout << getSegmentFChar() << getSegmentGChar() << getSegmentBChar() << std::endl;
    std::cout << getSegmentEChar() << getSegmentDChar() << getSegmentCChar() << std::endl;
}

std::string SevenSegments::getTopLine()
{
    std::stringstream topLineString;
    topLineString << " " << getSegmentAChar() << " ";
    return topLineString.str();
}

std::string SevenSegments::getMiddleLine()
{
    std::stringstream middleLineString;
    middleLineString << getSegmentFChar() << getSegmentGChar() << getSegmentBChar();
    return middleLineString.str();
}

std::string SevenSegments::getBottomLine()
{
    std::stringstream bottomLineString;
    bottomLineString << getSegmentEChar() << getSegmentDChar() << getSegmentCChar();
    return bottomLineString.str();
}


char SevenSegments::getSegmentAChar()
{
    if (m_segmentA)
    {
        return '_';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentBChar()
{
    if (m_segmentB)
    {
        return '|';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentCChar()
{
    if (m_segmentC)
    {
        return '|';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentDChar()
{
    if (m_segmentD)
    {
        return '_';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentEChar()
{
    if (m_segmentE)
    {
        return '|';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentFChar()
{
    if (m_segmentF)
    {
        return '|';
    } else
    {
        return ' ';
    }
}

char SevenSegments::getSegmentGChar()
{
    if (m_segmentG)
    {
        return '_';
    } else
    {
        return ' ';
    }
}
