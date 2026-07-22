#include "tarzan_ghidra_types.hpp"

// Address: 0x00463D80
// Label: TarzanToTheRescue::InitKnifeEnemyVariantC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitKnifeEnemyVariantC(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value3;
  int *intCursor;
  int value;
  int value2;
  
  *(undefined2 *)(entry + 0x3e) = 0x280;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,200,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0x54) = 0;
    value3 = (byte *)(entity->sceneObjects + 0xf);
    *value3 = *value3 | 2;
    *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2d80;
    *(undefined4 *)(value + 0x58) = 5;
    g_TarzanToTheRescueTrackedKnifeEnemyVariantC = entry;
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    *(undefined4 *)(value + 0xc) = 10;
    *(undefined4 *)(value + 0x5c) = 0;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueKnifeEnemyVariantCScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,*(undefined4 *)(value + 0x54));
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(entity->sceneObjects);
    value = *(int *)(entity->sceneObjects + 0x58);
    if ((-0x100 < value) && (value < 0x100)) {
      intCursor = (int *)(entity->sceneObjects + 0x18);
      *intCursor = *intCursor + value;
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  return;
}

