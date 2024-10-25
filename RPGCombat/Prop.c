#include <stdio.h>
#include <string.h>

#include "Utilities.h"
#include "Prop.h"

void CreateProp(Prop_T *prop, char *name, float initialHealth,
    float initialXPos, float initialYPos)
{
    strcpy(prop->name, name);
    prop->health = initialHealth;
    prop->isDestroyed = false;
    prop->xPos = initialXPos;
    prop->yPos = initialYPos;
}

void AttackProp(Character_T *character, Prop_T *prop, float attackDamage)
{
    if (!character->alive)
    {
        return;
    }

    float distance = CalculateDistance(character->xPos, prop->xPos,
        character->yPos, prop->yPos);
    if ((character->type == MELEE) && (distance > 2.0f))
    {
        printf("Melee character %s out of range for attack, distance: %.3f\n", character->name, distance);
        return;
    }
    if ((character->type == RANGED) && (distance > 20.0f))
    {
        printf("Ranged character %s out of range for attack, distance: %.3f\n", character->name, distance);
        return;
    }

    if ((prop->health - attackDamage) > 0.0f)
    {
        prop->health -= attackDamage;
    }
    else
    {
        prop->health = 0.0f;
        prop->isDestroyed = true;
    }
}

void PrintProp(Prop_T *prop)
{
    printf("Prop %s has the following attributes: \n", prop->name);
    printf("health: %.3f\n", prop->health);
    printf("Prop %s ", prop->name);
    (prop->isDestroyed > 0) ? printf("Destroyed\n") : printf("Not Destroyed\n");
    printf("pos: (%.3f, %.3f)\n", prop->xPos, prop->yPos);
    printf("\n");
}
