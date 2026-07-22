#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E3A0
// Label: JourneyToTheTreeHouse::UpdateNest
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateNest(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (*(short *)(entry + 0x4a) == 0) {
      if (((EntitySceneObject *)value)->linkedSceneObject != 0) {
        PlayAudioById(0xd0,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        *(undefined4 *)(entry + 0x4c) = 9;
        *(undefined2 *)(entry + 0x4a) = 1;
      }
    }
    else {
      value2 = *(int *)(entry + 0x4c) + -1;
      if (value2 < 0) {
        *(undefined2 *)(entry + 0x4a) = 0;
      }
      else {
        *(int *)(value + 0xa8) =
             *(int *)(value + 0xa8) - (int)*(short *)(&g_JourneyNestScaleDeltaTable + value2 * 2);
        *(int *)(value + 0xac) =
             *(int *)(value + 0xac) + (int)*(short *)(&g_JourneyNestScaleDeltaTable + value2 * 2);
        *(int *)(value + 0xb0) =
             *(int *)(value + 0xb0) - (int)*(short *)(&g_JourneyNestScaleDeltaTable + value2 * 2);
      }
      *(int *)(entry + 0x4c) = value2;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

