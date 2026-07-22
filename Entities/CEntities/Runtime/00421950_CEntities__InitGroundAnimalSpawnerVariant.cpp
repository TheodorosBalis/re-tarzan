#include "tarzan_ghidra_types.hpp"

// Address: 0x00421950
// Label: CEntities::InitGroundAnimalSpawnerVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitGroundAnimalSpawnerVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  value2 = *(int *)(entity->descriptor + 0x10);
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xb60;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
    *(undefined4 *)(entry + 0x4c) = 0;
    shortValue = *(short *)(value2 + 0xc);
    *(short *)(entry + 0x4a) = shortValue;
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x4a) = 0x3c;
    }
    value = *(int *)(value2 + 0x10);
    *(int *)(entry + 0x50) = value;
    if (value == 0) {
      *(undefined4 *)(entry + 0x50) = 0x3c;
    }
  }
  return;
}

