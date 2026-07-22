#include "tarzan_ghidra_types.hpp"

// Address: 0x00462EC0
// Label: TarzanToTheRescue::InitBoxInWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitBoxInWater(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  
  *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
  *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2002;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
  *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x1d4c;
  *(undefined4 *)(entity->sceneObjects + 0xac) = 0x1d4c;
  *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x1d4c;
  value = CEntities::CreateEntityAttachment(entry,0x44,0x10000000);
  if (value != 0) {
    if (entity->descriptor != 0) {
      *(undefined4 *)(value + 0x30) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
      ;
    }
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_005062e0);
    *(int *)(value + 0x34) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
      shortValue = RandomModulo(0xb);
      *(short *)(*(int *)(value + 0x34) + 0x16) = shortValue + 1;
    }
    *(undefined4 *)(value + 0x38) = 0;
    *(undefined4 *)(value + 0x40) = 0;
    *(undefined4 *)(value + 0xc) = 7;
    value2 = RandomModulo(4);
    *(int *)(value + 0x3c) = value2 + 6;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

