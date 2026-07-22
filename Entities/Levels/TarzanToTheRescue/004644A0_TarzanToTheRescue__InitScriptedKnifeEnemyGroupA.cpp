#include "tarzan_ghidra_types.hpp"

// Address: 0x004644A0
// Label: TarzanToTheRescue::InitScriptedKnifeEnemyGroupA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::InitScriptedKnifeEnemyGroupA(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value3;
  int value;
  int value2;
  
  value2 = *(int *)(entity->descriptor + 0x10);
  *(undefined2 *)(entry + 0x3e) = 0x280;
  *(undefined2 *)(entity->sceneObjects + 0xa6) = 0;
  value = CEntities::CreateEntityAttachment(entry,200,0x10000000);
  if (value != 0) {
    if (*(int *)(value2 + 4) == 0) {
      *(undefined4 *)(value + 0x58) = 2;
      *(undefined4 *)(value + 0x54) = 0;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x15f0;
      g_TarzanToTheRescueTrackedKnifeEnemyGroupA0 = entry;
    }
    if (*(int *)(value2 + 4) == 1) {
      *(undefined4 *)(value + 0x58) = 4;
      *(undefined4 *)(value + 0x54) = 4;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2c48;
      g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = entry;
    }
    if (*(int *)(value2 + 4) == 2) {
      *(undefined4 *)(value + 0x58) = 5;
      *(undefined4 *)(value + 0x54) = 8;
      *(int *)(entity->sceneObjects + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2be0;
      g_TarzanToTheRescueTrackedKnifeEnemyVariantC = entry;
    }
    CEntities::AcquireEntitySceneObjectResourceSet(entity->sceneObjects);
    *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
    *(undefined4 *)(value + 0x5c) = 0;
    *(undefined4 *)(value + 0xc0) = 0;
    *(undefined4 *)(value + 0xc) = 5;
    value3 = (byte *)(entity->sceneObjects + 0xf);
    *value3 = *value3 | 2;
    value2 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_TarzanToTheRescueScriptedKnifeEnemyGroupAScriptDesc);
    *(int *)(value + 0x10) = value2;
    if (value2 != 0) {
      CEntities::SelectScriptAttachmentSequence(value2,*(undefined4 *)(value + 0x54));
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ScriptedEnemyEntityListHead,entry);
  return;
}

