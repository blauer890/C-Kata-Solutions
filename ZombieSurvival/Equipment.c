#include <string.h>

#include "Equipment.h"

EquipmentAttributes_S attributes[EQUIPMENT_NUM] =
{
    {
        .id = EQUIPMENT_BASEBALL_BAT,
        .accuracy = 5,
        .dice = 1,
        .range = 1
    },
    {
        .id = EQUIPMENT_FRYING_PAN,
        .accuracy = 6,
        .dice = 1,
        .range = 1
    },
    {
        .id = EQUIPMENT_KATANA,
        .accuracy = 5,
        .dice = 1,
        .range = 1
    },
    {
        .id = EQUIPMENT_PISTOL,
        .accuracy = 4,
        .dice = 1,
        .range = 1
    },
    {
        .id = EQUIPMENT_ASSAULT_RIFLE,
        .accuracy = 3,
        .dice = 1,
        .range = 4
    },
    {
        .id = EQUIPMENT_BOTTLED_WATER,
        .accuracy = 255,
        .dice = 255,
        .range = 255
    },
    {
        .id = EQUIPMENT_MOLOTOV,
        .accuracy = 5,
        .dice = 1,
        .range = 2
    }
};

void LookupEquipmentAttributes(Equipment_E equipmentID, EquipmentAttributes_S *attributes)
{
    attributes->id = attributes[equipmentID].id;
    attributes->accuracy = attributes[equipmentID].accuracy;
    attributes->dice = attributes[equipmentID].dice;
    attributes->range = attributes[equipmentID].range;
}

bool IsWeapon(Equipment_E equipmentID)
{
    return (equipmentID != EQUIPMENT_WOUND) &&
           (equipmentID != EQUIPMENT_NONE) &&
           (equipmentID != EQUIPMENT_BOTTLED_WATER);
}

/*
typedef enum
{
    EQUIPMENT_BASEBALL_BAT,
    EQUIPMENT_FRYING_PAN,
    EQUIPMENT_KATANA,
    EQUIPMENT_PISTOL,
    EQUIPMENT_ASSAULT_RIFLE,
    EQUIPMENT_BOTTLED_WATER,
    EQUIPMENT_MOLOTOV,
    EQUIPMENT_NUM,
    EQUIPMENT_WOUND,
    EQUIPMENT_NONE = 255
} Equipment_E;
*/

void GetWeaponString(Equipment_E equipmentID, char *str)
{
    switch(equipmentID)
    {
        case EQUIPMENT_BASEBALL_BAT:
            strcpy(str, "baseball bat");
            break;
        case EQUIPMENT_FRYING_PAN:
            strcpy(str, "frying pan");
            break;
        case EQUIPMENT_KATANA:
            strcpy(str, "katana");
            break;
        case EQUIPMENT_PISTOL:
            strcpy(str, "pistol");
            break;
        case EQUIPMENT_ASSAULT_RIFLE:
            strcpy(str, "assault rifle");
            break;
        case EQUIPMENT_BOTTLED_WATER:
            strcpy(str, "bottled water");
            break;
        case EQUIPMENT_MOLOTOV:
            strcpy(str, "molotov");
            break;
        default:
            break;
    }
}

