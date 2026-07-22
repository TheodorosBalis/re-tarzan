#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A520
// Label: CEntities::InitBananaPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitBananaPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  uint value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y - *(int *)(value2 + 4);
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
      *(undefined2 *)(entry + 0x4a) = *(undefined2 *)(value2 + 0xc);
      value3 = *(uint *)(value2 + 0x10);
      if (value3 != 0) {
        *(uint *)(entry + 0x50) = value3;
        *(undefined4 *)(value + 0xb4) = 1;
        value3 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + (value3 & 0xf) * 2);
        *(uint *)(value + 0xb0) = value3;
        *(uint *)(value + 0xac) = value3;
        *(uint *)(value + 0xa8) = value3;
      }
    }
    if (*(short *)(entry + 0x4a) == 0) {
      *(undefined2 *)(value + 0xc) = 0x2021;
    }
    else {
      *(undefined2 *)(value + 0xc) = 0x2022;
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

