#pragma once

#include <string>
#include <unordered_map>

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

class SevenSegments
{
public:
    SevenSegments() : m_digitMap{}
    {
        m_digitMap.insert({'0', 0b00111111});
        m_digitMap.insert({'1', 0b00000110});
        m_digitMap.insert({'2', 0b01011011});
        m_digitMap.insert({'3', 0b01001111});
        m_digitMap.insert({'4', 0b01100110});
        m_digitMap.insert({'5', 0b01101101});
        m_digitMap.insert({'6', 0b01111101});
        m_digitMap.insert({'7', 0b00000111});
        m_digitMap.insert({'8', 0b01111111});
        m_digitMap.insert({'9', 0b01101111});
    }

private:
    void getTopSection(std::stringstream &rows, std::string numStr, int width);
    void getMiddleSection(std::stringstream &rows, std::string numStr, int width, int height);
    void getBottomSection(std::stringstream &rows, std::string numStr, int width, int height);

public:
    std::string getLCDRows(std::string numStr, int width, int height);

private:
    std::unordered_map<char, int> m_digitMap;
};

