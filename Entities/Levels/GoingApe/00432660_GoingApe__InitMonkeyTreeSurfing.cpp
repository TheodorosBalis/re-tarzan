#include "tarzan_ghidra_types.hpp"

// Address: 0x00432660
// Label: GoingApe::InitMonkeyTreeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::InitMonkeyTreeSurfing(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 4;
  if ((*(byte *)(entry + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1015);
    value = entity->sceneObjects;
    if (value != 0) {
      ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x9c0;
      ((EntitySceneObject *)value)->roll = 1;
      *(undefined4 *)(value + 0xb4) = 1;
      *(undefined2 *)(value + 0x140) = 0x100;
      *(undefined4 *)(value + 0xa8) = 0x1700;
      *(undefined4 *)(value + 0xac) = 0x1700;
      *(undefined4 *)(value + 0xb0) = 0x1700;
      *(undefined1 *)(value + 0x75) = 0xff;
      CEntities::SetEntitySceneObjectScriptAttachment
                (entry,&g_GoingApeMonkeyTreeSurfingScriptDesc);
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined2 *)(entry + 0x4a) = 0;
      value = RandomModulo(0x1e);
      *(int *)(entry + 0x4c) = value + -0xf;
      value2 = RandomModulo(2);
      *(undefined4 *)(entry + 0x50) = value2;
    }
    CEntities::LinkEntityIntoProcessingList(&g_LevelEnemyEntityListHead,entry);
  }
  else {
    value = CEntities::CountEntitiesOfTypeInList(g_LevelEnemyEntityListHead,0x53);
    if (value < 2) {
      UnloadEncodedResourceId(0x1015);
      return;
    }
  }
  return;
}

