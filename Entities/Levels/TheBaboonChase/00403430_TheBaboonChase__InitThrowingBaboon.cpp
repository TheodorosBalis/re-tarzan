#include "tarzan_ghidra_types.hpp"

// Address: 0x00403430
// Label: TheBaboonChase::InitThrowingBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitThrowingBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc830);
    *(undefined4 *)(value + 0x18) = value2;
    CEntities::SelectScriptAttachmentSequence(value2,1);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1e10;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  }
  return;
}

