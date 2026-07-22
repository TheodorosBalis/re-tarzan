#include "tarzan_ghidra_types.hpp"

// Address: 0x0044A8E0
// Label: CEntities::InitWeaponPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitWeaponPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  code *stringCursor;
  int value2;
  uint value3;
  undefined4 value4;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    if (entity->descriptor == 0) {
      value4 = 0;
    }
    else {
      value2 = *(int *)(entity->descriptor + 0x10);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y - *(int *)(value2 + 4);
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
      value4 = *(undefined4 *)(value2 + 0xc);
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
    *(undefined4 *)(entry + 0x4c) = value4;
    switch(value4) {
    case 1:
      *(undefined2 *)(value + 0xc) = 0x2024;
      break;
    case 2:
      *(undefined2 *)(value + 0xc) = 0x2025;
      break;
    default:
      *(undefined2 *)(value + 0xc) = 0x2023;
      break;
    case 10:
      if ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) {
        if (g_HudTokenCounterScene != 0) {
          *(undefined2 *)(entry + 0x46) = 4;
          stringCursor = *(code **)(g_EntityTypeCallbackTable + 0x20);
          *(code **)(entry + 0x2c) = stringCursor;
          *(undefined4 *)(entry + 0x30) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x24);
          (*stringCursor)(entry);
          return;
        }
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
      *(undefined2 *)(value + 0xc) = 0x2028;
      break;
    case 0x14:
      *(undefined2 *)(value + 0xc) = 0x2029;
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

