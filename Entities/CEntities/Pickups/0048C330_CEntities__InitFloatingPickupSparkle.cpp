#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C330
// Label: CEntities::InitFloatingPickupSparkle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitFloatingPickupSparkle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(value + 0xc) = 0x2033;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0xe) = 0x9421;
    *(undefined4 *)(value + 0x40) = 0xffffffe0;
    *(undefined4 *)(value + 0xb4) = 1;
    *(undefined4 *)(value + 0xa8) = 0xa00;
    *(undefined4 *)(value + 0xac) = 0xa00;
    *(undefined4 *)(value + 0xb0) = 0xa00;
    value = RandomModulo(0x28);
    *(int *)(entry + 0x4c) = value + -0x14;
    value = RandomModulo(0x100);
    *(int *)(entry + 0x50) = value + 0x100;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

