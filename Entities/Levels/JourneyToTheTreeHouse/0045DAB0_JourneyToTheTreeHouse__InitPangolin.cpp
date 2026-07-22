#include "tarzan_ghidra_types.hpp"

// Address: 0x0045DAB0
// Label: JourneyToTheTreeHouse::InitPangolin
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitPangolin(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x618;
  *(undefined2 *)(value + 0xc) = 0;
  CEntities::SetEntitySceneObjectScriptAttachment
            (entry,&g_JourneyToTheTreeHousePangolinScriptDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,1);
  ((EntitySceneObject *)value)->roll = 1;
  *(undefined1 *)(value + 0x75) = 0;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  *(undefined2 *)(entry + 0x48) = 0x15;
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  *(undefined4 *)(value + 0x6c) = 0xffffffe2;
  *(undefined4 *)(entry + 0x4c) = 4;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  return;
}

