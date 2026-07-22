#include "tarzan_ghidra_types.hpp"

// Address: 0x00475520
// Label: CEntities::MoveEntityForwardAndSnapFacingYaw
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntityForwardAndSnapFacingYaw(int entry,uint sceneObject)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  uint value;
  uint value2;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    if (*(char *)(entry2 + 0x75) != '\0') {
      sceneObject = ~sceneObject + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(sceneObject,0,entry2);
    ((EntitySceneObject *)entry2)->x = ((EntitySceneObject *)entry2)->x + *(int *)(entry2 + 0x54);
    ((EntitySceneObject *)entry2)->z = ((EntitySceneObject *)entry2)->z + *(int *)(entry2 + 0x5c);
    value2 = *(ushort *)(entry2 + 0x132) & 0xfff;
    if ((int)((EntitySceneObject *)entry2)->yaw != value2) {
      value = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)entry2)->yaw,value2);
      if ((int)((value ^ (int)value >> 0x1f) - ((int)value >> 0x1f)) < 2) {
        ((EntitySceneObject *)entry2)->yaw = (short)value2;
        ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw & 0xfff;
        return;
      }
      ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw + (short)value;
      ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw & 0xfff;
    }
  }
  return;
}

