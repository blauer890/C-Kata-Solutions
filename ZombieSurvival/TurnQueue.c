#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"
#include "Log.h"

#define MAX_SURVIVORS 5
#define MIN_SURVIVORS 2

Survivor_S *TurnQueue[MAX_SURVIVORS];
uint32_t TurnQueueIndex;
uint32_t SurvivorNum = 0;

void InitializeTurnQueue()
{
    for(uint8_t i = 0; i < MAX_SURVIVORS; i++)
    {
        TurnQueue[i] = NULL;
    }
    TurnQueueIndex = 0;
    LogInfo("starting game...");
}

void AddSurvivor(Survivor_S *survivor)
{
    uint32_t i = 0;
    //Find an empty spot
    while((i < MAX_SURVIVORS) && (TurnQueue[i] != NULL))
    {
        assert(strcmp(TurnQueue[i]->name, survivor->name));
        i++;
    }
    if(i == MAX_SURVIVORS)
    {
        printf("Can't add a new player\n");
    }
    TurnQueue[i] = survivor;
    SurvivorNum++;
    char buf[100];
    sprintf(buf, "survivor %s has been added to the game", survivor->name);
    LogInfo(buf);
}

static void RemoveSurvivor(Survivor_S *survivor)
{
    uint32_t i = 0;
    while(i < MAX_SURVIVORS)
    {
        if((TurnQueue[i] != NULL) && !strcmp(TurnQueue[i]->name, survivor->name))
        {
            break;
        }
    }
    for(uint32_t j = i; j < (MAX_SURVIVORS - 1); j++)
    {
        TurnQueue[j] = TurnQueue[j+1];
        TurnQueue[j+1] = NULL;
    }
    TurnQueue[MAX_SURVIVORS - 1] = NULL;
    SurvivorNum--;
    if(SurvivorNum == 0)
    {
        EndGame();
    }
}

void WoundSurvivor(Survivor_S *survivor)
{
    survivor->wounds++;
    if(survivor->wounds == 2)
    {
        RemoveSurvivor(survivor);
        if(!strcmp(TurnQueue[TurnQueueIndex]->name, survivor->name))
        {
            CompleteTurn(survivor);
        }
        char buf[200];
        sprintf(buf, "Surivor %s died", survivor->name);
        LogInfo(buf);
    } else {
        if(GetItemCount(survivor) == MAX_EQUIPMENT)
        {
            uint8_t lastReserveItemIndex = 0;
            for(uint8_t i = 0; i < 5; i++)
            {
                if(survivor->ReservesItems[i] != NONE)
                {
                    lastReserveItemIndex = i;
                }
            }
            survivor->ReservesItems[lastReserveItemIndex] = NONE;
        }
    }
    char buf[200];
    sprintf(buf, "survivor %s was wounded", survivor->name);
    LogInfo(buf);
}

static void AdvanceTurnQueue()
{
    uint32_t tempTurnQueueIndex = TurnQueueIndex;
    if(tempTurnQueueIndex < (MAX_SURVIVORS - 1))
    {
        tempTurnQueueIndex++;
    } else {
        tempTurnQueueIndex = 0;
    }
    while((TurnQueue[tempTurnQueueIndex] == NULL) && (tempTurnQueueIndex != TurnQueueIndex))
    {
        if(tempTurnQueueIndex < (MAX_SURVIVORS - 1))
        {
            tempTurnQueueIndex++;
        } else {
            tempTurnQueueIndex = 0;
        }
    }
    TurnQueueIndex = tempTurnQueueIndex;
}

void CompleteTurn(Survivor_S *survivor)
{
    survivor->actions = 3;
    if(!strcmp(TurnQueue[TurnQueueIndex]->name, survivor->name))
    {
        AdvanceTurnQueue();
    }
}

void ZombieKilled()
{
    Level_E maxLevel = GetGameLevel();
    for(uint8_t i = 0; i < MAX_SURVIVORS; i++)
    {
        if((TurnQueue[i] != NULL) && (TurnQueue[i]->level > maxLevel))
        {
            maxLevel = TurnQueue[i]->level;
            LogInfo("Game has leveled up");
        }
    }
    SetGameLevel(maxLevel);
}

