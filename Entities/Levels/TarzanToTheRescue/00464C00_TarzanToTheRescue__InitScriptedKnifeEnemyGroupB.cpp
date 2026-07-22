#include "tarzan_ghidra_types.hpp"

// Address: 0x00464C00
// Label: TarzanToTheRescue::InitScriptedKnifeEnemyGroupB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::InitScriptedKnifeEnemyGroupB(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value4;
  int value;
  int value2;
  undefined4 value3;
  
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  _g_TarzanToTheRescueElephantBarrierPlayerDeltaXQuarter = 0;
  *(undefined2 *)(entry + 0x3e) = 0x280;
  value = CEntities::CreateEntityAttachment(entry,200,0x10000000);
  if (value != 0) {
    if (entity->descriptor != 0) {
      value2 = *(int *)(entity->descriptor + 0x10);
      if (*(int *)(value2 + 4) == 0) {
        *(undefined4 *)(value + 0x58) = 0;
        *(undefined4 *)(value + 0x54) = 0;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2e50;
      }
      if (*(int *)(value2 + 4) == 1) {
        *(undefined4 *)(value + 0x58) = 3;
        *(undefined4 *)(value + 0x54) = 10;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2de8;
      }
      if (*(int *)(value2 + 4) == 2) {
        *(undefined4 *)(value + 0x58) = 1;
        *(undefined4 *)(value + 0x54) = 0x15;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2eb8;
      }
      if (*(int *)(value2 + 4) == 3) {
        *(undefined4 *)(value + 0x58) = 7;
        *(undefined4 *)(value + 0x54) = 0;
        *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2e50;
        g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = entry;
      }
    }
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    *(undefined4 *)(value + 0xc) = 5;
    *(undefined4 *)(value + 0x50) = 0x10;
    *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
    *(undefined4 *)(value + 0x5c) = 0;
    value4 = (byte *)(entity->sceneObjects + 0xf);
    *value4 = *value4 | 2;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueScriptedKnifeEnemyGroupBScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,*(undefined4 *)(value + 0x54));
    }
    if (*(int *)(value + 0x58) == 0) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      g_TarzanToTheRescueTrackedKnifeEnemyGroupB0 = entry;
    }
    if (*(int *)(value + 0x58) == 3) {
      g_TarzanToTheRescueScriptedBarrierLeftDone = 0;
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      if (g_TarzanToTheRescueActiveElephantBarrier == 0) {
        value2 = *(int *)(value + 0x54);
        value3 = *(undefined4 *)(value + 0x10);
        *(undefined4 *)(value + 0xc) = 5;
      }
      else {
        value3 = *(undefined4 *)(value + 0x10);
        value2 = *(int *)(value + 0x54) + 10;
        *(undefined4 *)(value + 0xc) = 0x20;
      }
      CEntities::SelectScriptAttachmentSequence(value3,value2);
      _g_TarzanToTheRescueTrackedKnifeEnemyGroupB1 = entry;
    }
    if (*(int *)(value + 0x58) == 1) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      if (g_TarzanToTheRescueActiveElephantBarrier == 0) {
        value2 = *(int *)(value + 0x54);
        value3 = *(undefined4 *)(value + 0x10);
        *(undefined4 *)(value + 0xc) = 5;
      }
      else {
        value3 = *(undefined4 *)(value + 0x10);
        value2 = *(int *)(value + 0x54) + 10;
        *(undefined4 *)(value + 0xc) = 0x20;
      }
      CEntities::SelectScriptAttachmentSequence(value3,value2);
      g_TarzanToTheRescueTrackedKnifeEnemyGroupB2 = entry;
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ScriptedEnemyEntityListHead,entry);
  return;
}

