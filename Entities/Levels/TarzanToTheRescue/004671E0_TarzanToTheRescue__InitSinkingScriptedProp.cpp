#include "tarzan_ghidra_types.hpp"

// Address: 0x004671E0
// Label: TarzanToTheRescue::InitSinkingScriptedProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitSinkingScriptedProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x10,0x20000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x400;
    *(undefined2 *)(entity->sceneObjects + 0xe) = 0x8421;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueSinkingScriptedPropScriptDesc);
    *(int *)(value + 0xc) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
  }
  return;
}

