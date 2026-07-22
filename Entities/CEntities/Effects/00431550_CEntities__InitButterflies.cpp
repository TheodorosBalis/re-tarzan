#include "tarzan_ghidra_types.hpp"

// Address: 0x00431550
// Label: CEntities::InitButterflies
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitButterflies(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  undefined4 value3;
  short shortValue;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1248;
  *(undefined2 *)(value + 0xc) = 0x2012;
  ((EntitySceneObject *)value)->roll = 0;
  if (entity->descriptor != 0) {
    value2 = *(int *)(entity->descriptor + 0x10);
    *(undefined4 *)(value + 0x20) = *(undefined4 *)(value2 + 4);
    *(undefined4 *)(value + 0x24) = *(undefined4 *)(value2 + 8);
    value3 = *(undefined4 *)(value2 + 0xc);
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 4;
    *(undefined4 *)(value + 0x28) = value3;
    *(undefined4 *)(value + 0x30) = 0;
    *(undefined2 *)(value + 0x140) = 0;
  }
  if (((EntitySceneObject *)value)->pad108 == 1) {
    *(undefined4 *)(entry + 0x4c) = 0xc;
    *(undefined2 *)(entry + 0x48) = 8;
    shortValue = RandomModulo(0x3c);
    *(short *)(entry + 0x4a) = shortValue + 0x1e;
  }
  else {
    *(undefined2 *)(entry + 0x48) = 0;
  }
  CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_ButterfliesScriptAttachmentDesc);
  CEntities::SelectEntityAnimationAttachmentState(entry,0);
  return;
}

