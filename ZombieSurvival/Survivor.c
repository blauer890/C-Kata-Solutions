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
    for(int i = 0; i < 10; i++)
    {
        newSurvivor->skills[i] = SKILLS_NONE;
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
}

void AddNewSkill(Survivor_S *survivor, Skills_E newSkill)
{
    int i = 0;
    while((i < 10) && (survivor->skills[i] != SKILLS_NONE))
    {
        i++;
    }
    survivor->skills[i] = newSkill;
}
