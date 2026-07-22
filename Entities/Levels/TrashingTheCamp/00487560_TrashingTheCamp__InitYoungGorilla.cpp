#include "tarzan_ghidra_types.hpp"

// Address: 0x00487560
// Label: TrashingTheCamp::InitYoungGorilla
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitYoungGorilla(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x3330;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    *(undefined2 *)(entry + 0x48) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x30;
    value2 = RandomModulo(10);
    *(int *)(entry + 0x50) = value2 + 5;
    CEntities::SetEntitySceneObjectScriptAttachment
              (entry,&g_TrashingTheCampYoungGorillaScriptDesc);
    PlayAudioById(0x29f,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
    value2 = CreateEntityEntitySceneObject((uint *)entry,2);
    value = g_WorldEntitySceneObjectArrayBase;
    if (value2 != 0) {
      *(undefined2 *)(value2 + 0xa6) = 2;
      *(undefined2 *)(value2 + 0xc) = 0x2011;
      *(int *)(value2 + 0x10) = value + 0x3330;
    }
  }
  return;
}

