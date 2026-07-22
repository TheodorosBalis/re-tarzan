#include "tarzan_ghidra_types.hpp"

// Address: 0x004837F0
// Label: CEntities::InitLeafSwimmingFishSplashDroplet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitLeafSwimmingFishSplashDroplet(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2490;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2007;
    value2 = (byte *)(entity->sceneObjects + 0xf);
    *value2 = *value2 | 4;
    value2 = (byte *)(entity->sceneObjects + 0xe);
    *value2 = *value2 | 0x21;
    *(undefined4 *)(entity->sceneObjects + 0x30) = 0xfff;
  }
  return;
}

