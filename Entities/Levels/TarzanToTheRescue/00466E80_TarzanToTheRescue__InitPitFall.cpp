#include "tarzan_ghidra_types.hpp"

// Address: 0x00466E80
// Label: TarzanToTheRescue::InitPitFall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitPitFall(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  *(undefined4 *)(entity->sceneObjects + 0x10) = g_CurrentWorldSceneContext;
  value2 = (byte *)(entity->sceneObjects + 0xf);
  *value2 = *value2 | 8;
  if (entity->descriptor != 0) {
    value = *(int *)(entity->descriptor + 0x10);
    if (*(int *)(value + 4) == 0) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2000;
    }
    if (*(int *)(value + 4) == 1) {
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2001;
    }
  }
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 0;
  }
  return;
}

