#include "tarzan_ghidra_types.hpp"

// Address: 0x0043C4E0
// Label: WelcomeToTheJungle::InitBongo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::InitBongo(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x548;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_BongoScriptAttachmentDesc);
    *(undefined2 *)(entry + 0x4a) = 0;
    *(undefined2 *)(entry + 0x48) = 0;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

