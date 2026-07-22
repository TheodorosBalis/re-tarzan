#include "tarzan_ghidra_types.hpp"

// Address: 0x00488600
// Label: TrashingTheCamp::SpawnCampThrownPropDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::SpawnCampThrownPropDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  value = CEntities::SpawnEntityByTypeAtPosition(0,0,0,0xfa,0x11);
  if (((value != 0) && (value2 = *(int *)(value + 0x38), value2 != 0)) &&
     (value3 = entity->sceneObjects, value3 != 0)) {
    *(undefined2 *)(value2 + 0xc) = *(undefined2 *)(value3 + 0xc);
    *(undefined4 *)(value2 + 0x14) = ((EntitySceneObject *)value3)->x;
    *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value3)->y;
    *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value3)->z;
    *(undefined2 *)(value2 + 0xa2) = ((EntitySceneObject *)value3)->yaw;
    *(undefined2 *)(value2 + 0xa0) = *(undefined2 *)(value3 + 0xa0);
    *(undefined2 *)(value2 + 0xa4) = ((EntitySceneObject *)value3)->pitch;
    *(undefined4 *)(value2 + 0x110) = ((EntitySceneObject *)value3)->surfacePathIndex;
    *(undefined4 *)(value2 + 0x10c) = ((EntitySceneObject *)value3)->surfaceIndex;
    *(undefined4 *)(value2 + 0x108) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
    value2 = CEntities::FindEntityAttachmentByFlags(value,0x800);
    if (value2 != 0) {
      value3 = RandomModulo(0x30);
      *(int *)(value2 + 0x10) = &((EntitySceneObject *)value3)->worldObject;
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined4 *)(value2 + 0x18) = 0;
      value3 = RandomModulo(0x30);
      *(int *)(value2 + 0x20) = &((EntitySceneObject *)value3)->worldObject;
      *(undefined4 *)(value2 + 0x2c) = 0x80;
      *(undefined4 *)(value2 + 0x24) = 0;
      value3 = RandomModulo(4);
      *(int *)(value2 + 0x28) = value3 + 2;
      *(undefined1 *)(value2 + 0xd) = 0xff;
    }
    *(undefined4 *)(value + 0x4c) = *(undefined4 *)(entry + 0x4c);
  }
  return;
}

