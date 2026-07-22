#include "tarzan_ghidra_types.hpp"

// Address: 0x00406750
// Label: RockinTheBoat::InitFreeRoamingKnifeEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitFreeRoamingKnifeEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  int value3;
  undefined *dataCursor;
  
  value = entity->sceneObjects;
  if (value == 0) {
    return;
  }
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) | 0x1000;
  *(undefined2 *)(entry + 0x3e) = 0x230;
  ((EntitySceneObject *)value)->roll = 0;
  value2 = CEntities::CreateEntityAttachment(entry,200,0x10000000);
  if (value2 == 0) goto LAB_004068dd;
  *(undefined4 *)(value2 + 0x54) = 0;
  *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 2;
  shortValue = *(short *)(&g_RockinKnifeEnemySpawnVariantTable +
                    g_RockinTheBoatNextFreeRoamKnifeVariant * 0x10);
  *(int *)(value2 + 0x58) = (int)shortValue;
  switch((int)shortValue) {
  case 1:
    dataCursor = &g_RockinKnifeEnemyVariant1Setup;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x28a0;
    goto LAB_00406832;
  default:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2970;
    value3 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant5Setup);
    *(undefined4 *)(value + 0x70) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x30;
    break;
  case 3:
    dataCursor = &g_RockinKnifeEnemyVariant6Setup;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x29d8;
    goto LAB_00406861;
  case 4:
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2698;
    value3 = CEntities::SetEntitySceneObjectScriptAttachment
                      (entry,&g_RockinKnifeEnemyVariant2Setup);
    *(undefined4 *)(value + 0x70) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x1e;
    break;
  case 5:
    dataCursor = &g_RockinKnifeEnemyVariant4Setup;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2700;
LAB_00406861:
    value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    *(undefined4 *)(value + 0x70) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x28;
    break;
  case 6:
    dataCursor = &g_RockinKnifeEnemyVariant3Setup;
    ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x2838;
LAB_00406832:
    value3 = (int)CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)dataCursor);
    *(undefined4 *)(value + 0x70) = 1;
    *(undefined4 *)(entry + 0x4c) = 0x1c;
  }
  CEntities::AcquireEntitySceneObjectResourceSet(value);
  *(undefined4 *)(value2 + 0xc) = 10;
  *(undefined4 *)(value2 + 0x5c) = 0;
  *(int *)(value2 + 0x10) = value3;
  if (value3 != 0) {
    CEntities::SelectScriptAttachmentSequence(value3,1);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  ((EntitySceneObject *)value)->y = 0;
LAB_004068dd:
  CEntities::LinkEntityIntoProcessingList(&g_ScriptedEnemyEntityListHead,entry);
  return;
}

