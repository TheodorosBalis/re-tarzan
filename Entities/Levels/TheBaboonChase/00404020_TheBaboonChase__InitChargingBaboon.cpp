#include "tarzan_ghidra_types.hpp"

// Address: 0x00404020
// Label: TheBaboonChase::InitChargingBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::InitChargingBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x7c,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1e10;
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004bc5e8);
    *(undefined4 *)(value + 0x10) = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x10),0);
    *(undefined4 *)(value + 0xc) = 3;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 1;
    *(undefined1 *)(entity->sceneObjects + 0x75) = 0xff;
    *(undefined4 *)(value + 0x28) = 3;
    *(undefined4 *)(value + 0x48) = 0;
    *(undefined4 *)(value + 0x2c) = 0;
    *(undefined4 *)(value + 0x5c) = 0;
    *(undefined4 *)(value + 0x60) = 0;
    *(int *)(value + 0x40) = *(int *)(entity->sceneObjects + 0x18) + 0x800;
  }
  return;
}

