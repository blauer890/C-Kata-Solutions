#pragma once

#include "Survivor.h"

typedef enum
{
    ENTITY_TYPE_SURVIVOR,
    ENTITY_TYPE_ZOMBIE,
    ENTITY_TYPE_NONE
} EntityType_E;

void SetupGameBoard();
void PrintGameBoard();
void AddSurvivorToBoard(Survivor_S *survivor);
void MoveSurvivorOnBoard(Survivor_S *survivor);
