#include "tarzan_ghidra_types.hpp"

// Address: 0x0044ADD0
// Label: CEntities::InitTARZANLetterPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitTARZANLetterPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value3;
  uint value4;
  
  value = entity->sceneObjects;
  *(undefined4 *)(entry + 0x50) = 0;
  *(undefined2 *)(entry + 0x48) = 1;
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (value != 0) {
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined4 *)(value + 0x40) = 0xffffff80;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x3a8;
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      value3 = *(undefined4 *)(value2 + 4);
      *(int *)(entry + 0x4c) = 1 << ((byte)value3 & 0x1f);
      *(undefined4 *)(value + 0x6c) = *(undefined4 *)(value2 + 8);
      value2 = *(int *)(value2 + 0x10);
      if (value2 != 0) {
        *(undefined4 *)(value + 0xb4) = 1;
        value4 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + value2 * 2);
        *(uint *)(value + 0xb0) = value4;
        *(uint *)(value + 0xac) = value4;
        *(uint *)(value + 0xa8) = value4;
      }
      switch(value3) {
      case 0:
        *(undefined2 *)(value + 0xc) = 0x2012;
        break;
      case 1:
      case 4:
        *(undefined2 *)(value + 0xc) = 0x2013;
        break;
      case 2:
        *(undefined2 *)(value + 0xc) = 0x2014;
        break;
      case 3:
        *(undefined2 *)(value + 0xc) = 0x2015;
        break;
      case 5:
        *(undefined2 *)(value + 0xc) = 0x2016;
      }
    }
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

