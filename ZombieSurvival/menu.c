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
    int numOfSurvivors = 0;
    while(GameRunning())
    {
        if(numOfSurvivors > 0)
        {
            Survivor_S *activeSurvivor;
            ActiveSurvivor(&activeSurvivor);
            printf("%s\'s turn, actions left: %u\n",activeSurvivor->name, activeSurvivor->actions);
            printf("Options: \n");
            if(activeSurvivor->InHandItems[0] != PISTOL)
            {
                printf("Explore - 1\n");
                printf("End turn - 2\n");
                printf("End game - 3\n");
                printf("Enter an option: ");
                int option = 0;
                scanf("%d", &option);
                if(option == 1)
                {
                    printf("\n");
                    printf("Exploring terrain\n");
                    activeSurvivor->actions--;
                } else if(option == 2)
                {
                    CompleteTurn(activeSurvivor);
                } else if(option == 3)
                {
                    EndGame();
                }
                printf("\n");
            } else
            {
                printf("End turn - 1\n");
                printf("End game - 2\n");
                printf("Enter an option: ");
                int option = 0;
                scanf("%d", &option);
                if(option == 1)
                {
                    CompleteTurn(activeSurvivor);
                } else if(option == 2)
                {
                    EndGame();
                }
                printf("\n");
            }
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
                numOfSurvivors++;
            } else if(option == 2)
            {
                EndGame();
            }
        }
    }
    return 0;
}
