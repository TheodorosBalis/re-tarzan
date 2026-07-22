#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A740
// Label: CEntities::InitBonusHealthPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitBonusHealthPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  uint value3;
  
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (0x17f < g_PlayerMaxHealth) {
    *(undefined2 *)(entry + 0x46) = 6;
    *(undefined4 *)(entry + 0x2c) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x30);
    *(undefined4 *)(entry + 0x30) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x34);
    entity->Release(entity);
    return;
  }
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2018;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x3a8;
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y - *(int *)(value2 + 4);
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
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
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

