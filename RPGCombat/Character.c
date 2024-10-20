#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Character.h"

void CreateCharacter(Character_T *characterOut, char *name, CharacterType_T type)
{
    strcpy(characterOut->name, name);
    characterOut->health = MAX_HEALTH;
    characterOut->level = 1;
    characterOut->type = type;
    characterOut->alive = true;
    characterOut->xPos = 0.0f;
    characterOut->yPos = 0.0f;
    characterOut->rootFaction = NULL;
}

void IncreaseLevel(Character_T *character)
{
    character->level++;
}

void MoveToPosition(Character_T *character, float xPos, float yPos)
{
    character->xPos = xPos;
    character->yPos = yPos;
}

static void PrintAlive(Character_T *character)
{
    char boolString[6];
    if (character->alive)
    {
        strcpy(boolString, "true");
    }
    else
    {
        strcpy(boolString, "false");
    }
    printf("alive: %s\n", boolString);
}

static void PrintType(Character_T *character)
{
    char typeString[7];
    if (character->type == MELEE)
    {
        strcpy(typeString, "MELEE");
    }
    else
    {
        strcpy(typeString, "RANGED");
    }
    printf("type: %s\n", typeString);
}

void PrintCharacter(Character_T *character)
{
    printf("%s has the following attributes: \n", character->name);
    printf("health: %.3f\n", character->health);
    printf("level: %u\n", character->level);
    PrintType(character);
    PrintAlive(character);
    printf("pos: (%.3f, %.3f)\n", character->xPos, character->yPos);
    PrintFactions(character);
    printf("\n");
}

static float CalculateDistance(float xPosA, float xPosB,
    float yPosA, float yPosB)
{
    return sqrtf((xPosB - xPosA) * (xPosB - xPosA) + (yPosB - yPosA) * (yPosB - yPosA));
}

void AttackCharacter(Character_T* attacker, Character_T* defender, float attackDamage)
{
    if ((attacker != defender) && !CheckAllies(attacker, defender))
    {
        float distance = CalculateDistance(attacker->xPos, defender->xPos,
            attacker->yPos, defender->yPos);
        if ((attacker->type == MELEE) && (distance > 2.0f))
        {
            printf("Melee character %s out of range for attack, distance: %.3f\n", attacker->name, distance);
            return;
        }
        if ((attacker->type == RANGED) && (distance > 20.0f))
        {
            printf("Ranged character %s out of range for attack, distance: %.3f\n", attacker->name, distance);
            return;
        }

        float damageScale = 1.0f;
        if ((defender->level - attacker->level) >= 5)
        {
            damageScale = 0.5f;
        }
        else if ((defender->level - attacker->level) <= 5)
        {
            damageScale = 2.0f;
        }

        if ((defender->health - damageScale * attackDamage) > 0.0f)
        {
            defender->health -= damageScale * attackDamage;
        }
        else
        {
            defender->health = 0.0f;
            defender->alive = false;
        }
    }
}

void HealCharacter(Character_T* healer, Character_T* injured, float healAmount)
{
    if (injured->alive && (((healer != injured) && CheckAllies(healer, injured)) || (healer == injured)))
    {
        if (injured->health + healAmount < MAX_HEALTH)
        {
            injured->health += healAmount;
        }
        else
        {
            injured->health = MAX_HEALTH;
        }
    }
}

void AddFaction(Character_T *character, char *factionName)
{
    FactionNode_T *tempNode = NULL;
    FactionNode_T *newNode = (FactionNode_T *)malloc(sizeof(FactionNode_T));
    strcpy(newNode->name, factionName);
    newNode->next = NULL;
    if (character->rootFaction == NULL)
    {
        character->rootFaction = newNode;
        printf("Adding new node to empty list, character: %s\n", character->name);
        return;
    }

    tempNode = character->rootFaction;
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }
    tempNode->next = newNode;
}

void RemoveFaction(Character_T *character, char *factionName)
{
    FactionNode_T *tempNode = NULL;
    if (character->rootFaction == NULL)
    {
        return;
    }

    FactionNode_T *nextNode = character->rootFaction->next;
    if (!strcmp(character->rootFaction->name, factionName))
    {
        free(character->rootFaction);
        character->rootFaction = NULL;
        character->rootFaction = nextNode;
        return;
    }
    tempNode = character->rootFaction;
    while ((tempNode->next != NULL) && strcmp(tempNode->next->name, factionName))
    {
        tempNode = tempNode->next;
    }
    if (tempNode->next == NULL)
    {
        return;
    }
    FactionNode_T *nodeToDelete = tempNode->next;
    tempNode->next = tempNode->next->next;
    free(nodeToDelete);
}

bool CheckAllies(Character_T *character1, Character_T *character2)
{
    FactionNode_T *tempCharacter1Node = NULL;
    FactionNode_T *tempCharacter2Node = NULL;

    if (character1->rootFaction == NULL)
    {
        return false;
    }

    if (character2->rootFaction == NULL)
    {
        return false;
    }

    tempCharacter1Node = character1->rootFaction;
    tempCharacter2Node = character2->rootFaction;
    while (tempCharacter1Node != NULL)
    {
        while (tempCharacter2Node != NULL)
        {
            if (!strcmp(tempCharacter1Node->name, tempCharacter2Node->name))
            {
                return true;
            }
            tempCharacter2Node = tempCharacter2Node->next;
        }
        tempCharacter2Node = character2->rootFaction;
        tempCharacter1Node = tempCharacter1Node->next;
    }
    return false;
}

void RemoveFactions(Character_T *character)
{
    FactionNode_T *currNode = NULL;
    FactionNode_T *nextNode = NULL;

    if (character->rootFaction == NULL)
    {
        return;
    }

    if (character->rootFaction->next = NULL)
    {
        free(character->rootFaction);
        character->rootFaction = NULL;
        return;
    }

    currNode = character->rootFaction;
    nextNode = character->rootFaction->next;
    while (nextNode != NULL)
    {
        free(currNode);
        currNode = NULL;
        currNode = nextNode;
        nextNode = currNode->next;
    }
}

void PrintFactions(Character_T *character)
{
    FactionNode_T *tempNode = NULL;

    printf("factions: ");
    if (character->rootFaction == NULL)
    {
        printf("empty\n");
        return;
    }

    tempNode = character->rootFaction;
    printf("%s->", tempNode->name);
    while (tempNode->next != NULL)
    {
        tempNode = tempNode->next;
        printf("%s->", tempNode->name);
    }
    printf("NULL\n");
}
