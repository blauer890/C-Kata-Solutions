#pragma once

#include <stdbool.h>

#include "Character.h"

#define MAX_PROP_NAME 30

typedef struct Props_S
{
   char name[MAX_PROP_NAME];
   float health;
   bool isDestroyed;
   float xPos;
   float yPos;
} Prop_T;

void CreateProp(Prop_T *propOut, char *name, float initialHealth,
   float initialXPos, float initialYPos);
void AttackProp(Character_T *character, Prop_T *prop, float attackDamage);
void PrintProp(Prop_T *prop);