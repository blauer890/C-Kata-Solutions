#pragma once

#include "Survivor.h"

void InitializeTurnQueue();
void StartGame();
void AddSurvivor(Survivor_S *survivor);
void WoundSurvivor(Survivor_S *survivor);
void CompleteTurn(Survivor_S *survivor);
void ZombieKilled();
