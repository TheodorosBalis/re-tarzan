#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F9D0
// Label: CEntities::InitBouncingBoxDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitBouncingBoxDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2004;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 2;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x2c) = 1;
    value2 = RandomModulo(0x14);
    *(int *)(value + 0x18) = value2 + 0x5a;
    *(undefined4 *)(value + 0x40) = 0;
    *(undefined4 *)(value + 0x44) = 0;
    *(undefined4 *)(value + 0x24) = 0x7fff;
    *(undefined4 *)(value + 0x5c) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 2;
  }
  return;
}

