#include <math.h>
#include "Utilities.h"

float CalculateDistance(float xPosA, float xPosB,
    float yPosA, float yPosB)
{
    return sqrtf((xPosB - xPosA) * (xPosB - xPosA) + (yPosB - yPosA) * (yPosB - yPosA));
}
