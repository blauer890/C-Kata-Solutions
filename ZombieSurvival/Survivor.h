#pragma once

#include <stdint.h>
#include <stdlib.h>

#define MAX_SURVIVOR_NAME_LEN 30
#define MAX_EQUIPMENT 5

typedef enum
{
    BASEBALL_BAT,
    FRYING_PAN,
    KATANA,
    PISTOL,
    BOTTLED_WATER,
    MOLOTOV,
    NONE
} Equipment_E;

typedef enum
{
    BLUE,
    YELLOW,
    ORANGE,
    RED
} Level_E;

typedef enum
{
    SKILLS_PLUS_ONE_ACTION,
    SKILLS_PLUS_ONE_DIE_RANGED,
    SKILLS_PLUS_ONE_DIE_MELEE,
    SKILLS_PLUS_ONE_FREE_MOVE_ACTION,
    SKILLS_HOARD,
    SKILLS_SNIPER,
    SKILLS_TOUGH,
    SKILLS_NONE
} Skills_E;

typedef struct
{
    char name[MAX_SURVIVOR_NAME_LEN];
    uint8_t wounds;
    uint8_t maxWounds;
    uint8_t actions;
    uint8_t maxActions;
    Equipment_E InHandItems[2];
    Equipment_E ReservesItems[5];
    uint32_t experience;
    Level_E level;
    Skills_E skills[10];
} Survivor_S;

void CreateSurvivor(Survivor_S *newSurvivor, char *name, size_t nameLen);
int GetItemCount(Survivor_S *survivor);
void KillZombie(Survivor_S *survivor);
void AddNewSkill(Survivor_S *survivor, Skills_E newSkill);

