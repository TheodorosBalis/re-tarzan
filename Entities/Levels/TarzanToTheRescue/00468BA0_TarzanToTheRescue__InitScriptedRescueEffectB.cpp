#include "tarzan_ghidra_types.hpp"

// Address: 0x00468BA0
// Label: TarzanToTheRescue::InitScriptedRescueEffectB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitScriptedRescueEffectB(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  value = CEntities::CreateEntityAttachment(entry,0x38,0x10000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2d18;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined4 *)(entity->sceneObjects + 0xa8) = 8000;
    *(undefined4 *)(entity->sceneObjects + 0xac) = 8000;
    *(undefined4 *)(entity->sceneObjects + 0xb0) = 8000;
    *(undefined4 *)(value + 0x10) = 0;
    value2 = entity->sceneObjects;
    *(undefined4 *)(value + 0x18) = ((EntitySceneObject *)value2)->x;
    *(undefined4 *)(value + 0x1c) = ((EntitySceneObject *)value2)->y;
    *(undefined4 *)(value + 0x20) = ((EntitySceneObject *)value2)->z;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueScriptedRescueEffectScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,2);
    }
    *(undefined4 *)(entity->sceneObjects + 0xb4) = 1;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    value2 = RandomModulo(0x200);
    value3 = RandomModulo(0x200);
    *(int *)(value + 0x28) = value2 - value3;
    value2 = RandomModulo(0x200);
    value3 = RandomModulo(0x200);
    *(int *)(value + 0x24) = value2 - value3;
    value2 = RandomModulo(0x200);
    value3 = RandomModulo(0x200);
    *(int *)(value + 0x2c) = value2 - value3;
    value2 = RandomModulo(0x40);
    *(int *)(value + 0x34) = value2 + 0x20;
  }
  return;
}

