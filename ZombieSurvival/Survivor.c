#include "Survivor.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

uint32_t yellowLevels[3] = {7,50,93};
uint32_t orangeLevels[3] = {18,61,104};
uint32_t redLevels[3] = {43,86,129};

bool FirstYellowLevel(uint32_t experience)
{
    return experience == yellowLevels[0];
}

bool FirstOrangeLevel(uint32_t experience)
{
    return experience == orangeLevels[0];
}

bool FirstRedLevel(uint32_t experience)
{
    return experience == redLevels[0];
}

bool InYellowLevels(uint32_t experience)
{
    for (uint32_t i = 0; i < 3; i++)
    {
        if (experience == yellowLevels[i])
        {
            return true;
        }
    }
    return false;
}

bool InOrangeLevels(uint32_t experience)
{
    for (uint32_t i = 0; i < 3; i++)
    {
        if (experience == orangeLevels[i])
        {
            return true;
        }
    }
    return false;
}

bool InRedLevels(uint32_t experience)
{
    for (uint32_t i = 0; i < 3; i++)
    {
        if (experience == redLevels[i])
        {
            return true;
        }
    }
    return false;
}

void PrintSurvivorSkills(Survivor_S *survivor)
{
    printf("%s\'s skills:\n", survivor->name);
    for (int i = 0; i < 10; i++)
    {
        if (survivor->skills[i] == SKILLS_NONE)
        {
            break;
        }
        switch(survivor->skills[i])
        {
            case SKILLS_PLUS_ONE_ACTION:
                printf("+1 One Action\n");
                break;
            case SKILLS_PLUS_ONE_DIE_RANGED:
                printf("+1 One Die Ranged\n");
                break;
            case SKILLS_PLUS_ONE_DIE_MELEE:
                printf("+1 One Die Melee\n");
                break;
            case SKILLS_PLUS_ONE_FREE_MOVE_ACTION:
                printf("+1 One Free Move Action\n");
                break;
            case SKILLS_HOARD:
                printf("Hoard\n");
                break;
            case SKILLS_SNIPER:
                printf("Sniper\n");
                break;
            case SKILLS_TOUGH:
                printf("Tough\n");
                break;
            default:
                break;
        }
    }
    printf("\n");
}

void CreateSurvivor(Survivor_S *newSurvivor, char *name, size_t nameLen)
{
    assert(nameLen < MAX_SURVIVOR_NAME_LEN);
    strcpy(newSurvivor->name, name);
    newSurvivor->wounds = 0;
    newSurvivor->maxWounds = 2;
    newSurvivor->actions = 0;
    newSurvivor->maxActions = 3;
    newSurvivor->inHandItems[0] = EQUIPMENT_NONE;
    newSurvivor->inHandItems[1] = EQUIPMENT_NONE;
    newSurvivor->reservesItems[0] = EQUIPMENT_NONE;
    newSurvivor->reservesItems[1] = EQUIPMENT_NONE;
    newSurvivor->reservesItems[2] = EQUIPMENT_NONE;
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
        if(survivor->inHandItems[i] != EQUIPMENT_NONE)
        {
            itemCount++;
        }
    }
    for(uint8_t i = 0; i < 5; i++)
    {
        if(survivor->reservesItems[i] != EQUIPMENT_NONE)
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
