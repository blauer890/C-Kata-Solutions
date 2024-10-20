#include <stdio.h>
#include "Character.h"

int main()
{
    Character_T Patrick, Spongebob;
    printf("-------------------------------------------------\n");
    printf("Creating characters Patrick and Spongebob\n");
    CreateCharacter(&Patrick, "Patrick", MELEE);
    CreateCharacter(&Spongebob, "Spongebob", RANGED);
    for (uint8_t i = 0; i < 30; i++)
    {
        IncreaseLevel(&Patrick);
    }
    for (uint8_t i = 0; i < 5; i++)
    {
        IncreaseLevel(&Spongebob);
    }
    MoveToPosition(&Spongebob, 38.0f, 55.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Patrick trying to attack Spongebob with 10.0f damage\n");
    AttackCharacter(&Patrick, &Spongebob, 10.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Spongebob moving to (1.0f, 1.0f)\n");
    MoveToPosition(&Spongebob, 1.0f, 1.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Spongebob trying to attack Patrick with 30.0f damage\n");
    AttackCharacter(&Spongebob, &Patrick, 30.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Patrick trying to attack Spongebob with 500.0f damage\n");
    AttackCharacter(&Patrick, &Spongebob, 500.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Spongebob trying to heal self with 30.0f health\n");
    HealCharacter(&Spongebob, &Spongebob, 30.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    printf("-------------------------------------------------\n");
    printf("Patrick trying to heal self with 10.0f health\n");
    HealCharacter(&Patrick, &Patrick, 10.0f);
    PrintCharacter(&Patrick);
    PrintCharacter(&Spongebob);

    Character_T Squidward, MrKrabs;
    printf("-------------------------------------------------\n");
    printf("Creating characters Squidward and Mr. Krabs\n");
    CreateCharacter(&Squidward, "Squidward", RANGED);
    CreateCharacter(&MrKrabs, "Mr. Krabs", MELEE);
    for (uint8_t i = 0; i < 14; i++)
    {
        IncreaseLevel(&Squidward);
    }
    for (uint8_t i = 0; i < 20; i++)
    {
        IncreaseLevel(&MrKrabs);
    }
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Moving Mr. Krabs to (25.0f, 10.0f)\n");
    MoveToPosition(&MrKrabs, 25.0f, 10.0f);
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Adding Squidward to factions Jellyfishers and Boaters\n");
    AddFaction(&Squidward, "Jellyfishers");
    AddFaction(&Squidward, "Boaters");
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Adding Mr. Krabs to faction Boaters\n");
    AddFaction(&MrKrabs, "Boaters");
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Checking if Mr. Krabs and Squidward are allies\n");
    printf("Allies: %u\n\n", CheckAllies(&Squidward, &MrKrabs));

    printf("-------------------------------------------------\n");
    printf("Moving Mr. Krabs to (10.0f, 10.0f)\n");
    MoveToPosition(&MrKrabs, 10.0f, 10.0f);
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Removing Mr. Krabs from faction Boaters\n");
    RemoveFaction(&MrKrabs, "Boaters");
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Squidward trying to attack Mr. Krabs with 100.0f damage\n");
    AttackCharacter(&Squidward, &MrKrabs, 100.0f);
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Adding Mr. Krabs to faction Jellyfishers\n");
    AddFaction(&MrKrabs, "Jellyfishers");
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Squidward trying to heal Mr. Krabs with 25.0f health\n");
    HealCharacter(&Squidward, &MrKrabs, 25.0f);
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Removing Squidward from faction Boaters\n");
    RemoveFaction(&Squidward, "Boaters");
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    printf("-------------------------------------------------\n");
    printf("Mr. Krabs trying to attack Squidward with 45.0f health\n");
    AttackCharacter(&MrKrabs, &Squidward, 45.0f);
    PrintCharacter(&Squidward);
    PrintCharacter(&MrKrabs);

    RemoveFactions(&Squidward);
    RemoveFactions(&MrKrabs);
    return 0;
}
