#include "tarzan_ghidra_types.hpp"

// Address: 0x004499F0
// Label: CEntities::InitUmbrellaPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitUmbrellaPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  ushort value4;
  int value2;
  int value3;
  
  if (entity->descriptor == 0) {
    *(undefined4 *)(entry + 0x50) = 0;
  }
  else {
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 8)
    ;
  }
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::CreateEntityAttachment(entry,0x18,0x80000058);
    if (value2 != 0) {
      if ((((EntitySceneObject *)value)->pad108 == 1) && (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1)) {
        ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
        ((EntitySceneObject *)value)->yaw = *(ushort *)(value + 0x132) ^ 0x800;
        *(undefined2 *)(value2 + 0x10) = 0;
      }
      else {
        *(undefined2 *)(value2 + 0x10) = *(undefined2 *)(entry + 0x50);
        *(undefined4 *)(entry + 0x50) = 0;
      }
      *(undefined4 *)(entry + 0x4c) = 0x3c;
      value3 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
      *(undefined2 *)(value + 0xc) = 0x2009;
      ((EntitySceneObject *)value)->worldObject = value3;
      *(undefined2 *)(entry + 0x48) = 1;
      ((EntitySceneObject *)value)->roll = 1;
      value4 = *(ushort *)(value + 0x132) ^ 0x800;
      ((EntitySceneObject *)value)->yaw = value4;
      *(ushort *)(value2 + 0x14) = value4;
      value2 = (int)(short)(value4 + 0x400 & 0xfff);
      *(int *)(value + 0x3c) =
           (int)(short)(&g_SinCosTable12Bit)[value2 - 0x400U & 0xfff] * *(int *)(entry + 0x50) >>
           0xc;
      *(int *)(value + 0x44) =
           (int)(short)(&g_SinCosTable12Bit)[value2] * *(int *)(entry + 0x50) >> 0xc;
    }
  }
  if ((*(byte *)(entry + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

