#include <stdio.h>

#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"

Survivor_S Spongebob;
Survivor_S Patrick;

void ExampleAction()
{
    printf("Performed an action\n");
}

void SpongebobAddItems()
{
    Spongebob.InHandItems[0] = NONE;
    Spongebob.InHandItems[1] = KATANA;
    Spongebob.ReservesItems[0] = NONE;
    Spongebob.ReservesItems[1] = MOLOTOV;
    Spongebob.ReservesItems[2] = BOTTLED_WATER;
    Spongebob.ReservesItems[3] = FRYING_PAN;
    Spongebob.ReservesItems[4] = NONE;
}

void SpongebobKillZombie()
{
    printf("Spongebob killing zombie\n");
    KillZombie(&Spongebob);
    ZombieKilled();
}

int main()
{
    InitializeTurnQueue();

    CreateSurvivor(&Spongebob, "Spongebob", sizeof("Spongebob"));
    CreateSurvivor(&Patrick, "Patrick", sizeof("Patrick"));

    AddSurvivor(&Spongebob);
    AddSurvivor(&Patrick);

    TakeAction(&Spongebob, ExampleAction);
    TakeAction(&Spongebob, SpongebobAddItems);

    printf("Spongebob completing turn in main.c\n");
    CompleteTurn(&Spongebob);

    WoundSurvivor(&Spongebob);

    TakeAction(&Patrick, ExampleAction);
    TakeAction(&Patrick, ExampleAction);

    printf("Patrick completing turn in main.c\n");
    CompleteTurn(&Patrick);

    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);

    CompleteTurn(&Spongebob);
    CompleteTurn(&Patrick);

    printf("Spongebob level: %u\n", Spongebob.level);
    printf("Game level: %u\n", GetGameLevel());

    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);

    printf("Spongebob level: %u\n", Spongebob.level);
    printf("Game level: %u\n", GetGameLevel());

    return 0;
}
