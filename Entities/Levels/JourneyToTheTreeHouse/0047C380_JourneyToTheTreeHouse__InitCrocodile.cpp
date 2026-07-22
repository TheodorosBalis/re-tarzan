#include "tarzan_ghidra_types.hpp"

// Address: 0x0047C380
// Label: JourneyToTheTreeHouse::InitCrocodile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitCrocodile(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3810;
  CEntities::SetEntitySceneObjectScriptAttachment
            (entry,&g_JourneyToTheTreeHouseCrocodileScriptAttachmentDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,0);
  ((EntitySceneObject *)value)->roll = 0;
  *(undefined1 *)(value + 0x75) = 0;
  *(undefined2 *)(value + 0xc) = 1;
  *(undefined4 *)(value + 0x6c) = 0xffffffc0;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  *(undefined2 *)(entry + 0x48) = 0x15;
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

