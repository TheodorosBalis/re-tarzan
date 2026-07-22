#include "tarzan_ghidra_types.hpp"

// Address: 0x00466B40
// Label: TarzanToTheRescue::InitClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitClayton(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  UnloadEncodedResourceId(0x68);
  UnloadEncodedResourceId(0x27);
  value = CEntities::CreateEntityAttachment(entry,0x28,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2908;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    *(undefined4 *)(value + 0x14) = 0;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(value + 0x18) = 0xf0;
    *(undefined4 *)(value + 0x20) = 0;
    *(undefined4 *)(value + 0x24) = 0;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueElephantRescueSequenceTriggerScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,1);
    }
  }
  return;
}

