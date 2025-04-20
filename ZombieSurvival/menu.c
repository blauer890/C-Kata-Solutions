#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"

#define MAX_SURVIVORS 5

/*
    SKILLS_PLUS_ONE_ACTION,
    SKILLS_PLUS_ONE_DIE_RANGED,
    SKILLS_PLUS_ONE_DIE_MELEE,
    SKILLS_PLUS_ONE_FREE_MOVE_ACTION,
    SKILLS_HOARD,
    SKILLS_SNIPER,
    SKILLS_TOUGH,
    SKILLS_NONE
*/

void PrintSurvivorSkills(Survivor_S *survivor)
{
    printf("%s\'s skills:\n", survivor->name);
    for (int i = 0; i < 10; i++)
    {
        if (survivor->skills[i] == SKILLS_NONE)
        {
            break;
        }
        switch(survivor->skills[i])
        {
            case SKILLS_PLUS_ONE_ACTION:
                printf("+1 One Action,\n");
                break;
            case SKILLS_PLUS_ONE_DIE_RANGED:
                printf("+1 One Die Ranged,\n");
                break;
            case SKILLS_PLUS_ONE_DIE_MELEE:
                printf("+1 One Die Melee,\n");
                break;
            case SKILLS_PLUS_ONE_FREE_MOVE_ACTION:
                printf("+1 One Free Move Action,\n");
                break;
            case SKILLS_HOARD:
                printf("Hoard,\n");
                break;
            case SKILLS_SNIPER:
                printf("Sniper,\n");
                break;
            case SKILLS_TOUGH:
                printf("Tough,\n");
                break;
            default:
                break;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    Survivor_S survivor1, survivor2, survivor3, survivor4, survivor5;

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
            printf("Kill zombie - 1\n");
            printf("Explore - 2\n");
            printf("End turn - 3\n");
            printf("View skills - 4\n");
            printf("End game - 5\n");
            printf("Enter an option: ");
            int option = 0;
            scanf("%d", &option);
            if(option == 1)
            {
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
                printf("\n");
                printf("Exploring terrain\n");
                CompleteAction(activeSurvivor);
            } else if(option == 3)
            {
                CompleteTurn(activeSurvivor);
            } else if(option == 4)
            {
                PrintSurvivorSkills(activeSurvivor);
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
                EndGame();
            } else {
                continue;
            }
        }
    }
    return 0;
}
