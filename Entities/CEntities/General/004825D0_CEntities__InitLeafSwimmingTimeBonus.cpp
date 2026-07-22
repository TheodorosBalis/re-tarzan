#include "tarzan_ghidra_types.hpp"

// Address: 0x004825D0
// Label: CEntities::InitLeafSwimmingTimeBonus
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingTimeBonus(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3a8;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2029;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 2;
    value2 = RandomModulo(0x40);
    *(int *)(value + 0x14) = value2 + 0x80;
    *(undefined4 *)(value + 0x10) = 0;
    *(undefined4 *)(value + 0x28) = 0;
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined4 *)(value + 0x34) = 0;
    *(undefined4 *)(value + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
  }
  return;
}

