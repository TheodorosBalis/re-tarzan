#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CBD0
// Label: UpdateSaborDistanceScaledRuntimeValue
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateSaborDistanceScaledRuntimeValue(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  
  value = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObjectData + 8);
  if (value < 0) {
    value = -value;
  }
  if (2000 < value) {
    value = 2000;
  }
  *(int *)(entity->sceneObjects + 0x44) = (2000 - value) / 0x14;
  return;
}

