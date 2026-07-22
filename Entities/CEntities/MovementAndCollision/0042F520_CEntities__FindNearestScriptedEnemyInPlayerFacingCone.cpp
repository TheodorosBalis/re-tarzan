#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F520
// Label: CEntities::FindNearestScriptedEnemyInPlayerFacingCone
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::FindNearestScriptedEnemyInPlayerFacingCone(void)

{
  short shortValue;
  int foundIndex;
  int foundIndex2;
  uint value;
  int foundIndex3;
  int foundIndex4;
  int foundIndex5;
  int foundIndex6;
  int localState;
  int localState3;
  int localState2;
  
  foundIndex3 = 0;
  localState2 = 0;
  localState = g_ScriptedEnemyEntityListHead;
  localState3 = 0x7fffffff;
  foundIndex2 = g_PlayerEntitySceneObject;
  if (g_ScriptedEnemyEntityListHead != 0) {
    do {
      for (foundIndex = *(int *)(localState + 0x38); foundIndex != 0; foundIndex = *(int *)(foundIndex + 0x34)) {
        foundIndex3 = 0;
        if (foundIndex2 != 0) {
          foundIndex4 = *(int *)(foundIndex + 0x18) - *(int *)(foundIndex2 + 0x18);
          foundIndex6 = *(int *)(foundIndex + 0x14) - *(int *)(foundIndex2 + 0x14);
          shortValue = *(short *)(foundIndex2 + 0xa2);
          foundIndex5 = *(int *)(foundIndex + 0x1c) - *(int *)(foundIndex2 + 0x1c);
          foundIndex2 = GetAngleFromXZVector12Bit(foundIndex6,foundIndex5);
          value = foundIndex2 - 0x800U & 0xfff;
          foundIndex3 = g_PlayerEntitySceneObject;
          if ((((((shortValue + -0x180) * 0x100000 >> 0x14 & 0xfffU) < value) &&
               (value < ((shortValue + 0x180) * 0x100000 >> 0x14 & 0xfffU))) &&
              (foundIndex2 = foundIndex5 * foundIndex5 + foundIndex4 * foundIndex4 + foundIndex6 * foundIndex6, 0 < foundIndex2)) &&
             ((foundIndex2 < localState3 && (foundIndex2 < 0x1000000)))) {
            localState3 = foundIndex2;
            localState2 = foundIndex;
          }
        }
        foundIndex2 = foundIndex3;
        foundIndex3 = localState2;
      }
      localState = *(int *)(localState + 0x20);
    } while (localState != 0);
    return foundIndex3;
  }
  return 0;
}

