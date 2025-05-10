#pragma once

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

    void printDigit();

    std::string getTopLine();
    std::string getMiddleLine();
    std::string getBottomLine();

private:
    char getSegmentAChar();
    char getSegmentBChar();
    char getSegmentCChar();
    char getSegmentDChar();
    char getSegmentEChar();
    char getSegmentFChar();
    char getSegmentGChar();

    bool m_segmentA;
    bool m_segmentB;
    bool m_segmentC;
    bool m_segmentD;
    bool m_segmentE;
    bool m_segmentF;
    bool m_segmentG;
};

