#include "tarzan_ghidra_types.hpp"

// Address: 0x00475480
// Label: CEntities::MoveEntityForwardAndEaseFacingYaw
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntityForwardAndEaseFacingYaw(int entry,uint sceneObject)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  uint value;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    if (*(char *)(entry2 + 0x75) != '\0') {
      sceneObject = ~sceneObject + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(sceneObject,0,entry2);
    ((EntitySceneObject *)entry2)->x = ((EntitySceneObject *)entry2)->x + *(int *)(entry2 + 0x54);
    ((EntitySceneObject *)entry2)->z = ((EntitySceneObject *)entry2)->z + *(int *)(entry2 + 0x5c);
    value = *(ushort *)(entry2 + 0x132) & 0xfff;
    if ((int)((EntitySceneObject *)entry2)->yaw != value) {
      entry3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)entry2)->yaw,value);
      if ((entry3 >> 2 ^ entry3 >> 0x1f) - (entry3 >> 0x1f) < 2) {
        ((EntitySceneObject *)entry2)->yaw = (short)value;
        ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw & 0xfff;
        return;
      }
      ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw + (short)(entry3 >> 2);
      ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw & 0xfff;
    }
  }
  return;
}

