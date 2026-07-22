#include "tarzan_ghidra_types.hpp"

// Address: 0x00410F30
// Label: CEntities::UpdateClaytonChasingProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateClaytonChasingProjectile(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  if (*(int *)(entry + 0x4c) == 0) {
    ((EntitySceneObject *)value2)->yaw = ((EntitySceneObject *)value2)->yaw + 0x113;
  }
  else if (*(int *)(entry + 0x4c) == 1) {
    *(short *)(value2 + 0xa0) = *(short *)(value2 + 0xa0) + -0x113;
    ((EntitySceneObject *)value2)->y = ((EntitySceneObject *)value2)->y + *(int *)(entry + 0x50);
  }
  value = ((EntitySceneObject *)value2)->x + 0x5a;
  ((EntitySceneObject *)value2)->x = value;
  value = *(int *)(g_PlayerEntitySceneObjectData + 8) - value;
  if ((((g_PlayerDamageInvulnerabilityTicks == 0) && (-200 < value)) && (value < 200)) &&
     ((value2 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - ((EntitySceneObject *)value2)->y, 0 < value2 &&
      (value2 < (int)((-(uint)(g_PlayerActionState != 10) & 100) + 0x96))))) {
    QueuePlayerDamageEvent(entry,8);
  }
  *(short *)(entry + 0x4a) = *(short *)(entry + 0x4a) + -1;
  if (*(short *)(entry + 0x4a) == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

