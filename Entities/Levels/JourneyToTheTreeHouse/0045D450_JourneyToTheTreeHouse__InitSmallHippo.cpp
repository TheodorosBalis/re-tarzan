#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D450
// Label: JourneyToTheTreeHouse::InitSmallHippo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitSmallHippo(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  *(undefined4 *)(value + 0xb4) = 1;
  *(undefined4 *)(value + 0xa8) = 0x600;
  *(undefined4 *)(value + 0xac) = 0x600;
  *(undefined4 *)(value + 0xb0) = 0x600;
  *(undefined4 *)(value + 0x20) = 0x400;
  *(undefined4 *)(value + 0x24) = 0x400;
  *(undefined4 *)(value + 0x28) = 0x400;
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

