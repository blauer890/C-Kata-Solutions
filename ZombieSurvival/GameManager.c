#include "GameManager.h"
#include "Log.h"

bool GameActive = false;
Level_E GameLevel = BLUE;

void StartGame()
{
    GameActive = true;
}

void EndGame()
{
    LogInfo("Game ended");
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

