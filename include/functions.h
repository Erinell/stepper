#include <config.h>

float remap(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float angleToStep(float angle)
{
  return remap(angle * 3.6, 0, 360, 0, stepPerRev);
}