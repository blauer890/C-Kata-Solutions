#pragma once

#include <stdbool.h>

#include "Survivor.h"
#include "TurnQueue.h"

void StartGame();
void EndGame();
bool GameRunning();
void SetGameLevel(Level_E newLevel);
Level_E GetGameLevel();

