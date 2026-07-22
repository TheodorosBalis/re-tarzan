#include "tarzan_ghidra_types.hpp"

// Address: 0x00431210
// Label: StorkRide::InitFinishLine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitFinishLine(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
    ((EntitySceneObject *)value)->worldObject = 0;
    *(undefined2 *)(value + 0xc) = 0;
    value = *(int *)(*(int *)(entity->descriptor + 0x10) + 4);
    *(int *)(entry + 0x4c) = value;
    if (value == 0) {
      *(undefined4 *)(entry + 0x4c) = 0x400;
    }
  }
  return;
}

