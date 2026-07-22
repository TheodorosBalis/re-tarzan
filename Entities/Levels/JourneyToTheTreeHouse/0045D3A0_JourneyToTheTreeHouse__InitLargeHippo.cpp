#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D3A0
// Label: JourneyToTheTreeHouse::InitLargeHippo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitLargeHippo(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  *(undefined4 *)(value + 0xa8) = 0xb00;
  *(undefined4 *)(value + 0xac) = 0xb00;
  *(undefined4 *)(value + 0xb0) = 0xb00;
  *(undefined4 *)(value + 0xb4) = 1;
  *(undefined4 *)(value + 0x20) = 3000;
  *(undefined4 *)(value + 0x24) = 3000;
  *(undefined4 *)(value + 0x28) = 3000;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x37a8;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_JourneyToTheTreeHouseHippoScriptDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,4);
  ((EntitySceneObject *)value)->roll = 0;
  *(undefined1 *)(value + 0x75) = 0;
  *(undefined2 *)(value + 0x140) = 0x100;
  value = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  *(undefined2 *)(entry + 0x48) = 0x15;
  *(undefined4 *)(entry + 0x50) = 2;
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

