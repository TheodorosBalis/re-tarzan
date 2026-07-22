#include "tarzan_ghidra_types.hpp"

// Address: 0x00442540
// Label: CEntities::MoveEntitySceneObjectAndEaseFacingAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectAndEaseFacingAngles(int entry,uint sceneObject)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  int entry3;
  uint value;
  ushort value2;
  uint value3;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    if (*(char *)(entry2 + 0x75) != '\0') {
      sceneObject = ~sceneObject + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(sceneObject,0,entry2);
    ((EntitySceneObject *)entry2)->x = ((EntitySceneObject *)entry2)->x + *(int *)(entry2 + 0x54);
    value = *(ushort *)(entry2 + 0x132) & 0xfff;
    ((EntitySceneObject *)entry2)->z = ((EntitySceneObject *)entry2)->z + *(int *)(entry2 + 0x5c);
    if (*(char *)(entry2 + 0x75) == '\0') {
      value = value ^ 0x800;
      value2 = 0x400 - *(short *)(entry2 + 0x130);
    }
    else {
      value2 = *(short *)(entry2 + 0x130) - 0x400;
    }
    value3 = value2 & 0xfff;
    if ((int)((EntitySceneObject *)entry2)->yaw != value) {
      entry3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)entry2)->yaw,value);
      if ((entry3 >> 2 ^ entry3 >> 0x1f) - (entry3 >> 0x1f) < 2) {
        ((EntitySceneObject *)entry2)->yaw = (short)value;
      }
      else {
        ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw + (short)(entry3 >> 2);
      }
      ((EntitySceneObject *)entry2)->yaw = ((EntitySceneObject *)entry2)->yaw & 0xfff;
    }
    if ((int)*(short *)(entry2 + 0xa0) != value3) {
      entry3 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(entry2 + 0xa0),value3);
      if ((entry3 >> 2 ^ entry3 >> 0x1f) - (entry3 >> 0x1f) < 2) {
        *(short *)(entry2 + 0xa0) = (short)value3;
        *(ushort *)(entry2 + 0xa0) = *(ushort *)(entry2 + 0xa0) & 0xfff;
        return;
      }
      *(short *)(entry2 + 0xa0) = *(short *)(entry2 + 0xa0) + (short)(entry3 >> 2);
      *(ushort *)(entry2 + 0xa0) = *(ushort *)(entry2 + 0xa0) & 0xfff;
    }
  }
  return;
}

