#include "tarzan_ghidra_types.hpp"

// Address: 0x004317B0
// Label: JourneyToTheTreeHouse::InitBlueButterflies
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::InitBlueButterflies(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value3;
  undefined2 value4;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1248;
  *(undefined2 *)(value + 0xc) = 0x2012;
  ((EntitySceneObject *)value)->roll = 0;
  value4 = RandomModulo(0x1000);
  ((EntitySceneObject *)value)->yaw = value4;
  if (entity->descriptor != 0) {
    value2 = *(int *)(entity->descriptor + 0x10);
    *(undefined4 *)(value + 0x20) = *(undefined4 *)(value2 + 4);
    *(undefined4 *)(value + 0x24) = *(undefined4 *)(value2 + 8);
    value3 = *(undefined4 *)(value2 + 0xc);
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 4;
    *(undefined4 *)(value + 0x28) = value3;
  }
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ButterfliesScriptAttachmentDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,0);
  return;
}

