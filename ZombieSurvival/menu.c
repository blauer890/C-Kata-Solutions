#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "Survivor.h"
#include "TurnQueue.h"
#include "GameManager.h"

#define MAX_SURVIVORS 5

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
            printf("%s\'s turn, actions left: %u\n", activeSurvivor->name, activeSurvivor->actions);
            printf("Options: \n");
            printf("Kill zombie - 1\n");
            printf("Explore - 2\n");
            printf("End turn - 3\n");
            printf("End game - 4\n");
            printf("Enter an option: ");
            int option = 0;
            scanf("%d", &option);
            if(option == 1)
            {
                KillZombie(activeSurvivor);
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
