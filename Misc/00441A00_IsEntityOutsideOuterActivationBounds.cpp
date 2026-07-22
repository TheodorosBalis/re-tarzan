#include "tarzan_ghidra_types.hpp"

// Address: 0x00441A00
// Label: IsEntityOutsideOuterActivationBounds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint IsEntityOutsideOuterActivationBounds(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int result;
  uint value;
  undefined3 value2;
  
  result = entity->sceneObjects;
  value = 0;
  if (result != 0) {
    if (*(code **)(g_CurrentLevelRuntimeHookTable + 0x18) != (code *)0x0) {
      value = (**(code **)(g_CurrentLevelRuntimeHookTable + 0x18))(result);
      return value;
    }
    value2 = (undefined3)((uint)result >> 8);
    if (((EntitySceneObject *)result)->x < g_RuntimeOuterActivationBounds) {
      return CONCAT31(value2,1);
    }
    if (g_RuntimeOuterActivationMaxX < ((EntitySceneObject *)result)->x) {
      return CONCAT31(value2,1);
    }
    value = ((EntitySceneObject *)result)->z;
    value2 = (undefined3)(value >> 8);
    if ((int)value < g_RuntimeOuterActivationMinZ) {
      return CONCAT31(value2,1);
    }
    if (g_RuntimeOuterActivationMaxZ < (int)value) {
      return CONCAT31(value2,1);
    }
  }
  return value & 0xffffff00;
}

