#include "tarzan_ghidra_types.hpp"

// Address: 0x004755C0
// Label: KerchakChase::InitFallingTreeObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::InitFallingTreeObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x10,0x10000000);
  if (value != 0) {
    *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200b;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 2;
    value2 = (byte *)(entity->sceneObjects + 0xf);
    *value2 = *value2 | 8;
    *(undefined4 *)(value + 0xc) = 0;
  }
  return;
}

