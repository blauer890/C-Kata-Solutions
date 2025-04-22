#pragma once
#include <stdint.h>

typedef enum
{
    EQUIPMENT_BASEBALL_BAT,
    EQUIPMENT_FRYING_PAN,
    EQUIPMENT_KATANA,
    EQUIPMENT_PISTOL,
    EQUIPMENT_ASSAULT_RIFLE,
    EQUIPMENT_BOTTLED_WATER,
    EQUIPMENT_MOLOTOV,
    EQUIPMENT_WOUND,
    EQUIPMENT_NONE
} Equipment_E;

typedef struct
{
    Equipment_E id;
    uint8_t accuracy;
    
} EquipmentAttributes_S;

EquipmentAttributes_S pistol =
{
    
};