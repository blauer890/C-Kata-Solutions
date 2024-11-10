#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define MAX_SURVIVORS 4

typedef struct
{
    uint8_t name[30];
    uint8_t wounds;
    bool isTurn;
    bool isAlive;
    uint8_t actionCounter;
}survivor_attributes_t;

uint8_t turnCounter = 0;
survivor_attributes_t *turnCounterQueue[MAX_SURVIVORS] = {NULL, NULL, NULL, NULL};

//Prototypes
void SetupGame(void);
survivor_attributes_t CreateSurvivor(uint8_t *name);
void SurvivorAction(survivor_attributes_t *survivor);
void AddSurvivor(survivor_attributes_t *newSurvivor);
void DoAction(survivor_attributes_t *survivor);
void EndTurn(survivor_attributes_t *survivor);
void WoundSurvivor(survivor_attributes_t *survivor);

int main()
{
    survivor_attributes_t Spongebob = CreateSurvivor("Spongebob");
    survivor_attributes_t Patrick = CreateSurvivor("Patrick");

    AddSurvivor(&Spongebob);
    AddSurvivor(&Patrick);

    SetupGame();

    for(int i = 0; i < 99; i++)
    {
        DoAction(&Spongebob);
    }
    EndTurn(&Spongebob);

    for(int i = 0; i < 99; i++)
    {
        DoAction(&Patrick);
    }
    EndTurn(&Patrick);

    WoundSurvivor(&Spongebob);
    WoundSurvivor(&Spongebob);

    DoAction(&Spongebob);
    EndTurn(&Spongebob);

    WoundSurvivor(&Patrick);
    WoundSurvivor(&Patrick);

    DoAction(&Patrick);
    EndTurn(&Patrick);

}

void SetupGame(void)
{
    if(turnCounterQueue[0]->isAlive)
    {
        turnCounterQueue[0]->isTurn = true;
    }

    int i = 1;
    while((i < MAX_SURVIVORS) && (turnCounterQueue[i] != NULL))
    {
        turnCounterQueue[i]->isTurn = false;
        i++;
    }
}

survivor_attributes_t CreateSurvivor(uint8_t *name)
{
    survivor_attributes_t newSurvivor;
    strcpy(newSurvivor.name, name);
    newSurvivor.wounds = 0;
    newSurvivor.isAlive = true;
    newSurvivor.isTurn = false;
    newSurvivor.actionCounter = 3;
    printf("%s wounds = %u\n", newSurvivor.name, newSurvivor.wounds);

    return newSurvivor;
}

void MoveTurnCounter(void)
{
    int originalTurn = turnCounter;

    if(turnCounter == 3)
    {
        turnCounter = 0;
        printf("turn counter = %d\n", turnCounter);
    }
    else
    {
        turnCounter++;
        printf("turn counter = %d\n", turnCounter);
    }

    while((turnCounter != originalTurn) &&
          ((turnCounterQueue[turnCounter] == NULL) ||
          !turnCounterQueue[turnCounter]->isAlive))
    {
        if(turnCounter == 3)
        {
            turnCounter = 0;
            printf("turn counter = %d\n", turnCounter);
        }
        else
        {
            turnCounter++;
            printf("turn counter = %d\n", turnCounter);
        }
    }

    if(turnCounter == originalTurn)
    {
        printf("Unable to advance turn counter\n");
        return;
    }

    turnCounterQueue[turnCounter]->isTurn = true;

    printf("It is now %s's turn\n", turnCounterQueue[turnCounter]->name);
}

void AddSurvivor(survivor_attributes_t *newSurvivor)
{
    int i = 0;
    while((turnCounterQueue[i] != NULL) && (i < MAX_SURVIVORS))
    {
        i++;
    }
    if(i >= MAX_SURVIVORS)
    {
        printf("Can't add survivor %s to queue, player queue full\n", newSurvivor->name);
        return;
    }
    printf("Adding survivor %s to turn counter queue at index %d\n", newSurvivor->name, i);
    turnCounterQueue[i] = newSurvivor;
}

void SurvivorAction(survivor_attributes_t *survivor)
{
    if(!survivor->isAlive)
    {
        printf("%s is not alive and cannot perform any actions\n", survivor->name);
        return;
    }
    if(survivor->actionCounter != 0)
    {
        survivor->actionCounter --;
        printf("%s did an action\n", survivor->name);
    }
}

void DoAction(survivor_attributes_t *survivor)
{
    SurvivorAction(survivor);
}

void EndTurn(survivor_attributes_t *survivor)
{
    if(survivor->isTurn == true)
    {
        survivor->isTurn = false;
        printf("%s ended their turn\n", survivor->name);
        MoveTurnCounter();
    }
}

void WoundSurvivor(survivor_attributes_t *survivor)
{
    if(survivor->wounds < 2)
    {
        survivor->wounds++;
        if(survivor->wounds == 2)
        {
            survivor->isAlive = false;
        }
    }
}
