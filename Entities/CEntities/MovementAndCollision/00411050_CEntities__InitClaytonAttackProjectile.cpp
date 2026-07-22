#include "tarzan_ghidra_types.hpp"

#define g_WorldEntitySceneObjectArrayBase (*(int *)0x0051C6CC)

// Address: 0x00411050
// Label: CEntities::InitClaytonAttackProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitClaytonAttackProjectile(int entityAddress)

{
  Entity *entity = (Entity *)entityAddress;
  int sceneObjectAddress;
  int worldObjectAddress;
  
  worldObjectAddress = g_WorldEntitySceneObjectArrayBase + 0x1ee0;
  sceneObjectAddress = entity->sceneObjects;
  *(ushort *)(sceneObjectAddress + 0xe) = *(ushort *)(sceneObjectAddress + 0xe) | 0x1021;
  ((EntitySceneObject *)sceneObjectAddress)->worldObject = worldObjectAddress;
  *(undefined2 *)(sceneObjectAddress + 0xc) = 0x202e;
  return;
}

