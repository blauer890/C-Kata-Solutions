#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "EquipmentCards.h"

#define NUMBER_OF_EQUIPMENT_CARDS 30

Skills_E cards[NUMBER_OF_EQUIPMENT_CARDS];

int front;
int back;
int numberOfCards;

static Equipment_E RemoveCard(int cardIndex)
{
    if (numberOfCards == 0)
    {
        printf("Card deck is empty\n");
    }
    if (cardIndex == 0)
    {
        front = 1;
    }
    for (int j = cardIndex - 1; j > 0; j--)
    {
        cards[j+1] = cards[j];
    }
    front++;
    numberOfCards--;
}

void PrintEquipmentCardDeck()
{
    printf("Equipment cards in deck:\n");
    for (int i = front; i < back; i++)
    {
        switch(cards[i])
        {
            case EQUIPMENT_BASEBALL_BAT:
                printf("Baseball bat\n");
                break;
            case EQUIPMENT_FRYING_PAN:
                printf("Frying pan\n");
                break;
            case EQUIPMENT_KATANA:
                printf("Katana\n");
                break;
            case EQUIPMENT_PISTOL:
                printf("Pistol\n");
                break;
            case EQUIPMENT_BOTTLED_WATER:
                printf("Bottled water\n");
                break;
            case EQUIPMENT_MOLOTOV:
                printf("Molotov\n");
                break;
            default:
                break;
        }
    }
    printf("\n");
}

void SetupEquipmentCardDeck()
{
    cards[0] = EQUIPMENT_BASEBALL_BAT;
    cards[1] = EQUIPMENT_FRYING_PAN;
    cards[2] = EQUIPMENT_FRYING_PAN;
    cards[3] = EQUIPMENT_MOLOTOV;
    cards[4] = EQUIPMENT_FRYING_PAN;
    cards[5] = EQUIPMENT_PISTOL;
    cards[6] = EQUIPMENT_BOTTLED_WATER;
    cards[7] = EQUIPMENT_BOTTLED_WATER;
    cards[8] = EQUIPMENT_ASSAULT_RIFLE;
    cards[9] = EQUIPMENT_BASEBALL_BAT;
    cards[10] = EQUIPMENT_KATANA;
    cards[11] = EQUIPMENT_FRYING_PAN;
    cards[12] = EQUIPMENT_BASEBALL_BAT;
    cards[13] = EQUIPMENT_FRYING_PAN;
    cards[14] = EQUIPMENT_MOLOTOV;
    cards[15] = EQUIPMENT_FRYING_PAN;
    cards[16] = EQUIPMENT_MOLOTOV;
    cards[17] = EQUIPMENT_BOTTLED_WATER;
    cards[18] = EQUIPMENT_PISTOL;
    cards[19] = EQUIPMENT_FRYING_PAN;
    cards[20] = EQUIPMENT_FRYING_PAN;
    cards[21] = EQUIPMENT_BASEBALL_BAT;
    cards[22] = EQUIPMENT_MOLOTOV;
    cards[23] = EQUIPMENT_BASEBALL_BAT;
    cards[24] = EQUIPMENT_ASSAULT_RIFLE;
    cards[25] = EQUIPMENT_FRYING_PAN;
    cards[26] = EQUIPMENT_BOTTLED_WATER;
    cards[27] = EQUIPMENT_KATANA;
    cards[28] = EQUIPMENT_FRYING_PAN;
    cards[29] = EQUIPMENT_KATANA;
    front = 0;
    back = NUMBER_OF_EQUIPMENT_CARDS - 1;
    numberOfCards = NUMBER_OF_EQUIPMENT_CARDS;
    srand(time(NULL));
}

Equipment_E DrawEquipmentCard()
{
    int newCardIndex = rand() % (back - front + 1) + front;
    Equipment_E equipmentToReturn = cards[newCardIndex];

    RemoveCard(newCardIndex);
    return equipmentToReturn;
}

