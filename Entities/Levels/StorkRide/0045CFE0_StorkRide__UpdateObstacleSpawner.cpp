#include "tarzan_ghidra_types.hpp"

// Address: 0x0045CFE0
// Label: StorkRide::UpdateObstacleSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::UpdateObstacleSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value7;
  int value;
  uint value6;
  int value2;
  int value3;
  int value4;
  int value5;
  
  CEntities::FindEntityAttachmentByFlags(entry,0x400);
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value6 = GetAngleFromXZVector12Bit
                      (*(int *)(entity->sceneObjects + 0x14) -
                       *(int *)(g_PlayerEntitySceneObjectData + 8),
                       *(int *)(entity->sceneObjects + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObjectData + 0x10));
    *(uint *)(value + 0x18) = value6 & 0xfff;
    value5 = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value5)->yaw,value6 & 0xfff);
    value7 = (short *)(&((EntitySceneObject *)value5)->yaw);
    *value7 = *value7 + (short)(value2 >> 1);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(int *)(value + 0x10) == 7) {
      value5 = entity->sceneObjects;
      value2 = *(int *)(g_PlayerEntity + 0x38);
      value3 = ((EntitySceneObject *)value5)->x - *(int *)(value2 + 0x14);
      value4 = ((EntitySceneObject *)value5)->y - *(int *)(value2 + 0x18);
      value5 = ((EntitySceneObject *)value5)->z - *(int *)(value2 + 0x1c);
      if (value5 * value5 + value4 * value4 + value3 * value3 < 0x1000000) {
        *(undefined4 *)(value + 0x10) = 9;
      }
    }
    else if (*(int *)(value + 0x10) == 9) {
      value5 = entity->sceneObjects;
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value5)->x,((EntitySceneObject *)value5)->y,
                 ((EntitySceneObject *)value5)->z + -0x100,0x18c,0x11);
      *(undefined4 *)(value + 0x10) = 10;
      return;
    }
  }
  return;
}

