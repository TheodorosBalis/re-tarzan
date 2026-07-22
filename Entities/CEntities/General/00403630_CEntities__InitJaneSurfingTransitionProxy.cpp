#include "tarzan_ghidra_types.hpp"

// Address: 0x00403630
// Label: CEntities::InitJaneSurfingTransitionProxy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitJaneSurfingTransitionProxy(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value2;
  int value;
  
  value = CEntities::CreateEntityAttachment(entry,0x1c,0x10000000);
  if (value != 0) {
    *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) =
         *(uint *)(*(int *)(g_CurrentWorldSceneContext + 0x24) + 4) | 2;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x208;
    *(undefined2 *)(entity->sceneObjects + 0xc) = 0x200d;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    value2 = (byte *)(entity->sceneObjects + 0xf);
    *value2 = *value2 | 8;
    *(undefined4 *)(value + 0xc) = 0;
    *(undefined4 *)(entity->sceneObjects + 0x6c) = 0xffffffc0;
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    g_JaneScriptedFollowEntity = entry;
  }
  return;
}

