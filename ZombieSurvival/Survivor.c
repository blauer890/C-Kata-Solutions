#include "Survivor.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void CreateSurvivor(Survivor_S *newSurvivor, char *name, size_t nameLen)
{
    assert(nameLen < MAX_SURVIVOR_NAME_LEN);
    strcpy(newSurvivor->name, name);
    newSurvivor->wounds = 0;
    newSurvivor->actions = 3;
    newSurvivor->experience = 0;
    newSurvivor->level = BLUE;
}

void TakeAction(Survivor_S *survivor, ActionFunc action)
{
    if(survivor->actions > 0)
    {
        action();
        survivor->actions--;
    }
}

int GetItemCount(Survivor_S *survivor)
{
    uint32_t itemCount = 0;
    for(uint8_t i = 0; i < 2; i++)
    {
        if(survivor->InHandItems[i] != NONE)
        {
            itemCount++;
        }
    }
    for(uint8_t i = 0; i < 5; i++)
    {
        if(survivor->ReservesItems[i] != NONE)
        {
            itemCount++;
        }
    }
    return itemCount;
}

void KillZombie(Survivor_S *survivor)
{
    survivor->experience++;
    if((survivor->experience >= 6) && (survivor->level != YELLOW))
    {
        printf("Survivor %s leveled up to yellow", survivor->name);
        survivor->level = YELLOW;
    } else if((survivor->experience >= 18) && (survivor->level != ORANGE))
    {
        printf("Survivor %s leveled up to orange", survivor->name);
        survivor->level = ORANGE;
    } else if((survivor->experience >= 42) && (survivor->level != RED))
    {
        printf("Survivor %s leveled up to red", survivor->name);
        survivor->level = RED;
    }
}


