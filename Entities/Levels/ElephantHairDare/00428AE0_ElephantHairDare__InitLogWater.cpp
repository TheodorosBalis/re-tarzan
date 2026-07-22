#include "tarzan_ghidra_types.hpp"

// Address: 0x00428AE0
// Label: ElephantHairDare::InitLogWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::InitLogWater(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1450;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200c;
  value = (byte *)(entity->sceneObjects + 0x7e);
  *value = *value | 1;
  return;
}

