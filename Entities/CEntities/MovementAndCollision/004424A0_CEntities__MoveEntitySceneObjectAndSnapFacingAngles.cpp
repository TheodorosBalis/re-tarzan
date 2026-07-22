#include "tarzan_ghidra_types.hpp"

// Address: 0x004424A0
// Label: CEntities::MoveEntitySceneObjectAndSnapFacingAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::MoveEntitySceneObjectAndSnapFacingAngles(int entry,uint sceneObject)

{
  Entity *entity = (Entity *)entry;
  int entry2;
  
  entry2 = entity->sceneObjects;
  if (entry2 != 0) {
    if (*(char *)(entry2 + 0x75) != '\0') {
      sceneObject = ~sceneObject + 1;
    }
    ComputeEntitySceneObjectCollisionMoveDelta(sceneObject,0,entry2);
    ((EntitySceneObject *)entry2)->x = ((EntitySceneObject *)entry2)->x + *(int *)(entry2 + 0x54);
    ((EntitySceneObject *)entry2)->z = ((EntitySceneObject *)entry2)->z + *(int *)(entry2 + 0x5c);
    ((EntitySceneObject *)entry2)->yaw = *(ushort *)(entry2 + 0x132);
    if (*(char *)(entry2 + 0x75) != '\0') {
      *(ushort *)(entry2 + 0xa0) = *(short *)(entry2 + 0x130) - 0x400U & 0xfff;
      return;
    }
    ((EntitySceneObject *)entry2)->yaw = *(ushort *)(entry2 + 0x132) ^ 0x800;
    *(ushort *)(entry2 + 0xa0) = 0x400U - *(short *)(entry2 + 0x130) & 0xfff;
  }
  return;
}

