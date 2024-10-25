#pragma once
#include <stdint.h>
#include <stdbool.h>

#define MAX_HEALTH 1000.0f
#define MAX_CHARACTER_NAME_LEN 30
#define MAX_FACTION_NAME_LEN 30

typedef enum CharacterType_E
{
    MELEE,
    RANGED
} CharacterType_T;

typedef struct FactionNode_S
{
    char name[MAX_FACTION_NAME_LEN];
    struct FactionNode_S *next;
} FactionNode_T;

typedef struct Character_S
{
    char name[MAX_CHARACTER_NAME_LEN];
    float health;
    uint8_t level;
    CharacterType_T type;
    bool alive;
    float xPos;
    float yPos;
    FactionNode_T *rootFaction;
} Character_T;

void CreateCharacter(Character_T *characterOut, char *name, CharacterType_T type);
void IncreaseLevel(Character_T *character);
void MoveToPosition(Character_T *character, float xPos, float yPos);
void PrintCharacter(Character_T *character);
void AttackCharacter(Character_T* attacker, Character_T* defender, float attackDamage);
void HealCharacter(Character_T* healer, Character_T* injured, float healAmount);
void AddFaction(Character_T *character, char *factionName);
void RemoveFaction(Character_T *character, char *factionName);
bool CheckAllies(Character_T *character1, Character_T *character2);
void RemoveFactions(Character_T *character);
void PrintFactions(Character_T *character);
