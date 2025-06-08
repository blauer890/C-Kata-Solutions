#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

#include "SevenSegments.h"

// width: 1, height: 1
// _ 
//|_|
//|_|

// width: 3, height: 2
// ___ 
//|   |
//|___|
//|   |
//|___|

void SevenSegments::getTopSection(std::stringstream &rows, std::string numStr, int width)
{
    for (char numChar : numStr)
    {
        rows << ' ';
        for (int i = 0; i < width; i++)
        {
            if (m_digitMap.at(numChar) & 0b00000001)
            {
                rows << '_';
            } else
            {
                rows << ' ';
            }
        }
        rows << ' ';
    }
    rows << std::endl;
}

void SevenSegments::getMiddleSection(std::stringstream &rows, std::string numStr, int width, int height)
{
    for (int i = 0; i < height - 1; i++)
    {
        for (char numChar : numStr)
        {
            if ((m_digitMap.at(numChar) & 0b00100000) >> 5)
            {
                rows << '|';
            } else
            {
                rows << ' ';
            }
            for (int j = 0; j < width; j++)
            {
                rows << ' ';
            }
            if ((m_digitMap.at(numChar) & 0b00000010) >> 1)
            {
                rows << '|';
            } else
            {
                rows << ' ';
            }
        }
        rows << std::endl;
    }
    for (char numChar : numStr)
    {
        if ((m_digitMap.at(numChar) & 0b00100000) >> 5)
        {
            rows << '|';
        } else
        {
            rows << ' ';
        }
        for (int i = 0; i < width; i++)
        {
            if ((m_digitMap.at(numChar) & 0b01000000) >> 6)
            {
                rows << '_';
            } else
            {
                rows << ' ';
            }
        }
        if ((m_digitMap.at(numChar) & 0b00000010) >> 1)
        {
            rows << '|';
        } else
        {
            rows << ' ';
        }
    }
    rows << std::endl;
}

void SevenSegments::getBottomSection(std::stringstream &rows, std::string numStr, int width, int height)
{
    for (int i = 0; i < height - 1; i++)
    {
        for (char numChar : numStr)
        {
            if ((m_digitMap.at(numChar) & 0b00010000) >> 4)
            {
                rows << '|';
            } else
            {
                rows << ' ';
            }
            for (int j = 0; j < width; j++)
            {
                rows << ' ';
            }
            if ((m_digitMap.at(numChar) & 0b00000100) >> 2)
            {
                rows << '|';
            } else
            {
                rows << ' ';
            }
        }
        rows << std::endl;
    }
    for (char numChar : numStr)
    {
        if ((m_digitMap.at(numChar) & 0b00010000) >> 4)
        {
            rows << '|';
        } else
        {
            rows << ' ';
        }
        for (int i = 0; i < width; i++)
        {
            if ((m_digitMap.at(numChar) & 0b00001000) >> 3)
            {
                rows << '_';
            } else
            {
                rows << ' ';
            }
        }
        if ((m_digitMap.at(numChar) & 0b00000100) >> 2)
        {
            rows << '|';
        } else
        {
            rows << ' ';
        }
    }
    rows << std::endl;
}

std::string SevenSegments::getLCDRows(std::string numStr, int width, int height)
{
    std::stringstream rows;
    getTopSection(rows, numStr, width);
    getMiddleSection(rows, numStr, width, height);
    getBottomSection(rows, numStr, width, height);
    return rows.str();
}
