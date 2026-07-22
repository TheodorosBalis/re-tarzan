#include "tarzan_ghidra_types.hpp"

// Address: 0x00410EE0
// Label: CEntities::InitClaytonChasingProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitClaytonChasingProjectile(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(undefined2 *)(entry + 0x4a) = 0x28;
  value2 = g_WorldEntitySceneObjectArrayBase + 0x1ee0;
  *(undefined2 *)(value + 0xc) = 0x2032;
  ((EntitySceneObject *)value)->worldObject = value2;
  *(int *)(entry + 0x50) =
       (int)(0xa122 / (longlong)
                      (*(int *)(g_PlayerEntitySceneObjectData + 8) -
                      *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x14)));
  return;
}

