#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

static bool isNum(uint8_t character)
{
    return (character >= 48) && (character <= 57);
}

static char computeISBN13CheckDigit(char* numStr, uint8_t numDigits)
{
    uint8_t sum = 0;
    uint8_t checkDigitNum = 0;
    for (uint8_t i = 0; i < numDigits; i++)
    {
        uint8_t digit = (uint8_t)(numStr[i] - 48);
        if (i % 2 == 1)
        {
            sum += digit * 3;
        } else
        {
            sum += digit;
        }
    }
    checkDigitNum = 10 - (sum % 10);
    if (checkDigitNum > 9)
    {
        checkDigitNum = 0;
    }
    return (char)(checkDigitNum + 48);
}

bool isISBN13(char *ISBNStr)
{
    uint8_t numDigits = 0;
    char numStr[14];
    uint8_t numStrIndex = 0;
    while (*ISBNStr)
    {
        if (isNum((uint8_t)*ISBNStr))
        {
            numStr[numStrIndex] = *ISBNStr;
            numStrIndex++;
            numStr[numStrIndex] = 0;
        }
        ISBNStr++;
    }
    char checkDigit = computeISBN13CheckDigit(numStr, numStrIndex-1);
    return numStr[numStrIndex-1] == checkDigit;
}

static char computeISBN10CheckDigit(char *numStr, uint8_t numDigits)
{
    uint16_t sum = 0;
    uint8_t checkDigitNum = 0;
    for (uint8_t i = 0; i < numDigits; i++)
    {
        uint8_t digit = (uint8_t)(numStr[i] - 48);
        sum += (digit * (i + 1));
    }
    checkDigitNum = sum % 11;
    switch(checkDigitNum)
    {
        case 10:
            return 'X';
        default:
            return (char)(checkDigitNum + 48);
    }
}

bool isISBN10(char *ISBNStr)
{
    uint8_t numDigits = 0;
    char numStr[11];
    uint8_t numStrIndex = 0;
    while (*ISBNStr)
    {
        if (isNum((uint8_t)(*ISBNStr)))
        {
            numStr[numStrIndex] = *ISBNStr;
            numStrIndex++;
            numStr[numStrIndex] = 0;
        }
        ISBNStr++;
    }
    char checkDigit = computeISBN10CheckDigit(numStr, numStrIndex-1);
    return numStr[numStrIndex-1] == checkDigit;
}

bool isValidISBN(char *ISBNStr)
{
    return isISBN13(ISBNStr) || isISBN10(ISBNStr);
}

int main(int argc, char *argv[])
{
    printf("isISBN13(\"9780470059029\"): %u\n", isISBN13("9780470059029"));
    printf("isISBN13(\"978 0 471 48648 0\"): %u\n", isISBN13("978 0 471 48648 0"));
    printf("isISBN13(\"978-0596809485\"): %u\n", isISBN13("978-0596809485"));
    printf("isISBN13(\"978-0-13-149505-0\"): %u\n", isISBN13("978-0-13-149505-0"));
    printf("isISBN13(\"978-0-262-13472-9\"): %u\n", isISBN13("978-0-262-13472-9"));
    printf("isISBN13(\"0471958697\"): %u\n", isISBN13("0471958697"));
    printf("isValidISBN(\"9780470059029\"): %u\n", isValidISBN("9780470059029"));
    printf("isValidISBN(\"0471958697\"): %u\n", isValidISBN("0471958697"));
    printf("isISBN10(\"0471958697\"): %u\n", isISBN10("0471958697"));
    printf("isValidISBN(\"0 471 60695 2\"): %u\n", isValidISBN("0 471 60695 2"));
    printf("isValidISBN(\"0-470-84525-2\"): %u\n", isValidISBN("0-470-84525-2"));
    printf("isValidISBN(\"0-321-14653-0\"): %u\n", isValidISBN("0-321-14653-0"));
}