#pragma once
#include <stdint.h>
#include <stdbool.h>

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

typedef struct
{
    Equipment_E id;
    uint8_t accuracy;
    uint8_t dice;
    uint8_t range;
} EquipmentAttributes_S;

void LookupEquipmentAttributes(Equipment_E equipmentID, EquipmentAttributes_S *attributes);
bool IsWeapon(Equipment_E equipmentID);
void GetWeaponString(Equipment_E equipmentID, char *str);

