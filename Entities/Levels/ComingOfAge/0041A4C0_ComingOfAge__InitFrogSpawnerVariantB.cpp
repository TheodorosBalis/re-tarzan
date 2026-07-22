#include "tarzan_ghidra_types.hpp"

// Address: 0x0041A4C0
// Label: ComingOfAge::InitFrogSpawnerVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitFrogSpawnerVariantB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x12b0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
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
  return;
}

