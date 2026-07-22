#include "tarzan_ghidra_types.hpp"

// Address: 0x004030B0
// Label: TheBaboonChase::InitBreakableBranch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitBreakableBranch(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value3;
  int value;
  int value2;
  
  value3 = (byte *)(entity->sceneObjects + 0xf);
  *value3 = *value3 | 8;
  *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
  value2 = CEntities::CreateEntityAttachment(entry,0x18,0x10000000);
  if ((value2 != 0) && (entity->descriptor != 0)) {
    value = *(int *)(entity->descriptor + 0x10);
    *(undefined4 *)(value2 + 0xc) = 0;
    value = *(int *)(value + 4);
    if (value == 0) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2003;
      *(undefined4 *)(value2 + 0x10) = 0;
      *(undefined4 *)(value2 + 0x14) = 0x180;
    }
    else if (value == 1) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2004;
      *(undefined4 *)(value2 + 0x10) = 1;
      *(undefined4 *)(value2 + 0x14) = 0xfffffe80;
      return;
    }
  }
  return;
}

