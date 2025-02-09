#include "GameManager.h"

bool GameActive = false;
Level_E GameLevel = BLUE;

void StartGame()
{
    GameActive = true;
}

void EndGame()
{
    GameActive = false;
}

bool GameRunning()
{
    return GameActive;
}

void SetGameLevel(Level_E newLevel)
{
    GameLevel = newLevel;
}

Level_E GetGameLevel()
{
    return GameLevel;
}

