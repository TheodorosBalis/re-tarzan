#include "tarzan_ghidra_types.hpp"

// Address: 0x00484720
// Label: TrashingTheCamp::InitScriptedLemur
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitScriptedLemur(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = g_WorldEntitySceneObjectArrayBase + 0x478;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0x140) = 0;
    CEntities::AcquireEntitySceneObjectResourceSet(value);
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&g_TrashingTheCampLemurScriptDesc);
    *(undefined2 *)(entry + 0x48) = 0;
    value = RandomModulo(0x32);
    *(int *)(entry + 0x4c) = value + 10;
    *(undefined4 *)(entry + 0x50) = 0;
  }
  return;
}

