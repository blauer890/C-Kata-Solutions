#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_LETTERS 26

bool isLetter(char testChar)
{
    return (testChar >= 65 && testChar <= 90) || 
        (testChar >= 97 && testChar <= 122);
}

void setLetterFlag(bool *letterFlags, char letterChar)
{
    if (letterChar >= 65 && letterChar <= 90)
    {
        if (!letterFlags[letterChar - 65])
        {
            letterFlags[letterChar - 65] = true;
        }
    }
    else if (letterChar >= 97 && letterChar <= 122)
    {
        if (!letterFlags[letterChar - 97])
        {
            letterFlags[letterChar - 97] = true;
        }
    }
}

bool allLetterFlagsSet(bool *letterFlags)
{
    for (size_t i = 0; i < NUMBER_OF_LETTERS; i++)
    {
        if (!letterFlags[i])
        {
            return false;
        }
    }
    return true;
}

bool isPangram(char *str)
{
    bool letterFlags[NUMBER_OF_LETTERS];
    while (*str != '\0')
    {
        if (isLetter(*str))
        {
            setLetterFlag(letterFlags, *str);
        }
        str++;
    }
    return allLetterFlagsSet(letterFlags);
}

int main()
{
    printf("isPangram(\"Cool story bro\"): %u\n", isPangram("Cool story bro"));
    printf("isPangram(\"The quick brown fox jumped over the lazy dog\"): %u\n",
        isPangram("The quick brown fox jumped over the lazy dog"));
    return 0;
}
