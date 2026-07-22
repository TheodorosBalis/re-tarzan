#include "tarzan_ghidra_types.hpp"

// Address: 0x00449D00
// Label: CEntities::InitCheckpointPickup
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitCheckpointPickup(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  short shortValue;
  ushort value3;
  int value2;
  
  if (entity->descriptor == 0) {
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined4 *)(entry + 0x50) = 0;
  }
  else {
    value = *(int *)(entity->descriptor + 0x10);
    *(undefined4 *)(entry + 0x4c) = *(undefined4 *)(value + 4);
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(value + 8);
  }
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = CEntities::CreateEntityAttachment(entry,0x18,0x80000058);
    if (value2 != 0) {
      if (((EntitySceneObject *)value)->pad108 == 1) {
        ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
        ((EntitySceneObject *)value)->yaw = *(ushort *)(value + 0x132) ^ 0x800;
        *(undefined2 *)(value2 + 0x12) = 0;
      }
      else {
        *(undefined2 *)(value2 + 0x12) = *(undefined2 *)(entry + 0x50);
        *(undefined4 *)(entry + 0x50) = 0;
      }
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3a8;
      if (g_CurrentCheckpointId == *(int *)(entry + 0x4c)) {
        *(undefined2 *)(value2 + 0xc) = 0;
        *(undefined2 *)(value2 + 0xe) = 0;
        *(undefined2 *)(value + 0xc) = g_CheckpointPickupActivationFrameSequence;
        *(undefined2 *)(entry + 0x48) = 9;
      }
      else {
        *(undefined2 *)(value + 0xc) = 0x1c;
        shortValue = RandomModulo(0x100);
        *(short *)(value2 + 0xc) = shortValue + 0x20;
        *(undefined2 *)(value2 + 0xe) = 0xffff;
        shortValue = RandomModulo(0x46);
        *(short *)(value2 + 0x10) = shortValue + 0x14;
        *(undefined2 *)(entry + 0x48) = 1;
      }
      *(undefined4 *)(value + 0xb4) = 1;
      value3 = *(ushort *)(value + 0x132) ^ 0x800;
      ((EntitySceneObject *)value)->roll = 1;
      ((EntitySceneObject *)value)->yaw = value3;
      *(ushort *)(value2 + 0x16) = value3;
      value2 = (int)(short)(value3 + 0x400 & 0xfff);
      *(int *)(value + 0x3c) =
           (int)(short)(&g_SinCosTable12Bit)[value2 - 0x400U & 0xfff] * *(int *)(entry + 0x50) >>
           0xc;
      shortValue = (&g_SinCosTable12Bit)[value2];
      value2 = *(int *)(entry + 0x50);
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + -0x555;
      *(int *)(value + 0x44) = shortValue * value2 >> 0xc;
      *(undefined4 *)(value + 0x40) = 0xffffff80;
    }
  }
  if ((*(byte *)(entry + 0x44) & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

