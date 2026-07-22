#include "tarzan_ghidra_types.hpp"

// Address: 0x0042FC70
// Label: CEntities::InitParabolicThrownProjectile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitParabolicThrownProjectile(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value3;
  int value2;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x84,0x10000000);
  if (value2 != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200f;
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffe0;
    *(undefined4 *)(value2 + 0xc) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(int *)(value2 + 0x10) = *(int *)(g_PlayerEntitySceneObject + 0x18) + -0x180;
    *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
    value = entity->sceneObjects;
    *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value)->y;
    value3 = ((EntitySceneObject *)value)->z;
    *(undefined4 *)(value2 + 0x30) = 3;
    *(undefined4 *)(value2 + 0x20) = value3;
    *(undefined4 *)(value2 + 0x74) = 0x38;
    *(undefined4 *)(value2 + 0x34) = 0;
    *(int *)(value2 + 0x48) = *(int *)(entity->sceneObjects + 0x18) + 0x400;
  }
  return;
}

