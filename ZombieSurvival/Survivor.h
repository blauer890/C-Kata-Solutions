#pragma once

#include <stdint.h>
#include <stdlib.h>

typedef void (*ActionFunc)();

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

typedef struct
{
    char name[MAX_SURVIVOR_NAME_LEN];
    uint8_t wounds;
    uint8_t actions;
    Equipment_E InHandItems[2];
    Equipment_E ReservesItems[5];
    uint32_t experience;
    Level_E level;
} Survivor_S;

void CreateSurvivor(Survivor_S *newSurvivor, char *name, size_t nameLen);
void TakeAction(Survivor_S *survivor, ActionFunc action);
int GetItemCount(Survivor_S *survivor);
void KillZombie(Survivor_S *survivor);

