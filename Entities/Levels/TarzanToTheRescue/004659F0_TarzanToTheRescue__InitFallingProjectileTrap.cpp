#include "tarzan_ghidra_types.hpp"

// Address: 0x004659F0
// Label: TarzanToTheRescue::InitFallingProjectileTrap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitFallingProjectileTrap(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x7c,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200f;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    *(undefined4 *)(value + 0x1c) = 3;
    *(undefined4 *)(value + 0x60) = 0x60;
    *(undefined4 *)(value + 0x20) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa2) = *(undefined2 *)(value + 0x70);
    *(undefined4 *)(value + 0x78) = 0;
  }
  return;
}

