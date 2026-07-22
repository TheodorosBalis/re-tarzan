#include "tarzan_ghidra_types.hpp"

// Address: 0x0042C510
// Label: GoingApe::InitMonkeySpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitMonkeySpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 inputEax;
  uint value4;
  int value;
  int value2;
  int value3;
  
  value4 = CONCAT31((int3)((uint)inputEax >> 8),*( undefined1 *)((int)&g_LevelTransitionContext + 2));
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\r') {
    value4 = *(uint *)(entry + 0x28) | 4;
    *(uint *)(entry + 0x28) = value4;
  }
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x9c0;
      LoadEncodedResourceId(0x1015);
      *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
      *(undefined4 *)(entry + 0x4c) = 0;
      if ((entity->descriptor != 0) &&
         (value = *(int *)(entity->descriptor + 0x10), value != 0)) {
        *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(value + 0xc);
        *(undefined4 *)(entry + 0x50) = ((EntitySceneObject *)value)->worldObject;
      }
      if (*(short *)(entry + 0x4a) == 0) {
        *(undefined2 *)(entry + 0x4a) = 0x3c;
      }
      if (*(int *)(entry + 0x50) == 0) {
        *(undefined4 *)(entry + 0x50) = 0x3c;
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList
                      (g_LevelEnemyEntityListHead,
                       CONCAT22((short)(value4 >> 0x10),*(undefined2 *)(entry + 0x46)));
    value2 = CEntities::CountEntitiesOfTypeInList(g_LevelEnemyEntityListHead,0x65);
    value3 = CEntities::CountEntitiesOfTypeInList(g_ActiveEntityListHead,0x62);
    if (value + value2 + value3 < 2) {
      UnloadEncodedResourceId(0x1015);
      return;
    }
  }
  return;
}

