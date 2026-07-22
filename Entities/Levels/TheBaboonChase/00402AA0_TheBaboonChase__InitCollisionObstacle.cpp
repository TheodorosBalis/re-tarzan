#include "tarzan_ghidra_types.hpp"

// Address: 0x00402AA0
// Label: TheBaboonChase::InitCollisionObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitCollisionObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  value2 = (byte *)(entity->sceneObjects + 0xf);
  *value2 = *value2 | 8;
  *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
  if (entity->descriptor != 0) {
    value = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
    if (value == 0) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2001;
    }
    else {
      if (value == 1) {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2002;
        return;
      }
      if (value == 2) {
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2000;
        return;
      }
    }
  }
  return;
}

