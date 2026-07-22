#include "tarzan_ghidra_types.hpp"

#define TotalGameLoopTicks (*(byte *)0x00534048)

// Address: 0x00411080
// Label: CEntities::UpdateClaytonAttackProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateClaytonAttackProjectile(int entityAddress)

{
  Entity *entity = (Entity *)entityAddress;
  int sceneObjectAddress;
  
  sceneObjectAddress = entity->sceneObjects;
  ComputeEntitySceneObjectCollisionMoveDelta(0x3c,0,sceneObjectAddress);
  ((EntitySceneObject *)sceneObjectAddress)->x = ((EntitySceneObject *)sceneObjectAddress)->x + *(int *)(sceneObjectAddress + 0x54);
  ((EntitySceneObject *)sceneObjectAddress)->z = ((EntitySceneObject *)sceneObjectAddress)->z + *(int *)(sceneObjectAddress + 0x5c);
  ((EntitySceneObject *)sceneObjectAddress)->y = ((EntitySceneObject *)sceneObjectAddress)->y + *(int *)(sceneObjectAddress + 0x58) + -0x140;
  if ((((byte)TotalGameLoopTicks & 3) == 0) &&
     (*(short *)(sceneObjectAddress + 0xc) = *(short *)(sceneObjectAddress + 0xc) + 1, 0x2031 < *(ushort *)(sceneObjectAddress + 0xc))) {
    CEntities::ReleaseEntityToFreeList((byte *)entityAddress);
  }
  return;
}

