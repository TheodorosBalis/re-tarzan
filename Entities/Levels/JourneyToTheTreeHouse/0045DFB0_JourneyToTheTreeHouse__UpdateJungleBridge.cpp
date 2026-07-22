#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DFB0
// Label: JourneyToTheTreeHouse::UpdateJungleBridge
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateJungleBridge(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  uint value2;
  undefined4 value3;
  
  if (*(short *)(entry + 0x48) == 0) {
    value = CEntities::ComputeEntityDistanceSqToPlayer3D(entry);
    if (value < 10000) {
      value = entity->sceneObjects;
      value2 = NextRandomValue();
      if (value2 < 0x8001) {
        value3 = 0x2f0;
      }
      else {
        value3 = 0x2ef;
      }
      PlayAudioById(value3,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
      *(undefined2 *)(entry + 0x48) = 0x35;
    }
  }
  value = CEntities::ComputeEntityDistanceSqToPlayer3D(entry);
  if (10000 < value) {
    *(undefined2 *)(entry + 0x48) = 0;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

