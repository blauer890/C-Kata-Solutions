#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"
#include "Equipment.h"
#include "EquipmentCards.h"
#include "GameBoard.h"

#define MAX_SURVIVORS 5

void PerformCombatAction(Survivor_S *survivor)
{
    // Perform combat action
    char leftHandPrompt[255];
    bool leftHandWeapon = false;
    char rightHandPrompt[255];
    bool rightHandWeapon = false;
    if (IsWeapon(survivor->inHandItems[0]))
    {
        char weaponString[50];
        GetWeaponString(survivor->inHandItems[0], weaponString);
        sprintf(leftHandPrompt, "Attack with left-hand item %s - L", weaponString);
        leftHandWeapon = true;
    }
    if (IsWeapon(survivor->inHandItems[1]))
    {
        char weaponString[50];
        GetWeaponString(survivor->inHandItems[1], weaponString);
        sprintf(rightHandPrompt, "Attack with right-hand item %s - R", weaponString);
        rightHandWeapon = true;
    }

    if (leftHandWeapon)
    {
        printf("%s\n", leftHandPrompt);
    }
    if (rightHandWeapon)
    {
        printf("%s\n", rightHandPrompt);
    }

    if (!leftHandWeapon && !rightHandWeapon)
    {
        printf("No valid weapons in hand\n");
        return;
    }

    char option = 0;
    scanf(" %c", &option);
    if ((option == 'L') && leftHandWeapon)
    {
        // TODO: Implement left-hand combat
    } else if ((option == 'R') && rightHandWeapon)
    {
        // TODO: Implement right-hand combat
    }

    KillZombie(survivor);
    if (InYellowLevels(survivor->experience))
    {
        survivor->maxActions++;
        if (FirstYellowLevel(survivor->experience))
        {
            survivor->level = YELLOW;
        }
        AddNewSkill(survivor, SKILLS_PLUS_ONE_ACTION);
    } else if (InOrangeLevels(survivor->experience))
    {
        if (FirstOrangeLevel(survivor->experience))
        {
            survivor->level = ORANGE;
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
                AddNewSkill(survivor, SKILLS_PLUS_ONE_DIE_MELEE);
                break;
            case 2:
                AddNewSkill(survivor, SKILLS_PLUS_ONE_FREE_MOVE_ACTION);
                break;
            default:
                break;
        }
    } else if (InRedLevels(survivor->experience))
    {
        if (FirstRedLevel(survivor->experience))
        {
            survivor->level = RED;
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
                AddNewSkill(survivor, SKILLS_PLUS_ONE_DIE_RANGED);
                break;
            case 2:
                AddNewSkill(survivor, SKILLS_HOARD);
                break;
            case 3:
                AddNewSkill(survivor, SKILLS_SNIPER);
                break;
            default:
                break;
        }
    }
    CompleteAction(survivor);
}

static void PrintSingleInventoryItem(Equipment_E equipment)
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

static void PrintInventoryItems(Survivor_S *survivor)
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

void EquipmentSearch(Survivor_S *survivor)
{
    // Search crate for new equipment
    printf("\n");
    Equipment_E newEquipment = DrawEquipmentCard();
    printf("%s found a ", survivor->name);
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
    PrintInventoryItems(survivor);
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
            if (survivor->inHandItems[0] == EQUIPMENT_WOUND)
            {
                printf("Wound card in in-hand slot 1, unable to equip new item\n");
            } else {
                survivor->inHandItems[0] = newEquipment;
            }
            break;
        case 2:
            if (survivor->inHandItems[1] == EQUIPMENT_WOUND)
            {
                printf("Wound card in in-hand slot 2, unable to equip new item\n");
            }
            survivor->inHandItems[1] = newEquipment;
            break;
        case 3:
            if (survivor->reservesItems[0] == EQUIPMENT_WOUND)
            {
                printf("Wound card in reserves slot 1, unable to equip new item\n");
            } else {
                survivor->reservesItems[0] = newEquipment;
            }
            break;
        case 4:
            if (survivor->reservesItems[1] == EQUIPMENT_WOUND)
            {
                printf("Wound card in reserves slot 2, unable to equip new item\n");
            } else {
                survivor->reservesItems[1] = newEquipment;
            }
            break;
        case 5:
            if (survivor->reservesItems[2] == EQUIPMENT_WOUND)
            {
                printf("Wound card in reserves slot 3, unable to equip new item\n");
            } else {
                survivor->reservesItems[2] = newEquipment;
            }
            break;
        default:
            break;
    }
    CompleteAction(survivor);
}

int main(int argc, char *argv[])
{
    Survivor_S survivor1, survivor2,
               survivor3, survivor4,
               survivor5;

    srand(time(NULL));

    SetupGameBoard();
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
            PrintGameBoard();

            printf("%s\'s turn, actions left: %u\n", activeSurvivor->name, activeSurvivor->maxActions - activeSurvivor->actions);
            printf("%s\'s experience: %u\n", activeSurvivor->name, activeSurvivor->experience);
            printf("Options: \n");
            printf("Attack - 1\n");
            printf("Move - 2\n");
            printf("View skills - 3\n");
            printf("Search - 4\n");
            printf("End game - 5\n");
            printf("Enter an option: ");
            int option = 0;
            scanf("%d", &option);
            switch(option)
            {
                case 1:
                    PerformCombatAction(activeSurvivor);
                    break;
                case 2:
                    CompleteAction(activeSurvivor);
                    break;
                case 3:
                    // Print survivor skills
                    printf("\n");
                    PrintSurvivorSkills(activeSurvivor);
                    break;
                case 4:
                    EquipmentSearch(activeSurvivor);
                    break;
                case 5:
                    EndGame();
                    break;
                default:
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
                AddSurvivorToBoard(&survivor1);
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
