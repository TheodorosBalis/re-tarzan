#include "tarzan_ghidra_types.hpp"

// Address: 0x004678E0
// Label: TarzanToTheRescue::InitCrocodile3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitCrocodile3D(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = CEntities::CreateEntityAttachment(entry,0x24,0x10000000);
  if (value != 0) {
    *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
    if (entity->descriptor != 0) {
      *(undefined4 *)(value + 0x10) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
      ;
    }
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x24f8;
    *(undefined4 *)(value + 0x18) = 0x78;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    *(undefined4 *)(value + 0xc) = 0;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescuePathfindingKnifeEnemyScriptDesc);
    *(int *)(value + 0x1c) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,0);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    *(undefined2 *)(entry + 0x3e) = 0x200;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

