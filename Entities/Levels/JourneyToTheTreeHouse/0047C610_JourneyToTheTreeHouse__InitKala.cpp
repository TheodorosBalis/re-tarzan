#include "tarzan_ghidra_types.hpp"

// Address: 0x0047C610
// Label: JourneyToTheTreeHouse::InitKala
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitKala(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0xf08;
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_JourneyToTheTreeHouseKalaScriptDesc);
  ((EntitySceneObject *)value)->roll = 1;
  *(undefined1 *)(value + 0x75) = 0;
  *(undefined2 *)(value + 0xc) = 0x3e;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value2 == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  if (entity->descriptor != 0) {
    value2 = *(int *)(entity->descriptor + 0x10);
    *(undefined2 *)(value + 0xa0) = *(undefined2 *)(value2 + 4);
    ((EntitySceneObject *)value)->yaw = *(undefined2 *)(value2 + 8);
    ((EntitySceneObject *)value)->pitch = *(undefined2 *)(value2 + 0xc);
  }
  *(undefined2 *)(entry + 0x48) = 0;
  CEntities::SelectEntityAnimationAttachmentState(entry,0);
  return;
}

