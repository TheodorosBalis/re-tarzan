#include "tarzan_ghidra_types.hpp"

// Address: 0x00458990
// Label: Stampede::InitMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::InitMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x14,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x3260;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 2;
    value2 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_005035a8);
    *(undefined4 *)(value + 0x10) = value2;
    CEntities::SelectScriptAttachmentSequence(value2,1);
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(g_PlayerEntitySceneObject + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0xa8) = 0x1800;
    *(undefined4 *)(entity->sceneObjects + 0xac) = 0x1800;
    *(undefined4 *)(entity->sceneObjects + 0xb0) = 0x1800;
  }
  return;
}

