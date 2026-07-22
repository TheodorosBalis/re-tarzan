#include "tarzan_ghidra_types.hpp"

// Address: 0x00430820
// Label: CEntities::InitThrowableFromNPC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitThrowableFromNPC(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x10000;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined4 *)(value + 0x48) = ((EntitySceneObject *)value)->x;
    *(undefined4 *)(value + 0x4c) = ((EntitySceneObject *)value)->y;
    *(undefined4 *)(value + 0x50) = ((EntitySceneObject *)value)->z;
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(value + 0xc) = 0x200f;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 0;
  }
  return;
}

