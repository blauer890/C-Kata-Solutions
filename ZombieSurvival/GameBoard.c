#include <stdio.h>
#include <stdint.h>

#include "GameBoard.h"

typedef struct
{
    uint16_t id;
    EntityType_E entityType;
} Entity_S;

uint16_t zombieID;
uint16_t survivorID;

Entity_S gameBoard[10][5];

void SetupGameBoard()
{
    zombieID = 0;
    survivorID = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            gameBoard[i][j].id = 65535;
            gameBoard[i][j].entityType = ENTITY_TYPE_NONE;
        }
    }
    zombieID++;
    gameBoard[5][1].id = zombieID;
    gameBoard[5][1].entityType = ENTITY_TYPE_ZOMBIE;
    zombieID++;
    gameBoard[8][4].id = zombieID;
    gameBoard[8][4].entityType = ENTITY_TYPE_ZOMBIE;
    zombieID++;
    gameBoard[9][2].id = zombieID;
    gameBoard[9][2].entityType = ENTITY_TYPE_ZOMBIE;
}

void PrintGameBoard()
{
    printf("Current game board:\n");
    printf("\n");
    for (uint8_t i = 0; i < 10; i++)
    {
        printf("|ZONE%u", i);
    }
    printf("|\n");
    for (int j = 4; j >= 0; j--)
    {
        printf("|");
        for (int i = 0; i < 10; i++)
        {
            if (gameBoard[i][j].entityType == ENTITY_TYPE_ZOMBIE)
            {
                printf("Z%-3u |", gameBoard[i][j].id);
            } else if (gameBoard[i][j].entityType == ENTITY_TYPE_SURVIVOR)
            {
                printf("S%-3u |", gameBoard[i][j].id);
            } else if (gameBoard[i][j].entityType == ENTITY_TYPE_NONE)
            {
                printf("X    |");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void AddSurvivorToBoard(Survivor_S *survivor)
{
    int j = 0;

    while ((j < 5) && (gameBoard[0][j].entityType != ENTITY_TYPE_NONE))
    {
        j++;
    }
    if (j == 5)
    {
        printf("Max player number reached, unable to add player to board\n");
    }
    survivorID++;
    survivor->id = survivorID;
    gameBoard[0][j].id = survivorID;
    gameBoard[0][j].entityType = ENTITY_TYPE_SURVIVOR;
}

static uint8_t FindSurvivorZone(Survivor_S *survivor)
{
    for (uint8_t i = 0; i < 10; i++)
    {
        for (uint8_t j = 0; j < 5; j++)
        {
            if ((gameBoard[i][j].entityType = ENTITY_TYPE_SURVIVOR) &&
                (gameBoard[i][j].id == survivor->id))
            {
                return i;
            }
        }
    }
}

void AttackValid(Survivor_S *survivor)
{
    uint8_t survivorZone = FindSurvivorZone(survivor);

    EquipmentAttributes_S inHandItem0;
    EquipmentAttributes_S inHandItem1;

    LookupEquipmentAttributes(survivor->inHandItems[0], &inHandItem0);
    LookupEquipmentAttributes(survivor->inHandItems[1], &inHandItem1);

}

void MoveSurvivorOnBoard(Survivor_S *survivor)
{
}

static void AddZombie()
{
    // TODO: Implement this if needed
}
