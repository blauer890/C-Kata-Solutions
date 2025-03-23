#include "Survivor.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void CreateSurvivor(Survivor_S *newSurvivor, char *name, size_t nameLen)
{
    assert(nameLen < MAX_SURVIVOR_NAME_LEN);
    strcpy(newSurvivor->name, name);
    newSurvivor->wounds = 0;
    newSurvivor->maxWounds = 2;
    newSurvivor->actions = 0;
    newSurvivor->maxActions = 3;
    newSurvivor->experience = 0;
    newSurvivor->level = BLUE;
    newSurvivor->skills = 0;
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
    switch(survivor->experience)
    {
    case 7:
        survivor->level = YELLOW;
        survivor->maxActions++;
        survivor->skills++;
        printf("Survivor %s leveled up to yellow and is at %u max actions\n", survivor->name, survivor->maxActions);
        break;
    case 50:
    case 93:
        survivor->maxActions++;
        survivor->skills++;
        printf("Survivor %s unlocked another action, at %u actions\n", survivor->name, survivor->maxActions);
        break;
    case 18:
        survivor->level = ORANGE;
        survivor->maxWounds += 2;
        survivor->skills += 2;
        printf("Survivor %s leveled up to orange and is at %u wounds\n", survivor->name, survivor->actions);
        break;
    case 61:
    case 104:
        survivor->maxWounds += 2;
        survivor->skills += 2;
        printf("Survivor %s increased max wounds by 2, at %u max wounds\n", survivor->name, survivor->maxWounds);
        break;
    case 43:
        survivor->level = RED;
        survivor->maxWounds += 3;
        survivor->skills += 3;
        printf("Survivor %s leveled up to red and is at %u max wounds\n", survivor->name, survivor->maxWounds);
        break;
    case 86:
    case 129:
        survivor->maxWounds += 3;
        survivor->skills += 3;
        printf("Survivor %s increased max wounds by 3, at %u max wounds\n", survivor->name, survivor->maxWounds);
        break;
    default:
        break;
    }
}


