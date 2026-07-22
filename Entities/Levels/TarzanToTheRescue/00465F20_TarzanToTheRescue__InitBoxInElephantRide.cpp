#include "tarzan_ghidra_types.hpp"

// Address: 0x00465F20
// Label: TarzanToTheRescue::InitBoxInElephantRide
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitBoxInElephantRide(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value2 != 0) {
    if (entity->descriptor != 0) {
      value = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value + 4) == 0) {
        *(undefined4 *)(value2 + 0x10) = 0;
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2015;
      }
      if (*(int *)(value + 4) == 1) {
        *(undefined4 *)(value2 + 0x10) = 1;
        *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2016;
      }
    }
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(value2 + 0xc) = 0;
  }
  return;
}

