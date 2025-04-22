#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"
#include "EquipmentCards.h"

#define MAX_SURVIVORS 5

void PrintSingleInventoryItem(Equipment_E equipment)
{
    switch(equipment)
    {
        case EQUIPMENT_BASEBALL_BAT:
            printf("baseball bat");
            break;
        case EQUIPMENT_FRYING_PAN:
            printf("frying pan");
            break;
        case EQUIPMENT_KATANA:
            printf("katana");
            break;
        case EQUIPMENT_PISTOL:
            printf("pistol");
            break;
        case EQUIPMENT_ASSAULT_RIFLE:
            printf("assault rifle");
            break;
        case EQUIPMENT_BOTTLED_WATER:
            printf("bottled water");
            break;
        case EQUIPMENT_MOLOTOV:
            printf("molotov");
            break;
        case EQUIPMENT_WOUND:
            printf("wound");
            break;
        case EQUIPMENT_NONE:
            printf("empty");
            break;
    }
}

void PrintInventoryItems(Survivor_S *survivor)
{
    printf("%s's in-hand items: ", survivor->name);
    PrintSingleInventoryItem(survivor->inHandItems[0]);
    printf(",");
    PrintSingleInventoryItem(survivor->inHandItems[1]);
    printf("\n");
    printf("%s's reserves items: ", survivor->name);
    PrintSingleInventoryItem(survivor->reservesItems[0]);
    printf(",");
    PrintSingleInventoryItem(survivor->reservesItems[1]);
    printf(",");
    PrintSingleInventoryItem(survivor->reservesItems[2]);
    printf("\n");
}

int main()
{
    Survivor_S survivor1, survivor2,
               survivor3, survivor4,
               survivor5;

    SetupEquipmentCardDeck();
    InitializeTurnQueue();
    printf("\n");
    StartGame();
    while(GameRunning())
    {
        if(NumberOfSurivors() > 0)
        {
            Survivor_S *activeSurvivor;
            ActiveSurvivor(&activeSurvivor);
            printf("%s\'s turn, actions left: %u\n", activeSurvivor->name, activeSurvivor->maxActions - activeSurvivor->actions);
            printf("%s\'s experience: %u\n", activeSurvivor->name, activeSurvivor->experience);
            printf("Options: \n");
            printf("Attack - 1\n");
            printf("Move - 2\n");
            printf("View skils - 3\n");
            printf("Search - 4\n");
            printf("End game - 5\n");
            printf("Enter an option: ");
            int option = 0;
            scanf("%d", &option);
            if(option == 1)
            {
                // Perform combat action
                KillZombie(activeSurvivor);
                if (InYellowLevels(activeSurvivor->experience))
                {
                    activeSurvivor->maxActions++;
                    if (FirstYellowLevel(activeSurvivor->experience))
                    {
                        activeSurvivor->level = YELLOW;
                    }
                    AddNewSkill(activeSurvivor, SKILLS_PLUS_ONE_ACTION);
                } else if (InOrangeLevels(activeSurvivor->experience))
                {
                    if (FirstOrangeLevel(activeSurvivor->experience))
                    {
                        activeSurvivor->level = ORANGE;
                    }
                    printf("\n");
                    printf("Select a new skill to acquire: \n");
                    printf("+1 Die Melee Combat Action - 1\n");
                    printf("+1 Free Move Action - 2\n");
                    int option = 0;
                    scanf("%d", &option);
                    switch(option)
                    {
                        case 1:
                            AddNewSkill(activeSurvivor, SKILLS_PLUS_ONE_DIE_MELEE);
                            break;
                        case 2:
                            AddNewSkill(activeSurvivor, SKILLS_PLUS_ONE_FREE_MOVE_ACTION);
                            break;
                        default:
                            break;
                    }
                } else if (InRedLevels(activeSurvivor->experience))
                {
                    if (FirstRedLevel(activeSurvivor->experience))
                    {
                        activeSurvivor->level = RED;
                    }
                    printf("\n");
                    printf("Select a new skills to acquire\n");
                    printf("+1 Die Ranged Combat Action - 1\n");
                    printf("Hoard - 2\n");
                    printf("Sniper - 3\n");
                    int option = 0;
                    scanf("%d", &option);
                    switch(option)
                    {
                        case 1:
                            AddNewSkill(activeSurvivor, SKILLS_PLUS_ONE_DIE_RANGED);
                            break;
                        case 2:
                            AddNewSkill(activeSurvivor, SKILLS_HOARD);
                            break;
                        case 3:
                            AddNewSkill(activeSurvivor, SKILLS_SNIPER);
                            break;
                        default:
                            break;
                    }
                }
                CompleteAction(activeSurvivor);
            } else if(option == 2)
            {
                // Perform move action
                printf("\n");
                printf("Exploring terrain\n");
                CompleteAction(activeSurvivor);
            } else if(option == 3)
            {
                // Print survivor skills
                PrintSurvivorSkills(activeSurvivor);
            } else if(option == 4)
            {
                // Search crate for new equipment
                printf("\n");
                Equipment_E newEquipment = DrawEquipmentCard();
                printf("%s found a ", activeSurvivor->name);
                switch(newEquipment)
                {
                    case EQUIPMENT_BASEBALL_BAT:
                        printf("baseball bat\n");
                        break;
                    case EQUIPMENT_FRYING_PAN:
                        printf("frying pan\n");
                        break;
                    case EQUIPMENT_KATANA:
                        printf("katana\n");
                        break;
                    case EQUIPMENT_PISTOL:
                        printf("pistol\n");
                        break;
                    case EQUIPMENT_ASSAULT_RIFLE:
                        printf("assault rifle\n");
                        break;
                    case EQUIPMENT_BOTTLED_WATER:
                        printf("bottled water\n");
                        break;
                    case EQUIPMENT_MOLOTOV:
                        printf("molotov\n");
                        break;
                    default:
                        break;
                }
                printf("Select an inventory slot to place the new equipment\n");
                PrintInventoryItems(activeSurvivor);
                printf("In-hand slot 1 - 1\n");
                printf("In-hand slot 2 - 2\n");
                printf("Reserves slot 1 - 3\n");
                printf("Reserves slot 2 - 4\n");
                printf("Reserves slot 3 - 5\n");
                int option = 0;
                scanf("%d", &option);
                switch(option)
                {
                    case 1:
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                
                }
                CompleteAction(activeSurvivor);
            } else if(option == 5)
            {
                EndGame();
            } else {
                continue;
            }
            printf("\n");
        } else {
            printf("Options: \n");
            printf("Create a new survivor - 1\n");
            printf("End game - 2\n");
            int option = 0;
            printf("Enter an option: ");
            scanf("%d", &option);
            printf("\n");
            if(option == 1)
            {
                // TODO: Replace with selecting from pre-made list of survivors
                char name[255];
                printf("Enter a survivor name: ");
                scanf("%s", name);
                printf("\n");
                printf("Creating survivor...\n");
                CreateSurvivor(&survivor1,name,strlen(name));
                AddSurvivor(&survivor1);
                printf("\n");
            } else if(option == 2)
            {
                // End game
                EndGame();
            } else {
                continue;
            }
        }
    }
    return 0;
}
