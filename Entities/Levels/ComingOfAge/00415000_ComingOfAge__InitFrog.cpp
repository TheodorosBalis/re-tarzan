#include "tarzan_ghidra_types.hpp"

// Address: 0x00415000
// Label: ComingOfAge::InitFrog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitFrog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  value2 = g_WorldEntitySceneObjectArrayBase;
  if (value != 0) {
    ((EntitySceneObject *)value)->roll = 1;
    *(undefined2 *)(value + 0x140) = 0;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x12b0;
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\n') {
      CEntities::AcquireEntitySceneObjectResourceSet(value);
    }
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&DAT_004c22c8);
    *(undefined2 *)(entry + 0x48) = 0;
    *(undefined2 *)(entry + 0x4a) = 0;
  }
  return;
}

