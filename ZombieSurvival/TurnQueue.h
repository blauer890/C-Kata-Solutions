#pragma once

#include "Survivor.h"

void InitializeTurnQueue();
uint32_t NumberOfSurivors();
void ActiveSurvivor(Survivor_S **survivor);
void AddSurvivor(Survivor_S *survivor);
void WoundSurvivor(Survivor_S *survivor);
void CompleteTurn(Survivor_S *survivor);
void CompleteAction(Survivor_S *survivor);
void ZombieKilled();
