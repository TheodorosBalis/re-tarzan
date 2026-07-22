#include "tarzan_ghidra_types.hpp"

// Address: 0x00403B50
// Label: TheBaboonChase::InitSnake
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitSnake(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1040;
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc8e8);
    *(undefined4 *)(value + 0x10) = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  }
  return;
}

