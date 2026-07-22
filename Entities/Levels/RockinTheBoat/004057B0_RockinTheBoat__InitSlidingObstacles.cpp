#include "tarzan_ghidra_types.hpp"

// Address: 0x004057B0
// Label: RockinTheBoat::InitSlidingObstacles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitSlidingObstacles(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  undefined4 value4;
  uint value5;
  int value2;
  int value3;
  
  value5 = 0;
  if (entity->descriptor != 0) {
    value5 = (uint)*(ushort *)(entity->descriptor + 0x14);
  }
  value = entity->sceneObjects;
  if (value != 0) {
    value3 = value5 * 0xc;
    ((EntitySceneObject *)value)->worldObject = g_CurrentWorldSceneContext;
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0xc) = (&g_RockinSlidingObstacleConfigSceneId)[value5 * 6];
    if (((EntitySceneObject *)value)->pad108 == 1) {
      ComputeEntitySceneObjectCollisionMoveDelta(0,0,value);
      ((EntitySceneObject *)value)->yaw = *(ushort *)(value + 0x132) ^ 0x800;
    }
    value2 = CEntities::CreateRuntimeMotionStateAttachment(entry);
    if (value2 != 0) {
      *(int *)(value2 + 0x1c) = (int)*(short *)(&g_RockinSlidingObstacleConfigPosZ + value3);
      *(int *)(value2 + 0x18) = (int)*(short *)(&g_RockinSlidingObstacleConfigPosY + value3);
      *(int *)(value2 + 0x34) = (int)*(short *)(&g_RockinSlidingObstacleConfigTravelStart + value3);
      *(int *)(value2 + 0x38) = (int)*(short *)(&g_RockinSlidingObstacleConfigTravelEnd + value3);
    }
    shortValue = *(short *)(&g_RockinSlidingObstacleConfigFlags + value3);
    *(int *)(entry + 0x4c) = (int)shortValue;
    if (((int)shortValue & 1U) != 0) {
      value3 = CreateEntityEntitySceneObject((uint *)entry,2);
      value4 = g_CurrentWorldSceneContext;
      if (value3 != 0) {
        *(undefined2 *)(value3 + 0xa6) = 1;
        *(undefined4 *)(value3 + 0x10) = value4;
        *(undefined2 *)(value3 + 0xc) = 0x2015;
        *(undefined2 *)(value3 + 0xa2) = ((EntitySceneObject *)value)->yaw;
      }
    }
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

