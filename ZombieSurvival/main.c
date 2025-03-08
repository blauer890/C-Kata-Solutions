#include <stdio.h>

#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"
#include "Log.h"

Survivor_S Spongebob;
Survivor_S Patrick;

void ExampleAction()
{
    LogInfo("Example action");
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
    LogInfo("Spongebob added items");
}

void SpongebobKillZombie()
{
    LogInfo("Spongebob killing zombie");
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

    LogInfo("Spongebob completing turn");
    CompleteTurn(&Spongebob);

    WoundSurvivor(&Spongebob);

    TakeAction(&Patrick, ExampleAction);
    TakeAction(&Patrick, ExampleAction);

    LogInfo("Patrick completing turn");
    CompleteTurn(&Patrick);

    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);

    CompleteTurn(&Spongebob);
    CompleteTurn(&Patrick);

    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);
    TakeAction(&Spongebob, SpongebobKillZombie);

    return 0;
}
